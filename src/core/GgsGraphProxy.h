#pragma once
#include "GgsNodeProxy.h"
#include "GgsEdgeProxy.h"
#include "qgsvectorlayer.h"

#include "ogdf/basic/Graph.h"
#include "ogdf/basic/GraphAttributes.h"

#include <QProgressBar>

class GgsGraphProxy: public QObject
{
	Q_OBJECT
public:
	GgsGraphProxy() { Q_ASSERT(!mNodeLayer || !mEdgeLayer); }
	GgsGraphProxy(
		QgsVectorLayer* nodeLayer, 
		QgsVectorLayer* edgeLayer, 
		const QString& name = QString());
	// 浅拷贝
	GgsGraphProxy(const GgsGraphProxy& other);
	~GgsGraphProxy();

	QUuid uuid() { return mUuid; }

	QString getName() const { return mName; }
	void setName(const QString& id) { mName = id; };

	GgsNodeLayerProxy* nodeLayerProxy() { return mNodeLayer; }
	GgsEdgeLayerProxy* edgeLayerProxy() { return mEdgeLayer; }

	GgsNodeProxy* newNodeProxy(const QgsFeature& f);
	GgsEdgeProxy* newEdgeProxy(GgsNodeProxy* fn, GgsNodeProxy* tn, const QgsFeature& f);

	ogdf::Graph* graph() { return mGraph; }
	ogdf::GraphAttributes* graphAttributes() { return mGraphAttributes; }

	bool removeEdgeProxy(GgsEdgeProxy* pEdgeProxy);
	bool removeNodeProxy(GgsNodeProxy* pNodeProxy);

	// 深拷贝
	GgsGraphProxy* clone(QProgressBar* progressBar = nullptr);

private:
	QString mName;
	GgsNodeLayerProxy* mNodeLayer = nullptr;
	GgsEdgeLayerProxy* mEdgeLayer = nullptr;

	QUuid mUuid;

	// 图
	ogdf::Graph* mGraph = nullptr;
	ogdf::GraphAttributes* mGraphAttributes = nullptr;
};

Q_DECLARE_METATYPE(GgsGraphProxy)

