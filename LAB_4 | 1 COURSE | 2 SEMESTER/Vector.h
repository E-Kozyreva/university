#pragma once
#include <iostream>
#include "Matrix.h"
using namespace std;

template<class T>
class Vector
{
protected:
	int N;
	T* vector;
public:
	Vector() {};
	Vector(int l);
	Vector(const Vector& V);
	Vector(int s, const T* arr);
	~Vector();

	void SetI(int i, T symbol);
	int GetW();

	Vector<T> operator = (const Vector<T>& other);
	bool operator ==(const Vector<T>& other);
	T operator [](const int i);
	Vector<T> operator+(const Vector<T>& other);
	Vector<T> operator-(const Vector<T>& other);
	T operator*(const Vector<T>& other);

	template <class T>
	friend ostream& operator<<(ostream& os, const Vector<T>& vec);
	template <class T>
	friend istream& operator>>(istream& in, Vector<T>& vec);
};

template<class T>
int Vector<T>::GetW() 
{
	return N;
}

template<class T>
void Vector<T>::SetI(int i, T symbol) 
{
	for (int n = 0; n < N; n++)
		if (n == i)
			vector[n] = symbol;
}

template<class T>
Vector<T>::Vector(int _N) 
{
	N = _N;
	vector = new int[N];

	for (int n = 0; n < N; n++)
		vector[n] = 0;
}

template<class T>
Vector<T>::Vector(int s, const T* arr)
{
	N = s;
	vector = new T[N];

	for (int n = 0; n < N; n++)
		vector[n] = arr[n];
}

template<class T>
Vector<T>::Vector(const Vector<T>& V)
{
	N = V.N;
	vector = new T[N];

	for (int n = 0; n < N; n++)
		vector[n] = V.vector[n];
}

template<class T>
Vector<T>::~Vector()
{
	if (vector != 0) {
		delete[] vector;
		vector = 0;
		N = 0;
	}
}

template<class T>
Vector<T> Vector<T>::operator=(const Vector<T>& other)
{
	if (*this == other)
		return *this;

	delete[] vector;
	this->N = other.N;
	vector = new T[N];

	for (int i = 0; i < N; i++)
		vector[i] = other.vector[i];
	return *this;
}

template<class T>
bool Vector<T>::operator==(const Vector<T>& other)
{
	if (N == other.N) {
		for (int i = 0; i < N; i++)
			if (vector[i] != other.vector[i])
				return false;
		return true;
	}
	else
		return false;
}

template<class T>
T Vector<T>::operator[](const int i)
{
	return vector[i];
}

template<class T>
Vector<T> Vector<T>::operator+(const Vector<T>& other)
{
	if (N == other.N) {
		Vector<T> vec(N, other.vector);

		for (int n = 0; n < N; n++)
			vec.vector[n] = other.vector[n] + vector[n];
		return vec;
	} else {
		throw - 1;
	}
}

template<class T>
Vector<T> Vector<T>::operator-(const Vector<T>& other)
{
	if (N == other.N) {
		Vector<T> vec(N, other.vector);

		for (int n = 0; n < N; n++)
			vec.vector[n] = vector[n] - other.vector[n];
		return vec;
	} else {
		throw - 1;
	}
}

template<class T>
T Vector<T>::operator *(const Vector<T>& other)
{
	T result = 0;

	if (N == other.N) {
		for (int i = 0; i < N; i++)
			result = result + (vector[i] * other.vector[i]);
		return result;
	} else {
		throw - 1;
	}
}

template<class T>
ostream& operator<<(ostream& os, const Vector<T>& V)
{
	os << "(";
	for (int n = 0; n < V.N; n++) {
		os << V.vector[n];
		if (n < V.N - 1)
			os << " ";
	}
	os << ")^T";
	cout << endl;
	return os;
}

template<class T>
istream& operator>>(istream& in, Vector<T>& V)
{
	cout << "Enter size" << endl << "N = ";
	int a;
	in >> a;
	T* temp;
	temp = new T[a];

	for (int i = 0; i < a; i++)
		in >> temp[i];

	Vector<T> Ve(a, temp);
	V = Ve;

	delete[] temp;
	return in;
}
