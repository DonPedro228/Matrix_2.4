Matrix Class – C++ Pet Project

📌 Description

This pet project demonstrates the implementation of a custom `Matrix` class in C++ to work with square matrices of integers (`N x N`). It includes support for a variety of operator overloads, custom behaviors, and object-oriented design patterns.

The project was created as part of an academic assignment and follows modern C++ development principles.

---

✨ Features

- Initialization, copy and default constructors
- Assignment operator
- Input/output via streams
- Type conversion to `std::string`
- Element access via `[]` indexing operator
- Scalar multiplication: `matrix * scalar`
- Comparison operators: `==`, `!=`, `<`, `>`, `<=`, `>=`
- Matrix norm calculation (|max - min|)
- Increment & decrement operators (`++`, `--`) in both prefix and postfix forms
- Internal memory layout with fixed maximum size (`MAX_SIZE`)
- Compile-time structure size comparison with and without `#pragma pack(1)`

---

🧩 Class Overview

Private Members
- `int size` – current matrix size (NxN)
- `int count` – total number of elements (N*N)
- `int data[MAX_SIZE][MAX_SIZE]` – storage for matrix elements

Important Methods
- `norm()` – computes the difference between the largest and smallest element in the matrix
- `operator[](int index)` – access row by index
- `operator string()` – converts matrix to human-readable string
- `operator>>(istream&, Matrix&)` – read matrix from input
- `operator<<(ostream&, const Matrix&)` – print matrix to output

---

🔧 How It Works

```cpp
Matrix m1, m2;
cin >> m1 >> m2;

if (m1 == m2)
    cout << "Matrices are equal\n";
else
    cout << "Matrices are not equal\n";

int norm = m1.norm();
cout << "Norm of m1 = " << norm << "\n";

Matrix m3 = m1 * 5;
cout << "m1 multiplied by 5:\n" << m3;

✅ Requirements

    C++17 or higher

    Console-based input/output

    No external dependencies

📁 Project Structure

/Matrix
├── Matrix.h         // Header file for class definition
├── Matrix.cpp       // Implementation file
├── main.cpp         // Demonstration and test logic
├── README.md        // You are here

🧪 Unit Testing

Included in the project is a simple test method using Microsoft UnitTest Framework:

TEST_METHOD(TestNorm) {
    Matrix m(3);
    int value = 1;
    for (int i = 0; i < 3; ++i)
        for (int j = 0; j < 3; ++j)
            m[i][j] = value++;
    Assert::AreEqual(8, m.norm());
}

🛠️ Build Instructions

You can compile and run the project using any modern C++ compiler or IDE like:

    Visual Studio

    Code::Blocks

    g++

Example (g++):

g++ -o matrix main.cpp Matrix.cpp
./matrix

📚 Future Improvements

    Dynamic memory support (instead of fixed MAX_SIZE)

    Support for non-square matrices

    Determinant, inverse, and transpose functions

    File I/O support
