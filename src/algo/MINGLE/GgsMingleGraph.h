#pragma once
#include <QMap>
#include "GgsMingleEdge.h"

class GgsMingleGraph
{
public:
	GgsMingleGraph();
	~GgsMingleGraph();

	GgsMingleNode* addNode(GgsMingleNode* node);
	void removeNode(QString id);

	GgsMingleEdge* addEdge(GgsMingleNode* from, GgsMingleNode* to);
	void removeEdge(QString fromId, QString toId);

	bool hasNode(QString id);

	void empty();

	QList<GgsMingleNode*> nodes();

private:
	QMap<QString, GgsMingleNode*> mNodes;
	QMap<QString, QMap<QString, GgsMingleEdge*>> mEdges;
};

