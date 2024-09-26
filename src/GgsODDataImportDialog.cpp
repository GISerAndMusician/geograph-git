#include "GgsODDataImportDialog.h"
#include <QFileDialog>
#include <QMessageBox>
#include "GgsCsvParser.h"
#include "qgsvectorlayer.h"
#include "qgsprojectionselectiondialog.h"
#include "qgscoordinatereferencesystem.h"

#pragma execution_character_set("utf-8") 

GgsODDataImportDialog::GgsODDataImportDialog(QWidget* parent /*= nullptr*/)
	:QDialog(parent)
{
	setupUi(this);

	mFileParser = new GgsCsvParser;

	initSplitterComboBox();

	connect(toolButtonExplore, &QToolButton::clicked, this, &GgsODDataImportDialog::explore);
	connect(this->comboBoxSpliter, SIGNAL(currentIndexChanged(int)), this, SLOT(spliterChanged(int)));
	connect(this->toolButtonCRS, &QToolButton::clicked, this, &GgsODDataImportDialog::selectCRS);
	connect(this->pushButton_ok, &QPushButton::clicked, this, &GgsODDataImportDialog::importOD);

	progressBar->setVisible(false);
}

void GgsODDataImportDialog::explore()
{
	QgsSettings settings;
	QString lastUsedDir = settings.value(QStringLiteral("UI/lastCSVGraphDir"), QDir::homePath()).toString();

	QStringList fileFilters;
	fileFilters << tr("CSV文件") + QStringLiteral(" (*.csv *.txt)");

	QString szPath = QFileDialog::getOpenFileName(this,
		tr("请选择OD文件"),
		lastUsedDir,
		fileFilters.join(QLatin1String(";;")));

	if (szPath.isNull())
	{
		return;
	}
	this->lineEditDataSource->setText(szPath);

	QFileInfo myFI(szPath);
	QString myPath = myFI.path();
	settings.setValue(QStringLiteral("UI/lastCSVGraphDir"), myPath);

	loadCSVFile(szPath);
}

void GgsODDataImportDialog::spliterChanged(int index)
{
	mFileParser->setSplitter((GgsCsvParser::Splitter)(comboBoxSpliter->itemData(index).toInt()));

	QString fileName = lineEditDataSource->text();
	if (!fileName.isNull()) {
		loadCSVFile(fileName);
	}
}

void GgsODDataImportDialog::selectCRS()
{
	QgsProjectionSelectionDialog mySelector(this);
	mySelector.setWindowIcon(this->windowIcon());

	QgsCoordinateReferenceSystem crs = QgsCoordinateReferenceSystem::fromOgcWmsCrs(lineEditCRS->text());
	if (!crs.isValid())
	{
		mySelector.showNoCrsForLayerMessage();
	}

	if (!mySelector.exec())
	{
		return;
	}

	this->lineEditCRS->setText(mySelector.crs().authid());
}

void GgsODDataImportDialog::importOD()
{
	progressBar->setVisible(true);

	QString nodeLayerProperties = QString("%1?crs=%2&index=yes&memoryid=%3").
		arg("Point").
		arg(QgsCoordinateReferenceSystem::fromOgcWmsCrs(lineEditCRS->text()).authid()).
		arg(QUuid::createUuid().toString());    // 几何类型

	QFileInfo nodeFileInfo(lineEditDataSource->text());

	mNodeLayer = new QgsVectorLayer(
		nodeLayerProperties,
		nodeFileInfo.fileName().split(".")[0] + "_点",
		"memory");

	QString edgeLayerProperties = QString("%1?crs=%2&index=yes&memoryid=%3").
		arg("LineString").
		arg(QgsCoordinateReferenceSystem::fromOgcWmsCrs(lineEditCRS->text()).authid()).
		arg(QUuid::createUuid().toString());    // 几何类型

	mEdgeLayer = new QgsVectorLayer(
		edgeLayerProperties,
		nodeFileInfo.fileName().split(".")[0] + "_线",
		"memory");

	if (!mNodeLayer->isValid() || !mEdgeLayer->isValid())
	{
		return;
	}
	else {
		mNodeLayer->startEditing();
		mEdgeLayer->startEditing();

		QMap<QString, QStringList> data = mFileParser->data();

		QString OXLabel = comboBox_OX->currentText();
		QString OYLabel = comboBox_OY->currentText();
		QString DXLabel = comboBox_DX->currentText();
		QString DYLabel = comboBox_DY->currentText();

		int iFeatureCount = data[OXLabel].size();
		if (progressBar)
		{
			progressBar->setRange(0, iFeatureCount - 1);
			progressBar->setFormat(QObject::tr("正在载入要素...%p%"));
		}

		QgsVectorDataProvider* nodeDateProvider = mNodeLayer->dataProvider();
		QgsVectorDataProvider* edgeDataProvider = mEdgeLayer->dataProvider();

		for (int i = 0; i < iFeatureCount; i++)
		{
			/*QString start_time = "start_time";
			QString end_time = "end_time";
			//QDateTime start_date_time = QDateTime::fromString(data[start_time][i] + ":0", "yyyy-M-d h:mm:z");
			//QDateTime end_date_time = QDateTime::fromString(data[end_time][i] + ":0", "yyyy-M-d h:mm:z");
			QDateTime start_date_time = QDateTime::fromSecsSinceEpoch(data[start_time][i].toInt());
			QDateTime end_date_time = QDateTime::fromSecsSinceEpoch(data[end_time][i].toInt());

			QDateTime from_dt(QDate(2016, 11, 14), QTime(23, 0, 0));
			QDateTime to_dt(QDate(2016, 11, 14), QTime(23, 59, 59));

			if (from_dt <= start_date_time && start_date_time <= to_dt 
				&& from_dt <= end_date_time && end_date_time <= to_dt)*/
			{
				QgsFeature feature_O;
				QgsPointXY pt_O;
				pt_O.setX(data[OXLabel][i].toDouble());
				pt_O.setY(data[OYLabel][i].toDouble());
				feature_O.setGeometry(QgsGeometry::fromPointXY(pt_O));

				QgsFeature feature_D;
				QgsPointXY pt_D;
				pt_D.setX(data[DXLabel][i].toDouble());
				pt_D.setY(data[DYLabel][i].toDouble());
				feature_D.setGeometry(QgsGeometry::fromPointXY(pt_D));

				nodeDateProvider->addFeature(feature_O);
				nodeDateProvider->addFeature(feature_D);

				QgsFeature edge;
				QgsPolylineXY pl;
				pl << pt_O << pt_D;
				edge.setGeometry(QgsGeometry::fromPolylineXY(pl));
				edgeDataProvider->addFeature(edge);

			}

			QApplication::processEvents(QEventLoop::ExcludeUserInputEvents);
			progressBar->setValue(i);
		}
		mNodeLayer->commitChanges();
		mEdgeLayer->commitChanges();

		QList< QgsMapLayer * > layers;
		layers << mEdgeLayer << mNodeLayer;
		QgsProject::instance()->addMapLayers(layers);
	}

	progressBar->setVisible(false);
	this->accept();
}

void GgsODDataImportDialog::initSplitterComboBox()
{
	comboBoxSpliter->addItem("逗号（使用英文逗号分隔）", GgsCsvParser::Splitter::COMMA);
	comboBoxSpliter->addItem("空格（使用空格分隔）", GgsCsvParser::Splitter::SPACE);
	comboBoxSpliter->addItem("制表符（使用Tab分隔）", GgsCsvParser::Splitter::TAB);
}

void GgsODDataImportDialog::loadCSVFile(const QString& filepath)
{

	if (!mFileParser->load(filepath)) {
		QMessageBox::information(this, tr("提示信息"), tr("文件解析失败！"));
		return;
	}

	QStringList headers = mFileParser->headers();
	comboBox_OX->clear();
	comboBox_OX->addItems(headers);
	comboBox_OY->clear();
	comboBox_OY->addItems(headers);
	comboBox_DX->clear();
	comboBox_DX->addItems(headers);
	comboBox_DY->clear();
	comboBox_DY->addItems(headers);
}
