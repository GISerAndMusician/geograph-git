#pragma once
#include "GgsNodeProxy.h"

class GgsEdgeProxy: public GgsElementBase
{
public:
	GgsEdgeProxy( GgsNodeProxy* fromNode, GgsNodeProxy* toNode, const QgsFeature& feature, ogdf::edge edge);
	GgsEdgeProxy(const GgsEdgeProxy& other);
	~GgsEdgeProxy();

	GgsNodeProxy* fromNode() const { return mFromNode; }
	GgsNodeProxy* toNode() const { return mToNode; }

	ogdf::edge edge() { return mEdge; }

private:
	GgsNodeProxy* mFromNode;
	GgsNodeProxy* mToNode;
	ogdf::edge mEdge = nullptr;
};

#include "qgsvectorlayer.h"
class GgsEdgeLayerProxy
{
public:
	GgsEdgeLayerProxy( QgsVectorLayer* edgeLayer);
	GgsEdgeLayerProxy(const GgsEdgeLayerProxy& other);
	~GgsEdgeLayerProxy();

	QgsVectorLayer* edgeLayer() { return mEgdeLayer; }

	void addEdge(GgsEdgeProxy* edge);

	QList<GgsEdgeProxy*> edges() { return mEdges.values(); }

	GgsEdgeProxy* findEgde(ogdf::edge e);
	GgsEdgeProxy* findEdge(QgsFeatureId fid) const;
	GgsEdgeProxy* findEdge(GgsNodeProxy* from, GgsNodeProxy* to);

	bool removeEdge(GgsEdgeProxy* edge);

private:
	QgsVectorLayer* mEgdeLayer;
	QMap<QgsFeatureId, GgsEdgeProxy*> mEdges;
};
