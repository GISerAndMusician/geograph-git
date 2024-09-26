#pragma once
#include "qgsfeature.h"
#include <QObject>

class GgsKdeebBundler: public QObject
{
	Q_OBJECT

public:
	GgsKdeebBundler();
	~GgsKdeebBundler();

	void setAttraction(double a);
	double getAttraction();

	void setSmooth(int s);
	int getSmooth();

	void setKernel(int k);
	int getKernel();

	void setSplitDistance(double d);
	double getSplitDistance();

	void setRemoveDistance(double d);
	double getRemoveDistance();

	void setIterator(int i);
	int getIterator();

	void setPolylines(const QList<QgsPolylineXY>& pls);

	void doBundle();

	QList<QgsPolylineXY> polylines() { return mPolylines; };

signals:
	void progressChanged(int current, int total);

private:
	void computemDensityMapSize();

	void computeKernelValues();
	
	void computeKernelGrad();

	double scale(double value, double min, double max, double minScale, double maxScale);

	void resampling();

	void computeDensityMapKernelGradient();

	void setGradientDensityMapToZero();

	void getMaxMinFromGradientDensityMap();

	void normalizeGradientMap();

	void updateLineGradKernel();

	void smoothing();

private:

	QList<QgsPolylineXY> mPolylines;

	double mAttraction = 2.1;
	int mKernelSize = 25;

	double mSplitDist = 15;
	double mRemoveDist = 5;
	int mDensityMapSize = 0;
	int mSmoothingLimit = 1;
	int mIter = 50;

	QList<float> mKernels;
	QList<float> mGradientKernelX;
	QList<float> mGradientKernelY;
	QList<QList<float>> mGradientDensityMapX;
	QList<QList<float>> mGradientDensityMapY;

	float mMinGradientDensValueX;
	float mMaxGradientDensValueX;
	float mMinGradientDensValueY;
	float mMaxGradientDensValueY;
};

