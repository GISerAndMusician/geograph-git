#include "GgsEntropyWeight.h"
#include <iostream>

GgsEntropyWeight::GgsEntropyWeight()
{

}

GgsEntropyWeight::~GgsEntropyWeight()
{

}

Eigen::MatrixXd GgsEntropyWeight::calculate(MatrixXd matrix)
{	
	int iRows = matrix.rows();
	int iCols = matrix.cols();

	// 计算每一列的均值和标准差
	/*VectorXd mean = matrix.colwise().mean();
	VectorXd std = ((matrix.rowwise() - mean.transpose()).array().square().colwise().sum() / (matrix.rows() - 1)).sqrt();

	IOFormat HeavyFmt(FullPrecision, 0, ", ", ";\n", "[", "]", "[", "]");
	std::cout << mean.format(HeavyFmt) << std::endl;
	std::cout << std.format(HeavyFmt) << std::endl;

	// 对矩阵进行标准化
	normalizedData = (matrix.rowwise() - mean.transpose()).array().rowwise() / std.transpose().array();*/

	IOFormat HeavyFmt(FullPrecision, 0, ", ", ";\n", "[", "]", "[", "]");
	for (int i = 0; i < iRows; i++)
	{	
		// 为防止0的出现，按照均值对矩阵平移
		double min = matrix.row(i).mean();
		MatrixXd tmp = MatrixXd::Constant(1, iCols, min);
		matrix.row(i) += tmp;
		matrix.row(i).normalize();
	}
	std::cout << matrix.format(HeavyFmt) << std::endl;

	// 计算熵值H
	std::cout << "熵值H" << std::endl;
	MatrixXd H(iRows, 1);
	for (int i=0; i<iRows; i++)
	{
		for (int j=0; j<iCols; j++)
		{
			matrix(i, j) *= log(matrix(i, j));
		}
		double Hi = (-1 / log(iCols)) * matrix.row(i).sum();
		H(i, 0) = Hi;

		std::cout << Hi << std::endl;
	}
	std::cout << H.format(HeavyFmt) << std::endl;

	// 获得权重
	MatrixXd W(iRows, 1);
	for (int i = 0; i < iRows; i++)
	{
		double Wi = (1 - H(i, 0)) / (iRows - H.col(0).sum());
		W(i, 0) = Wi;
	}
	std::cout << "权重" << std::endl;
	std::cout << W.format(HeavyFmt) << std::endl;

	return W;
}
