#pragma once
#include <Eigen/Dense>

using namespace Eigen;

class GgsEntropyWeight
{
public:
	GgsEntropyWeight();
	~GgsEntropyWeight();

	// 根据指标值计算信息熵，获得熵权值
	static MatrixXd calculate(MatrixXd matrix);

};