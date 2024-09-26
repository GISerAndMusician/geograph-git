#include "GgsLwoInteraction.h"
#include "qgsmapcanvas.h"
#include "qgsvectorlayer.h"
#include "qgswkbtypes.h"
#include "qgspointxy.h"
#include "qgscircularstring.h"
#include "qgslinestring.h"
#include "qgscategorizedsymbolrenderer.h"
#include "qgsmarkersymbollayer.h"
#include "qgspallabeling.h"
#include "qgsvectorlayerlabeling.h"
#include "qgsrulebasedlabeling.h"
#include "qgsgeometryutils.h"

#include "..\GgsGraphMapToolSelect.h"
#include "GgsGraphProject.h"
#include "GgsGraphProxy.h"
#include "GgsNodeProxy.h"
#include "Compute_Geometry.h"

#include "ogdf/basic/extended_graph_alg.h"
#include "ogdf/misclayout/CircularLayout.h"

#include <QMessageBox>

#pragma execution_character_set("utf-8") 

/*
 * \brief 在图层中需要增加的临时字段
*/
const QString NODE_RADIUS = "NODE_RADIUS"; // 圈选区域内部节点的半径
const QString NODE_X = "NODE_X"; // 圈选区域内部节点的X坐标
const QString NODE_Y = "NODE_Y"; // 圈选区域内部节点的Y坐标
const QString SELECTION_INDEX = "SELECTION_INDEX"; // 圈选区域的索引号
const QString LABEL_DX = "LABEL_DX"; // 圈选区域内部节点标签的X坐标
const QString LABEL_DY = "LABEL_DY"; // 圈选区域内部节点标签的Y坐标
const QString LABEL_ANGLE = "LABEL_ANGLE"; // 圈选区域内部节点标签的角度

//const QString EDGE_CROSS_TYPE = "EDGE_CROSS_TYPE";
enum EdgeCrossType
{
	NONE = 0, // 与圈选区域无交集
	FROM_TOUCH = 1, // 起始节点在圈选区域内
	TO_TOUCH = 2, // 终止节点在圈选区域内
	CONTAIN = 3, // 完全包含在圈选区域内
	CROSS = 4, // 穿越圈选区域
};

GgsLwoInteraction::GgsLwoInteraction(GgsGraphMapToolSelect* mapTool)
	: QObject()
{
	mMapTool = mapTool;

	// listen();
}

GgsLwoInteraction::~GgsLwoInteraction()
{
	mute();
}

void GgsLwoInteraction::recover()
{
	for each (GgsGraphProxy* g in mModifiedGraph)
	{
		GgsNodeLayerProxy* nodeLayerProxy = g->nodeLayerProxy();
		QgsVectorLayer* nodeLayer = nodeLayerProxy->nodeLayer();
		QList<GgsNodeProxy*> nodes =  nodeLayerProxy->nodes();

		nodeLayer->startEditing();
		for each (GgsNodeProxy* n in nodes)
		{
			QgsFeature f = n->feature();
			QgsGeometry g = f.geometry();
			nodeLayer->changeGeometry(f.id(), g);
		}
		nodeLayer->commitChanges();

		GgsEdgeLayerProxy* egdeLayerProxy = g->edgeLayerProxy();
		QgsVectorLayer* edgeLayer = egdeLayerProxy->edgeLayer();
		QList<GgsEdgeProxy*> edges = egdeLayerProxy->edges();
		
		edgeLayer->startEditing();
		for each (GgsEdgeProxy* e in edges)
		{
			QgsFeature f = e->feature();
			QgsGeometry g = f.geometry();
			edgeLayer->changeGeometry(f.id(), g);
		}
		edgeLayer->commitChanges();
	}

	mModifiedGraph.clear();
	mSelectionBuffer.clear();
	mSelectedNodes.clear();

	// 恢复图层样式
	if (mOriginNodeLayerRenderer)
	{
		mCurrentNodeLayer->setRenderer(mOriginNodeLayerRenderer);
		mOriginNodeLayerRenderer = nullptr;
	}

	// 清除标注规则
	if (mCurrentNodeLayer)
	{
		QgsRuleBasedLabeling* ruleLabel = dynamic_cast<QgsRuleBasedLabeling*>(mCurrentNodeLayer->labeling());
		if (ruleLabel)
		{
			QList<QgsRuleBasedLabeling::Rule*> children = ruleLabel->rootRule()->children();
			for (int i = children.size() - 1; i >= 0; i--)
			{
				ruleLabel->rootRule()->removeChildAt(i);
			}
		}

		if (!mOriginNodeLayerLabeling)
		{
			mCurrentNodeLayer->setLabelsEnabled(false);
		}
		else {
			mCurrentNodeLayer->setLabeling(mOriginNodeLayerLabeling);
		}

		mCurrentNodeLayer->deselect(mCurrentNodeLayer->selectedFeatureIds());

		QgsAttributeIds node_attributeIds;
		node_attributeIds << mCurrentNodeLayer->fields().indexOf(NODE_RADIUS)
			<< mCurrentNodeLayer->fields().indexOf(NODE_X)
			<< mCurrentNodeLayer->fields().indexOf(NODE_Y)
			<< mCurrentNodeLayer->fields().indexOf(SELECTION_INDEX)
			<< mCurrentNodeLayer->fields().indexOf(LABEL_DX)
			<< mCurrentNodeLayer->fields().indexOf(LABEL_DY)
			<< mCurrentNodeLayer->fields().indexOf(LABEL_ANGLE);
		mCurrentNodeLayer->startEditing();
		mCurrentNodeLayer->dataProvider()->deleteAttributes(node_attributeIds);
		mCurrentNodeLayer->commitChanges();
	}

	if (mCurrentEdgeLayer)
	{
		mCurrentEdgeLayer->deselect(mCurrentEdgeLayer->selectedFeatureIds());
	}
	
	
}

void GgsLwoInteraction::listen()
{
	connect(mMapTool, &GgsGraphMapToolSelect::graphFeatureSelectionChanged,
		this, &GgsLwoInteraction::onGraphSelectionChanged);
}

void GgsLwoInteraction::mute()
{
	disconnect(mMapTool, &GgsGraphMapToolSelect::graphFeatureSelectionChanged,
		this, &GgsLwoInteraction::onGraphSelectionChanged);
}

double GgsLwoInteraction::getNodeRadius()
{
	return mNodeRadius;
}

void GgsLwoInteraction::setNodeRadius(double radius)
{
	mNodeRadius = radius;
}

QColor GgsLwoInteraction::getNodeFillColor()
{
	return mNodeFillColor;
}

void GgsLwoInteraction::setNodeFillColor(QColor color)
{
	mNodeFillColor = color;
}

QColor GgsLwoInteraction::getNodeStrokeColor()
{
	return mNodeStrokeColor;
}

void GgsLwoInteraction::setNodeStrokeColor(QColor color)
{
	mNodeStrokeColor = color;
}

double GgsLwoInteraction::getNodeRatio()
{
	return mNodeRatio;
}

void GgsLwoInteraction::setNodeRatio(double ratio)
{
	mNodeRatio = ratio;
}

QString GgsLwoInteraction::getLabel()
{
	return mLabel;
}

void GgsLwoInteraction::setLabel(QString label)
{
	mLabel = label;
}

double GgsLwoInteraction::getLabelSpan()
{
	return mLabelSpan;
}

void GgsLwoInteraction::setLabelSpan(double span)
{
	mLabelSpan = span;
}

QColor GgsLwoInteraction::getCircleNodeFillColor()
{
	return mCircleNodeFillColor;
}

void GgsLwoInteraction::setCircleNodeFillColor(QColor color)
{
	mCircleNodeFillColor = color;
}

QColor GgsLwoInteraction::getCircleNodeStrokeColor()
{
	return mCircleNodeStrokeColor;
}

void GgsLwoInteraction::setCircleNodeStrokeColor(QColor color)
{
	mCircleNodeStrokeColor = color;
}

void GgsLwoInteraction::onGraphSelectionChanged(GgsGraphProxy* graph)
{
	if (!mModifiedGraph.contains(graph))
	{
		mModifiedGraph.append(graph);
	}

	mCurrentSelectionGeometry = mMapTool->handler()->selectedGeometry();
	mCurrentSelectionRadius = mMapTool->handler()->radius();
	mCurrentSelectionCenter = mCurrentSelectionGeometry.centroid().asPoint();

	for each (SelectionBuffer buf in mSelectionBuffer)
	{
		if (buf.geometry.intersects(mCurrentSelectionGeometry))
		{
			QMessageBox::information(nullptr, tr("提示"), tr("所选区域与其它区域有交集，无效选区！"));
			return;
		}
	}

	mCurrentEgdeLayerProxy = graph->edgeLayerProxy();
	mCurrentNodeLayerProxy = graph->nodeLayerProxy();
	mCurrentEdgeLayer = mCurrentEgdeLayerProxy->edgeLayer();
	mCurrentNodeLayer = mCurrentNodeLayerProxy->nodeLayer();

	// 存储图层渲染信息
	if (!mOriginNodeLayerRenderer)
	{
		mOriginNodeLayerRenderer = mCurrentNodeLayer->renderer()->clone();
	}

	SelectionBuffer buffer;
	buffer.geometry = mCurrentSelectionGeometry;
	buffer.radius = mCurrentSelectionRadius;
	buffer.graph = graph;
	// 如果没有选择任何要素，则可以跳过
	if (mCurrentNodeLayer->selectedFeatureCount() || 
		mCurrentEdgeLayer->selectedFeatureCount())
	{
		mSelectionBuffer.append(buffer);
	}
	else {
		return;
	}

	QgsFields fields = mCurrentNodeLayer->fields();
	if (!fields.names().contains(NODE_RADIUS))
	{
		QgsField field(NODE_RADIUS, QVariant::Double);
		mCurrentNodeLayer->dataProvider()->addAttributes(QList<QgsField>() << field);
	}
	if (!fields.names().contains(NODE_X))
	{
		QgsField field(NODE_X, QVariant::Double);
		mCurrentNodeLayer->dataProvider()->addAttributes(QList<QgsField>() << field);
	}
	if (!fields.names().contains(NODE_Y))
	{
		QgsField field(NODE_Y, QVariant::Double);
		mCurrentNodeLayer->dataProvider()->addAttributes(QList<QgsField>() << field);
	}
	if (!fields.names().contains(SELECTION_INDEX))
	{
		QgsField field(SELECTION_INDEX, QVariant::Int);
		mCurrentNodeLayer->dataProvider()->addAttributes(QList<QgsField>() << field);
	}
	if (!fields.names().contains(LABEL_DX))
	{
		QgsField field(LABEL_DX, QVariant::Double);
		mCurrentNodeLayer->dataProvider()->addAttributes(QList<QgsField>() << field);
	}
	if (!fields.names().contains(LABEL_DY))
	{
		QgsField field(LABEL_DY, QVariant::Double);
		mCurrentNodeLayer->dataProvider()->addAttributes(QList<QgsField>() << field);
	}
	if (!fields.names().contains(LABEL_ANGLE))
	{
		QgsField field(LABEL_ANGLE, QVariant::String); // 角度由于要用于唯一值分类，尽量以字符串（2位小数）
		mCurrentNodeLayer->dataProvider()->addAttributes(QList<QgsField>() << field);
	}

	// 先处理轮毂线
	hub();

	// 生成圆形布局
	layout();

	// 更新连边位置
	update();

	// 再次进行轮毂线处理
	reHub();

	render();
}

void GgsLwoInteraction::hub()
{
	// 记录选区节点集合，便于后续处理
	int iCurrent = this->indexOfCurrentSelectionBuffer();
	QgsFeatureList f_nodes = mCurrentNodeLayer->selectedFeatures();
	for each (QgsFeature fn in f_nodes)
	{
		GgsNodeProxy* nodeProxy = mCurrentNodeLayerProxy->findNode(fn.id());
		if (mSelectedNodes.contains(iCurrent))
		{
			mSelectedNodes[iCurrent].append(nodeProxy);
		}
		else {
			mSelectedNodes.insert(iCurrent, QList<GgsNodeProxy*>() << nodeProxy);
		}
	}

	// 选区连边关系判别，并进行hub操作
	mCurrentEdgeLayer->startEditing();
	QgsFeatureList f_edges = mCurrentEdgeLayer->selectedFeatures();
	for each (QgsFeature f in f_edges)
	{
		GgsEdgeProxy* edgeProxy = mCurrentEgdeLayerProxy->findEdge(f.id());

		bool bFromInSelection = mSelectedNodes[iCurrent].contains(edgeProxy->fromNode());
		bool bToInSelection = mSelectedNodes[iCurrent].contains(edgeProxy->toNode());
		
		// 先处理CROSS的情况，其它情况需要等选区内节点位置布局后再进行处理
		if (!bFromInSelection &&
			!bToInSelection)
		{
			// 获取连边和圈选区域的交点
			QgsGeometry interGeom = f.geometry().intersection(mCurrentSelectionGeometry);
			QgsVertexIterator iter = interGeom.vertices();

			QgsMultiPointXY ptXYs;
			while (iter.hasNext())
			{
				ptXYs << iter.next();
			}
			
			if (ptXYs.size() >= 2)
			{
				QgsGeometry g = f.geometry();		

				interpolateForCross(ptXYs.first(), ptXYs.last(), mCurrentSelectionCenter, mCurrentSelectionRadius, g);
				mCurrentEdgeLayer->changeGeometry(f.id(), g);
			}
		}
	}
	mCurrentEdgeLayer->commitChanges();
}

void GgsLwoInteraction::interpolateForCross(QgsPointXY p1, QgsPointXY p2, QgsPointXY center, double radius, QgsGeometry& origin)
{
	QgsPointSequence ret;

	QgsCircularString cs = QgsCircularString::fromTwoPointsAndCenter(QgsPoint(p1), QgsPoint(p2), QgsPoint(center));
	QgsLineString* ls = cs.curveToLine(M_PI_2 / 90 * mTolerance);

	if (ls->numPoints() >= 5)
	{
		// 获取离交点1最近的连边上的控制点
		int atVertex_1 = 0, afterVertex_1 = 0;
		betweenVertices(ls->startPoint(), origin, atVertex_1, afterVertex_1);
		
		// 求起始节点与交点1连线的分割点
		QgsPoint start_1 = origin.vertexAt(atVertex_1);
		double dist_1 = start_1.distance(ls->startPoint());
		QgsPoint c2_1 = ls->pointN(1);
		QgsPoint c1_1 = QgsGeometryUtils::pointOnLineWithDistance(c2_1, start_1, dist_1*0.45);
		QgsPoint end_1 = ls->pointN(2);
		QgsLineString* beizier_1 = QgsLineString::fromBezierCurve(start_1, c1_1, c2_1, end_1, 60);
		QgsPointSequence part1;
		
		beizier_1->points(part1);

		// 获取离交点2最近的连边上的控制点
		int n = ls->numPoints();
		int atVertex_2 = 0, afterVertex_2 = 0;
		betweenVertices(ls->endPoint(), origin, atVertex_2, afterVertex_2);

		// 求交点2与终止节点的分割点
		QgsPoint start_2 = QgsPoint(ls->pointN(n - 3));
		QgsPoint c1_2 = QgsPoint(ls->pointN(n - 2));
		QgsPoint end_2 = origin.vertexAt(afterVertex_2);
		double dist_2 = end_2.distance(ls->endPoint());
		QgsPoint c2_2 = QgsGeometryUtils::pointOnLineWithDistance(ls->endPoint(), end_2, dist_2*0.45);
		QgsLineString* beizier_2 = QgsLineString::fromBezierCurve(start_2, c1_2, c2_2, end_2, 60);
		QgsPointSequence part2;
		beizier_2->points(part2);

		QgsPointSequence middle;

		for (int i = 3; i< ls->numPoints() - 3; i++)
		{
			middle.append(ls->pointN(i));
		}

		ret.append(part1);
		ret.append(middle);
		ret.append(part2);

		int from = afterVertex_1, to = atVertex_2;
		for (int i = from; i <= to; i++)
			origin.deleteVertex(from);
		
		ret.removeFirst();
		ret.removeLast();

		delete beizier_1;
		beizier_1 = nullptr;
		delete beizier_2;
		beizier_2 = nullptr;
	}
	else {
		ls->points(ret);
	}

	int atVertex = 0, afterVertex = 0;
	betweenVertices(ret.first(), origin, atVertex, afterVertex);

	for each (QgsPointXY pt in ret)
	{
		origin.insertVertex(QgsPoint(pt), ++atVertex);
	}

	delete ls;
	ls = nullptr;
}

void GgsLwoInteraction::betweenVertices(const QgsPointXY& pt, QgsGeometry geom, int& first, int& second)
{
	QgsPointXY minDistPt;
	geom.closestSegmentWithContext(pt, minDistPt, second);
	first = second - 1;

	/*QgsPolylineXY pl = geom.asPolyline();

	for (int i = 0; i < pl.size() - 1; i++)
	{
		first = i;
		second = i + 1;

		QgsPolylineXY xy;
		xy.append(pl[first]);
		xy.append(pl[second]);

		QgsGeometry geom = QgsGeometry::fromPolylineXY(xy);

		if(geom.boundingBox().contains(pt))
			return;
	}
	first = second = -1;*/
}

void GgsLwoInteraction::layout()
{
	int iCurrent = this->indexOfCurrentSelectionBuffer();
	QList<GgsNodeProxy*> nodeList = mSelectedNodes[iCurrent];

	// 按照度对节点进行排序
	qSort(nodeList.begin(), nodeList.end(), GgsNodeProxy::compareDegree);

	double rad = 0, x = 0, y = 0, new_x = 0, new_y = 0, label_x = 0, label_y = 0;
	int N = nodeList.size();
	int i = 0;
	mCurrentNodeLayer->startEditing();
	for each (GgsNodeProxy* node in nodeList)
	{
		mCurrentNodeLayer->changeAttributeValue(node->feature().id(), mCurrentNodeLayer->fields().indexOf(SELECTION_INDEX), QVariant(indexOfCurrentSelectionBuffer()));

		rad = 2.0 * M_PI / N;

		QString szAngle = QString::number(360 - i * rad * 180.0 / M_PI, 'f', 2);
		mCurrentNodeLayer->changeAttributeValue(node->feature().id(), mCurrentNodeLayer->fields().indexOf(LABEL_ANGLE), QVariant(szAngle));

		QgsPointXY pt = node->feature().geometry().asPoint();
		x = mCurrentSelectionCenter.x() + mCurrentSelectionRadius * cos(i * rad);
		y = mCurrentSelectionCenter.y() + mCurrentSelectionRadius * sin(i * rad);

		QgsGeometry geom = QgsGeometry::fromPointXY(QgsPointXY(x, y));
		mCurrentNodeLayer->changeGeometry(node->feature().id(), geom);

		new_x = x - mNodeRadius * cos(i * rad);
		new_y = y - mNodeRadius * sin(i * rad);
		
		mCurrentNodeLayer->changeAttributeValue(node->feature().id(), mCurrentNodeLayer->fields().indexOf(NODE_RADIUS), QVariant(mNodeRadius));
		mCurrentNodeLayer->changeAttributeValue(node->feature().id(), mCurrentNodeLayer->fields().indexOf(NODE_X), QVariant(new_x));
		mCurrentNodeLayer->changeAttributeValue(node->feature().id(), mCurrentNodeLayer->fields().indexOf(NODE_Y), QVariant(new_y));

		label_x = mLabelSpan * cos(i * rad);
		label_y = mLabelSpan * sin(i * rad);

		mCurrentNodeLayer->changeAttributeValue(node->feature().id(), mCurrentNodeLayer->fields().indexOf(LABEL_DX), QVariant(label_x));
		mCurrentNodeLayer->changeAttributeValue(node->feature().id(), mCurrentNodeLayer->fields().indexOf(LABEL_DY), QVariant(label_y));
		i++;
	}
	mCurrentNodeLayer->commitChanges();
}

void GgsLwoInteraction::update()
{
	int iCurrent = this->indexOfCurrentSelectionBuffer();
	QList<GgsNodeProxy*> nodeList = mSelectedNodes[iCurrent];

	mCurrentEdgeLayer->startEditing();
	for each (GgsNodeProxy* node in nodeList)
	{
		ogdf::List<ogdf::edge> edgeList;
		node->node()->adjEdges(edgeList);

		for each (ogdf::edge e in edgeList)
		{
			GgsEdgeProxy* edgeProxy = mCurrentEgdeLayerProxy->findEgde(e);
			if (!edgeProxy)
			{
				continue;
			}
			
			QgsFeature from = edgeProxy->fromNode()->feature(mCurrentNodeLayer);
			QgsFeature to = edgeProxy->toNode()->feature(mCurrentNodeLayer);

			QgsPointXY newFrom = from.geometry().asPoint();
			QgsPointXY newTo = to.geometry().asPoint();

			QgsFeature f = edgeProxy->feature(mCurrentEdgeLayer);
			QgsPolylineXY pl = f.geometry().asPolyline();

			bool bFromInCircle = nodeList.contains(edgeProxy->fromNode()),
				 bToInCircle = nodeList.contains(edgeProxy->toNode());
			
			QgsPolylineXY newPolyline;
			int atVertex = 0, afterVertex = 0;
			if (bFromInCircle && bToInCircle) {
				newPolyline << newFrom << newTo;
			}
			else if (bFromInCircle && !bToInCircle) {
				QgsGeometry interesects = f.geometry().intersection(mCurrentSelectionGeometry);
				QgsVertexIterator iter = interesects.vertices();
				QgsPolylineXY intersects_points;
				while (iter.hasNext())
				{
					intersects_points << iter.next();
				}
				if (intersects_points.size() >= 1)
				{
					newPolyline << newFrom;
					betweenVertices(intersects_points.last(), f.geometry(), atVertex, afterVertex);
					for (int i = afterVertex; i < pl.size() - 1; i++)
					{
						newPolyline << pl.at(i);
					}
				}
			}else if (!bFromInCircle && bToInCircle){
				QgsGeometry interesects = f.geometry().intersection(mCurrentSelectionGeometry);
				QgsVertexIterator iter = interesects.vertices();
				QgsPolylineXY intersects_points;
				while (iter.hasNext())
				{
					intersects_points << iter.next();
				}

				if (intersects_points.size() >= 1)
				{
					betweenVertices(intersects_points.first(), f.geometry(), atVertex, afterVertex);
					for (int i = 0; i <= atVertex; i++ )
					{
						newPolyline << pl.at(i);
					}
					newPolyline << newTo;
				}
			}

			QgsGeometry g = QgsGeometry::fromPolylineXY(newPolyline);

			mCurrentEdgeLayer->changeGeometry(f.id(), g);
		}
	}
	mCurrentEdgeLayer->commitChanges();
}

void GgsLwoInteraction::reHub()
{
	// 只存在两种情况：（1）两个节点均在圆形布局上（也就是均被选中），此类情况不需要再进行reHub；
	// （2）某个节点在圆形布局上，另一个在圆形布局外
	int iCurrent = this->indexOfCurrentSelectionBuffer();
	QList<GgsNodeProxy*> nodeList = mSelectedNodes[iCurrent];

	mCurrentEdgeLayer->startEditing();
	for each (GgsNodeProxy* nodeProxy in nodeList)
	{
		ogdf::List<ogdf::edge> edgeList;
		nodeProxy->node()->adjEdges(edgeList);

		for each (ogdf::edge e in edgeList)
		{
			GgsEdgeProxy* edgeProxy = mCurrentEgdeLayerProxy->findEgde(e);
			if (!edgeProxy)
			{
				continue;
			}

			// 判断邻接连边的节点被选中的情况（至少有一个是选区内的节点）
			bool fromOnCircle = nodeList.contains(edgeProxy->fromNode());
			bool toOnCircle = nodeList.contains(edgeProxy->toNode());
			if (fromOnCircle && toOnCircle) // 如果两个节点均在圆上，则跳过
			{
				continue;
			}
			else {
				// 布局后的节点位置有变动，由于选区是圆形，且节点是布局在圆周上的，计算误差有可能会导致
				// 某些在圆周上的节点通过intersection函数判断时交点个数有问题。
				// 可以通过圆心、起始节点、终止节点之间的夹角来判断线和圆的关系。
				QgsFeature fromFeature = edgeProxy->fromNode()->feature(mCurrentNodeLayer);
				QgsFeature toFeature = edgeProxy->toNode()->feature(mCurrentNodeLayer);
				QgsPointXY fromPt = fromFeature.geometry().asPoint();
				QgsPointXY toPt = toFeature.geometry().asPoint();

				QgsFeature f = edgeProxy->feature(mCurrentEdgeLayer);
				QgsGeometry g = f.geometry();

				QgsGeometry interesects = g.intersection(mCurrentSelectionGeometry);
				QgsVertexIterator iter = interesects.vertices();
				QgsPolylineXY intersects_points;
				while (iter.hasNext())
				{
					intersects_points << iter.next();
				}
								
				bool bCross = false;
				double angle = 0.0;
				if (fromOnCircle)
				{
					QgsPointXY tmp = intersects_points.size() > 0 ? intersects_points.last() : toPt;
					angle = QgsGeometryUtils::angleBetweenThreePoints(
						mCurrentSelectionCenter.x(), mCurrentSelectionCenter.y(),
						fromPt.x(), fromPt.y(),
						tmp.x(), tmp.y()
					);
				}
				else if (toOnCircle) 
				{
					QgsPointXY tmp = intersects_points.size() > 0 ? intersects_points.first() : fromPt;
					angle = QgsGeometryUtils::angleBetweenThreePoints(
						mCurrentSelectionCenter.x(), mCurrentSelectionCenter.y(),
						toPt.x(), toPt.y(),
						tmp.x(), tmp.y()
					);
				}

				if (angle > M_PI)
				{
					angle = 2 * M_PI - angle;
				}

				if (angle < M_PI / 2.0 )
				{
					bCross = true;
				}

				if (bCross) // 这里要注意，即使是CROSS，也可能仅有一个交点
				{
					
					QgsGeometry interGeom = g.intersection(mCurrentSelectionGeometry);
					QgsVertexIterator iter = interGeom.vertices();

					QgsMultiPointXY ptXYs;
					while (iter.hasNext())
					{
						QgsPoint pt = iter.next();
						ptXYs.append(QgsPointXY(pt.x(), pt.y()));
					}

					if (ptXYs.size() == 1)
					{
						int atVertex = 0, afterVertex = 0;
						if (fromOnCircle)
						{
							betweenVertices(ptXYs.first(), mCurrentSelectionGeometry, atVertex, afterVertex);
							ptXYs.push_front(g.vertexAt(atVertex));
						}
						else if (toOnCircle)
						{
							betweenVertices(ptXYs.last(), mCurrentSelectionGeometry, atVertex, afterVertex);
							ptXYs.push_back(g.vertexAt(afterVertex));
						}
					}
					
					if (ptXYs.size())
					{
						interpolateForCross(ptXYs.first(), ptXYs.last(), mCurrentSelectionCenter, mCurrentSelectionRadius, g);
						mCurrentEdgeLayer->changeGeometry(f.id(), g);
					}
				}

				// 处理连边CROSS其他选区的情况
				for (int i = 0; i < mSelectionBuffer.size() - 1; i++)
				{
					SelectionBuffer buf = mSelectionBuffer[i];
					if (buf.geometry.intersects(g))
					{
						QgsGeometry intersections = buf.geometry.intersection(g);
						QgsVertexIterator iter = intersections.vertices();

						QgsMultiPointXY ptXYs;
						while (iter.hasNext())
						{
							QgsPoint pt = iter.next();
							ptXYs.append(pt);
						}

						if (ptXYs.size() >= 2)
						{
							QgsPointXY otherCenter = buf.geometry.centroid().asPoint();
							double otherRadius = buf.radius;

							interpolateForCross(ptXYs[0], ptXYs[ptXYs.size() - 1], otherCenter, otherRadius, g);
							mCurrentEdgeLayer->changeGeometry(f.id(), g);
						}
					}
				}
			}
		}
	}
	mCurrentEdgeLayer->commitChanges();
}

void GgsLwoInteraction::render()
{
	int iCurrent = this->indexOfCurrentSelectionBuffer();
	QList<GgsNodeProxy*> nodeList = mSelectedNodes[iCurrent];

	mCurrentNodeLayer->startEditing();
	for each (GgsNodeProxy* nodeProxy in nodeList)
	{
		QgsFeature nodeFeature = nodeProxy->feature(mCurrentNodeLayer);
		double node_x = nodeFeature.attribute(NODE_X).toDouble();
		double node_y = nodeFeature.attribute(NODE_Y).toDouble();
		QgsGeometry g = QgsGeometry::fromPointXY(QgsPointXY(node_x, node_y));
		mCurrentNodeLayer->changeGeometry(nodeFeature.id(), g);
	}
	mCurrentNodeLayer->commitChanges();

	mCurrentEdgeLayer->startEditing();
	for each (GgsNodeProxy* nodeProxy in nodeList)
	{
		ogdf::List<ogdf::edge> edgeList;
		nodeProxy->node()->adjEdges(edgeList);

		for each (ogdf::edge e in edgeList)
		{
			GgsEdgeProxy* edgeProxy = mCurrentEgdeLayerProxy->findEgde(e);
			if (!edgeProxy)
			{
				continue;
			}

			// 如果两个节点均在圆上，则更新OFFSET位置
			bool fromOnCircle = nodeList.contains(edgeProxy->fromNode());
			bool toOnCircle = nodeList.contains(edgeProxy->toNode());
			if (fromOnCircle && toOnCircle)
			{
				QgsFeature edgeFeature = edgeProxy->feature(mCurrentEdgeLayer);
				QgsPolylineXY pl = edgeFeature.geometry().asPolyline();
				pl[0] = edgeProxy->fromNode()->feature(mCurrentNodeLayer).geometry().asPoint();
				pl[pl.size() - 1] = edgeProxy->toNode()->feature(mCurrentNodeLayer).geometry().asPoint();
				QgsGeometry g = QgsGeometry::fromPolylineXY(pl);
				mCurrentEdgeLayer->changeGeometry(edgeFeature.id(), g);
			}
		}
	}
	mCurrentEdgeLayer->commitChanges();

	renderSymbols();

	mCurrentNodeLayer->removeSelection();
	mCurrentEdgeLayer->removeSelection();	
}


void GgsLwoInteraction::renderSymbols(bool updateLabel)
{
	if (!mCurrentNodeLayer)
	{
		return;
	}

	// 进行节点渲染处理
	int fieldIndex_radius = mCurrentNodeLayer->fields().indexOf(NODE_RADIUS);
	QSet<QVariant> set_radius = mCurrentNodeLayer->uniqueValues(fieldIndex_radius);
	QVariantList list_radius = set_radius.toList();

	QgsCategoryList cats_radius = QgsCategorizedSymbolRenderer::createCategories(list_radius,
		QgsSymbol::defaultSymbol(mCurrentNodeLayer->geometryType()), mCurrentNodeLayer, NODE_RADIUS);

	for (auto iter = cats_radius.begin(); iter != cats_radius.end(); ++iter) {

		QgsSimpleMarkerSymbolLayer* symLayer = new QgsSimpleMarkerSymbolLayer(QgsSimpleMarkerSymbolLayerBase::Shape::Circle);

		if (!(*iter).value().isNull())
		{
			symLayer->setSize(mNodeRadius * mNodeRatio);
			symLayer->setFillColor(mCircleNodeFillColor);
			symLayer->setStrokeColor(mCircleNodeStrokeColor);
		}
		else {
			symLayer->setSize(mNodeRadius);
			symLayer->setFillColor(mNodeFillColor);
			symLayer->setStrokeColor(mNodeStrokeColor);
		}

		symLayer->setSizeUnit(QgsUnitTypes::RenderMapUnits);
		iter->symbol()->changeSymbolLayer(0, symLayer);
	}

	std::unique_ptr<QgsCategorizedSymbolRenderer> renderer = qgis::make_unique<QgsCategorizedSymbolRenderer>(NODE_RADIUS, cats_radius);
	mCurrentNodeLayer->setRenderer(renderer->clone());


	// 设置文字标注
	QString label = mLabel.isNull() ? LABEL_ANGLE : mLabel;
	QgsRuleBasedLabeling* ruleLable = dynamic_cast<QgsRuleBasedLabeling*>(mCurrentNodeLayer->labeling());
	QgsRuleBasedLabeling::Rule* rootRule = ruleLable ? ruleLable->rootRule() : new QgsRuleBasedLabeling::Rule(nullptr);

	if (rootRule && updateLabel)
	{
		int iCount= rootRule->children().size();
		for (int i=iCount - 1; i>=0; i--)
		{
			rootRule->removeChildAt(i);
		}
	}

	QList<int> selections_keys = mSelectedNodes.keys();
	for each (int key in selections_keys)
	{
		for each (GgsNodeProxy* node in mSelectedNodes[key])
		{
			SelectionBuffer buffer = mSelectionBuffer[key];
			QgsFeature feature = node->feature(buffer.graph->nodeLayerProxy()->nodeLayer());

			QVariant angle = feature.attribute(label);
			QString label_angle = feature.attribute(label).toString();
			QString angleOffset = feature.attribute(LABEL_ANGLE).toString();
			double xOffset = mLabelSpan * cos(feature.attribute(LABEL_ANGLE).toDouble() * M_PI / 180.0 );
			double yOffset = mLabelSpan * sin(feature.attribute(LABEL_ANGLE).toDouble() * M_PI / 180.0);

			QgsPalLayerSettings* layerSettings = new QgsPalLayerSettings;
			layerSettings->fieldName = label;
			layerSettings->placement = QgsPalLayerSettings::Placement::OverPoint;
			layerSettings->angleOffset = angleOffset.toDouble();
			layerSettings->xOffset = xOffset;
			layerSettings->yOffset = yOffset;
			layerSettings->distUnits = QgsUnitTypes::RenderMapUnits;

			QgsTextFormat textFormat;
			textFormat.setColor(QColor(0, 0, 0));
			//textFormat.setFont("");

			QgsTextBufferSettings bufferSettings;
			bufferSettings.setEnabled(true);
			bufferSettings.setColor(QColor(255, 255, 255));
			bufferSettings.setSize(1);
			bufferSettings.setOpacity(1.0);
			textFormat.setBuffer(bufferSettings);
			layerSettings->setFormat(textFormat);

			QgsRuleBasedLabeling::Rule* rule = new QgsRuleBasedLabeling::Rule(layerSettings);
			QString szExpression = QString("\"%1\" = %2 AND \"%3\" = %4")
				.arg(SELECTION_INDEX)
				.arg(key)
				.arg(LABEL_ANGLE)
				.arg(angleOffset);
			rule->setFilterExpression(szExpression);
			rule->setDescription(szExpression);
			rule->setRuleKey(szExpression);
			rule->setSettings(layerSettings);

			if (!rootRule->findRuleByKey(szExpression))
			{
				rootRule->appendChild(rule);
			}
		}
	}

	if (!ruleLable)
	{
		ruleLable = new QgsRuleBasedLabeling(rootRule);
	}
	
	mCurrentNodeLayer->setLabelsEnabled(true);
	mCurrentNodeLayer->setLabeling(ruleLable);
	mCurrentNodeLayer->triggerRepaint();
}

int GgsLwoInteraction::indexOfCurrentSelectionBuffer()
{
	return mSelectionBuffer.size() - 1;
}

