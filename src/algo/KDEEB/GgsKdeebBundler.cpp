#include "GgsKdeebBundler.h"
#include <math.h>
#include <float.h>
#include "qgsmapcanvas.h"

GgsKdeebBundler::GgsKdeebBundler()
{

}

GgsKdeebBundler::~GgsKdeebBundler()
{

}

void GgsKdeebBundler::setAttraction(double a)
{
	mAttraction = a;
}

double GgsKdeebBundler::getAttraction()
{
	return mAttraction;
}

void GgsKdeebBundler::setSmooth(int s)
{
	mSmoothingLimit = s;
}

int GgsKdeebBundler::getSmooth()
{
	return mSmoothingLimit;
}

void GgsKdeebBundler::setKernel(int k)
{
	mKernelSize = k;
}

int GgsKdeebBundler::getKernel()
{
	return mKernelSize;
}

void GgsKdeebBundler::setSplitDistance(double d)
{
	mSplitDist = d;
}

double GgsKdeebBundler::getSplitDistance()
{
	return mSplitDist;
}

void GgsKdeebBundler::setRemoveDistance(double d)
{
	mRemoveDist = d;
}

double GgsKdeebBundler::getRemoveDistance()
{
	return mRemoveDist;
}

void GgsKdeebBundler::setIterator(int i)
{
	mIter = i;
}

int GgsKdeebBundler::getIterator()
{
	return mIter;
}

void GgsKdeebBundler::setPolylines(const QList<QgsPolylineXY>& pls)
{
	mPolylines = pls;
}

void GgsKdeebBundler::doBundle()
{
	if (!mPolylines.size())
	{
		return;
	}
	computemDensityMapSize();
	computeKernelValues();
	computeKernelGrad();

	// 执行循环
	int iTotalpoints = 0;

	for (int i = 0; i < mIter; i++)
	{
		resampling();

		computeDensityMapKernelGradient();
		normalizeGradientMap();
		updateLineGradKernel();

		smoothing();

		for each (QgsPolylineXY line in mPolylines)
		{
			iTotalpoints += line.size();
		}

		emit progressChanged(i + 1, mIter);
	}
	
}

void GgsKdeebBundler::computemDensityMapSize()
{
	for each (QgsPolylineXY line in mPolylines)
	{
		for each (QgsPointXY point in line)
		{
			if ((int)(point.x()) > mDensityMapSize)
			{
				mDensityMapSize = (int)point.x() + 1;
			}

			if ((int)(point.y()) > mDensityMapSize)
			{
				mDensityMapSize = (int)point.y() + 1;
			}
		}
	}
}

void GgsKdeebBundler::computeKernelValues()
{
	for (int i = 0; i < ((int)mKernelSize) * ((int)mKernelSize); i++)
	{
		mKernels.append(0.0f);
	}

	float halfKernel = (mKernelSize / 2.0) * (mKernelSize / 2.0);

	for (float y = 0; y < mKernelSize; y++)
	{
		for (float x = 0; x < mKernelSize; x++)
		{
			float centerDist = (float)(((float)(y - (mKernelSize - 1.0) / 2.0)) * ((float)(y - (mKernelSize - 1.0) / 2.0)) +
				((x - (mKernelSize - 1.0) / 2.0)) * ((x - (mKernelSize - 1.0) / 2.0)));

			if (centerDist < halfKernel)
			{
				double scaledValue = scale(centerDist, 0, halfKernel, 1, 0);
				mKernels[(int)(x + y * mKernelSize)] = (float)scaledValue;
			}
		}
	}
}

void GgsKdeebBundler::computeKernelGrad()
{
	for (int i = 0; i < mKernelSize * mKernelSize ; i++)
	{
		mGradientKernelX.append(0.0f);
		mGradientKernelY.append(0.0f);
	}

	for (int y = 0; y < mKernelSize; y++)
	{
		for (int x = 0; x < mKernelSize; x++)
		{
			if ((x > 0) && (x < (mKernelSize - 1)))
				mGradientKernelX[x + y * mKernelSize] = mKernels[(x - 1) + y * mKernelSize] - mKernels[(x + 1) + y * mKernelSize];
			if (x == 0)
				mGradientKernelX[x + y * mKernelSize] = mKernels[(x + 1) + y * mKernelSize] - mKernels[(x)+y * mKernelSize];
			if (x == (mKernelSize - 1))
				mGradientKernelX[x + y * mKernelSize] = mKernels[(x)+y * mKernelSize] - mKernels[(x - 1) + y * mKernelSize];

			if ((y > 0) && (y < (mKernelSize - 1)))
				mGradientKernelY[x + y * mKernelSize] = mKernels[(x)+(y - 1) * mKernelSize] - mKernels[(x)+(y + 1) * mKernelSize];
			if (y == 0)
				mGradientKernelY[x + y * mKernelSize] = mKernels[(x)+(y + 1) * mKernelSize] - mKernels[(x)+(y)* mKernelSize];
			if (y == (mKernelSize - 1))
				mGradientKernelY[x + y * mKernelSize] = mKernels[(x)+(y)* mKernelSize] - mKernels[(x)+(y - 1) * mKernelSize];
		}
	}
}

double GgsKdeebBundler::scale(double value, double min, double max, double minScale, double maxScale)
{
	double scaled = minScale + (double)(value - min) / (max - min) * (maxScale - minScale);
	return scaled;
}

void GgsKdeebBundler::resampling()
{
	QgsPointXY currentVert;
	QgsPointXY nextVert;

	for (int x = 0; x < mPolylines.size(); x++)
	{
		QgsPolylineXY tmpVertexList;
		tmpVertexList.append(mPolylines[x][0]);

		// 对每条线进行采样
		for (int y = 0; y < mPolylines[x].size() - 1; y++)
		{
			currentVert = mPolylines[x][y];
			nextVert = mPolylines[x][y + 1];

			double dist = std::sqrt(
				(currentVert.x()- nextVert.x()) * (currentVert.x() - nextVert.x()) + (currentVert.y() - nextVert.y()) * (currentVert.y() - nextVert.y())
			);

			// 判断下一个点是否距离过远或过近
			if (dist > mSplitDist)
			{
				tmpVertexList.append(QgsPointXY(
					(currentVert.x() + nextVert.x()) / 2.0,
					(currentVert.y() + nextVert.y()) / 2.0
				));
			}
			if (!(dist < mRemoveDist) || y == mPolylines.size()- 2)
			{
				tmpVertexList.append(nextVert);
			}
		}
		tmpVertexList.append(mPolylines[x][mPolylines[x].size() - 1]);
		mPolylines[x] = tmpVertexList;
	}
}

void GgsKdeebBundler::computeDensityMapKernelGradient()
{
	setGradientDensityMapToZero();

	for each (QgsPolylineXY line in mPolylines)
	{
		for each (QgsPointXY point in line)
		{
			QgsPointXY points(
				point.x() - mKernelSize / 2,
				point.y() - mKernelSize / 2
			);

			for (int y = 0; y < mKernelSize; y++)
			{
				for (int x = 0; x < mKernelSize; x++)
				{
					if (((points.x() + x) < mDensityMapSize) && 
						((points.y() + y) < mDensityMapSize) && 
						((points.x() + x) > 0) && 
						((points.y() + y) > 0))
					{
						mGradientDensityMapX[(int)(points.x() + x)][(int)(points.y() + y)] += mGradientKernelX[x + y * mKernelSize];
						mGradientDensityMapY[(int)(points.x() + x)][(int)(points.y() + y)] += mGradientKernelY[x + y * mKernelSize];
					}
				}
			}
		}
	}

	getMaxMinFromGradientDensityMap();
}

void GgsKdeebBundler::setGradientDensityMapToZero()
{
	for (int y = 0; y < mDensityMapSize; y++)
	{
		QList<float> row;
		for (int x = 0; x < mDensityMapSize; x++)
		{
			row.append(0);
		}
		mGradientDensityMapX.append(row);
		mGradientDensityMapY.append(row);
	}
}

void GgsKdeebBundler::getMaxMinFromGradientDensityMap()
{
	mMaxGradientDensValueX = FLT_MIN;
	mMinGradientDensValueX = FLT_MAX;
	mMaxGradientDensValueY = FLT_MIN;
	mMinGradientDensValueY = FLT_MAX;

	for (int y = 0; y < mDensityMapSize; y++)
	{
		for (int x = 0; x < mDensityMapSize; x++)
		{
			if (mGradientDensityMapX[x][y] > mMaxGradientDensValueX)
				mMaxGradientDensValueX = mGradientDensityMapX[x][y];
			if (mGradientDensityMapX[x][y] < mMinGradientDensValueX)
				mMinGradientDensValueX = mGradientDensityMapX[x][y];

			if (mGradientDensityMapY[x][y] > mMaxGradientDensValueY)
				mMaxGradientDensValueY = mGradientDensityMapY[x][y];
			if (mGradientDensityMapY[x][y] < mMinGradientDensValueY)
				mMinGradientDensValueY = mGradientDensityMapY[x][y];
		}
	}
}

void GgsKdeebBundler::normalizeGradientMap()
{
	for (int y = 0; y < mDensityMapSize; y++)
	{
		float l = 0;
		for (int x = 0; x < mDensityMapSize; x++)
		{
			l = (float)std::sqrt(mGradientDensityMapX[x][y] * mGradientDensityMapX[x][y] + mGradientDensityMapY[x][y] * mGradientDensityMapY[x][y]);
			if (l != 0)
			{
				mGradientDensityMapX[x][y] /= l;
				mGradientDensityMapY[x][y] /= l;
			}
		}
	}
}

void GgsKdeebBundler::updateLineGradKernel()
{
	double totalDistance = 0.0f;

	for (int j = 0; j < mPolylines.size(); j++)
	{
		for (int i = 1; i < mPolylines[j].size() - 1; i++)
		{
			if (((mPolylines[j][i].x()) < mDensityMapSize) && ((mPolylines[j][i].y()) < mDensityMapSize) &&
				((mPolylines[j][i].x()) > 0) && ((mPolylines[j][i].y()) > 0))
			{
				QgsPointXY temp = mPolylines[j][i];
				mPolylines[j][i].setX(
					mPolylines[j][i].x() - mGradientDensityMapX[(int)temp.x()][(int)temp.y()] * mAttraction
				);
				mPolylines[j][i].setY(
					mPolylines[j][i].y() - mGradientDensityMapY[(int)temp.x()][(int)temp.y()] * mAttraction
				);
			}
		}
	}
}

void GgsKdeebBundler::smoothing()
{
	int smoothnbr = 0;
	
	if (mSmoothingLimit != 0)
	{
		for (int j = 0; j < mPolylines.size(); j++)
		{
			for (int i = 1; i < mPolylines[j].size() - 1; i++)
			{
				smoothnbr = 0;
				QgsPointXY tempf;

				for (int t = -mSmoothingLimit; t <= mSmoothingLimit; ++t)
				{
					if (i + t < 0 || i + t > mPolylines[j].size() - 1)
					{
						continue;
					}

					tempf.setX(
						tempf.x() + mPolylines[j][i + t].x()
					);
					tempf.setY(
						tempf.y() + mPolylines[j][i + t].y()
					);
					smoothnbr++;
				}

				tempf.setX(
					tempf.x() / smoothnbr
				);
				tempf.setY(
					tempf.y() / smoothnbr
				);

				mPolylines[j][i].setX(tempf.x());
				mPolylines[j][i].setY(tempf.y());
			}
		}
	}
}
