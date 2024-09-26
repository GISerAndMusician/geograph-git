#include "GgsGraphProxy.h"
#include <qgsproject.h>
#include <QApplication>

#pragma execution_character_set("utf-8") 

GgsGraphProxy::GgsGraphProxy(QgsVectorLayer* nodeLayer, QgsVectorLayer* edgeLayer, const QString& name /*= QString()*/)
	: mName(name)
{
	mUuid = QUuid::createUuid();

	mGraph = new ogdf::Graph;
	mGraphAttributes = new ogdf::GraphAttributes(*mGraph, 
		ogdf::GraphAttributes::nodeGraphics | ogdf::GraphAttributes::edgeGraphics | ogdf::GraphAttributes::nodeWeight);
	mNodeLayer = new GgsNodeLayerProxy(nodeLayer);
	mEdgeLayer = new GgsEdgeLayerProxy(edgeLayer);
}

GgsGraphProxy::GgsGraphProxy(const GgsGraphProxy& other)
	: GgsGraphProxy(other.mNodeLayer->nodeLayer(), other.mEdgeLayer->edgeLayer(), other.mName)
{
	mName = other.mName;

	mGraph = new ogdf::Graph(*other.mGraph);
}

GgsGraphProxy::~GgsGraphProxy()
{

	if (mEdgeLayer)
	{
		delete mEdgeLayer;
		mEdgeLayer = nullptr;
	}

	if (mNodeLayer) {
		delete mNodeLayer;
		mNodeLayer = nullptr;
	}

	if (mGraphAttributes)
	{
		delete mGraphAttributes;
		mGraphAttributes = nullptr;
	}

	if (mGraph)
	{
		delete mGraph;
		mGraph = nullptr;
	}

}

GgsNodeProxy* GgsGraphProxy::newNodeProxy(const QgsFeature& f)
{
	ogdf::node n = mGraph->newNode();
	mGraphAttributes->x(n) = f.geometry().asPoint().x();
	mGraphAttributes->y(n) = f.geometry().asPoint().y();
	mGraphAttributes->weight(n) = 1;

	GgsNodeProxy* pNodeProxy = new GgsNodeProxy(f, n);
	mNodeLayer->addNode(pNodeProxy);

	return pNodeProxy;
}

GgsEdgeProxy* GgsGraphProxy::newEdgeProxy(GgsNodeProxy* fn, GgsNodeProxy* tn, const QgsFeature& f)
{
	ogdf::edge e = mGraph->newEdge(fn->node(), tn->node());
	GgsEdgeProxy* pEdgeProxy = new GgsEdgeProxy(fn, tn, f, e);
	mEdgeLayer->addEdge(pEdgeProxy);

	return pEdgeProxy;
}

bool GgsGraphProxy::removeEdgeProxy(GgsEdgeProxy* pEdgeProxy)
{
	bool bSuccess = mEdgeLayer->removeEdge(pEdgeProxy);
	if (bSuccess)
	{
		mGraph->delEdge(pEdgeProxy->edge());
		return true;
	}
	else {
		return false;
	}
}

bool GgsGraphProxy::removeNodeProxy(GgsNodeProxy* pNodeProxy)
{
	ogdf::List<ogdf::edge> elist;
	pNodeProxy->node()->adjEdges(elist);

	for (int i=0; i<elist.size(); i++)
	{
		ogdf::edge e = *elist.get(i);
		GgsEdgeProxy* edgeProxy =  mEdgeLayer->findEgde(e);
		if (!edgeProxy)
		{
			return false;
		}
		else {
			mEdgeLayer->removeEdge(edgeProxy);
		}
	}

	mGraph->delNode(pNodeProxy->node());

	return mNodeLayer->removeNode(pNodeProxy);
}

GgsGraphProxy* GgsGraphProxy::clone(QProgressBar* progressBar)
{
	QgsVectorLayer* pOriginNodeLayer = mNodeLayer->nodeLayer();
	QgsVectorLayer* pOriginEdgeLayer = mEdgeLayer->edgeLayer();

	if (progressBar)
	{
		progressBar->setVisible(true);
		progressBar->setTextVisible(true);

		progressBar->setRange(0, pOriginNodeLayer->featureCount() - 1);
		progressBar->setFormat(tr("正在创建图层...%p%"));
	}

	// 创建节点图层
	QString nodeLayerProperties = QString("%1?crs=%2&index=yes&memoryid=%3").
		arg("Point").
		arg(pOriginNodeLayer->crs().authid()).
		arg(QUuid::createUuid().toString());    // 几何类型
	QgsVectorLayer* pNodeLayer = new QgsVectorLayer(
		nodeLayerProperties,
		pOriginNodeLayer->name(),
		"memory");

	if (!pNodeLayer->isValid())
	{
		return nullptr;
	}
	else {
		pNodeLayer->dataProvider()->addAttributes(pOriginNodeLayer->fields().toList());

		QList< QgsMapLayer * > layers;
		layers << pNodeLayer;
		QgsProject::instance()->addMapLayers(layers);
	}

	// 创建连边图层
	QString edgeLayerProperties = QString("%1?crs=%2&index=yes&memoryid=%3").
		arg("LineString").
		arg(pOriginEdgeLayer->crs().authid()).
		arg(QUuid::createUuid().toString());    // 几何类型

	QgsVectorLayer* pEgdeLayer = new QgsVectorLayer(
		edgeLayerProperties,
		pOriginEdgeLayer->name(),
		"memory");

	if (!pEgdeLayer->isValid())
	{
		return nullptr;
	}
	else {
		pEgdeLayer->dataProvider()->addAttributes(pOriginEdgeLayer->fields().toList());

		QList< QgsMapLayer * > layers;
		layers << pEgdeLayer;
		QgsProject::instance()->addMapLayers(layers);
	}

	GgsGraphProxy* newGraph = new GgsGraphProxy(pNodeLayer,
		pEgdeLayer,
		"[图]" + pEgdeLayer->name()
	);

	if (progressBar)
	{
		progressBar->setRange(0, pOriginNodeLayer->featureCount() - 1);
		progressBar->setFormat(QObject::tr("正在载入节点要素...%p%"));
	}

	pNodeLayer->startEditing();
	QMap<QgsFeatureId, QPair<GgsNodeProxy*, GgsNodeProxy*>> nodeMap;
	for (int i=0; i< mNodeLayer->nodes().size(); i++)
	{
		GgsNodeProxy* originNodeProxy = mNodeLayer->nodes()[i];
		QgsFeature feature = originNodeProxy->feature(mNodeLayer->nodeLayer());
		pNodeLayer->dataProvider()->addFeature(feature);

		// 创建节点代理
		GgsNodeProxy* nodeProxy = newGraph->newNodeProxy(feature);
		nodeMap.insert(originNodeProxy->feature().id(), QPair<GgsNodeProxy*, GgsNodeProxy*>(originNodeProxy, nodeProxy));

		QApplication::processEvents(QEventLoop::ExcludeUserInputEvents);
		if (progressBar)
			progressBar->setValue(i);
	}

	pNodeLayer->commitChanges();
	pNodeLayer->updateExtents();

	pEgdeLayer->startEditing();
	if (progressBar)
	{
		progressBar->setRange(0, pOriginEdgeLayer->featureCount() - 1);
		progressBar->setFormat(QObject::tr("正在载入连边要素...%p%"));
	}

	for (int i = 0; i < mEdgeLayer->edges().size(); i++)
	{
		std::cout << i << ":" << std::endl;
		GgsEdgeProxy* edgeProxy = mEdgeLayer->edges()[i];
		GgsNodeProxy* fromNodeProxy =  nodeMap[edgeProxy->fromNode()->feature().id()].second;
		GgsNodeProxy* toNodeProxy = nodeMap[edgeProxy->toNode()->feature().id()].second;

		if (edgeProxy)
		{
			QgsFeature feature = edgeProxy->feature(mEdgeLayer->edgeLayer());
			pEgdeLayer->dataProvider()->addFeature(feature);

			// 创建连边代理
			GgsEdgeProxy* edgeProxy = newGraph->newEdgeProxy(
				fromNodeProxy,
				toNodeProxy,
				feature
			);
		}

		QApplication::processEvents(QEventLoop::ExcludeUserInputEvents);
		if (progressBar)
			progressBar->setValue(i);
	}
	pEgdeLayer->commitChanges();
	pEgdeLayer->updateExtents();

	return newGraph;
}
