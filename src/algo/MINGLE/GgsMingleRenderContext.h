#pragma once

class GgsMingleRenderContext
{
public:

	/* 需要在要素中补充的属性字段名称
	*/
	static const char* MINGLE_CLUSTER; // 聚类颜色信息
	static const char* MINGLE_EDGE; // 连边颜色信息
	static const char* MINGLE_DIRECTION; // 方向颜色信息

	enum LineType {
		LINE,
		BEZIER,
		QUADRATIC
	};

	enum ColorType {
		SOLID,
		CLUSTER,
		DIRECTION,
		EDGE
	};

	GgsMingleRenderContext();
	~GgsMingleRenderContext();

	LineType getLineType();
	void setLineType(LineType t);

	double getCurveness();
	void setCurveness(double c);

	double getDelta();
	void setDelta(double d);

	double getMargin();
	void setMargin(double m);

	bool isLooseEnabled();
	void enableLoose(bool l);

	void setColorType(ColorType t);
	ColorType getColorType();

	void setAlpha(double a);
	double getAlpha();

private:
	ColorType mColorType = SOLID;
	LineType mLineType;
	double mCurveness;
	double mDelta;
	double mMargin;
	double mLoose = true;
	double mAlpha = 1.0;
};

