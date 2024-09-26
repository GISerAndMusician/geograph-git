#pragma once
#include <QList>
#include "GgsMingleRenderContext.h"
#include "qgspointxy.h"

class GgsMingleEdge;
class GgsMingleNode
{
public:
	QgsPointXY m1;
	QgsPointXY m2;

	GgsMingleNode();
	GgsMingleNode(QString id, QString name, QgsPointXY coordSource, QgsPointXY coordTarget);
	GgsMingleNode(const GgsMingleNode& other);
	~GgsMingleNode();

	QString getId();
	void setId(QString id);

	QString getName();
	void setName(QString name);

	QgsPointXY getCoordSource();
	void setCoordSource(QgsPointXY coords);

	QgsPointXY getCoordTarget();
	void setCoordTarget(QgsPointXY coords);

 	bool adjacentTo(GgsMingleNode node);
 	
	GgsMingleEdge* getEdge(QString id);

	void setGroup(int group);
	int getGroup();

	QList<GgsMingleNode*>& parents();
	QList<GgsMingleNode*>& nodes() { return mNodes; }
	void setNodes(QList<GgsMingleNode*> nodes) { mNodes = nodes; };
	QList<GgsMingleNode*>& nodeArray() { return mNodeArray; }
	void setNodeArray(QList<GgsMingleNode*> nodeArray) { mNodeArray = nodeArray; }

	GgsMingleNode* getBundle();
	void setBundle(GgsMingleNode* bundle);

	double getInk();
	void setInk(double ink);

	int getWeight() { return mWeight; };
	void setWeight(int w) { mWeight = w; }

	QMap<QString, GgsMingleEdge*>& adjacencies() { return mAdjacencies; }

	void setRemoved(bool flag) { mRemoved = true; };
	bool isRemoved() { return mRemoved; }

	void setClusterIndex(int i) { mClusterIndex = i; };
	int getClusterIndex() { return mClusterIndex; };

	struct PositionItem
	{
		GgsMingleNode* node;
		double normal[2];
		double pos[2];
		double unbundledPos[2];
	};

	QList<QList<PositionItem>> unbundleEdges(GgsMingleRenderContext ctx);

private:
	QList<QList<PositionItem>> expandEdges();

	void expandEdgesRichHelper(GgsMingleNode* node, QList<PositionItem>& array, QList<QList<PositionItem>>& collect);

private:
	QString mId;
	QString mName;
	QgsPointXY mCoordSource;
	QgsPointXY mCoordTarget;
	QMap<QString, GgsMingleEdge*> mAdjacencies;

	int mWeight = 1;

	int mGroup = -1;

	QList<GgsMingleNode*> mParents;
	QList<GgsMingleNode*> mNodes;
	QList<GgsMingleNode*> mNodeArray;

	double mInk = 0;
	GgsMingleNode* mCombineNode = nullptr;

	GgsMingleRenderContext mRenderContext;
	QList<QList<GgsMingleNode::PositionItem>> mUnbundleEdges;

	bool mRemoved = false;

	int mClusterIndex = -1;
};
