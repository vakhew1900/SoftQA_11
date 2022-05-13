#include "pch.h"
#include "CppUnitTest.h"
#include "../SoftQA_Chupinin_11/ConvertToTEX.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace convertOperatorToTexTest
{
	TEST_CLASS(convertOperatorToTexTest)
	{
	public:
		
		TEST_METHOD(TexFormatOfOperatorIsSymbol)
		{
			string str = "+";
			string expectedTexFormat = "+";

			string texFormat = convertOperatorToTex(str);

			Assert::AreEqual(expectedTexFormat, texFormat);
		}

		TEST_METHOD(TexFormatOfOperatorIsFunction)
		{
			string str = "||";
			string expectedTexFormat = "\\vee";

			string texFormat = convertOperatorToTex(str);

			Assert::AreEqual(expectedTexFormat, texFormat);
		}

		TEST_METHOD(TexFormatOfOperatorIsCharSet)
		{
			string str = "..";
			string expectedTexFormat = "..";

			string texFormat = convertOperatorToTex(str);

			Assert::AreEqual(expectedTexFormat, texFormat);
		}


		TEST_METHOD(OperatorIsFunction)
		{
			string str = "sqrt()";
			string expectedTexFormat = "\\sqrt";

			string texFormat = convertOperatorToTex(str);

			Assert::AreEqual(expectedTexFormat, texFormat);
		}

		TEST_METHOD(TypeTest)
		{
			string str = "frac()";
			string expectedTexFormat = "\\frac";

			string texFormat = convertOperatorToTex(str);

			Assert::AreEqual(expectedTexFormat, texFormat);
		}

		TEST_METHOD(OperatorIsCharSet)
		{
			string str = "&&";
			string expectedTexFormat = "\\wedge";

			string texFormat = convertOperatorToTex(str);

			Assert::AreEqual(expectedTexFormat, texFormat);
		}

		TEST_METHOD(OperatorIsChar)
		{
			string str = "&";
			string expectedTexFormat = "\\cap";

			string texFormat = convertOperatorToTex(str);

			Assert::AreEqual(expectedTexFormat, texFormat);
		}
	};
}
