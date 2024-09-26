#include "GgsCsvGraphExportDialog.h"
#include <QFileDialog>
#include <QMessageBox>
#include <qgssettings.h>

#pragma execution_character_set("utf-8")

GgsCsvGraphExportDialog::GgsCsvGraphExportDialog(GgsGraphProxy* graph, QWidget* parent /*= nullptr*/)
	: QDialog(parent)
{
	this->setupUi(this);
	connect(this->okButton, &QPushButton::clicked, this, &GgsCsvGraphExportDialog::onOK);
	connect(this->toolButton_filepath, &QToolButton::clicked, this, &GgsCsvGraphExportDialog::onFilePath);

	mGraph = graph;

	progressBar->setVisible(false);
}

GgsCsvGraphExportDialog::~GgsCsvGraphExportDialog()
{

}

void GgsCsvGraphExportDialog::onOK()
{
	QString szNodeFileName = this->lineEdit_filepath->text() + "\\" + this->lineEdit_filename->text() + "_node.csv";
	QString szEdgeFileName = this->lineEdit_filepath->text() + "\\" + this->lineEdit_filename->text() + "_edge.csv";

	QgsVectorLayer* pNodeLayer = mGraph->nodeLayerProxy()->nodeLayer();
	QgsVectorLayer* pEdgeLayer = mGraph->edgeLayerProxy()->edgeLayer();

	// 节点
	progressBar->setVisible(true);
	progressBar->setTextVisible(true);
	
	progressBar->setRange(0, pNodeLayer->featureCount() - 1);
	progressBar->setFormat(tr("正在导出节点...%p%"));

	QStringList nodeHeaders;
	for each (QgsField field in pNodeLayer->fields())
	{
		nodeHeaders << field.name();
	}

	QgsFeatureIterator iter_nodeFeatures = pNodeLayer->getFeatures();
	QgsFeature nodeFeature;
	QStringList nodeBody;
	int index = 0;
	while (iter_nodeFeatures.nextFeature(nodeFeature))
	{
		QStringList featureAttrs;

		for each (QString header in nodeHeaders)
		{
			featureAttrs << nodeFeature.attribute(header).toString();
		}

		nodeBody << featureAttrs.join(",");

		QApplication::processEvents(QEventLoop::ExcludeUserInputEvents);
		if (progressBar)
			progressBar->setValue(index++);
	}

	QFile nodeFile(szNodeFileName);
	if (!nodeFile.open(QIODevice::WriteOnly | QIODevice::Text))
	{
		return;
	}

	QTextStream nodeFileOut(&nodeFile);
	nodeFileOut << nodeHeaders.join(",") << endl;
	nodeFileOut << nodeBody.join("\n");
	nodeFile.close();

	// 连边
	progressBar->setRange(0, pEdgeLayer->featureCount() - 1);
	progressBar->setFormat(tr("正在导出连边...%p%"));
	QStringList edgeHeaders;
	for each (QgsField field in pEdgeLayer->fields())
	{
		edgeHeaders << field.name();
	}

	QgsFeatureIterator iter_edgeFeatures = pEdgeLayer->getFeatures();
	QgsFeature edgeFeature;
	QStringList edgeBody;
	index = 0;
	while (iter_edgeFeatures.nextFeature(edgeFeature))
	{
		QStringList featureAttrs;
		for each (QString header in edgeHeaders)
		{
			featureAttrs << edgeFeature.attribute(header).toString();
		}
		edgeBody << featureAttrs.join(",");

		QApplication::processEvents(QEventLoop::ExcludeUserInputEvents);
		if (progressBar)
			progressBar->setValue(index++);
	}

	QFile edgeFile(szEdgeFileName);
	if (!edgeFile.open(QIODevice::WriteOnly | QIODevice::Text))
	{
		return;
	}

	QTextStream edgeFileOut(&edgeFile);
	edgeFileOut << edgeHeaders.join(",") << endl;
	edgeFileOut << edgeBody.join("\n");
	edgeFile.close();

	QMessageBox::information(this, tr("导出CSV图文件"), tr("导出成功！"));

	this->accept();
}

void GgsCsvGraphExportDialog::onFilePath()
{
	QgsSettings settings;
	QString lastUsedDir = settings.value(QStringLiteral("UI/lastCSVGraphDir"), QDir::homePath()).toString();

	QString folderPath = QFileDialog::getExistingDirectory(nullptr, QObject::tr("选择导出路径"),
		lastUsedDir);

	this->lineEdit_filepath->setText(folderPath);
}

