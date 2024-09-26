#include "GgsBezierCurve.h"

#include <QDebug>


GgsBezierCurve::GgsBezierCurve(const QVector<Point> &points)
    : m_pointsInput(points)
{
    //Nothing
}

void GgsBezierCurve::Calculate3(int outPointNum)
{

    m_pointsOutput.clear();
    m_pointsOutput.resize(outPointNum);

    double step = (double)1.0 / (outPointNum-1);
    double t = 0;
    qDebug() << "BeizierCurve::Calculate step:" << step;

    for(int i = 0; i < outPointNum; ++i, t+=step){
        if(1.0 - t < 5e-6) {
            t = 1.0;
        }

        m_pointsOutput[i] = Point(0, 0, 0);
        for(int j = 0, len = m_pointsInput.length(); j < len; ++j){
            double basic = this->bernstein(len-1, j, t);
            m_pointsOutput[i] += m_pointsInput[j] * basic;
        }
    }
}

void GgsBezierCurve::Calculate2(int outPointNum)
{
	if (m_pointsInput.size() < 3)
	{
		return;
	}
	m_pointsOutput.clear();

	double t = 0;
	double delta_t = 1.0 / (outPointNum);
	double f1, f2, f3;
	for (int i=0; i<=outPointNum; ++i)
	{
		t = delta_t * i;
		f1 = (1 - t) * (1 - t);
		f2 = 2 * (1 - t) * t;
		f3 = t * t;

		double x = f1 * m_pointsInput[0].x + f2 * m_pointsInput[1].x + f3 * m_pointsInput[2].x;
		double y = f1 * m_pointsInput[0].y + f2 * m_pointsInput[1].y + f3 * m_pointsInput[2].y;
		double z = f1 * m_pointsInput[0].z + f2 * m_pointsInput[1].z + f3 * m_pointsInput[2].z;
		m_pointsOutput << Point(x, y, z);
	}
}

QVector<GgsBezierCurve::Point> GgsBezierCurve::GetOutputPoints()
{
    return this->m_pointsOutput;
}

uint64_t GgsBezierCurve::combination(int n, int i)
{
    uint32_t key = (n << 16) | i;
    if(m_combVal.contains(key)) {
        return this->m_combVal[key];
    }

    if(n < i) {
        return 0;
    }
    int m = i > n-i? i:n-i;     //取二者中大的
    if(m == 0 || m == n) {
        return 1;
    }

    //n*(n-1)*...*(m+1)
    uint64_t p1 = 1;
    for(int j = n; j > m; j--) {
        p1 *= j;
    }
    //(n-m)*(n-m-1)*...*1
    uint64_t p2 = 1;
    for(int j = n - m; j > 0; j--) {
        p2 *= j;
    }

    uint64_t ret = p1 / p2;
    this->m_combVal[key] = ret;
    return ret;
}

double GgsBezierCurve::bernstein(int n, int i, double t)
{
    double basis;
    double ti;  // t^i
    double tni; // (1 - t)^i

    if (t == 0.0 && i == 0) {
        ti = 1.0;
    } else {
        ti = pow(t, i);
    }

    if (n == i && t == 1.0) {
        tni = 1.0;
    } else {
        tni = pow((1 - t), (n - i));
    }

    basis = this->combination(n, i) * ti * tni;
    return basis;
}
