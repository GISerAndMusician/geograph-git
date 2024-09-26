#ifndef BEIZIERCURVE_H
#define BEIZIERCURVE_H

#include <QVector>
#include <QMap>

class GgsBezierCurve
{
public:
    struct Point
    {
        Point(): x(0), y(0), z(0) {}
        Point(double x, double y, double z): x(x), y(y), z(z) {}

        Point operator *(double num) {
            return Point(x*num, y*num, z*num);
        }
        Point operator +(const Point& p) {
            return Point(x+p.x, y+p.y, z+p.z);
        }
        void operator +=(const Point& p) {
            this->x += p.x;
            this->y += p.y;
            this->z += p.z;
        }

        double x;
        double y;
        double z;
    };

	// 生成三次贝塞尔曲线点
	void Calculate3(int outPointNum = 11);

	// 生成二次贝塞尔曲线点
	void Calculate2(int outPointNum = 11);

	// 获取曲线点集
	QVector<Point> GetOutputPoints();
	
	explicit GgsBezierCurve(const QVector<Point> &points);

protected:
    /// 求组合数
    uint64_t combination(int n, int i);
    /// 计算单项值
    double bernstein(int n, int i, double t);


private:
    QVector<Point> m_pointsInput;
    QVector<Point> m_pointsOutput;
    QMap<uint32_t, uint64_t> m_combVal;
};

#endif // BEIZIERCURVE_H
