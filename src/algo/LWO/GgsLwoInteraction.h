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

	// 恢复到最初状态
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
	// 内插控制点
	void interpolateForCross(QgsPointXY p1, QgsPointXY p2, QgsPointXY center, double radius, QgsGeometry& origin);

	void betweenVertices(const QgsPointXY& pt, QgsGeometry geom, int& first, int& second);

	// 处理轮毂线
	void hub();

	// 生成圆形布局
	void layout();

	// 更新节点关联的连边位置
	void update();

	// 再次处理轮毂线（节点布局后，连边位置有更新，导致连边与轮毂的空间关系发生变化
	void reHub();

	// 渲染
	void render();

	int indexOfCurrentSelectionBuffer();

private:
	/*
	 * \brief 与当前圈选区域相关的变量
	*/
	GgsGraphMapToolSelect* mMapTool; // 选择工具
	QgsGeometry mCurrentSelectionGeometry; // 选择几何对象
	double mCurrentSelectionRadius; // 圈选区域半径
	QgsPointXY mCurrentSelectionCenter;
	GgsEdgeLayerProxy* mCurrentEgdeLayerProxy = nullptr;
	GgsNodeLayerProxy* mCurrentNodeLayerProxy = nullptr;
	QgsVectorLayer* mCurrentEdgeLayer = nullptr;
	QgsVectorLayer* mCurrentNodeLayer = nullptr;

	// 圈选区内的节点，<选区索引号，节点集合>
	QMap<int, QList<GgsNodeProxy*>> mSelectedNodes;
	// 临存选区
	QList<SelectionBuffer> mSelectionBuffer;

	// 容忍度，与生成曲线平滑度有关（以角度1度为单位）
	int mTolerance = 3;

	// 节点尺寸
	double mNodeRadius = 0.4; // 地理坐标系下默认0.4；投影坐标默认40000
	// 圈选区域内节点放大比例
	double mNodeRatio = 2.0; 

	// 圈选区域内节点标签偏移距离
	double mLabelSpan = 10;  // 地理坐标系下默认10
	QString mLabel;

	// 圈内节点符号样式
	QColor mCircleNodeFillColor = Qt::green;
	QColor mCircleNodeStrokeColor = Qt::black;
	// 圈外节点符号样式
	QColor mNodeFillColor = Qt::green;
	QColor mNodeStrokeColor = Qt::black;

	// 修改过的图，用于恢复原图
	QList<GgsGraphProxy*> mModifiedGraph;
	QgsFeatureRenderer* mOriginNodeLayerRenderer = nullptr;
	QgsAbstractVectorLayerLabeling* mOriginNodeLayerLabeling = nullptr;

};

