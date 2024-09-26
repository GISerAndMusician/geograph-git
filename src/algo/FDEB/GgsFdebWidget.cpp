#include "GgsFdebWidget.h"
#include <QVariant>
#include "qgsproject.h"
#include "qgsvectorlayer.h"
#include "GgsFdebGraph.hpp"
#include "qgsfeature.h"
#include "qgsmemoryproviderutils.h"

#include "GgsGraphProject.h"

GgsFdebWidget::GgsFdebWidget(QWidget* parent /*= nullptr*/)
	:QWidget(parent)
{
	setupUi(this);

	initComboBox();
	initUiValues();

	connect(pushButtonRun, &QPushButton::clicked, this, &GgsFdebWidget::run);
	this->progressBar->hide();
	connect(GgsGraphProject::instance(), &GgsGraphProject::graphLayerAdded, this, &GgsFdebWidget::refreshGraphProxys);
}

GgsFdebWidget::~GgsFdebWidget()
{

}

void GgsFdebWidget::refreshGraphProxys(GgsGraphProxy* graphProxy)
{
	comboBoxGraphLayer->clear();
	this->initComboBox();
}

void GgsFdebWidget::initComboBox()
{
	for each (GgsGraphProxy* graphProxy in GgsGraphProject::instance()->graphProxys())
	{
		comboBoxGraphLayer->addItem(QIcon(":/graph/bundling/graphlayer.png"),
				graphProxy->getName(),
				QVariant::fromValue(graphProxy)
			);
	}
}

void GgsFdebWidget::initUiValues()
{
	doubleSpinBoxK->setValue(mK);
	spinBoxI->setValue(mI);
	spinBoxCycles->setValue(mCycles);
	doubleSpinBoxCompatibility->setValue(mCompat);
	doubleSpinBoxsmooth->setValue(mSignma);

	doubleSpinBoxS->setValue(mS);
	doubleSpinBoxEdgeDistance->setValue(mEpsilon);
	doubleSpinBoxGravityExponent->setValue(mGravityExponent);

	doubleSpinBoxWeightThreshold->setValue(mEdgeWeight);
	doubleSpinBoxPercentage->setValue(mEdgePercentage);
}

void GgsFdebWidget::createVectorLayer(std::vector<GgsFdebEdge> edges, GgsGraphProxy* graphProxy)
{

	QgsVectorLayer* pLayer = QgsMemoryProviderUtils::createMemoryLayer(
		"[FDEB]" + graphProxy->edgeLayerProxy()->edgeLayer()->name(),
		QgsFields(),
		QgsWkbTypes::LineString,
		graphProxy->edgeLayerProxy()->edgeLayer()->crs());

	if(!pLayer->isValid())
	{
		return;
	}

	QgsProject::instance()->addMapLayer(pLayer);

	QgsVectorDataProvider* provider = pLayer->dataProvider();

	std::vector<GgsFdebEdge>::iterator iter_edges = edges.begin();
	while (iter_edges != edges.end())
	{
		QgsFeature feature;

		QgsPolylineXY plXY;

		std::vector<meerkat::mk_vector2> pts = (*iter_edges).points();
		std::vector<meerkat::mk_vector2>::iterator iter_pts = pts.begin();
		while (iter_pts != pts.end())
		{
			plXY.append(
				QgsPointXY(
					(*iter_pts).x() / mCoordScale,
					(*iter_pts).y() / mCoordScale
				)
			);
			iter_pts++;
		}
		feature.setGeometry(QgsGeometry::fromPolylineXY(plXY));
		
		provider->addFeature(feature);
		iter_edges++;
	}
	pLayer->commitChanges();
	pLayer->updateExtents();
}

void GgsFdebWidget::run()
{
	GgsGraphProxy* graphProxy = comboBoxGraphLayer->currentData().value<GgsGraphProxy*>();

	if (!graphProxy)
	{
		return;
	}

	this->progressBar->show();
	this->progressBar->setRange(0, mCycles * mI);

	GgsFdebGraph g;
	g.set_algorithm_params(
		doubleSpinBoxK->value(), // K
		spinBoxCycles->value(), // Cycles,
		spinBoxI->value(), // I,
		doubleSpinBoxCompatibility->value(), // Compat
		doubleSpinBoxsmooth->value() // Signma
	);

	g.set_network_params(
		doubleSpinBoxWeightThreshold->value(), // edge weight
		doubleSpinBoxPercentage->value() // edge percentage
	);

	g.set_physics_params(
		doubleSpinBoxS->value(), // S
		doubleSpinBoxEdgeDistance->value(), // epsilon
		meerkat::mk_vector2(0.0, 0.0),
		doubleSpinBoxGravityExponent->value() // gravitation exponent
	);

	//g.enable_gravitation();

	std::map<std::string, GgsFdebNode> nodes;
	GgsNodeLayerProxy* nodeLayerProxy = graphProxy->nodeLayerProxy();
	QgsVectorLayer* nodeLayer = nodeLayerProxy->nodeLayer();

	QgsFeatureIterator iter = nodeLayer->getFeatures();
	QgsFeature f;
	while (iter.nextFeature(f))
	{
		QgsPointXY ptXY = f.geometry().asPoint();
		GgsFdebNode n;
		n._pos.set(
			ptXY.x() * mCoordScale,
			ptXY.y() * mCoordScale
		);
		nodes.insert(
			std::make_pair(QString::number(f.id()).toStdString(), n)
		);
	}

// 	for each (GgsNodeProxy* nodeProxy in nodeLayerProxy->nodes())
// 	{
// 		QgsPointXY ptXY = nodeProxy->feature().geometry().asPoint();
// 		GgsFdebNode n;
// 		n._pos.set(
// 			ptXY.x() * mCoordScale,
// 			ptXY.y() * mCoordScale
// 		);
// 		nodes.insert(
// 			std::make_pair( QString::number(nodeProxy->feature().id()).toStdString(), n)
// 		);
// 	}

	std::vector<GgsFdebEdge> edges;
	GgsEdgeLayerProxy* edgeLayerProxy = graphProxy->edgeLayerProxy();
	for each (GgsEdgeProxy* edgeProxy in edgeLayerProxy->edges())
	{

		std::string sourceLabel = QString::number(edgeProxy->fromNode()->feature().id()).toStdString();
		std::string targetLabel = QString::number(edgeProxy->toNode()->feature().id()).toStdString();

		edges.push_back(
			GgsFdebEdge(
				sourceLabel,
				targetLabel,
				nodes[sourceLabel]._pos,
				nodes[targetLabel]._pos,
				1.0
			)
		);
	}

	g.load(nodes, edges);

	int cycleIndex = mCycles;
	do
	{
		int iterLeft;
		while ((iterLeft = g.iterate()) > 0) {
			this->progressBar->setValue(( mCycles - cycleIndex + 1) * (mI - iterLeft));
			qApp->processEvents();
		};
		g.add_subvisions();
	} while (( cycleIndex = g.update_cycle()) > 0);

	g.smooth();

	std::vector<GgsFdebEdge> edges_out = g.edges();

	createVectorLayer(edges_out, graphProxy);

	this->progressBar->hide();
}
