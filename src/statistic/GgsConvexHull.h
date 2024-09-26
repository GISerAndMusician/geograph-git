#pragma once
#include <QVector>
#include <qgspointxy.h>

double cross(const QgsPointXY& O, const QgsPointXY& A, const QgsPointXY& B) {
	return (A.x() - O.x()) * (B.y() - O.y()) - (A.y() - O.y()) * (B.x() - O.x());
}

QVector<QgsPointXY> convexHull( QVector<QgsPointXY> P) {
	int n = P.size();
	int k = 0;
	QVector<QgsPointXY> H(2 * n);
	std::sort(P.begin(), P.end(), [](QgsPointXY a, QgsPointXY b) {
		return a.x() < b.x() || (a.x() == b.x() && a.y() < b.y());
	});
	for (int i = 0; i < n; ++i)
	{
		while (k >= 2 && cross(H[k - 2], H[k - 1], P[i]) <= 0)
		{
			k--;
		}
		H[k++] = P[i];
	}

	for (int i = n - 2, t = k + 1; i >= 0; i--)
	{
		while (k >= t && cross(H[k - 2], H[k - 1], P[i]) <= 0)
		{
			k--;
		}
		H[k++] = P[i];
	}
	H.resize(k - 1);
	return H;
}

double crossProduct(const QgsPointXY& O, const QgsPointXY& A, const QgsPointXY& B) {
	return (A.x() - O.x()) * (B.y() - O.y()) - (A.y() - O.y()) * (B.x() - O.x());
}

QVector<QgsPointXY> concaveEnvelope(QVector<QgsPointXY> P) {
	int n = P.size();
	QVector<QgsPointXY> concave;

	if (n <= 1) 
	{
		return concave;
	}

	// 找到最近的点
	int leftMost = 0;
	for (int i=0; i<n; i++)
	{
		if (P[i].x() < P[leftMost].x() || (P[i].x() == P[leftMost].x() && P[i].y() < P[leftMost].y())) {
			leftMost = i;
		}
	}

	QgsPointXY p0 = P[leftMost];
	concave.push_back(p0);

	// 扫描圆周
	for (int i=0; i<n; i++)
	{
		int nextIndex = (i + 1) % n;
		while (nextIndex != leftMost && crossProduct(P[nextIndex], P[i], concave.back()) <= 0)
		{
			nextIndex = (nextIndex + 1) % n;
		}
		concave.push_back(P[nextIndex]);
	}

	return concave;
}