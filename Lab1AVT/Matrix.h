#ifndef __MATRIX_H__
#define __MATRIX_H__

#include <vector>

// class Matrix - so funciona p matrizes quadradas.

class Matrix {
public:
	std::vector<float> m;
	Matrix(int size = 4);
	Matrix(float *o, int size);
	Matrix(Matrix &other);
	void printMatrix();

	Matrix& operator*=(const Matrix &m1);
	Matrix& operator=(const Matrix &m1);
	friend Matrix operator*(Matrix lhs, const Matrix &rhs);
	void transposeMatrix();
	void invertMatrix();
	//Matrix multMatrix(Matrix &m1, Matrix &m2);
	int sizeofMatrix();
};

#endif 