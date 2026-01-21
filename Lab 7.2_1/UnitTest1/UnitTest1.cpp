#include "pch.h"
#include "CppUnitTest.h"
#include "D:\education\Lab 7.2_1\Lab 7.2_1.cpp"
using namespace Microsoft::VisualStudio::CppUnitTestFramework;

// Forward declarations of functions from Lab 7.2_1.cpp
void Create(int** a, const int k, const int n, const int Low, const int High);
void Print(int** a, const int k, const int n);
int FindMaxOfRowMins(int** a, const int k, const int n);

namespace UnitTest1
{
	TEST_CLASS(UnitTest1)
	{
	public:

		TEST_METHOD(Test_FindMaxOfRowMins_Simple)
		{
			const int k = 3, n = 4;
			int** a = new int* [k];
			for (int i = 0; i < k; ++i)
				a[i] = new int[n];

			// Matrix:
			//  1  2  3  4   min=1
			//  5  6  7  8   min=5
			// -1  0  2  3   min=-1
			a[0][0] = 1; a[0][1] = 2; a[0][2] = 3; a[0][3] = 4;
			a[1][0] = 5; a[1][1] = 6; a[1][2] = 7; a[1][3] = 8;
			a[2][0] = -1; a[2][1] = 0; a[2][2] = 2; a[2][3] = 3;

			int result = FindMaxOfRowMins(a, k, n);
			Assert::AreEqual(5, result);

			for (int i = 0; i < k; ++i)
				delete[] a[i];
			delete[] a;
		}

		TEST_METHOD(Test_FindMaxOfRowMins_AllEqual)
		{
			const int k = 2, n = 3;
			int** a = new int* [k];
			for (int i = 0; i < k; ++i)
				a[i] = new int[n];

			// All elements are 7
			for (int i = 0; i < k; ++i)
				for (int j = 0; j < n; ++j)
					a[i][j] = 7;

			int result = FindMaxOfRowMins(a, k, n);
			Assert::AreEqual(7, result);

			for (int i = 0; i < k; ++i)
				delete[] a[i];
			delete[] a;
		}

		TEST_METHOD(Test_Create_Range)
		{
			const int k = 5, n = 5, Low = -2, High = 2;
			int** a = new int* [k];
			for (int i = 0; i < k; ++i)
				a[i] = new int[n];

			Create(a, k, n, Low, High);

			for (int i = 0; i < k; ++i)
				for (int j = 0; j < n; ++j)
					Assert::IsTrue(a[i][j] >= Low && a[i][j] <= High);

			for (int i = 0; i < k; ++i)
				delete[] a[i];
			delete[] a;
		}

		TEST_METHOD(Test_Print_NoCrash)
		{
			const int k = 2, n = 2;
			int** a = new int* [k];
			for (int i = 0; i < k; ++i)
				a[i] = new int[n];

			a[0][0] = 1; a[0][1] = 2;
			a[1][0] = 3; a[1][1] = 4;

			// Just check that Print does not throw
			try {
				Print(a, k, n);
			}
			catch (...) {
				Assert::Fail(L"Print threw an exception");
			}

			for (int i = 0; i < k; ++i)
				delete[] a[i];
			delete[] a;
		}
	};
}