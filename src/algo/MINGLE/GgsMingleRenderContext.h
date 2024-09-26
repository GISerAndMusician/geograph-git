#pragma once

class GgsMingleRenderContext
{
public:

	/* ��Ҫ��Ҫ���в���������ֶ�����
	*/
	static const char* MINGLE_CLUSTER; // ������ɫ��Ϣ
	static const char* MINGLE_EDGE; // ������ɫ��Ϣ
	static const char* MINGLE_DIRECTION; // ������ɫ��Ϣ

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

