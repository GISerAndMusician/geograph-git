#pragma once
#include <Eigen/Dense>

using namespace Eigen;

class GgsEntropyWeight
{
public:
	GgsEntropyWeight();
	~GgsEntropyWeight();

	// ����ָ��ֵ������Ϣ�أ������Ȩֵ
	static MatrixXd calculate(MatrixXd matrix);

};