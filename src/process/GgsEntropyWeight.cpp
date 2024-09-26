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

	// ����ÿһ�еľ�ֵ�ͱ�׼��
	/*VectorXd mean = matrix.colwise().mean();
	VectorXd std = ((matrix.rowwise() - mean.transpose()).array().square().colwise().sum() / (matrix.rows() - 1)).sqrt();

	IOFormat HeavyFmt(FullPrecision, 0, ", ", ";\n", "[", "]", "[", "]");
	std::cout << mean.format(HeavyFmt) << std::endl;
	std::cout << std.format(HeavyFmt) << std::endl;

	// �Ծ�����б�׼��
	normalizedData = (matrix.rowwise() - mean.transpose()).array().rowwise() / std.transpose().array();*/

	IOFormat HeavyFmt(FullPrecision, 0, ", ", ";\n", "[", "]", "[", "]");
	for (int i = 0; i < iRows; i++)
	{	
		// Ϊ��ֹ0�ĳ��֣����վ�ֵ�Ծ���ƽ��
		double min = matrix.row(i).mean();
		MatrixXd tmp = MatrixXd::Constant(1, iCols, min);
		matrix.row(i) += tmp;
		matrix.row(i).normalize();
	}
	std::cout << matrix.format(HeavyFmt) << std::endl;

	// ������ֵH
	std::cout << "��ֵH" << std::endl;
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

	// ���Ȩ��
	MatrixXd W(iRows, 1);
	for (int i = 0; i < iRows; i++)
	{
		double Wi = (1 - H(i, 0)) / (iRows - H.col(0).sum());
		W(i, 0) = Wi;
	}
	std::cout << "Ȩ��" << std::endl;
	std::cout << W.format(HeavyFmt) << std::endl;

	return W;
}
