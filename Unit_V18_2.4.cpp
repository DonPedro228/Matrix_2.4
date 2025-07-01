#include "pch.h"
#include "CppUnitTest.h"
#include "..//laboratory_2.4_V18/Matrix.h"
#include "..//laboratory_2.4_V18/Matrix.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitV1824
{
	TEST_CLASS(UnitV1824)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			Matrix m;

			m.setSize(3);
			m.setCount(9);

			int value = 1;
			for (int i = 0; i < 3; ++i) {
				for (int j = 0; j < 3; ++j) {
					m[i][j] = value++;
				}
			}

			int matrix_norm = m.norm();
			int expected_result = 8;

			Assert::AreEqual(expected_result, matrix_norm);
		}
	};
}
