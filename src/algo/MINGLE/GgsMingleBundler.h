#pragma once
#include "GgsMingleGraph.h"
#include "GgsMingleKdTree.h"
#include "qgsgeometry.h"
#include "qgsfeature.h"

class GgsMingleBundler: public QObject
{
	Q_OBJECT
public:
	GgsMingleBundler();
	~GgsMingleBundler();

	/*
	* 设置节点
	* MINGLE算法中的节点MINGLENode是由一对坐标点组成的4维向量，因为MINGLE算法不通过连边兼容性计算相似，
	* 所以，需要通过构成的4维向量来计算相邻/相近。
	*/
	void setNodes(QList<GgsMingleNode*> nodes);

	/* 构建KD树
	*/
	void buildKdTree();

	/*
	* 根据邻近节点数构建邻接图，节点数指的是MINGLENode邻近的数量
	* @param 邻近节点数
	*/
	void buildNearestNeighborGraph(int k = 10);

	/* 执行MINGLE算法
	*/
	void mingle();

	/* 执行渲染
	*/
	void render(GgsMingleRenderContext ctx, QgsVectorLayer* pLayer);

	void setAngleStrength(double angle) { mAngleStrength = angle; };
	double getAngleStrenth() { return mAngleStrength; }

	void setNeighbors(int n) { mNeighbors = n; };
	int getNeighbors() { return mNeighbors; }

private:
	struct InkSavingNeighbor
	{
		QList<GgsMingleNode*> bundle;
		double inkTotal;
		GgsMingleNode* combined;
	};

	QList<GgsMingleNode*> getNodesByKDTreeIndexes(std::vector<int> indexes);

	/* 计算并获得最节省墨水的邻接节点
	*/
	InkSavingNeighbor getMaximumInkSavingNeighbor(GgsMingleNode* n);

	/* 计算节点所用的墨水值
	*/
	double getInkValue(GgsMingleNode* n, int depth = 0);

	/* 构建联合节点
	*/
	GgsMingleNode* getCombinedNode(GgsMingleNode* from, GgsMingleNode* to);

	/* 计算MINGLENode的中间分割点
	*/
	void computeIntermediateNodePositions(GgsMingleNode* cb);

	/* 计算多个节点的中心
	*/
	QList<QgsPointXY> getCentroids(QList<GgsMingleNode*> nodes);

	/* 计算黄金分割点
	*/
	double goldenSectionSearch(double a, double b, double c, double tau, GgsMingleNode* node, QList<QgsPointXY> centoids);
	
	/* 损失函数
	*/
	double costFunction(GgsMingleNode* node, QList<QgsPointXY> centoids, double x);
	
	/* 计算最大转弯角度
	*/
	double getMaxTurningAngleValue(GgsMingleNode* node, QgsPointXY m1, QgsPointXY m2);

	/* 将两个MINGLENode节点组织成一个簇
	*/
	void bundle(GgsMingleNode* combineNode, GgsMingleNode* node1, GgsMingleNode* node2);

	void coalesceGraph();

	GgsMingleNode* coalesceNodes(QList<GgsMingleNode*> nodes);

	void updateGraph(GgsMingleNode* groupedNode, QList<GgsMingleNode*> nodes, QMap<QString, GgsMingleNode*> ids);

	// 以直线方式绘制
	void renderLine(QList<QList<GgsMingleNode::PositionItem>> edges, QgsVectorLayer* pLayer);
	// 以bezier曲线方式绘制
	void renderBezier(QList<QList<GgsMingleNode::PositionItem>> edges, QgsVectorLayer* pLayer);
	// 以quadratic曲线方式绘制
	void renderQuadratic(QList<QList<GgsMingleNode::PositionItem>> edges, QgsVectorLayer* pLayer);

	// 调整控制点位置
	QgsPointXY adjustPosition(const QString& id, GgsMingleNode::PositionItem posItem, double* pos, double margin, double delta);

private:
	GgsMingleGraph* mGraph = new GgsMingleGraph;
	GgsMingleKdTree<Point4D<double>>* mKDTree = nullptr;

	QMap<int, GgsMingleNode*> mKDTreeIndexes;

private:
	double mAngleStrength = 3;
	int mNeighbors = 10;

	GgsMingleRenderContext mRenderContext;

	QList<QString> mRemovedIds;

signals:
	void progressChanged(int iter, int current, int total);
};

