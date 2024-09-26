#pragma once
#include <QObject>
#include <QColor>

#include "qgsgeometry.h"

class QgsMapCanvas;
class QgsFeatureRenderer;
class QgsAbstractVectorLayerLabeling;
class GgsGraphMapToolSelect;
class GgsGraphProxy;
class GgsNodeProxy;
class GgsNodeLayerProxy;
class GgsEdgeLayerProxy;
class QgsPointXY;

struct SelectionBuffer
{
	QgsGeometry geometry;
	double radius;
	GgsGraphProxy* graph;
};

class GgsLwoInteraction: public QObject
{
	Q_OBJECT

public:
	GgsLwoInteraction(GgsGraphMapToolSelect* mapTool);
	~GgsLwoInteraction();

	// �ָ������״̬
	void recover();

	void listen();
	void mute();

	double getNodeRadius();
	void setNodeRadius(double radius);

	QColor getNodeFillColor();
	void setNodeFillColor(QColor color);

	QColor getNodeStrokeColor();
	void setNodeStrokeColor(QColor color);

	double getNodeRatio();
	void setNodeRatio(double ratio);

	QString getLabel();
	void setLabel(QString label);

	double getLabelSpan();
	void setLabelSpan(double span);

	QColor getCircleNodeFillColor();
	void setCircleNodeFillColor(QColor color);

	QColor getCircleNodeStrokeColor();
	void setCircleNodeStrokeColor(QColor color);

	void renderSymbols(bool updateLabel = false);

private slots:
	void onGraphSelectionChanged(GgsGraphProxy* graph);

private:
	// �ڲ���Ƶ�
	void interpolateForCross(QgsPointXY p1, QgsPointXY p2, QgsPointXY center, double radius, QgsGeometry& origin);

	void betweenVertices(const QgsPointXY& pt, QgsGeometry geom, int& first, int& second);

	// ���������
	void hub();

	// ����Բ�β���
	void layout();

	// ���½ڵ����������λ��
	void update();

	// �ٴδ�������ߣ��ڵ㲼�ֺ�����λ���и��£�������������챵Ŀռ��ϵ�����仯
	void reHub();

	// ��Ⱦ
	void render();

	int indexOfCurrentSelectionBuffer();

private:
	/*
	 * \brief �뵱ǰȦѡ������صı���
	*/
	GgsGraphMapToolSelect* mMapTool; // ѡ�񹤾�
	QgsGeometry mCurrentSelectionGeometry; // ѡ�񼸺ζ���
	double mCurrentSelectionRadius; // Ȧѡ����뾶
	QgsPointXY mCurrentSelectionCenter;
	GgsEdgeLayerProxy* mCurrentEgdeLayerProxy = nullptr;
	GgsNodeLayerProxy* mCurrentNodeLayerProxy = nullptr;
	QgsVectorLayer* mCurrentEdgeLayer = nullptr;
	QgsVectorLayer* mCurrentNodeLayer = nullptr;

	// Ȧѡ���ڵĽڵ㣬<ѡ�������ţ��ڵ㼯��>
	QMap<int, QList<GgsNodeProxy*>> mSelectedNodes;
	// �ٴ�ѡ��
	QList<SelectionBuffer> mSelectionBuffer;

	// ���̶ȣ�����������ƽ�����йأ��ԽǶ�1��Ϊ��λ��
	int mTolerance = 3;

	// �ڵ�ߴ�
	double mNodeRadius = 0.4; // ��������ϵ��Ĭ��0.4��ͶӰ����Ĭ��40000
	// Ȧѡ�����ڽڵ�Ŵ����
	double mNodeRatio = 2.0; 

	// Ȧѡ�����ڽڵ��ǩƫ�ƾ���
	double mLabelSpan = 10;  // ��������ϵ��Ĭ��10
	QString mLabel;

	// Ȧ�ڽڵ������ʽ
	QColor mCircleNodeFillColor = Qt::green;
	QColor mCircleNodeStrokeColor = Qt::black;
	// Ȧ��ڵ������ʽ
	QColor mNodeFillColor = Qt::green;
	QColor mNodeStrokeColor = Qt::black;

	// �޸Ĺ���ͼ�����ڻָ�ԭͼ
	QList<GgsGraphProxy*> mModifiedGraph;
	QgsFeatureRenderer* mOriginNodeLayerRenderer = nullptr;
	QgsAbstractVectorLayerLabeling* mOriginNodeLayerLabeling = nullptr;

};

