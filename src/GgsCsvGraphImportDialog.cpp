#include "GgsCsvGraphImportDialog.h"
#include <QFileDialog>
#include <QMessageBox>

#include "GgsCsvParser.h"
#include "GgsGraphLayerBuilder.h"
#include "GgsNodeProxy.h"
#include "GgsEdgeProxy.h"
#include "GgsGraphProxy.h"

#include "qgssettings.h"
#include "qgsprojectionselectiondialog.h"
#include "qgscoordinatereferencesystem.h"
#include "qgsvectorlayer.h"

#pragma execution_character_set("utf-8") 

GgsCsvGraphImportDialog::GgsCsvGraphImportDialog(QWidget* parent /*= nullptr*/)
	: QDialog(parent)
{
	setupUi(this);

	progressBar->setVisible(false);

	mNodeFileParser = new GgsCsvParser;
	mEdgeFileParser = new GgsCsvParser;

	initSplitterComboBox();

	connect(this->toolButtonNodeFileBrowser, &QToolButton::clicked, this, &GgsCsvGraphImportDialog::browserNodeFile);
	connect(this->comboBoxNodeFileSpliter, SIGNAL(currentIndexChanged(int)), this, SLOT(nodeFilterSpliterChanged(int)));
	connect(this->toolButtonEdgeFileBrowser, &QToolButton::clicked, this, &GgsCsvGraphImportDialog::browserEgdeFile);
	connect(this->comboBoxEdgeFileSpliter, SIGNAL(currentIndexChanged(int)), this, SLOT(edgeFilterSpliterChanged(int)));
	connect(this->toolButtonCRS, &QToolButton::clicked, this, &GgsCsvGraphImportDialog::selectCRS);
	connect(this->okButton, &QPushButton::clicked, this, &GgsCsvGraphImportDialog::createLayers);
}

GgsCsvGraphImportDialog::~GgsCsvGraphImportDialog()
{
	if (mNodeFileParser) 
	{
		delete mNodeFileParser;
		mNodeFileParser = nullptr;
	}

	if (mEdgeFileParser) 
	{
		delete mEdgeFileParser;
		mEdgeFileParser = nullptr;
	}

}

void GgsCsvGraphImportDialog::initSplitterComboBox()
{
	comboBoxNodeFileSpliter->addItem("逗号（使用英文逗号分隔）", GgsCsvParser::Splitter::COMMA);
	comboBoxNodeFileSpliter->addItem("空格（使用空格分隔）", GgsCsvParser::Splitter::SPACE);
	comboBoxNodeFileSpliter->addItem("制表符（使用Tab分隔）", GgsCsvParser::Splitter::TAB);

	comboBoxEdgeFileSpliter->addItem("逗号（使用英文逗号分隔）", GgsCsvParser::Splitter::COMMA);
	comboBoxEdgeFileSpliter->addItem("空格（使用空格分隔）", GgsCsvParser::Splitter::SPACE);
	comboBoxEdgeFileSpliter->addItem("制表符（使用Tab分隔）", GgsCsvParser::Splitter::TAB);
}

void GgsCsvGraphImportDialog::loadNodeCSVFile(const QString& nodeFileName)
{
	disconnect(checkBoxAllNodeHeaders, &QCheckBox::stateChanged, this, &GgsCsvGraphImportDialog::toggleSelectAllNodeHeaders);

	this->lineEditNodeFileName->setText(nodeFileName);

	QFileInfo nodeFileInfo(nodeFileName);
	this->lineEditNodeLayerName->setText(nodeFileInfo.fileName().split(".")[0]);

	if (!mNodeFileParser->load(nodeFileName)) {
		QMessageBox::information(this, tr("提示信息"), tr("文件解析失败！"));
		return;
	}

	QStringList headers = mNodeFileParser->headers();
	comboBoxXHeaders->clear();
	comboBoxXHeaders->addItems(headers);
	comboBoxYHeaders->clear();
	comboBoxYHeaders->addItems(headers);
	comboBoxIdHeaders->clear();
	comboBoxIdHeaders->addItems(headers);

	listWidgetNodeHeaders->clear();
	for each (QString header in headers)
	{
		QListWidgetItem *item = new QListWidgetItem(listWidgetNodeHeaders);
		QCheckBox* checkBox = new QCheckBox;
		checkBox->setText(header);
		checkBox->setChecked(true);
		listWidgetNodeHeaders->addItem(item);
		listWidgetNodeHeaders->setItemWidget(item, checkBox);

		connect(checkBox, &QCheckBox::stateChanged, this, &GgsCsvGraphImportDialog::askIfSelectAllNodeHeaders);
	}

	checkBoxAllNodeHeaders->setChecked(true);
	connect(checkBoxAllNodeHeaders, &QCheckBox::stateChanged, this, &GgsCsvGraphImportDialog::toggleSelectAllNodeHeaders);
}

void GgsCsvGraphImportDialog::loadEdgeCSVFile(const QString& edgeFilePath)
{
	disconnect(checkBoxAllEdgeHeaders, &QCheckBox::stateChanged, this, &GgsCsvGraphImportDialog::toggleSelectAllEdgeHeaders);

	this->lineEditEdgeFileName->setText(edgeFilePath);

	QFileInfo edgeFileInfo(edgeFilePath);
	this->lineEditEdgeLayerName->setText(edgeFileInfo.fileName().split(".")[0]);

	if (!mEdgeFileParser->load(edgeFilePath)) {
		QMessageBox::information(this, tr("提示信息"), tr("文件解析失败！"));
		return;
	}

	QStringList headers = mEdgeFileParser->headers();
	comboBoxEdgeSourceHeaders->clear();
	comboBoxEdgeSourceHeaders->addItems(headers);
	comboBoxEdgeTargetHeaders->clear();
	comboBoxEdgeTargetHeaders->addItems(headers);

	listWidgetEdgeHeaders->clear();
	for each (QString header in headers)
	{
		QListWidgetItem *item = new QListWidgetItem(listWidgetEdgeHeaders);
		QCheckBox* checkBox = new QCheckBox;
		checkBox->setText(header);
		checkBox->setChecked(true);
		listWidgetEdgeHeaders->addItem(item);
		listWidgetEdgeHeaders->setItemWidget(item, checkBox);

		connect(checkBox, &QCheckBox::stateChanged, this, &GgsCsvGraphImportDialog::askIfSelectAllEdgeHeaders);
	}

	checkBoxAllEdgeHeaders->setChecked(true);
	connect(checkBoxAllEdgeHeaders, &QCheckBox::stateChanged, this, &GgsCsvGraphImportDialog::toggleSelectAllEdgeHeaders);
}

void GgsCsvGraphImportDialog::browserNodeFile()
{
	QgsSettings settings;
	QString lastUsedDir = settings.value(QStringLiteral("UI/lastCSVGraphDir"), QDir::homePath()).toString();

	QStringList fileFilters;
	fileFilters << tr("CSV文件") + QStringLiteral(" (*.csv *.txt)");

	QString nodeFileName = QFileDialog::getOpenFileName(this, 
		tr("选择作为节点的CSV文件"), 
		lastUsedDir, 
		fileFilters.join(QLatin1String(";;")));
	if (nodeFileName.isNull()) 
	{
		return;
	}

	QFileInfo myFI(nodeFileName);
	QString myPath = myFI.path();
	settings.setValue(QStringLiteral("UI/lastCSVGraphDir"), myPath);

	loadNodeCSVFile(nodeFileName);
}

void GgsCsvGraphImportDialog::browserEgdeFile()
{
	QgsSettings settings;
	QString lastUsedDir = settings.value(QStringLiteral("UI/lastCSVGraphDir"), QDir::homePath()).toString();

	QStringList fileFilters;
	fileFilters << tr("CSV文件") + QStringLiteral(" (*.csv *.txt)");

	QString edgeFileName = QFileDialog::getOpenFileName(this,
		tr("选择作为连边的CSV文件"),
		lastUsedDir,
		fileFilters.join(QLatin1String(";;")));
	if (edgeFileName.isNull())
	{
		return;
	}

	QFileInfo myFI(edgeFileName);
	QString myPath = myFI.path();
	settings.setValue(QStringLiteral("UI/lastCSVGraphDir"), myPath);

	loadEdgeCSVFile(edgeFileName);
}

void GgsCsvGraphImportDialog::selectCRS()
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

void GgsCsvGraphImportDialog::nodeFilterSpliterChanged(int index)
{
	mNodeFileParser->setSplitter((GgsCsvParser::Splitter)(comboBoxNodeFileSpliter->itemData(index).toInt()));

	QString nodeFileName = lineEditNodeFileName->text();
	if (!nodeFileName.isNull()) {
		loadNodeCSVFile(nodeFileName);
	}	
}

void GgsCsvGraphImportDialog::edgeFilterSpliterChanged(int index)
{
	mEdgeFileParser->setSplitter((GgsCsvParser::Splitter)(comboBoxEdgeFileSpliter->itemData(index).toInt()));

	QString edgeFileName = lineEditEdgeFileName->text();
	if (!edgeFileName.isNull())
	{
		loadEdgeCSVFile(edgeFileName);
	}
}

void GgsCsvGraphImportDialog::toggleSelectAllNodeHeaders(int status)
{
	if (mListWidgetNodeSelect)
	{
		return;
	}
	int iCount = listWidgetNodeHeaders->count();
	if (!iCount)
	{
		return;
	}

	for (int i = 0; i < iCount; i++) {
		QListWidgetItem* pItem = listWidgetNodeHeaders->item(i);
		mCheckBoxAllNodeHeaders = true;
		(static_cast<QCheckBox*>(listWidgetNodeHeaders->itemWidget(pItem)))->setChecked(checkBoxAllNodeHeaders->isChecked());
		mCheckBoxAllNodeHeaders = false;
	}
}

void GgsCsvGraphImportDialog::toggleSelectAllEdgeHeaders(int status)
{
	if (mListWidgetEdgeSelect)
	{
		return;
	}
	int iCount = listWidgetEdgeHeaders->count();
	if (!iCount)
	{
		return;
	}

	for (int i = 0; i < iCount; i++) {
		QListWidgetItem* pItem = listWidgetEdgeHeaders->item(i);
		mCheckBoxAllEdgeHeaders = true;
		(static_cast<QCheckBox*>(listWidgetEdgeHeaders->itemWidget(pItem)))->setChecked(checkBoxAllEdgeHeaders->isChecked());
		mCheckBoxAllEdgeHeaders = false;
	}
}

void GgsCsvGraphImportDialog::askIfSelectAllNodeHeaders(int status)
{
	if (mCheckBoxAllNodeHeaders)
	{
		return;
	}

	int iChecked = 0;
	for (int i = 0; i < listWidgetNodeHeaders->count(); i++) {
		QListWidgetItem* pItem = listWidgetNodeHeaders->item(i);
		if ((static_cast<QCheckBox*>(listWidgetNodeHeaders->itemWidget(pItem)))->isChecked()) {
			iChecked++;
		}
	}
	mListWidgetNodeSelect = true;
	checkBoxAllNodeHeaders->setChecked(iChecked == listWidgetNodeHeaders->count());
	mListWidgetNodeSelect = false;
}

void GgsCsvGraphImportDialog::askIfSelectAllEdgeHeaders(int status)
{
	if (mCheckBoxAllEdgeHeaders)
	{
		return;
	}

	int iChecked = 0;
	for (int i = 0; i < listWidgetEdgeHeaders->count(); i++) {
		QListWidgetItem* pItem = listWidgetEdgeHeaders->item(i);
		if ((static_cast<QCheckBox*>(listWidgetEdgeHeaders->itemWidget(pItem)))->isChecked()) {
			iChecked++;
		}
	}
	mListWidgetEdgeSelect = true;
	checkBoxAllEdgeHeaders->setChecked(iChecked == listWidgetEdgeHeaders->count());
	mListWidgetEdgeSelect = false;
}

void GgsCsvGraphImportDialog::createLayers()
{
	progressBar->setVisible(true);
	progressBar->setTextVisible(true);

	progressBar->setRange(0, listWidgetNodeHeaders->count()-1);
	progressBar->setFormat(tr("正在创建节点图层...%p%"));
	// 创建节点图层
	QStringList selectedNodeHeaders;
	for (int i = 0; i < listWidgetNodeHeaders->count(); i++)
	{
		QListWidgetItem* pItem = listWidgetNodeHeaders->item(i);
		QCheckBox* pCheckBox = static_cast<QCheckBox*>(listWidgetNodeHeaders->itemWidget(pItem));
		if (pCheckBox->isChecked())
		{
			selectedNodeHeaders << pCheckBox->text();
		}
		progressBar->setValue(i);
	}

	QString nodeLayerProperties = QString("%1?crs=%2&index=yes&memoryid=%3").
		arg("Point").
		arg(QgsCoordinateReferenceSystem::fromOgcWmsCrs(lineEditCRS->text()).authid()).
		arg(QUuid::createUuid().toString());    // 几何类型

	QgsVectorLayer* pNodeLayer = new QgsVectorLayer(
		nodeLayerProperties,
		lineEditNodeLayerName->text(),
		"memory");

	QgsCoordinateReferenceSystem sys = pNodeLayer->crs();

	if (!pNodeLayer->isValid())
	{
		return;
	}
	else {
		// 添加属性字段
		QgsFields fields = GgsGraphLayerBuilder::buildFields(mNodeFileParser->data());
		pNodeLayer->dataProvider()->addAttributes(fields.toList());

		QList< QgsMapLayer * > layers;
		layers << pNodeLayer;
		QgsProject::instance()->addMapLayers(layers);
	}

	progressBar->setRange(0, listWidgetEdgeHeaders->count()-1);
	progressBar->setFormat(tr("正在创建连边图层...%p%"));
	// 创建连边图层
	QStringList selectedEdgeHeaders;
	for (int i = 0; i < listWidgetEdgeHeaders->count(); i++)
	{
		QListWidgetItem* pItem = listWidgetEdgeHeaders->item(i);
		QCheckBox* pCheckBox = static_cast<QCheckBox*>(listWidgetEdgeHeaders->itemWidget(pItem));
		if (pCheckBox->isChecked())
		{
			selectedEdgeHeaders << pCheckBox->text();
		}
		progressBar->setValue(i);
	}

	QString edgeLayerProperties = QString("%1?crs=%2&index=yes&memoryid=%3").
		arg("LineString").
		arg(pNodeLayer->crs().authid()).
		arg(QUuid::createUuid().toString());    // 几何类型

	QgsVectorLayer* pEgdeLayer = new QgsVectorLayer(
		edgeLayerProperties,
		lineEditEdgeLayerName->text(),
		"memory");

	if (!pEgdeLayer->isValid())
	{
		return;
	}
	else {
		// 添加属性字段
		QgsFields fields = GgsGraphLayerBuilder::buildFields(mEdgeFileParser->data());
		pEgdeLayer->dataProvider()->addAttributes(fields.toList());

		QList< QgsMapLayer * > layers;
		layers << pEgdeLayer;
		QgsProject::instance()->addMapLayers(layers);
	}

	mGraphProxy = new GgsGraphProxy(pNodeLayer,
		pEgdeLayer,
		"[图]" + pEgdeLayer->name()
	);
	
	QMap<QString, QgsFeatureId> idMap;
	GgsGraphLayerBuilder::buildNodeLayer(
		mGraphProxy,
		mNodeFileParser->data(),
		comboBoxXHeaders->currentText(),
		comboBoxYHeaders->currentText(),
		comboBoxIdHeaders->currentText(),
		selectedNodeHeaders,
		idMap,
		progressBar
	);

	GgsGraphLayerBuilder::buildEdgeLayer(
		mGraphProxy,
		mEdgeFileParser->data(),
		idMap,
		comboBoxEdgeSourceHeaders->currentText(),
		comboBoxEdgeTargetHeaders->currentText(),
		selectedEdgeHeaders,
		progressBar
	);

	progressBar->setVisible(false);
	this->accept();
}
