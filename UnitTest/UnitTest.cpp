#include "pch.h"
#include "CppUnitTest.h"
#include "../Lab_05_2.cpp"  
#include <cmath>

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest_Lab05_2
{
	TEST_CLASS(UnitTest_Lab05_2)
	{
	public:

		TEST_METHOD(TestA)
		{
			double x = 3.0;
			int n = 1;
			double R = 1.0 / x;

			double res = A(x, n, R);
			double expected = R * (2.0 * n - 1) / ((2.0 * n + 1) * x * x);

			Assert::AreEqual(expected, res, 1e-10, L"Function A() works incorrectly!");
		}

		TEST_METHOD(TestS)
		{
			double x = 3.0;
			double eps = 1e-6;
			int n = 0;
			double s = 0;

			double result = S(x, eps, n, s);

			double expected = atanh(1.0 / x); // точне значення

			Assert::AreEqual(expected, result, 1e-6, L"Function S() convergence incorrect!");
		}
	};
}
