#include "pch.h"
#include "CppUnitTest.h"
#include "../SoftQA_Chupinin_11/ConvertToTEX.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace isNumberTest
{
	TEST_CLASS(isNumberTest)
	{
	public:
		
		TEST_METHOD(TypeTest)
		{
			string str = "11.5";
			int expectedResult = 1;

			int result = isNumber(str);

			Assert::AreEqual(expectedResult, result);
		}

		TEST_METHOD(PositiveInteger)
		{
			string str = "11";
			int expectedResult = 1;

			int result = isNumber(str);

			Assert::AreEqual(expectedResult, result);
		}


		TEST_METHOD(NegativeInteger)
		{
			string str = "-11";
			int expectedResult = 1;

			int result = isNumber(str);

			Assert::AreEqual(expectedResult, result);
		}

		TEST_METHOD(Negative)
		{
			string str = "-11.5";
			int expectedResult = 1;

			int result = isNumber(str);

			Assert::AreEqual(expectedResult, result);
		}

		TEST_METHOD(Zero)
		{
			string str = "0";
			int expectedResult = 1;

			int result = isNumber(str);

			Assert::AreEqual(expectedResult, result);
		}

		TEST_METHOD(ManySymbolsAfterPoint)
		{
			string str = "11.56789";
			int expectedResult = 1;

			int result = isNumber(str);

			Assert::AreEqual(expectedResult, result);
		}

		TEST_METHOD(OneCharIsNumber)
		{
			string str = "1";
			int expectedResult = 1;

			int result = isNumber(str);

			Assert::AreEqual(expectedResult, result);
		}

		TEST_METHOD(StringContainsLetter)
		{
			string str = "1x1";
			int expectedResult = 0;

			int result = isNumber(str);

			Assert::AreEqual(expectedResult, result);
		}


		TEST_METHOD(StringContainsInvalidMathematicalSymbols)
		{
			string str = "1*1";
			int expectedResult = 0;

			int result = isNumber(str);

			Assert::AreEqual(expectedResult, result);
		}

		TEST_METHOD(StringContainsInvalidPunctuationMarks)
		{
			string str = "1!1";
			int expectedResult = 0;

			int result = isNumber(str);

			Assert::AreEqual(expectedResult, result);
		}


		TEST_METHOD(IntegerWithMaxLength)
		{
			string str = "12345678910121314151";
			int expectedResult = 1;

			int result = isNumber(str);

			Assert::AreEqual(expectedResult, result);
		}

		TEST_METHOD(FloatWithMaxLength)
		{
			string str = "1234567891012131415.1";
			int expectedResult = 1;

			int result = isNumber(str);

			Assert::AreEqual(expectedResult, result);
		}

		TEST_METHOD(StringHaveLengthThatMoreMaxAndItInteger)
		{
			string str = "12345678910111213141516";
			int expectedResult = 0;

			int result = isNumber(str);

			Assert::AreEqual(expectedResult, result);
		}

		TEST_METHOD(StringHaveLengthThatMoreMaxAndItFloat)
		{
			string str = "1234567891011121314151.6";
			int expectedResult = 0;

			int result = isNumber(str);

			Assert::AreEqual(expectedResult, result);
		}
	};
}
