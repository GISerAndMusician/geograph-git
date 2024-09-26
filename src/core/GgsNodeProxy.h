#pragma once
#include "qgsfeature.h"
#include "ogdf/basic/Graph.h"

class GgsElementBase 
{
public:
	GgsElementBase(const QgsFeature& feature);
	~GgsElementBase();
	/*
	* @desc ��ȡ�ڵ������Ҫ�أ��������ʸ��ͼ�㣬��᷵��ͼ�����µ�Ҫ�����ݣ��������޸ĺ��Ҫ�أ���
	*       �����򷵻س�ʼ��ʱ��Ҫ��
	* @param nodeLayer �ڵ�������ͼ��
	* @return QgsFeature Ҫ��
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

	// �˽ӿڲ���ɾ�����������ߣ������Ҫ�������GgsGraphProxy��removeNodeProxy�ӿ�
	bool removeNode(const GgsNodeProxy* node);

	GgsNodeProxy* findNode(QgsFeatureId fid) const;
	GgsNodeProxy* findNode(const ogdf::node n) const;
	
private:
	QgsVectorLayer* mNodeLayer;
	
	QMap<QgsFeatureId, GgsNodeProxy*> mNodes;
};

