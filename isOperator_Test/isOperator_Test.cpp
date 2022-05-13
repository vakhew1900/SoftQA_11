#include "pch.h"
#include "CppUnitTest.h"
#include "../SoftQA_Chupinin_11/ConvertToTEX.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace isOperatorTest
{
	TEST_CLASS(isOperatorTest)
	{
	public:
		
		TEST_METHOD(TestMethodStringIsNotOperator)
		{
			string str = "str";
			int expectedResult = -1;

			int result = isOperator(str);

			Assert::AreEqual(expectedResult, result);
		}

		TEST_METHOD(StringIsOperatorWithOneOperand)
		{
			string str = "all()";
			int expectedResult = 1;

			int result = isOperator(str);

			Assert::AreEqual(expectedResult, result);
		}

		TEST_METHOD(StringIsOperatorWithTwoOperands)
		{
			string str = "=";
			int expectedResult = 2;

			int result = isOperator(str);

			Assert::AreEqual(expectedResult, result);
		}

		TEST_METHOD(StringIsOperatorWithThreeOperands)
		{
			string str = "summator()";
			int expectedResult = 3;

			int result = isOperator(str);

			Assert::AreEqual(expectedResult, result);
		}

		TEST_METHOD(StringIsAtBeginningOfListOfArrayOfOperatorsWithOneOperand)
		{
			string str = "!";
			int expectedResult = 1;

			int result = isOperator(str);

			Assert::AreEqual(expectedResult, result);
		}

		TEST_METHOD(StringIsAtBeginningOfListOfArrayOfOperatorsWithTwoOperands)
		{
			string str = "+";
			int expectedResult = 2;

			int result = isOperator(str);

			Assert::AreEqual(expectedResult, result);
		}


		TEST_METHOD(StringIsAtEndingOfListOfArrayOfOperatorsWithOneOperand)
		{
			string str = "exist()";
			int expectedResult = 1;

			int result = isOperator(str);

			Assert::AreEqual(expectedResult, result);
		}

		TEST_METHOD(StringIsAtEndingOfListOfArrayOfOperatorsWithTwoOperands)
		{
			string str = "frac()";
			int expectedResult = 2;

			int result = isOperator(str);

			Assert::AreEqual(expectedResult, result);
		}

		TEST_METHOD(StringIsPartOfOperator)
		{
			string str = "frac";
			int expectedResult = -1;

			int result = isOperator(str);

			Assert::AreEqual(expectedResult, result);
		}

	};
}
