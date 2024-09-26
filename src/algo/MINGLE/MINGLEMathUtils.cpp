#include "GgsMingleMathUtils.h"

double MINGLE::norm(double a[2])
{
	return sqrt(a[0] * a[0] + a[1] * a[1]);
}

double MINGLE::dist(double a[2], double b[2])
{
	double diffX = a[0] - b[0], diffY = a[1] - b[1];
	return sqrt(diffX * diffX + diffY * diffY);
}

double MINGLE::PHI()
{
	return (1 + sqrt(5)) / 2;
}

double* MINGLE::sub(double a[2], double b[2])
{
	double ret[2];
	ret[0] = a[0] - b[0];
	ret[1] = a[1] - b[1];
	return ret;
}

double* MINGLE::normalize(double a[2])
{
	double n = MINGLE::norm(a);
	return MINGLE::mult(1 / n, a);
}

double* MINGLE::mult(double k, double a[2])
{
	double ret[2] = {
		a[0] * k,
		a[1] * k
	};
	return ret;
}

double MINGLE::dot(double a[2], double b[2])
{
	return a[0] * b[0] + a[1] * b[1];
}

double* MINGLE::add(double a[2], double b[2])
{
	double ret[2] = {
		a[0] + b[0],
		a[1] + b[1]
	};
	return ret;
}

QgsPointXY MINGLE::lerp(QgsPointXY a, QgsPointXY b, double delta)
{
	return QgsPointXY(
		a.x() * (1 - delta) + b.x() * delta,
		a.y() * (1 - delta) + b.y() * delta
	);
}
