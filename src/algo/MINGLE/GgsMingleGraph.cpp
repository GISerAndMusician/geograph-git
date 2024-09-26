#include "GgsMingleGraph.h"

GgsMingleGraph::GgsMingleGraph()
{

}

GgsMingleGraph::~GgsMingleGraph()
{
	empty();
}

GgsMingleNode* GgsMingleGraph::addNode(GgsMingleNode* node)
{
	if (!mNodes.contains(node->getId()))
	{
		mNodes.insert(node->getId(), node);
	}
	return mNodes[node->getId()];
}

void GgsMingleGraph::removeNode(QString id)
{
	if (hasNode(id))
	{
// 		if (mNodes[id])
// 		{
// 			delete mNodes[id];
// 			mNodes[id] = nullptr;
// 		}

		for each (GgsMingleNode* n in mNodes.values())
		{
			if (n->adjacencies().contains(id))
			{
				n->adjacencies().remove(id);
			}
		}

		mNodes.remove(id);

// 		QMap<QString, MINGLEEdge*> adjs = mEdges[id];
// 		for each (MINGLEEdge* e in adjs.values())
// 		{
// 			if (e)
// 			{
// 				delete e;
// 				e = nullptr;
// 			}
// 		}
		mEdges.remove(id);
	}
}

GgsMingleEdge* GgsMingleGraph::addEdge(GgsMingleNode* from, GgsMingleNode* to)
{
	if (!hasNode(from->getId()))
	{
		addNode(from);
	}
	if (!hasNode((to->getId())))
	{
		addNode(to);
	}
	from = mNodes[from->getId()];
	to = mNodes[to->getId()];
	if (!from->adjacentTo(*to))
	{
		GgsMingleEdge* e = new GgsMingleEdge(from, to);
		mEdges[from->getId()].insert(to->getId(), e);
		mEdges[to->getId()].insert(from->getId(), e);

		// 为各个node添加adjacencies
		from->adjacencies().insert(to->getId(), e);
		to->adjacencies().insert(from->getId(), e);

		return mEdges[from->getId()][to->getId()];
	}
	return mEdges[from->getId()][to->getId()];
}

void GgsMingleGraph::removeEdge(QString fromId, QString toId)
{
	if (mEdges.contains(fromId))
	{
		if (mEdges[fromId].contains(toId))
		{
			if (mEdges[fromId][toId])
			{
				delete mEdges[fromId][toId];
				mEdges[fromId][toId] = nullptr;
			}
		}
		mEdges.remove(fromId);
	}
}

bool GgsMingleGraph::hasNode(QString id)
{
	return mNodes.contains(id);
}

void GgsMingleGraph::empty()
{
	for each (GgsMingleNode* n in mNodes.values())
	{
		if (n)
		{
			delete n;
			n = nullptr;
		}
	}
	mNodes.clear();

	for each (QMap<QString, GgsMingleEdge*> adj in mEdges.values())
	{
		for each (GgsMingleEdge* e in adj)
		{
			if (e)
			{
				delete e;
				e = nullptr;
			}
		}
	}

	mEdges.clear();
}

QList<GgsMingleNode*> GgsMingleGraph::nodes()
{
	return mNodes.values();
}
