#include <iostream>
#include "matrix.h"

int main()
{
	int arr[9] = { 1, 2, 3, 4, 5, 6, 7, 8, 9 };
	int arr1[9] = { 1, 1, 1, 1, 1, 1, 1, 1, 1 };
	Matrix M(3, 3, arr);
	Matrix N(3, 3, arr1);

	cout << "M" << endl << M << endl;

	cout << "N" << endl << N << endl;

	cout << "M+N" << endl << M+N << endl;

	cout << "M+5" << endl << M+5 << endl;

	cout << "M-N" << endl << M-N << endl;

	cout << "M-3" << endl << M-3 << endl;

	return 0;
}
