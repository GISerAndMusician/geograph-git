#pragma once
#include "qgsfeature.h"
#include "ogdf/basic/Graph.h"

class GgsElementBase 
{
public:
	GgsElementBase(const QgsFeature& feature);
	~GgsElementBase();
	/*
	* @desc 获取节点关联的要素，如果传入矢量图层，则会返回图层最新的要素数据（尤其是修改后的要素），
	*       否则，则返回初始化时的要素
	* @param nodeLayer 节点所属的图层
	* @return QgsFeature 要素
	*/
	QgsFeature feature(const QgsVectorLayer* nodeLayer = nullptr) const;

protected:
	QgsFeature mFeature;
};

class GgsNodeProxy: public GgsElementBase
{
public:
	GgsNodeProxy(const QgsFeature& feature, ogdf::node node);
	GgsNodeProxy(const GgsNodeProxy& other);
	~GgsNodeProxy();
	
	ogdf::node node() { return mNode; }

	static bool compareDegree(const GgsNodeProxy* n1, const GgsNodeProxy* n2);

private:
	ogdf::node mNode = nullptr;
};

#include "qgsvectorlayer.h"
class GgsNodeLayerProxy
{
public:
	GgsNodeLayerProxy( QgsVectorLayer* nodeLayer);
	GgsNodeLayerProxy(const GgsNodeLayerProxy& other);
	~GgsNodeLayerProxy();

	QgsVectorLayer* nodeLayer() const { return mNodeLayer; }

	QList<GgsNodeProxy*> nodes();

	void addNode(GgsNodeProxy* n);

	// 此接口不会删除关联的连边，如果需要，请调用GgsGraphProxy的removeNodeProxy接口
	bool removeNode(const GgsNodeProxy* node);

	GgsNodeProxy* findNode(QgsFeatureId fid) const;
	GgsNodeProxy* findNode(const ogdf::node n) const;
	
private:
	QgsVectorLayer* mNodeLayer;
	
	QMap<QgsFeatureId, GgsNodeProxy*> mNodes;
};

