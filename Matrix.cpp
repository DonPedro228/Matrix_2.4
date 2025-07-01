#include "Matrix.h"


Matrix::Matrix() : size(0), count(0) {}

Matrix::Matrix(int _size) : size(_size) {
	count = size * size;
	for (int i = 0; i < size; ++i)
		for (int j = 0; j < size; ++j)
			data[i][j] = 0;
}


Matrix::Matrix(const Matrix& other) {
	size = other.size;
	count = other.count;
	for (int i = 0; i < size; ++i) {
		for (int j = 0; j < size; ++j) {
			data[i][j] = other.data[i][j];
		}
	}
}

Matrix::~Matrix() {}

Matrix& Matrix::operator=(const Matrix& other) {
	if (this != &other) {
		size = other.size;
		count = other.count;
		for (int i = 0; i < size; ++i) {
			for (int j = 0; j < size; ++j) {
				data[i][j] = other.data[i][j];
			}
		}
	}

	return *this;
}

istream& operator>>(istream& in, Matrix& m) {
	cout << "Enter size: "; in >> m.size;
	m.count = m.size * m.size;
	cout << "Enter matrix elements: " << endl;
	for (int i = 0; i < m.size; ++i) {
		for (int j = 0; j < m.size; ++j) {
			in >> m.data[i][j];
		}
	}
	return in;
}

ostream& operator<<(ostream& out, const Matrix& m) {
	for (int i = 0; i < m.size; ++i) {
		for (int j = 0; j < m.size; ++j) {
			out << setw(4) << m.data[i][j] << " ";
		}
		out << endl;
	}
	return out;
}

Matrix::operator string() const {
	stringstream sout;
	for (int i = 0; i < size; ++i) {
		for (int j = 0; j < size; ++j) {
			sout << setw(4) << data[i][j] << " ";
		}
		sout << endl;
	}

	return sout.str();
}

int* Matrix::operator [] (int index) {
	return data[index];
}

Matrix operator*(const Matrix& m, int scalar) {
	Matrix result = m;
	for (int i = 0; i < m.size; ++i) {
		for (int j = 0; j < m.size; ++j) {
			result.data[i][j] *= scalar;
		}
	}
	return result;
}

int Matrix::norm() const {
	int max_el = data[0][0];
	int min_el = data[0][0];
	for (int i = 0; i < size; ++i) {
		for (int j = 0; j < size; ++j) {
			if (data[i][j] > max_el) {
				max_el = data[i][j];
			}
			if (data[i][j] < min_el) {
				min_el = data[i][j];
			}
		}
	}
	return fabs(max_el - min_el);
}

bool operator==(const Matrix& a, const Matrix& b) {
	if (a.getSize() != b.getSize()) return false;
	for (int i = 0; i < a.getSize(); ++i)
		for (int j = 0; j < a.getSize(); ++j)
			if (a.getData(i, j) != b.getData(i, j))
				return false;
	return true;
}

bool operator!=(const Matrix& a, const Matrix& b) {
	return !(a == b);
}

bool operator < (const Matrix& a, const Matrix& b) {
	if (a.size != b.size) return false;
	for (int i = 0; i < a.size; ++i)
		for (int j = 0; j < a.size; ++j) {
			if (a.data[i][j] < b.data[i][j]) return true;
			if (a.data[i][j] > b.data[i][j]) return false;
		}
	return false;
}

bool operator>(const Matrix& a, const Matrix& b) {
	return b < a;
}

bool operator<=(const Matrix& a, const Matrix& b) {
	return !(a > b);
}

bool operator>=(const Matrix& a, const Matrix& b) {
	return !(a < b);
}

//Increments && decrements
Matrix& Matrix::operator++() {
	for (int i = 0; i < size; ++i) {
		for (int j = 0; j < size; ++j) {
			++data[i][j];
		}
	}
	return *this;
}

Matrix& Matrix::operator--() {
	for (int i = 0; i < size; ++i) {
		for (int j = 0; j < size; ++j) {
			--data[i][j];
		}
	}
	return *this;
}

Matrix Matrix::operator++(int) {
	Matrix temp = *this;
	++(*this);
	return temp;
}

Matrix Matrix::operator--(int) {
	Matrix temp = *this;
	--(*this);
	return temp;
}