#include "GgsClusterDialog.h"
#include "qgsproject.h"
#include "qgsvectorlayer.h"

GgsClusterDialog::GgsClusterDialog(QWidget* parent /*= nullptr*/)
	: QDialog(parent)
{
	setupUi(this);

	connect(ok_pushButton, &QPushButton::clicked, this, &GgsClusterDialog::onOk);

	initComboBox();
}

GgsClusterDialog::~GgsClusterDialog()
{

}

QgsVectorLayer* GgsClusterDialog::layer()
{
	return layers_comboBox->currentData(Qt::UserRole).value<QgsVectorLayer*>();
}

int GgsClusterDialog::clusterCount()
{
	return spinBox_cluster_count->value();
}

void GgsClusterDialog::onOk()
{
	this->accept();
}

void GgsClusterDialog::initComboBox()
{
	QList<QgsMapLayer*> layers = QgsProject::instance()->mapLayers().values();
	for each (QgsMapLayer* layer in layers)
	{
		QgsVectorLayer* vectorLayer = dynamic_cast<QgsVectorLayer*>(layer);
		if (!vectorLayer)
		{
			continue;
		}

		if (vectorLayer->geometryType() == QgsWkbTypes::GeometryType::PointGeometry)
		{
			this->layers_comboBox->insertItem(0, vectorLayer->name(), QVariant::fromValue(vectorLayer));
		}
	}
}
