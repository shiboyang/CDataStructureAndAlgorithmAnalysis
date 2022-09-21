//
// Created by shiby on 22-9-16.
//

#include "include/matrix.h"
#include <iostream>

using namespace std;

Matrix::Matrix(int r, int c, const int* d)
		:rows(r), columns(c)
{
	data = new int[r*c];
	for (int i = 0; i<rows*columns; ++i) {
		data[i] = d ? d[i] : 0;
	}
}

Matrix::Matrix(const Matrix& other)
{
	rows = other.rows;
	columns = other.columns;
	data = new int[rows*columns];
	for (int i = 0; i<rows*columns; ++i) {
		data[i] = other.data[i];
	}
}

Matrix::~Matrix()
{
	delete[] data;
}
Matrix Matrix::operator+(const Matrix& other)
{
	Matrix matrix(*this);

	for (int i = 0; i<other.rows*other.columns; ++i) {
		matrix.data[i] += other.data[i];
	}

	return matrix;
}
Matrix Matrix::operator+(const int& num)
{
	Matrix matrix(*this);

	for (int i = 0; i<rows*columns; ++i) {
		matrix.data[i] += num;
	}
	return matrix;
}
Matrix Matrix::operator-(const Matrix& other)
{
	Matrix matrix(*this);

	for (int i = 0; i<other.rows*other.columns; ++i) {
		matrix.data[i] -= other.data[i];
	}

	return matrix;
}
Matrix Matrix::operator-(const int& num)
{
	Matrix matrix(*this);

	for (int i = 0; i<rows*columns; ++i) {
		matrix.data[i] -= num;
	}
	return matrix;
}

ostream& operator<<(ostream& os, const Matrix& m)
{
	std::cout << "[";
	for (int i = 0; i<m.rows; i++) {
		std::cout << "[";
		for (int j = 0; j<m.columns; ++j) {
			std::cout << m.data[m.rows*j+i];
			if (j==m.rows-1)
				continue;
			std::cout << ", ";
		}
		std::cout << "]";
		if (i==m.rows-1)
			continue;
		std::cout << "," << std::endl;
	}
	std::cout << "]";

	return os;
}
