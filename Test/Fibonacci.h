#pragma once
#include <assert.h>
struct Matrix2By2
{
	long long m_00;
	long long m_01;
	long long m_10;
	long long m_11;

	Matrix2By2(long long m_00, long long m_01, long long m_10, long long m_11):m_00(m_00), m_01(m_01), m_10(m_10), m_11(m_11){}
	Matrix2By2(){}
};
Matrix2By2 MatrixMultiply(const Matrix2By2 & matrix1, const Matrix2By2 & matrix2)
{
	return Matrix2By2(matrix1.m_00 * matrix2.m_00 + matrix1.m_01 * matrix2.m_10,
					matrix1.m_00 * matrix2.m_01 + matrix1.m_01 * matrix2.m_11,
					matrix1.m_10 * matrix2.m_00 + matrix1.m_11 * matrix2.m_10,
					matrix1.m_10 * matrix2.m_01 + matrix1.m_11 * matrix2.m_11
		);
}
Matrix2By2 MatrixPower(unsigned int n)
{
	assert(n > 0);
	Matrix2By2 matrix;
	if (n == 1)
		matrix = Matrix2By2(1,1,1,0);
	else if (n % 2 == 0)
	{
		matrix = MatrixMultiply(MatrixPower(n /2),MatrixPower(n / 2));
	}else if (n % 2 != 0)
	{
		matrix = MatrixMultiply(MatrixPower((n-1/2)),MatrixPower((n-1)/2));
		matrix = MatrixMultiply(matrix,Matrix2By2(1, 1, 1, 0));
	}
	return matrix;
}