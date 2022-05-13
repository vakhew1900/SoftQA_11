#include "pch.h"
#include "CppUnitTest.h"
#include "../SoftQA_Chupinin_11/ConvertToTEX.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace getPriorityOfOperatorTest
{
	TEST_CLASS(getPriorityOfOperatorTest)
	{
	public:
		
		TEST_METHOD(StringIsNotOperator)
		{
			string str = "string";

			int expectedResult = -1;

			int result = getPriorityOfOperator(str);

			Assert::AreEqual(expectedResult, result);
		}

		TEST_METHOD(PriorityIs0)
		{
			string str = "exist()";

			int expectedResult = 0;

			int result = getPriorityOfOperator(str);

			Assert::AreEqual(expectedResult, result);
		}

		TEST_METHOD(PriorityIs1)
		{
			string str = "in()";

			int expectedResult = 1;

			int result = getPriorityOfOperator(str);

			Assert::AreEqual(expectedResult, result);
		}

		TEST_METHOD(PriorityIs2)
		{
			string str = "pow()";

			int expectedResult = 2;

			int result = getPriorityOfOperator(str);

			Assert::AreEqual(expectedResult, result);
		}

		TEST_METHOD(PriorityIs3)
		{
			string str = "%";

			int expectedResult = 3;

			int result = getPriorityOfOperator(str);

			Assert::AreEqual(expectedResult, result);
		}

		TEST_METHOD(PriorityIs4)
		{
			string str = "+-";

			int expectedResult = 4;

			int result = getPriorityOfOperator(str);

			Assert::AreEqual(expectedResult, result);
		}

		TEST_METHOD(PriorityIs5)
		{
			string str = "<=";

			int expectedResult = 5;

			int result = getPriorityOfOperator(str);

			Assert::AreEqual(expectedResult, result);
		}

		TEST_METHOD(PriorityIs6)
		{
			string str = "=";

			int expectedResult = 6;

			int result = getPriorityOfOperator(str);

			Assert::AreEqual(expectedResult, result);
		}


		TEST_METHOD(PriorityIs7)
		{
			string str = "&&";

			int expectedResult = 7;

			int result = getPriorityOfOperator(str);

			Assert::AreEqual(expectedResult, result);
		}


		TEST_METHOD(PriorityIs8)
		{
			string str = "||";

			int expectedResult = 8;

			int result = getPriorityOfOperator(str);

			Assert::AreEqual(expectedResult, result);
		}

		TEST_METHOD(PriorityIs9)
		{
			string str = ",";

			int expectedResult = 9;

			int result = getPriorityOfOperator(str);

			Assert::AreEqual(expectedResult, result);
		}
	};
}
