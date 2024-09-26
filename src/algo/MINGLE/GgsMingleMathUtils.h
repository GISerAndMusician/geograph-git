#pragma once
#include <math.h>
#include "qgspointxy.h"

namespace MINGLE
{

	double norm(double a[2]);

	double dist(double a[2], double b[2]);

	double PHI();

	double* sub(double a[2], double b[2]);

	double* normalize(double a[2]);

	double* mult(double k, double a[2]);

	double dot(double a[2], double b[2]);

	double* add(double a[2], double b[2]);

	QgsPointXY lerp(QgsPointXY a, QgsPointXY b, double delta);
}

