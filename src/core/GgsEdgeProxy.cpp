#include "GgsEdgeProxy.h"

GgsEdgeProxy::GgsEdgeProxy( GgsNodeProxy* fromNode, GgsNodeProxy* toNode, const QgsFeature& feature, ogdf::edge edge)
	:GgsElementBase(feature)
{
	mFromNode = fromNode;
	mToNode = toNode;
	mEdge = edge;
}

// GgsEdgeProxy::GgsEdgeProxy(const GgsEdgeProxy& other)
// 	: GgsEdgeProxy(other.mFromNode, other.mToNode, other.mFeature, other.mEdge)
// {
// 
// }

GgsEdgeProxy::~GgsEdgeProxy()
{

}

GgsEdgeLayerProxy::GgsEdgeLayerProxy( QgsVectorLayer* edgeLayer)
	:mEgdeLayer(edgeLayer)
{

}

GgsEdgeLayerProxy::GgsEdgeLayerProxy(const GgsEdgeLayerProxy& other)
	: GgsEdgeLayerProxy(other.mEgdeLayer)
{
	mEdges = other.mEdges;
}

GgsEdgeLayerProxy::~GgsEdgeLayerProxy()
{
	QMap<QgsFeatureId, GgsEdgeProxy*>::iterator iter = mEdges.begin();
	while (iter != mEdges.end())
	{
		GgsEdgeProxy* tmp = (*iter);
		if (tmp)
		{
			delete tmp;
			tmp = nullptr;
		}
		iter++;
	}
}

void GgsEdgeLayerProxy::addEdge(GgsEdgeProxy* edge)
{
	mEdges.insert(edge->feature().id(), edge);
}

GgsEdgeProxy* GgsEdgeLayerProxy::findEgde(ogdf::edge e)
{
	for each (GgsEdgeProxy* edgeProxy in mEdges)
	{
		if (ogdf::EdgeElement::equal(*edgeProxy->edge(), *e))
		{
			return edgeProxy;
		}
	}

	return nullptr;
}

GgsEdgeProxy* GgsEdgeLayerProxy::findEdge(QgsFeatureId fid) const
{
	if (mEdges.find(fid) == mEdges.end())
	{
		return nullptr;
	}
	else
	{
		return (*mEdges.find(fid));
	}
}

GgsEdgeProxy* GgsEdgeLayerProxy::findEdge(GgsNodeProxy* from, GgsNodeProxy* to)
{
	for each (GgsEdgeProxy* edge in mEdges.values())
	{
		if (edge->fromNode() == from
			&& edge->toNode() == to)
		{
			return edge;
		}
	}

	return nullptr;
}

bool GgsEdgeLayerProxy::removeEdge(GgsEdgeProxy* edge)
{
	mEgdeLayer->startEditing();

	QgsFeature edgeFeature = edge->feature(mEgdeLayer);

	bool featureDeleted = mEgdeLayer->deleteFeature(edgeFeature.id());
	if (!featureDeleted)
	{
		return false;
	}

	if (mEdges[edgeFeature.id()])
	{
		delete mEdges[edgeFeature.id()];
		mEdges[edgeFeature.id()] = nullptr;
	}

	bool edgeDeleted = mEdges.remove(edgeFeature.id());

	if (!edgeDeleted)
	{
		mEgdeLayer->rollBack();
		return false;
	}

	mEgdeLayer->commitChanges();

	return true;
}
