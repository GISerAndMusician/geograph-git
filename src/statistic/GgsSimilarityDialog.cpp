#include "GgsSimilarityDialog.h"
#include <qgsmaplayer.h>
#include <qgsproject.h>
#include <qgsvectorlayer.h>
#include <math.h>
#include <QMessageBox>

#pragma execution_character_set("utf-8") 

GgsSimilarityDialog::GgsSimilarityDialog(QWidget* parent /*= nullptr*/)
	:QDialog(parent)
{
	setupUi(this);
	initComboBox();

	connect(this->pushButtonOk, &QPushButton::clicked, this, &GgsSimilarityDialog::onOk);
	connect(this->pushButtonCancel, &QPushButton::clicked, this, &GgsSimilarityDialog::rejected);
}

GgsSimilarityDialog::~GgsSimilarityDialog()
{

}

void GgsSimilarityDialog::onOk()
{
	QgsVectorLayer* pRefenceLayer = comboBoxReferencLayer->currentData(Qt::UserRole).value<QgsVectorLayer*>();
	QgsVectorLayer* pLayer = comboBoxLayer->currentData(Qt::UserRole).value<QgsVectorLayer*>();

	QgsFeatureIterator iter_ref = pRefenceLayer->getFeatures();
	QgsFeature feature_ref;
	double L_ref = 0, A_ref = 0, D_ref = 0;
	QgsRectangle layerBBox_ref;
	QgsPointXY center_ref;
	while (iter_ref.nextFeature(feature_ref))
	{
		L_ref += feature_ref.geometry().length();
		A_ref += feature_ref.geometry().area();
		center_ref = feature_ref.geometry().centroid().asPoint();

		QgsRectangle bBox = feature_ref.geometry().boundingBox();
		layerBBox_ref.combineExtentWith(bBox);
	}

	QgsFeatureIterator iter = pLayer->getFeatures();
	QgsFeature feature;
	double L = 0, A = 0, D = 0;
	QgsRectangle layerBBox;
	QgsPointXY center;
	while (iter.nextFeature(feature))
	{
		L += feature.geometry().length();
		A += feature.geometry().area();

		center = feature.geometry().centroid().asPoint();
		QgsRectangle bBox = feature.geometry().boundingBox();
		layerBBox.combineExtentWith(bBox);
	}

	double L_Sim = L / L_ref;
	double A_Sim = A / A_ref;
	double Dist = center.distance(center_ref);
	QString msg = QString("长度相似性：%1；大小相似性：%2；中心偏移距离：%3").
		arg(QString::number(L_Sim)).
		arg(QString::number(A_Sim)).
		arg(QString::number(Dist));
	QMessageBox::information(this, tr("相似度"), msg);
}

void GgsSimilarityDialog::initComboBox()
{
	QList<QgsMapLayer*> layers = QgsProject::instance()->mapLayers().values();
	for each (QgsMapLayer* layer in layers)
	{
		QgsVectorLayer* vectorLayer = dynamic_cast<QgsVectorLayer*>(layer);
		if (!vectorLayer)
		{
			continue;
		}

		this->comboBoxReferencLayer->insertItem(0, vectorLayer->name(), QVariant::fromValue(vectorLayer));
		this->comboBoxLayer->insertItem(0, vectorLayer->name(), QVariant::fromValue(vectorLayer));
	}
}
