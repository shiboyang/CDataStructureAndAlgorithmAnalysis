//
// Created by shiby on 22-9-16.
//

#ifndef MATRIX__MATRIX_H
#define MATRIX__MATRIX_H
#include <iostream>
using namespace std;

class Matrix {
private:
	int* data;
	int rows;
	int columns;

public:
    Matrix(int r, int c, const int* d = nullptr);
    ~Matrix();
	Matrix(const Matrix& other);

	friend ostream& operator<<(ostream& os, const Matrix& m);

	//+
	Matrix operator+(const Matrix& other);
	Matrix operator+(const int& num);

	//-
	Matrix operator-(const Matrix& other);
	Matrix operator-(const int& num);

};

#endif //MATRIX__MATRIX_H
