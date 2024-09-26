#include "GgsAggregation.h"
#include "GgsGraphProxy.h"

GgsAggregation::GgsAggregation(GgsGraphProxy* graph)
{
	mGraph = graph;
}

void GgsAggregation::aggregate()
{
	/*GgsNodeLayerProxy* nodeLayerProxy = mGraph->nodeLayerProxy();
	GgsEdgeLayerProxy* edgeLayerProxy = mGraph->edgeLayerProxy();
	QgsVectorLayer* nodeLayer = nodeLayerProxy->nodeLayer();
	QgsVectorLayer* edgeLayer = edgeLayerProxy->edgeLayer();

	QList<GgsNodeProxy*> nodeProxys = nodeLayerProxy->nodes();
	for each (GgsNodeProxy* nodeProxy in nodeProxys)
	{
		QgsFeature f = nodeProxy->feature(nodeLayer);
		QgsPointXY pt = f.geometry().asPoint();

		QgsRectangle buffer(
			QgsPointXY(pt.x() - mSearchBuffer, pt.y() - mSearchBuffer),
			QgsPointXY(pt.x() + mSearchBuffer, pt.y() + mSearchBuffer)
		);

		QgsFeatureIterator iter = nodeLayer->getFeatures(buffer);
		while (iter.isValid())
		{
			QgsFeature near;
			iter.nextFeature(near);

			double d = f.geometry().distance(near.geometry());
			if (d < mTolerance)
			{
				QgsPointXY oldPt = near.geometry().asPoint();
				QgsPointXY newPt(
					(pt.x() + oldPt.x()) / 2.0,
					(pt.y() + oldPt.y()) / 2.0
				);


			}
		}
	}*/
}
