#include "GgsNodeProxy.h"

#include "ogdf/basic/Graph.h"

/************************************************************************/
/* GgsElementBase                                                         */
/************************************************************************/
GgsElementBase::GgsElementBase(const QgsFeature& feature)
	:mFeature(feature)
{

}

GgsElementBase::~GgsElementBase()
{

}

QgsFeature GgsElementBase::feature(const QgsVectorLayer* nodeLayer /*= nullptr*/) const
{
	if (nodeLayer)
	{
		return nodeLayer->getFeature(mFeature.id());
	}
	else
		return mFeature;
}

/************************************************************************/
/* GgsNodeProxy                                                         */
/************************************************************************/
GgsNodeProxy::GgsNodeProxy(const QgsFeature& feature, ogdf::node node)
	: GgsElementBase(feature)
{
	mNode = node;
}

// GgsNodeProxy::GgsNodeProxy(const GgsNodeProxy& other)
// 	: GgsNodeProxy(other.mFeature, other.mNode)
// {
// 	mFeature = other.mFeature;
// 
// }

GgsNodeProxy::~GgsNodeProxy()
{

}

bool GgsNodeProxy::compareDegree(const GgsNodeProxy* n1, const GgsNodeProxy* n2)
{
	return n1->mNode->degree() > n2->mNode->degree();
}

GgsNodeLayerProxy::GgsNodeLayerProxy( QgsVectorLayer* nodeLayer)
	:mNodeLayer(nodeLayer)
{

}

// GgsNodeLayerProxy::GgsNodeLayerProxy(const GgsNodeLayerProxy& other)
// 	: GgsNodeLayerProxy(other.mNodeLayer)
// {
// 
// 	for each (QgsFeatureId id in other.mNodes.keys())
// 	{
// 		mNodes.insert(id, new GgsNodeProxy(*other.mNodes[id]));
// 	}
// 
// 	mNodeLayer = other.mNodeLayer->clone();
// }

GgsNodeLayerProxy::~GgsNodeLayerProxy()
{
	QMap<QgsFeatureId, GgsNodeProxy*>::iterator iter = mNodes.begin();
	while (iter != mNodes.end())
	{
		GgsNodeProxy* tmp = (*iter);
		if (tmp)
		{
			delete tmp;
			tmp = nullptr;
		}
		iter++;
	}
}

QList<GgsNodeProxy*> GgsNodeLayerProxy::nodes()
{
	return mNodes.values();
}

void GgsNodeLayerProxy::addNode(GgsNodeProxy* n)
{
	mNodes.insert(n->feature().id(), n);
}

bool GgsNodeLayerProxy::removeNode(const GgsNodeProxy* node)
{
	mNodeLayer->startEditing();

	QgsFeature nodeFeature = node->feature(mNodeLayer);

	bool featureDeleted = mNodeLayer->deleteFeature(nodeFeature.id());
	if (!featureDeleted)
	{
		return false;
	}

	if (mNodes[nodeFeature.id()])
	{
		delete mNodes[nodeFeature.id()];
		mNodes[nodeFeature.id()] = nullptr;
	}

	bool edgeDeleted = mNodes.remove(nodeFeature.id());

	if (!edgeDeleted)
	{
		mNodeLayer->rollBack();
		return false;
	}

	mNodeLayer->commitChanges();

	return true;

}

GgsNodeProxy* GgsNodeLayerProxy::findNode(QgsFeatureId fid) const
{
	if (mNodes.find(fid) == mNodes.end())
	{
		return nullptr;
	}
	else
	{
		return (*mNodes.find(fid));
	}
}

GgsNodeProxy* GgsNodeLayerProxy::findNode(const ogdf::node n) const
{
	for each (GgsNodeProxy* nodeProxy in mNodes.values())
	{
		if (ogdf::NodeElement::equal(*n, *nodeProxy->node()))
		{
			return nodeProxy;
		}
	}

	return nullptr;
}

