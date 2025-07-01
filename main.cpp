#include "Matrix.h"


int main() {
	Matrix m1, m2;

	cout << "Input m1: " << endl;
	cin >> m1;
	cout << m1 << endl;

	cout << "Input m2: " << endl;
	cin >> m2;
	cout << m2 << endl;
	 
	if (m1 == m2) {
		cout << "m1 equal m2" << endl;
	}
	else {
		cout << "m1 not equal m2" << endl;
	}

	int norm_matrix = m1.norm();
	cout << "Matrix norm m1 is " << norm_matrix << endl;

	Matrix m3;
	int scalar;
	cout << "Input scalar: "; cin >> scalar;
	m3 = m1 * scalar;
	cout << m3 << endl;


	return 0;
}