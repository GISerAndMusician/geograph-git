#include "GgsMingleEdge.h"

GgsMingleEdge::GgsMingleEdge(GgsMingleNode* from, GgsMingleNode* to)
	: mFrom(from),
	mTo(to)
{

}

GgsMingleEdge::GgsMingleEdge(const GgsMingleEdge& other)
	: GgsMingleEdge(other.mFrom, other.mTo)
{

}

GgsMingleEdge::~GgsMingleEdge()
{

}

GgsMingleNode* GgsMingleEdge::fromNode()
{
	return mFrom;
}

GgsMingleNode* GgsMingleEdge::toNode()
{
	return mTo;
}

