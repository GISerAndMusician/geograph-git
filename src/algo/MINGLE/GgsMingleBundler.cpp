#include "GgsMingleBundler.h"
#include "GgsMingleMathUtils.h"
#include <QPainterPath>
#include "GgsBezierCurve.h"
#include "qgsfeature.h"

#include "GgsApp.h"

GgsMingleBundler::GgsMingleBundler()
{

}

GgsMingleBundler::~GgsMingleBundler()
{

}

void GgsMingleBundler::setNodes(QList<GgsMingleNode*> nodes)
{
	mGraph->empty();

	for each (GgsMingleNode* n in nodes)
	{
		mGraph->addNode(n);
	}
}

void GgsMingleBundler::buildKdTree()
{
	std::vector<Point4D<double>> pts;
	int index = 0;
	for each (GgsMingleNode* n in mGraph->nodes())
	{
		Point4D<double> pt;
		pt.x = n->getCoordSource().x();
		pt.y = n->getCoordSource().y();
		pt.z = n->getCoordTarget().x();
		pt.w = n->getCoordTarget().y();
		pt.index = index;
		pts.push_back(pt);

		// 存储MINGLENode在KDTree中的索引号
		mKDTreeIndexes.insert(index, n);
		index++;
	}

	mKDTree = new GgsMingleKdTree<Point4D<double>>(pts, 4);
}

void GgsMingleBundler::buildNearestNeighborGraph(int k)
{
	buildKdTree();
	for each (GgsMingleNode* n in mGraph->nodes())
	{
		Point4D<double> pt;
		pt.x = n->getCoordSource().x();
		pt.y = n->getCoordSource().y();
		pt.z = n->getCoordTarget().x();
		pt.w = n->getCoordTarget().y();

		std::vector<int> indexes = mKDTree->findNearestKPoints(pt, k);
		QList<GgsMingleNode*> nodes = getNodesByKDTreeIndexes(indexes);
		for (int i = 0, j = nodes.size(); i < j; ++i)
		{
			if (nodes[i]->getId() != n->getId())
			{
				mGraph->addEdge(n, nodes[i]);
			}
		}

	}
}

QList<GgsMingleNode*> GgsMingleBundler::getNodesByKDTreeIndexes(std::vector<int> indexes)
{
	QList<GgsMingleNode*> nodes;
	std::vector<int>::iterator iter = indexes.begin();
	while (iter != indexes.end())
	{
		nodes.append(mKDTreeIndexes[(*iter)]);
		iter++;
	}

	return nodes;
}

void GgsMingleBundler::mingle()
{
	int iter = 1;

	GgsMingleGraph* pGraph = this->mGraph;
	int totalGain = 0;
	int ungrouped = -1;
	double gain = 0;
	int k = 0;

	do {
		gain = 0;
		k = 0;
		int current = 0;

// 		// 调试使用
// 		QList<MINGLENode*> sorted = mGraph->nodes();
// 		std::sort(sorted.begin(), sorted.end(), [](MINGLENode* a, MINGLENode* b)
// 		{ return a->getId().toInt() < b->getId().toInt(); });
// 		// ！调试使用

		for each (GgsMingleNode* node in mGraph->nodes())
		{
			node->setGroup(ungrouped);
		}

		for each (GgsMingleNode* node in  mGraph->nodes())
		{
			if (node->getGroup() == ungrouped)
			{
				InkSavingNeighbor ans = getMaximumInkSavingNeighbor(node);
				QList<GgsMingleNode*> bundle = ans.bundle;
				GgsMingleNode* u = bundle[0] ? bundle[0] : nullptr ;
				GgsMingleNode* v = bundle[1] ? bundle[1] : nullptr;
				GgsMingleNode* combined = ans.combined;
				double gainUV = -ans.inkTotal;

				//graph has been collapsed and is now only one node
				if (!u && !v)
				{
					gain = -std::numeric_limits<double>::infinity();
					continue;
				}

				if (gainUV > 0)
				{
					this->bundle(combined, u, v);
					gain += gainUV;
					if (v->getGroup() != ungrouped)
					{
						u->setGroup(v->getGroup());
					}
					else
					{
						v->setGroup(k);
						u->setGroup(k);
					}
				}
				else
				{
					u->setGroup(k);
				}
				k++;
			}

			current++;

			emit progressChanged(iter, current, mGraph->nodes().size());
		}

		coalesceGraph();
		totalGain += gain;
		iter++;

	} while (gain > 0);
}

void GgsMingleBundler::render(GgsMingleRenderContext ctx, QgsVectorLayer* pLayer)
{	
	mRenderContext = ctx;
	QgsFeatureList features;
	int iColorIndex = 0;
	for each (GgsMingleNode* node in mGraph->nodes())
	{
		// 处理渲染色彩信息
		for each (GgsMingleNode* tmp in node->nodeArray())
		{
			tmp->setClusterIndex(iColorIndex);
		}
		iColorIndex++;

		QList<QList<GgsMingleNode::PositionItem>> edges = node->unbundleEdges(ctx);
		switch (ctx.getLineType())
		{
		case GgsMingleRenderContext::LINE:
			renderLine(edges, pLayer);
			break;
		case GgsMingleRenderContext::BEZIER:
			renderBezier(edges, pLayer);
			break;
		case GgsMingleRenderContext::QUADRATIC:
			renderQuadratic(edges, pLayer);
		}
	}
}

GgsMingleBundler::InkSavingNeighbor GgsMingleBundler::getMaximumInkSavingNeighbor(GgsMingleNode* n)
{
	GgsMingleNode* nodeFrom = n;
	double inkFrom = getInkValue(n);
	nodeFrom->setInk(inkFrom);
	double inkTotal = std::numeric_limits<double>::infinity();
	GgsMingleNode* bundle[2] = {nullptr, nullptr};
	GgsMingleNode* combinedBundle = nullptr;

	QMap<QString, GgsMingleEdge*> adj = n->adjacencies();
// 	// 调试使用
// 	QList<QString> sorted = adj.keys();
// 	std::sort(sorted.begin(), sorted.end(), [](QString& a, QString& b)
// 	{ return a.toInt() < b.toInt(); });
// 	// !调试使用
	for each (QString id in adj.keys())
	{
		GgsMingleEdge* a = adj[id];

		if (a->fromNode() != n)
		{
			GgsMingleNode* tmp = a->fromNode();
			a->setFromNode(a->toNode());
			a->setToNode(tmp);
		}

		GgsMingleNode* nodeTo = adj[id]->toNode();
		double inkTo = getInkValue(nodeTo);
		nodeTo->setInk(inkTo);
		GgsMingleNode* combined = getCombinedNode(nodeFrom, nodeTo);
		double inkUnion = getInkValue(combined);
		double inkValue = inkUnion - (inkFrom + inkTo);

		if (inkTotal > inkValue)
		{
			inkTotal = inkValue;
			bundle[0] = nodeFrom;
			bundle[1] = nodeTo;
			combinedBundle = combined;
		}
	}

	InkSavingNeighbor sv;
	sv.bundle = QList<GgsMingleNode*>() << bundle[0] << bundle[1];
	sv.inkTotal = inkTotal;
	sv.combined = combinedBundle;
	return sv;
}

double GgsMingleBundler::getInkValue(GgsMingleNode* n, int depth)
{
	QgsPointXY m1, m2;
	double acum;
	double diffX = 0, diffY = 0;
	QList<GgsMingleNode*> nodes;

	// bundle node
	if (!depth && (n->getBundle() || n->nodes().size()))
	{
		nodes = n->getBundle() ? n->getBundle()->nodes() : n->nodes();
		m1 = n->m1;
		m2 = n->m2;
		acum = 0;
		for (int i = 0, L = nodes.size(); i < L; ++i)
		{
			double normIpt[2] = { diffX, diffY };
			GgsMingleNode* ni;
			ni = nodes[i];
			diffX = m1.x() - ni->getCoordSource().x();
			diffY = m1.y() - ni->getCoordSource().y();
			normIpt[0] = diffX;
			normIpt[1] = diffY;
			acum += MINGLE::norm(normIpt);
			diffX = m2.x() - ni->getCoordTarget().x();
			diffY = m2.y() - ni->getCoordTarget().y();
			normIpt[0] = diffX;
			normIpt[1] = diffY;
			acum += MINGLE::norm(normIpt);
			acum += getInkValue(ni, depth + 1);
		}

		if (!depth)
		{
			double a[2] = { m1.x(), m1.y() };
			double b[2] = { m2.x(), m2.y() };
			acum += MINGLE::dist(a, b);
		}

		n->setInk(acum);
		return n->getInk();
	}


	//coalesced node
	if (n->parents().size())
	{
		QList<GgsMingleNode*> nodes = n->parents();
		m1 = n->getCoordSource();
		m2 = n->getCoordTarget();
		acum = 0;
		for (int i = 0, L = nodes.length(); i < L; ++i)
		{
			double normIpt[2] = { diffX, diffY };

			GgsMingleNode* ni = nodes[i];
			double coords[4] = {
				ni->getCoordSource().x(),
				ni->getCoordSource().y(),
				ni->getCoordTarget().x(),
				ni->getCoordTarget().y()
			};
			diffX = m1.x() - ni->getCoordSource().x();
			diffY = m1.y() - ni->getCoordSource().y();
			normIpt[0] = diffX;
			normIpt[1] = diffY;
			acum += MINGLE::norm(normIpt);
			diffX = m2.x() - ni->getCoordTarget().x();
			diffY = m2.y() - ni->getCoordTarget().y();
			normIpt[0] = diffX;
			normIpt[1] = diffY;
			acum += MINGLE::norm(normIpt);
			acum += getInkValue(ni, depth + 1);
		}

		if (!depth)
		{
			double a[2] = { m1.x(), m1.y() };
			double b[2] = { m2.x(), m2.y() };
			acum += MINGLE::dist(a, b);
		}

		n->setInk(acum);
		return n->getInk();
	}

	//simple node
	if (depth)
	{
		n->setInk(0);
		return n->getInk();
	}

	diffX = n->getCoordSource().x() - n->getCoordTarget().x();
	diffY = n->getCoordSource().y() - n->getCoordTarget().y();

	double normIpt[2] = { diffX, diffY };
	n->setInk(MINGLE::norm(normIpt));

	return n->getInk();
}

GgsMingleNode* GgsMingleBundler::getCombinedNode(GgsMingleNode* from, GgsMingleNode* to)
{
	GgsMingleNode* node1 = from->getBundle() != nullptr ? from->getBundle() : from;
	GgsMingleNode* node2 = to->getBundle() != nullptr ? to->getBundle() : to;

	QString id = node1->getId() + "-" + node2->getId();
	QString name = node1->getName() + "-" + node2->getName();

	QList<GgsMingleNode*> nodes1 = node1->nodes().size() != 0 ? node1->nodes() : QList<GgsMingleNode*>() << node1;
	QList<GgsMingleNode*> nodes2 = node2->nodes().size() != 0 ? node2->nodes() : QList<GgsMingleNode*>() << node2;

	if (node1->getId() == node2->getId())
	{
		return node1;
	}

	QList<GgsMingleNode*> nodes;
	nodes.append(nodes1);
	nodes.append(nodes2);

	QList<GgsMingleNode*> nodeArray;
	nodeArray.append(node1->nodeArray());
	nodeArray.append(node2->nodeArray());

	GgsMingleNode* ans = new GgsMingleNode;
	ans->setId(id);
	ans->setName(name);
	ans->setNodes(nodes);
	ans->setNodeArray(nodeArray);
	ans->setWeight(node1->getWeight() + node2->getWeight());

	computeIntermediateNodePositions(ans);

	return ans;
}

void GgsMingleBundler::computeIntermediateNodePositions(GgsMingleNode* cb)
{
	if (!cb->nodes().size())
	{
		return;
	}

	QList<QgsPointXY> centroids = getCentroids(cb->nodes());
	double a = 0.0, b = 1.0, c = 0.72, tau = 0.1;
	double res = goldenSectionSearch(a, b, c, tau, cb, centroids);
	costFunction(cb, centroids, res);
}

QList<QgsPointXY> GgsMingleBundler::getCentroids(QList<GgsMingleNode*> nodes)
{
	QList<QgsPointXY> ret;

	double topCentroidX = 0, topCentroidY = 0, bottomCentroidX = 0, bottomCentroidY = 0;
	int L = nodes.size();
	for (int i = 0; i < L; ++i)
	{
		topCentroidX += nodes[i]->getCoordSource().x();
		topCentroidY += nodes[i]->getCoordSource().y();
		bottomCentroidX += nodes[i]->getCoordTarget().x();
		bottomCentroidY += nodes[i]->getCoordTarget().y();
	}
	topCentroidX /= L;
	topCentroidY /= L;
	bottomCentroidX /= L;
	bottomCentroidY /= L;

	ret.append(QgsPointXY(topCentroidX, topCentroidY));
	ret.append(QgsPointXY(bottomCentroidX, bottomCentroidY));

	return ret;
}

double GgsMingleBundler::goldenSectionSearch(double a, double b, double c, double tau, GgsMingleNode* node, QList<QgsPointXY> centoids)
{
	double phi = MINGLE::PHI(),
		resphi = 2 - MINGLE::PHI(),
		x;

	if (c - b > b - a)
	{
		x = b + resphi * (c - b);
	}
	else
	{
		x = b - resphi * (b - a);
	}

	if (abs(c - a) < tau * (abs(b) + abs(x)))
	{
		return (c + a) / 2;
	}

	if (costFunction(node, centoids, x) < costFunction(node, centoids, b))
	{
		if (c - b > b - a)
		{
			return this->goldenSectionSearch(b, x, c, tau, node, centoids);
		}
		return this->goldenSectionSearch(a, x, b, tau, node, centoids);
	}

	if (c - b > b - a)
	{
		return this->goldenSectionSearch(a, b, x, tau, node, centoids);
	}
	return this->goldenSectionSearch(x, b, c, tau, node, centoids);
}

double GgsMingleBundler::costFunction(GgsMingleNode* node, QList<QgsPointXY> centoids, double x)
{
	double ink, aplpha, p;
	QgsPointXY m1, m2, top, bottom;
	x /= 2;
	top = centoids[0];
	bottom = centoids[1];
	m1 = MINGLE::lerp(top, bottom, x);
	m2 = MINGLE::lerp(top, bottom, 1 - x);
	node->m1 = m1;
	node->m2 = m2;

	node->setInk(0);
	ink = getInkValue(node);
	aplpha = getMaxTurningAngleValue(node, m1, m2);

	p = mAngleStrength > 0 ? mAngleStrength : 1.2;
	return ink * (1 + sin(aplpha) / p);
}

double GgsMingleBundler::getMaxTurningAngleValue(GgsMingleNode* node, QgsPointXY m1, QgsPointXY m2)
{
	double norm, dot, angleValue, angle = 0;
	double m2ToM1[2] = { m1.x() - m2.x(), m1.y() - m2.y() };
	double m1ToM2[2] = { -m2ToM1[0], -m2ToM1[1] };
	double m1M2Norm = MINGLE::norm(m2ToM1);

	if (node->getBundle() || node->nodes().size())
	{
		QList<GgsMingleNode*> nodes = node->getBundle() ? node->getBundle()->nodes() : node->nodes();
		for (int i = 0, L = nodes.size(); i < L; ++i)
		{
			double vec[2] = {
				nodes[i]->getCoordSource().x() - m1.x(),
				nodes[i]->getCoordSource().y() - m1.y()
			};
			norm = MINGLE::norm(vec);
			dot = vec[0] * m2ToM1[0] + vec[1] * m2ToM1[1];
			angleValue = abs(acos(dot / norm / m1M2Norm));
			angle = angle < angleValue ? angleValue : angle;

			vec[0] = nodes[i]->getCoordTarget().x() - m2.x();
			vec[1] = nodes[i]->getCoordTarget().y() - m2.y();

			norm = MINGLE::norm(vec);
			dot = vec[0] * m1ToM2[0] + vec[1] * m1ToM2[1];
			angleValue = abs(acos(dot / norm / m1M2Norm));
			angle = angle < angleValue ? angleValue : angle;
		}

		return angle;
	}

	return -1;
}

void GgsMingleBundler::bundle(GgsMingleNode* combineNode, GgsMingleNode* node1, GgsMingleNode* node2)
{
	node1->setBundle(combineNode);
	node2->setBundle(combineNode);

	node1->setInk(combineNode->getInk());
	node1->m1 = combineNode->m1;
	node1->m2 = combineNode->m2;

	node2->setInk(combineNode->getInk());
	node2->m1 = combineNode->m1;
	node2->m2 = combineNode->m2;
}

void GgsMingleBundler::coalesceGraph()
{
	QMap<int, QMap<QString, GgsMingleNode*>> groupsIds;
	int maxGroup = -std::numeric_limits<double>::infinity();

// 	// 调试使用
// 	QList<MINGLENode*> sorted = mGraph->nodes();
// 	std::sort(sorted.begin(), sorted.end(), [](MINGLENode* a, MINGLENode* b)
// 	{ return a->getId().toInt() < b->getId().toInt(); });
// 	// ！调试使用
	for each (GgsMingleNode* node in mGraph->nodes())
	{
		int group = node->getGroup();
		if (maxGroup < group)
		{
			maxGroup = group;
		}
		if (!groupsIds.contains(group))
		{
			groupsIds.insert(group, QMap<QString, GgsMingleNode*>());
		}
		groupsIds[group].insert(node->getId(), node);
	}
	maxGroup++;

	QList<QString> removedIds;
	while (maxGroup--)
	{
		QMap<QString, GgsMingleNode*> ids = groupsIds.contains(maxGroup) ? groupsIds[maxGroup] : QMap<QString, GgsMingleNode*>();
		QList<GgsMingleNode*> nodes;
		nodes.append(ids.values());
		if (ids.size())
		{
			GgsMingleNode* groupedNode = coalesceNodes(nodes);
			updateGraph(groupedNode, nodes, ids);
		}
	}
}

GgsMingleNode* GgsMingleBundler::coalesceNodes(QList<GgsMingleNode*> nodes)
{
	GgsMingleNode* node = nodes[0];
	QgsPointXY m1 = node->m1;
	QgsPointXY m2 = node->m2;
	QList<GgsMingleNode*> nodeArray;
	int weight = 0;
	for (int i = 0; i < nodes.size(); i++)
	{
		weight += nodes[i]->getWeight() ? nodes[i]->getWeight() : 0;
	}

	double coords[4];
	if (!m1.isEmpty())
	{
		coords[0] = m1.x();
		coords[1] = m1.y();
		coords[2] = m2.x();
		coords[3] = m2.y();

		for (int i = 0, L = nodes.size(); i < L; ++i)
		{
			QList<GgsMingleNode*> na = nodes[i]->nodeArray().size() > 0 ?
				nodes[i]->nodeArray() : nodes[i]->parents().size() > 0 ?
				QList<GgsMingleNode*>() : QList<GgsMingleNode*>() << nodes[i];

			nodeArray.append(na);
		}

		GgsMingleNode* pCombineNodes = new GgsMingleNode;
		pCombineNodes->setId(node->getBundle()->getId());
		pCombineNodes->setName(node->getBundle()->getName());
		pCombineNodes->setNodeArray(nodeArray);
		pCombineNodes->parents().append(nodes);
		pCombineNodes->setWeight(weight);
		pCombineNodes->setInk(node->getBundle()->getInk());
		pCombineNodes->setCoordSource(
			QgsPointXY(coords[0], coords[1])
		);
		pCombineNodes->setCoordTarget(
			QgsPointXY(coords[2], coords[3])
		);

		return pCombineNodes;
	}

	return nodes[0];
}

void GgsMingleBundler::updateGraph(GgsMingleNode* groupedNode, QList<GgsMingleNode*> nodes, QMap<QString, GgsMingleNode*> ids)
{
	QList<GgsMingleNode*> connections;

// 	// 调试代码
// 	QList<MINGLENode*> sortedNodes = nodes;
// 	std::sort(sortedNodes.begin(), sortedNodes.end(), [](MINGLENode* a, MINGLENode* b)
// 	{ return a->getId().toInt() < b->getId().toInt(); });
// 	// !调试代码
	for (int i = 0, L = nodes.size(); i < L; ++i)
	{
		connections.clear();
		GgsMingleNode* n = nodes[i];

		QMap<QString, GgsMingleEdge*> adj = n->adjacencies();
// 		// 调试代码
// 		QList<QString> sorted = adj.keys();
// 		std::sort(sorted.begin(), sorted.end(), [](QString& a, QString& b)
// 		{ return a.toInt() < b.toInt(); });
// 		// !调试代码
		for each (QString id in adj.keys())
		{
			GgsMingleEdge* a = adj[id];
			if (a->fromNode() != n)
			{
				GgsMingleNode* tmp = a->fromNode();
				a->setFromNode(a->toNode());
				a->setToNode(tmp);
			}

			QString nodeToId = a->toNode()->getId();
			if (!ids.contains(nodeToId) && !mRemovedIds.contains(nodeToId))
			{
				connections.append(a->toNode());
			}
		}
			
		// 需要过滤掉邻接表中的n记录
		for each (GgsMingleNode* tmp in mGraph->nodes())
		{
			if (tmp->adjacencies().contains(n->getId()))
			{
				tmp->adjacencies().remove(n->getId());
			}
		}

// 		for (int j = i + 1; j < L; ++j)
// 		{
// 			MINGLENode* tmp = nodes[j];
// 			if (tmp->adjacencies().contains(n->getId()))
// 			{
// 				tmp->adjacencies().remove(n->getId());
// 			}
// 		}

		if (!mRemovedIds.contains(n->getId()))
		{
			mRemovedIds.append(n->getId());
		}
		this->mGraph->removeNode(n->getId());
	}

	mGraph->addNode(groupedNode);

	for (int i = 0, L = connections.length(); i < L; ++i)
	{
		mGraph->addEdge(groupedNode, connections[i]);
	}
}

void GgsMingleBundler::renderLine(QList<QList<GgsMingleNode::PositionItem>> edges, QgsVectorLayer* pLayer)
{
	QgsFeatureList featureList;

	for (int i=0, L = edges.size(); i<L; ++i)
	{
		QList<GgsMingleNode::PositionItem> e = edges[i];
		QgsFeature f;
		f.setFields(pLayer->fields(), true);
		QgsPolylineXY plXY;

		for each (GgsMingleNode::PositionItem pt in e)
		{
			plXY << QgsPointXY(pt.unbundledPos[0], pt.unbundledPos[1]);
		}

		f.setGeometry(
			QgsGeometry::fromPolylineXY(plXY)
		);
		f.setAttribute(GgsMingleRenderContext::MINGLE_CLUSTER, e[0].node->getClusterIndex());
		f.setAttribute(GgsMingleRenderContext::MINGLE_EDGE, i);
		f.setAttribute(GgsMingleRenderContext::MINGLE_DIRECTION, rand() % 2);
		
		featureList << f;
	}

	QgsVectorDataProvider* provider = pLayer->dataProvider();
	provider->addFeatures(featureList);

	pLayer->commitChanges();
	pLayer->updateExtents();
}

void GgsMingleBundler::renderBezier(QList<QList<GgsMingleNode::PositionItem>> edges, QgsVectorLayer* pLayer)
{
	QgsFeatureList featureList;

	double pct = mRenderContext.getCurveness();

	for (int i=0, L = edges.size(); i<L; ++i)
	{
		QgsFeature feature;
		feature.setFields(pLayer->fields(), true);

		QList<GgsMingleNode::PositionItem> e = edges[i];
		double* start = e[0].unbundledPos;
		double* midpoint = e[(e.size() - 1) / 2].unbundledPos;

		QgsPolylineXY plXY;

		if (e.size() > 3)
		{
			// 如果启用松弛
			if (mRenderContext.isLooseEnabled())
			{
				QgsPointXY tmp = adjustPosition(e[0].node->getId(), e[(e.size() - 1) / 2], midpoint, mRenderContext.getMargin(), mRenderContext.getDelta());
				midpoint[0] = tmp.x();
				midpoint[1] = tmp.y();
			}

			QVector<GgsBezierCurve::Point> inputs1;
			inputs1 << GgsBezierCurve::Point(start[0], start[1], 0);

			// 前半段beizier
			double* c1 = e[1].unbundledPos;
			double* c2 = e[(e.size() - 1) / 2 - 1].unbundledPos;
			QgsPointXY end = MINGLE::lerp(
				QgsPointXY( midpoint[0], midpoint[1]), 
				QgsPointXY(c2[0], c2[1]), 1-pct);
			inputs1 << GgsBezierCurve::Point(c1[0], c1[1], 0);
			inputs1 << GgsBezierCurve::Point(c2[0], c2[1], 0);
			inputs1 << GgsBezierCurve::Point(end.x(), end.y(), 0);

			GgsBezierCurve preBeizier(inputs1);
			preBeizier.Calculate3(21); // 生成的控制点数量
			QVector<GgsBezierCurve::Point> preOutputs = preBeizier.GetOutputPoints();

			QVector<GgsBezierCurve::Point>::iterator iter_pts = preOutputs.begin();
			while (iter_pts != preOutputs.end())
			{
				plXY.append(
					QgsPointXY(
						(*iter_pts).x,
						(*iter_pts).y
					)
				);
				iter_pts++;
			}

			// 后半段beizier
			c1[0] = e[(e.size() - 1) / 2 + 1].unbundledPos[0];
			c1[1] = e[(e.size() - 1) / 2 + 1].unbundledPos[1];
			c2[0] = e[e.size() - 2].unbundledPos[0];
			c2[1] = e[e.size() - 2].unbundledPos[1];
			end.setX(e[e.size() - 1].unbundledPos[0]);
			end.setY(e[e.size() - 1].unbundledPos[1]);

			QVector<GgsBezierCurve::Point> inputs2;

			if (1 - pct)
			{
				QgsPointXY startXY = MINGLE::lerp(
					QgsPointXY(midpoint[0], midpoint[1]),
					QgsPointXY(c1[0], c1[1]), 1-pct);
				plXY.append(startXY);
			}
			inputs2 << preOutputs.last();
			inputs2 << GgsBezierCurve::Point(c1[0], c1[1], 0);
			inputs2 << GgsBezierCurve::Point(c2[0], c2[1], 0);
			inputs2 << GgsBezierCurve::Point(end.x(), end.y(), 0);

			GgsBezierCurve postBeizier(inputs2);
			postBeizier.Calculate3(21); // 生成的控制点数量
			QVector<GgsBezierCurve::Point> postOutputs = postBeizier.GetOutputPoints();

			iter_pts = postOutputs.begin();
			while (iter_pts != postOutputs.end())
			{
				plXY.append(
					QgsPointXY(
						(*iter_pts).x,
						(*iter_pts).y
					)
				);
				iter_pts++;
			}
			
			
		}
		else 
		{
			double* end = e[e.size() - 1].unbundledPos;
			plXY << QgsPointXY(start[0], start[1])
				<< QgsPointXY(end[0], end[1]);
		}

		feature.setGeometry(QgsGeometry::fromPolylineXY(plXY));
		feature.setAttribute(GgsMingleRenderContext::MINGLE_CLUSTER, e[0].node->getClusterIndex());
		feature.setAttribute(GgsMingleRenderContext::MINGLE_EDGE, i);
		feature.setAttribute(GgsMingleRenderContext::MINGLE_DIRECTION, rand() % 2);

		featureList << feature;

	}

	QgsVectorDataProvider* provider = pLayer->dataProvider();
	provider->addFeatures(featureList);

	pLayer->commitChanges();
	pLayer->updateExtents();
}

void GgsMingleBundler::renderQuadratic(QList<QList<GgsMingleNode::PositionItem>> edges, QgsVectorLayer* pLayer)
{
	QgsFeatureList featureList;

	for (int i = 0, L = edges.size(); i < L; ++i)
	{
		QList<GgsMingleNode::PositionItem> e = edges[i];
		GgsMingleNode* nodeStart = e[0].node;

		QgsFeature f;
		f.setFields(pLayer->fields(), true);

		QgsPointXY posStart;
		QgsPointXY quadStart;

		QgsPolylineXY plXY;
		for (int j = 0, N = e.size(); j < N; ++j)
		{
			GgsMingleNode::PositionItem posItem = e[j];
			double* pos = posItem.unbundledPos;

			if (j != 0)
			{
				QgsPointXY pos0 = !posStart.isEmpty() ? posStart : QgsPointXY(e[j - 1].unbundledPos[0], e[j - 1].unbundledPos[1]);
				
				// 如果启用松弛
				if (mRenderContext.isLooseEnabled())
				{
					QgsPointXY newPos = adjustPosition(nodeStart->getId(), posItem, pos, mRenderContext.getMargin(), mRenderContext.getDelta());
					pos[0] = newPos.x();
					pos[1] = newPos.y();
				}
				 
				QgsPointXY tmp = MINGLE::lerp(QgsPointXY(pos0.x(), pos0.y()), QgsPointXY(pos[0], pos[1]), 0.5);
				double midPos[2] = {tmp.x(), tmp.y()};

				QgsPointXY tmp2 = MINGLE::lerp(QgsPointXY(pos0.x(), pos0.y()), QgsPointXY(midPos[0], midPos[1]),
					j == 1? 0 : mRenderContext.getCurveness());
				double pos1[2] = { tmp2.x(), tmp2.y()};

				double pos3[2] = { pos[0], pos[1] };
				QgsPointXY tmp3 = MINGLE::lerp(QgsPointXY(midPos[0], midPos[1]), QgsPointXY(pos3[0], pos3[1]),
					j == N-1 ? 1: (1-mRenderContext.getCurveness()));
				double pos2[2] = { tmp3.x(), tmp3.y()};

				if (!quadStart.isEmpty())
				{
					QVector<GgsBezierCurve::Point> pts;
					pts << GgsBezierCurve::Point(quadStart.x(), quadStart.y(), 0)
						<< GgsBezierCurve::Point(pos0.x(), pos0.y(), 0)
						<< GgsBezierCurve::Point(pos1[0], pos1[1], 0);
					GgsBezierCurve curve(pts);
					curve.Calculate2(11);
					pts = curve.GetOutputPoints();

					for each (GgsBezierCurve::Point p in pts)
					{
						plXY << QgsPointXY(p.x, p.y);
					}
				}

				plXY << QgsPointXY(pos1[0], pos1[1]);
				plXY << QgsPointXY(pos2[0], pos2[1]);

				quadStart.set(pos2[0], pos2[1]);
				posStart.set(pos[0], pos[1]);
			}
		}

		f.setGeometry(QgsGeometry::fromPolylineXY(plXY));
		f.setAttribute(GgsMingleRenderContext::MINGLE_CLUSTER, e[0].node->getClusterIndex());
		f.setAttribute(GgsMingleRenderContext::MINGLE_EDGE, i);
		f.setAttribute(GgsMingleRenderContext::MINGLE_DIRECTION, rand() % 2);

		featureList << f;
	}

	QgsVectorDataProvider* provider = pLayer->dataProvider();
	provider->addFeatures(featureList);
	
	pLayer->commitChanges();
	pLayer->updateExtents();
}

QgsPointXY GgsMingleBundler::adjustPosition(const QString& id, GgsMingleNode::PositionItem posItem, double* pos, double margin, double delta)
{
	double mapUnitPerPiexel = GgsApp::instance()->mapCanvas()->mapUnitsPerPixel();;

	QList<GgsMingleNode*> nodeArray = posItem.node->nodeArray();
	double epsilon = 1.0;
	int index;
	double lengthBefore, lengthAfter;
	QgsPointXY ret(pos[0], pos[1]);
	
	if (nodeArray.size() > 0)
	{
		index = INT_MAX;
		lengthBefore = 0;
		lengthAfter = 0;
		for (int k=0; k<nodeArray.size(); ++k)
		{
			GgsMingleNode* node = nodeArray[k];
			if (node->getId() == id)
			{
				index = k;
			}

			if (k < index)
			{
				lengthBefore += mapUnitPerPiexel * node->getWeight() * 0.26000 + mapUnitPerPiexel * margin;
			}else if (k > index)
			{
				lengthAfter += mapUnitPerPiexel * node->getWeight() * 0.26000 + mapUnitPerPiexel * margin;
			}
		}

		double* tmp = MINGLE::add(pos,
			MINGLE::mult((lengthBefore - (lengthBefore + lengthAfter) / 2) * std::min(epsilon, delta), posItem.normal)
		);

		ret.set(tmp[0], tmp[1]);
	}

	return ret;
}
