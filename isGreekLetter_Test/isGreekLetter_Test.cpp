#include "pch.h"
#include "CppUnitTest.h"
#include "../SoftQA_Chupinin_11/ConvertToTEX.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace isGreekLetterTest
{
	TEST_CLASS(isGreekLetterTest)
	{
	public:
		
		TEST_METHOD(TypeTest)
		{
			string str = "pi";
			int expectedResult = 1;

			int result = isGreekLetter(str);

			Assert::AreEqual(expectedResult, result);
		}

		TEST_METHOD(StringIsAtBeginningOfArrayOfLowercaseGreek)
		{
			string str = "alpha";
			int expectedResult = 1;

			int result = isGreekLetter(str);

			Assert::AreEqual(expectedResult, result);
		}

		TEST_METHOD(StringIsAtEndingOfArrayOfLowercaseGreek)
		{
			string str = "omega";
			int expectedResult = 1;

			int result = isGreekLetter(str);

			Assert::AreEqual(expectedResult, result);
		}


		TEST_METHOD(StringIsAtBeginningOfArrayOfCapitalGreekLetter)
		{
			string str = "Alpha";
			int expectedResult = 1;

			int result = isGreekLetter(str);

			Assert::AreEqual(expectedResult, result);
		}

		TEST_METHOD(StringIsAtEndingOfArrayOfCapitalGreekLetter)
		{
			string str = "Omega";
			int expectedResult = 1;

			int result = isGreekLetter(str);

			Assert::AreEqual(expectedResult, result);
		}


		TEST_METHOD(StringIsAtMiddleOfArrayOfCapitalGreekLetter)
		{
			string str = "Pi";
			int expectedResult = 1;

			int result = isGreekLetter(str);

			Assert::AreEqual(expectedResult, result);
		}


		TEST_METHOD(StringIsNotGreekLetter)
		{
			string str = "Pi";
			int expectedResult = 1;

			int result = isGreekLetter(str);

			Assert::AreEqual(expectedResult, result);
		}
	};
}
