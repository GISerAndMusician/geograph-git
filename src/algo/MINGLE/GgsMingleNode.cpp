#include "GgsMingleNode.h"
#include "GgsMingleMathUtils.h"

GgsMingleNode::GgsMingleNode()
{

}

GgsMingleNode::GgsMingleNode(QString id, QString name, QgsPointXY coordSource, QgsPointXY coordTarget)
	: mId(id),
	mName(name),
	mCoordSource(coordSource),
	mCoordTarget(coordTarget)
{

}

GgsMingleNode::GgsMingleNode(const GgsMingleNode& other)
	: GgsMingleNode(other.mId, other.mName, other.mCoordSource, other.mCoordTarget)
{
	mAdjacencies = other.mAdjacencies;
	mWeight = other.mWeight;
	mGroup = other.mGroup;
	mParents = other.mParents;
	mNodes = other.mNodes;
	mNodeArray = other.mNodeArray;
	mInk = other.mInk;
	mCombineNode = other.mCombineNode;
}

GgsMingleNode::~GgsMingleNode()
{

}

QString GgsMingleNode::getId()
{
	return mId;
}

void GgsMingleNode::setId(QString id)
{
	mId = id;
}

QString GgsMingleNode::getName()
{
	return mName;
}

void GgsMingleNode::setName(QString name)
{
	mName = name;
}

QgsPointXY GgsMingleNode::getCoordSource()
{
	return mCoordSource;
}

void GgsMingleNode::setCoordSource(QgsPointXY coords)
{
	mCoordSource = coords;
}

QgsPointXY GgsMingleNode::getCoordTarget()
{
	return mCoordTarget;
}

void GgsMingleNode::setCoordTarget(QgsPointXY coords)
{
	mCoordTarget = coords;
}

bool GgsMingleNode::adjacentTo(GgsMingleNode node)
{
	return mAdjacencies.contains(node.getId());
}

GgsMingleEdge* GgsMingleNode::getEdge(QString id)
{
	if (mAdjacencies.contains(id))
	{
		return mAdjacencies[id];
	}
	else
	{
		return nullptr;
	}
}

void GgsMingleNode::setGroup(int group)
{
	mGroup = group;
}

int GgsMingleNode::getGroup()
{
	return mGroup;
}

QList<GgsMingleNode*>& GgsMingleNode::parents()
{
	return mParents;
}

GgsMingleNode* GgsMingleNode::getBundle()
{
	return mCombineNode;
}

void GgsMingleNode::setBundle(GgsMingleNode* bundle)
{
	mCombineNode = bundle;
}

double GgsMingleNode::getInk()
{
	return mInk;
}

void GgsMingleNode::setInk(double ink)
{
	mInk = ink;
}

QList<QList<GgsMingleNode::PositionItem>> GgsMingleNode::unbundleEdges(GgsMingleRenderContext ctx)
{
	mRenderContext = ctx;

	QList<QList<PositionItem>> expandedEdges = this->expandEdges();
	QList<QList<PositionItem>> ans;
	if ((fabs(ctx.getDelta()) == 0 || fabs(ctx.getDelta() - 1) == 0) && 
		this->mUnbundleEdges.size() > 0)
	{
		return mUnbundleEdges;
	}

	for (int i=0, L = expandedEdges.size(); i<L; ++i)
	{
		QList<PositionItem> edge = expandedEdges[i];
		int last = edge.size() - 1;
		QList<PositionItem> edgeCopy = edge;

		double x0[2] = {edge[0].pos[0], edge[0].pos[1]};
		double xk[2] = {edge[last].pos[0], edge[last].pos[1]};
		double* xk_x0 = MINGLE::sub(xk, x0);
		
		edgeCopy[0].unbundledPos[0] = edgeCopy[0].pos[0];
		edgeCopy[0].unbundledPos[1] = edgeCopy[0].pos[1];

		double* normal = MINGLE::sub(edgeCopy[1].pos, edgeCopy[0].pos);
		double normalizeIpt[2] = { -normal[1], normal[0] };
		normal = MINGLE::normalize(normalizeIpt);
		edgeCopy[0].normal[0] = normal[0];
		edgeCopy[1].normal[1] = normal[1];

		edgeCopy[last].unbundledPos[0] = edgeCopy[edge.size() - 1].pos[0];
		edgeCopy[last].unbundledPos[1] = edgeCopy[edge.size() - 1].pos[1];
		normal = MINGLE::sub(edgeCopy[last].pos, edgeCopy[last - 1].pos);
		normalizeIpt[0] = -normal[1];
		normalizeIpt[1] = normal[0];
		normal = MINGLE::normalize(normalizeIpt);
		edgeCopy[last].normal[0] = normal[0];
		edgeCopy[last].normal[1] = normal[1];

		for (int j=1, N=edge.size() - 1; j < N; ++j)
		{
			double* xi = edge[j].pos;
			double* xi_x0 = MINGLE::sub(xi, x0);
			double dot = MINGLE::dot(xi_x0, xk_x0);
			double norm = MINGLE::dist(xk, x0);
			double norm2 = norm * norm;
			double c = dot / norm2;
			double* xi_bar = MINGLE::add(x0, MINGLE::mult(c, xk_x0));
			QgsPointXY lerp = MINGLE::lerp(QgsPointXY(xi_bar[0], xi_bar[1]), QgsPointXY(xi[0], xi[1]), ctx.getDelta());
			edgeCopy[j].unbundledPos[0] = lerp.x();
			edgeCopy[j].unbundledPos[1] = lerp.y();
			normal = MINGLE::sub(edgeCopy[j+1].pos, edgeCopy[j-1].pos);
			normalizeIpt[0] = -normal[1];
			normalizeIpt[1] = normal[0];
			normal = MINGLE::normalize(normalizeIpt);
			edgeCopy[j].normal[0] = normal[0];
			edgeCopy[j].normal[1] = normal[1];
		}

		ans.append(edgeCopy);
	}

	if (fabs(ctx.getDelta()) == 0 || fabs(ctx.getDelta() - 1) == 0)
	{
		this->mUnbundleEdges = ans;
	}

	return ans;
}

QList<QList<GgsMingleNode::PositionItem>> GgsMingleNode::expandEdges()
{
	QList<QList<PositionItem>> ans;
	QList<PositionItem> array;
	expandEdgesRichHelper(this, array, ans);
	return ans;
}

void GgsMingleNode::expandEdgesRichHelper(GgsMingleNode* node, QList<PositionItem>& array, QList<QList<PositionItem>>& collect)
{
	

	QgsPointXY sourceCoord = node->getCoordSource();
	QgsPointXY targetCoord = node->getCoordTarget();

	QList<GgsMingleNode*> ps = node->parents();
	if (ps.size() > 0)
	{
		for (int i=0, L=ps.size(); i<L; ++i)
		{
			QList<PositionItem> a = array;
			if (!a.size())
			{
				double p[2] = {(sourceCoord.x() + targetCoord.x()) / 2,
					(sourceCoord.y() + targetCoord.y()) / 2};

				// createPosItem
				PositionItem posItem;
				posItem.node = node;
				posItem.pos[0] = p[0];
				posItem.pos[1] = p[1];
				a.append(posItem);
			}

			PositionItem prePosItem;
			prePosItem.node = node;
			prePosItem.pos[0] = sourceCoord.x();
			prePosItem.pos[1] = sourceCoord.y();
			a.prepend(prePosItem);

			PositionItem postPosItem;
			postPosItem.node = node;
			postPosItem.pos[0] = targetCoord.x();
			postPosItem.pos[1] = targetCoord.y();
			a.append(postPosItem);
			
			expandEdgesRichHelper(ps[i], a, collect);

		}
	}
	else
	{
		QList<PositionItem> a = array;
		if (!a.size())
		{
			double p[2] = { (sourceCoord.x() + targetCoord.x()) / 2,
					 (sourceCoord.y() + targetCoord.y())/ 2 };

			PositionItem posItem;
			posItem.node = node;
			posItem.pos[0] = p[0];
			posItem.pos[1] = p[1];
			a.append(posItem);
		}

		PositionItem prePosItem;
		prePosItem.node = node;
		prePosItem.pos[0] = sourceCoord.x();
		prePosItem.pos[1] = sourceCoord.y();
		a.prepend(prePosItem);

		PositionItem postPosItem;
		postPosItem.node = node;
		postPosItem.pos[0] = targetCoord.x();
		postPosItem.pos[1] = targetCoord.y();
		a.append(postPosItem);

		collect.append(a);
	}
}
