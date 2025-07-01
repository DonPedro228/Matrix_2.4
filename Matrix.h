#pragma once
#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
#include <iomanip>
#include <algorithm>
#include <cmath>
using namespace std;

const int MAX_SIZE = 100;

class Matrix {
private:
	int size;
	int count;
	int data[MAX_SIZE][MAX_SIZE];
public:
	Matrix();
	Matrix(const Matrix&);
	Matrix(int _size);
	~Matrix();

	//Getters && Setters
	int getSize() const { return size; }
	int getCount() const { return count; }
	int getData(int i, int j) const { return data[i][j]; }


	void setSize(int _size) { size = _size; }
	void setCount(int _count) { count = _count; }

	//Other class methods
	Matrix& operator=(const Matrix&);
	operator string() const;
	int* operator [] (int);

	friend ostream& operator <<(ostream&, const Matrix&);
	friend istream& operator >>(istream&, Matrix&);

	friend Matrix operator*(const Matrix&, int scalar);
	int norm() const;

	friend bool operator > (const Matrix& a, const Matrix& b);
	friend bool operator < (const Matrix& a, const Matrix& b);
	friend bool operator >= (const Matrix& a, const Matrix& b);
	friend bool operator <= (const Matrix& a, const Matrix& b);
	friend bool operator == (const Matrix& a, const Matrix& b);
	friend bool operator != (const Matrix& a, const Matrix& b);


	Matrix& operator ++ ();
	Matrix& operator -- ();
	Matrix operator ++ (int);
	Matrix operator -- (int);
};