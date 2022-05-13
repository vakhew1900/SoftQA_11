#include "pch.h"
#include "CppUnitTest.h"
#include "../SoftQA_Chupinin_11/ConvertToTEX.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace isVarTest
{
	TEST_CLASS(isVarTest)
	{
	public:
		
		TEST_METHOD(TypeTest)
		{
			string str = "var";
			int expectedResult = 1;

			int result = isVar(str);

			Assert::AreEqual(expectedResult, result);
		}

		TEST_METHOD(VariableContainsDigits)
		{
			string str = "var1";
			int expectedResult = 1;

			int result = isVar(str);

			Assert::AreEqual(expectedResult, result);
		}

		TEST_METHOD(VariableContainsUnderscore)
		{
			string str = "var_name";
			int expectedResult = 1;

			int result = isVar(str);

			Assert::AreEqual(expectedResult, result);
		}


		TEST_METHOD(VariableContainsUnderscoreAndDigit)
		{
			string str = "var_name1";
			int expectedResult = 1;

			int result = isVar(str);

			Assert::AreEqual(expectedResult, result);
		}

		TEST_METHOD(StringContainsInvalidCharacterForVariableAtBeginningOfString)
		{
			string str = "$var";
			int expectedResult = 0;

			int result = isVar(str);

			Assert::AreEqual(expectedResult, result);
		}

		TEST_METHOD(StringContainsInvalidCharacterForVariableAtMiddleOfString)
		{
			string str = "var$name";
			int expectedResult = 0;

			int result = isVar(str);

			Assert::AreEqual(expectedResult, result);
		}

		TEST_METHOD(StringContainsInvalidCharacterForVariableAtEndingOfString)
		{
			string str = "var$";
			int expectedResult = 0;

			int result = isVar(str);

			Assert::AreEqual(expectedResult, result);
		}

		TEST_METHOD(FirstCharacterOfStringIsDigit)
		{
			string str = "1var";
			int expectedResult = 0;

			int result = isVar(str);

			Assert::AreEqual(expectedResult, result);
		}

		TEST_METHOD(VariableConsistsOfOneCharacter)
		{
			string str = "x";
			int expectedResult = 1;

			int result = isVar(str);

			Assert::AreEqual(expectedResult, result);
		}


		TEST_METHOD(LengthOfStringIsGreaterThanAllowedValues)
		{
			string str = "this_name_var_is_very_big";
			int expectedResult = 0;

			int result = isVar(str);

			Assert::AreEqual(expectedResult, result);
		}


		TEST_METHOD(StringContainsCapitalLetters)
		{
			string str = "Var";
			int expectedResult = 1;

			int result = isVar(str);

			Assert::AreEqual(expectedResult, result);
		}
	};
}
