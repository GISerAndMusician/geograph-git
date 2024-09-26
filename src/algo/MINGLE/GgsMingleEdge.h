#pragma once
#include "GgsMingleNode.h"

class GgsMingleEdge
{
public:
	GgsMingleEdge(GgsMingleNode* from, GgsMingleNode* to);
	GgsMingleEdge(const GgsMingleEdge& other);
	~GgsMingleEdge();

	GgsMingleNode* fromNode();
	void setFromNode(GgsMingleNode* n) { mFrom = n; };

	GgsMingleNode* toNode();
	void setToNode(GgsMingleNode* n) { mTo = n; };

private:
	GgsMingleNode* mFrom;
	GgsMingleNode* mTo;
};

