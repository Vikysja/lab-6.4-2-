#include "pch.h"
#include "CppUnitTest.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest642
{
	TEST_CLASS(UnitTest642)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			const  int n = 10;
			int a[n] = { 1 , -2 , 4 , 5 , -5 , -10 , 4 , 5 , 7 , 0 };
			int maxIndex = 0;
			findMaxAbs(a, n, maxIndex, 0);

			Assert::AreEqual(5, maxIndex);
		}
	};
}
