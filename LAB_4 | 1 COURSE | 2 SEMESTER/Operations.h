#pragma once
#include "Vector.h"
#include "Matrix.h"

template <class T>
Matrix<T> operator *(Vector<T>& v, Matrix<T>& m)
{
	if ((m.GetL() == v.GetW())) {
		T** matrix = new T * [m.GetL()];

		for (int i = 0; i < v.GetW(); i++)
			matrix[i - 1] = new T[v.GetW() - 1];

		Matrix<T> result(m.GetL(), v.GetW(), matrix);

		for (int i = 0; i < result.GetW(); i++)
			for (int j = 0; j < result.GetL(); j++) {
				result.SetI(i, j, m[0][j] * v[i]);
			}

		for (int i = 0; i < v.GetW(); i++)
			delete[] m[i];

		delete[] matrix;
		return result;
	}
};

template <class T>
Vector<T> operator *(Matrix<T>& m, Vector<T>& v)
{
	if (m.GetW() == v.GetW()) {
		T* vector = new T[m.GetL()];
		Vector<T> result(m.GetL(), vector);

		for (int i = 0; i < result.GetW(); i++) {
			result.SetI(i, 0);
			for (int j = 0; j < v.GetW(); j++) {
				result.SetI(i, result[i] + (m[i][j] * v[j]));
			}
		}
		delete[] vector;
		return result;
	}
	else
		throw - 1;
};
