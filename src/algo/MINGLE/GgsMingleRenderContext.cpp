#include "GgsMingleRenderContext.h"

const char* GgsMingleRenderContext::MINGLE_CLUSTER = "MINGLE_CLUSTER";
const char* GgsMingleRenderContext::MINGLE_EDGE = "MINGLE_EDGE";
const char* GgsMingleRenderContext::MINGLE_DIRECTION = "MINGLE_DIRECTION";

GgsMingleRenderContext::GgsMingleRenderContext()
{

}

GgsMingleRenderContext::~GgsMingleRenderContext()
{

}

GgsMingleRenderContext::LineType GgsMingleRenderContext::getLineType()
{
	return mLineType;
}

void GgsMingleRenderContext::setLineType(LineType t)
{
	mLineType = t;
}

double GgsMingleRenderContext::getCurveness()
{
	return mCurveness;
}

void GgsMingleRenderContext::setCurveness(double c)
{
	mCurveness = c;
}

double GgsMingleRenderContext::getDelta()
{
	return mDelta;
}

void GgsMingleRenderContext::setDelta(double d)
{
	mDelta = d;
}

double GgsMingleRenderContext::getMargin()
{
	return mMargin;
}

void GgsMingleRenderContext::setMargin(double m)
{
	mMargin = m;
}

bool GgsMingleRenderContext::isLooseEnabled()
{
	return mLoose;
}

void GgsMingleRenderContext::enableLoose(bool l)
{
	mLoose = l;
}

void GgsMingleRenderContext::setColorType(ColorType t)
{
	mColorType = t;
}

GgsMingleRenderContext::ColorType GgsMingleRenderContext::getColorType()
{
	return mColorType;
}

void GgsMingleRenderContext::setAlpha(double a)
{
	mAlpha = a;
}

double GgsMingleRenderContext::getAlpha()
{
	return mAlpha;
}
