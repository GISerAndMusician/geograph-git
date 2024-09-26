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
	* ���ýڵ�
	* MINGLE�㷨�еĽڵ�MINGLENode����һ���������ɵ�4ά��������ΪMINGLE�㷨��ͨ�����߼����Լ������ƣ�
	* ���ԣ���Ҫͨ�����ɵ�4ά��������������/�����
	*/
	void setNodes(QList<GgsMingleNode*> nodes);

	/* ����KD��
	*/
	void buildKdTree();

	/*
	* �����ڽ��ڵ��������ڽ�ͼ���ڵ���ָ����MINGLENode�ڽ�������
	* @param �ڽ��ڵ���
	*/
	void buildNearestNeighborGraph(int k = 10);

	/* ִ��MINGLE�㷨
	*/
	void mingle();

	/* ִ����Ⱦ
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

	/* ���㲢������ʡīˮ���ڽӽڵ�
	*/
	InkSavingNeighbor getMaximumInkSavingNeighbor(GgsMingleNode* n);

	/* ����ڵ����õ�īˮֵ
	*/
	double getInkValue(GgsMingleNode* n, int depth = 0);

	/* �������Ͻڵ�
	*/
	GgsMingleNode* getCombinedNode(GgsMingleNode* from, GgsMingleNode* to);

	/* ����MINGLENode���м�ָ��
	*/
	void computeIntermediateNodePositions(GgsMingleNode* cb);

	/* �������ڵ������
	*/
	QList<QgsPointXY> getCentroids(QList<GgsMingleNode*> nodes);

	/* ����ƽ�ָ��
	*/
	double goldenSectionSearch(double a, double b, double c, double tau, GgsMingleNode* node, QList<QgsPointXY> centoids);
	
	/* ��ʧ����
	*/
	double costFunction(GgsMingleNode* node, QList<QgsPointXY> centoids, double x);
	
	/* �������ת��Ƕ�
	*/
	double getMaxTurningAngleValue(GgsMingleNode* node, QgsPointXY m1, QgsPointXY m2);

	/* ������MINGLENode�ڵ���֯��һ����
	*/
	void bundle(GgsMingleNode* combineNode, GgsMingleNode* node1, GgsMingleNode* node2);

	void coalesceGraph();

	GgsMingleNode* coalesceNodes(QList<GgsMingleNode*> nodes);

	void updateGraph(GgsMingleNode* groupedNode, QList<GgsMingleNode*> nodes, QMap<QString, GgsMingleNode*> ids);

	// ��ֱ�߷�ʽ����
	void renderLine(QList<QList<GgsMingleNode::PositionItem>> edges, QgsVectorLayer* pLayer);
	// ��bezier���߷�ʽ����
	void renderBezier(QList<QList<GgsMingleNode::PositionItem>> edges, QgsVectorLayer* pLayer);
	// ��quadratic���߷�ʽ����
	void renderQuadratic(QList<QList<GgsMingleNode::PositionItem>> edges, QgsVectorLayer* pLayer);

	// �������Ƶ�λ��
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

