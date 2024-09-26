#include "GgsKdeebWidget.h"
#include "GgsGraphProject.h"
#include "GgsKdeebBundler.h"
#include "qgsmemoryproviderutils.h"
#include "qgsproject.h"
#include "GgsApp.h"

GgsKdeebWidget::GgsKdeebWidget(QgsMapCanvas* mapCanvas, QWidget* parent /*= nullptr*/)
	: QWidget(parent)
{
	mMapCanvas = mapCanvas;
	setupUi(this);

	initComboBox();

	connect(pushButtonRun, &QPushButton::clicked, this, &GgsKdeebWidget::run);
	this->progressBar->hide();
	connect(GgsGraphProject::instance(), &GgsGraphProject::graphLayerAdded, this, &GgsKdeebWidget::refreshGraphProxys);
}

GgsKdeebWidget::~GgsKdeebWidget()
{

}

void GgsKdeebWidget::refreshGraphProxys(GgsGraphProxy* graphProxy)
{
	comboBoxGraphLayer->clear();
	this->initComboBox();
}

void GgsKdeebWidget::run()
{
	GgsGraphProxy* graphProxy = comboBoxGraphLayer->currentData().value<GgsGraphProxy*>();

	if (!graphProxy)
	{
		return;
	}

	QList<QgsPolylineXY> pls;
	QgsVectorLayer* pEdgeLayer = graphProxy->edgeLayerProxy()->edgeLayer();
	QgsRectangle ext = pEdgeLayer->extent();
	GgsApp::instance()->mapCanvas()->zoomToFeatureExtent(ext);

	QgsFeatureIterator iter = pEdgeLayer->getFeatures();
	QgsFeature f;
	while (iter.nextFeature(f))
	{
		QgsPolylineXY mapLineXY = f.geometry().asPolyline();

		QgsPolylineXY screenLineXY;
		for each (QgsPointXY mapPointXY in mapLineXY)
		{
			screenLineXY << mMapCanvas->getCoordinateTransform()->transform(mapPointXY);
		}

		pls << screenLineXY;
	}

	GgsKdeebBundler bundler;
	connect(&bundler, &GgsKdeebBundler::progressChanged, this, &GgsKdeebWidget::updateProgress);
	this->progressBar->show();
	this->progressBar->setRange(0, spinBoxIterator->value());

	bundler.setAttraction(doubleSpinBoxAttraction->value());
	bundler.setSmooth(spinBoxSmooth->value());
	bundler.setKernel(spinBoxKernel->value());
	bundler.setSplitDistance(doubleSpinBoxSplitDist->value());
	bundler.setRemoveDistance(doubleSpinBoxRemoveDist->value());
	bundler.setIterator(spinBoxIterator->value());
	bundler.setPolylines(pls);
	bundler.doBundle();
	QList<QgsPolylineXY> bundles = bundler.polylines();

	QgsVectorLayer* pLayer = QgsMemoryProviderUtils::createMemoryLayer(
		"[KDEEB]" + graphProxy->edgeLayerProxy()->edgeLayer()->name(),
		QgsFields(),
		QgsWkbTypes::LineString,
		graphProxy->edgeLayerProxy()->edgeLayer()->crs());

	if (!pLayer->isValid())
	{
		return;
	}

	QgsProject::instance()->addMapLayer(pLayer);

	QgsVectorDataProvider* provider = pLayer->dataProvider();
	for each (QgsPolylineXY line in bundles)
	{
		QgsFeature f;

		QgsPolylineXY mapLineXY;
		for each (QgsPointXY point in line)
		{
			mapLineXY << mMapCanvas->getCoordinateTransform()->toMapCoordinates(point.x(), point.y());
		}

		f.setGeometry(QgsGeometry::fromPolylineXY(mapLineXY));

		provider->addFeature(f);
	}

	pLayer->commitChanges();
	pLayer->updateExtents();

	this->progressBar->hide();
}

void GgsKdeebWidget::updateProgress(int current, int total)
{
	this->progressBar->setValue(current);
	qApp->processEvents();
}

void GgsKdeebWidget::initComboBox()
{
	for each (GgsGraphProxy* graphProxy in GgsGraphProject::instance()->graphProxys())
	{
		comboBoxGraphLayer->addItem(QIcon(":/graph/bundling/graphlayer.png"),
			graphProxy->getName(),
			QVariant::fromValue(graphProxy)
		);
	}
}
