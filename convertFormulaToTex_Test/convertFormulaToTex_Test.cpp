#include "pch.h"
#include "CppUnitTest.h"
#include "../SoftQA_Chupinin_11/convertTreeToTEX.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace convertFormulaToTexTest
{
	TEST_CLASS(convertFormulaToTexTest)
	{
	public:
		
		TEST_METHOD(TypeTest)
		{
			string reversePolishEntry = "A B ||";
			string expectedTexFormula = "$ A \\vee B $";

			string texFormula = convertFormulaToTex(reversePolishEntry);

			Assert::AreEqual(expectedTexFormula, texFormula);
		}

		TEST_METHOD(ZeroOperators)
		{
			string reversePolishEntry = "A";
			string expectedTexFormula = "$ A $";

			string texFormula = convertFormulaToTex(reversePolishEntry);

			Assert::AreEqual(expectedTexFormula, texFormula);
		}

		TEST_METHOD(OneOfOperandsIsGreekLetter)
		{
			string reversePolishEntry = "alpha B ||";
			string expectedTexFormula = "$ \\alpha \\vee B $";

			string texFormula = convertFormulaToTex(reversePolishEntry);

			Assert::AreEqual(expectedTexFormula, texFormula);
		}


		TEST_METHOD(OneOfOperandsIsNumber)
		{
			string reversePolishEntry = "11.5 B ||";
			string expectedTexFormula = "$ 11.5 \\vee B $";

			string texFormula = convertFormulaToTex(reversePolishEntry);

			Assert::AreEqual(expectedTexFormula, texFormula);
		}

		TEST_METHOD(OperatorWithOneOperand)
		{
			string reversePolishEntry = "B !";
			string expectedTexFormula = "$ \\overline {B} $";

			string texFormula = convertFormulaToTex(reversePolishEntry);

			Assert::AreEqual(expectedTexFormula, texFormula);
		}

		TEST_METHOD(OperatorWithThreeOperands)
		{
			string reversePolishEntry = "A B C summator()";
			string expectedTexFormula = "$ \\sum_ {A} ^ {B} {C} $";

			string texFormula = convertFormulaToTex(reversePolishEntry);

			Assert::AreEqual(expectedTexFormula, texFormula);
		}

		TEST_METHOD(OperatorWithThreeOperandsThereAreGreekLetterNumber)
		{
			string reversePolishEntry = "alpha B 11.5 summator()";
			string expectedTexFormula = "$ \\sum_ {\\alpha} ^ {B} {11.5} $";

			string texFormula = convertFormulaToTex(reversePolishEntry);

			Assert::AreEqual(expectedTexFormula, texFormula);
		}

		TEST_METHOD(TwoOperandsWithOnePrioritet)
		{
			string reversePolishEntry = "A B || C ||";
			string expectedTexFormula = "$ A \\vee B \\vee C $";

			string texFormula = convertFormulaToTex(reversePolishEntry);

			Assert::AreEqual(expectedTexFormula, texFormula);
		}
		TEST_METHOD(TwoOperandsWithDifferentPrioritetAndOperatorWithLowePrioritetisExecuteLater)
		{
			string reversePolishEntry = "A B / C +";
			string expectedTexFormula = "$ A \\div B + C $";

			string texFormula = convertFormulaToTex(reversePolishEntry);

			Assert::AreEqual(expectedTexFormula, texFormula);
		}

		TEST_METHOD(TwoOperandsWithDifferentPrioritetAndOperatorWithLowePrioritetisExecuteEalier)
		{
			string reversePolishEntry = "A B + C *";
			string expectedTexFormula = "$ (A + B) \\cdot C $";

			string texFormula = convertFormulaToTex(reversePolishEntry);

			Assert::AreEqual(expectedTexFormula, texFormula);
		}

		TEST_METHOD(theOperatorConsistsOfOneCharacter)
		{
			string reversePolishEntry = "A B +";
			string expectedTexFormula = "$ A + B $";

			string texFormula = convertFormulaToTex(reversePolishEntry);

			Assert::AreEqual(expectedTexFormula, texFormula);
		}

		TEST_METHOD(OperatorIsFunctionIn—Format)
		{
			string reversePolishEntry = "A B in()";
			string expectedTexFormula = "$ A \\in B $";

			string texFormula = convertFormulaToTex(reversePolishEntry);

			Assert::AreEqual(expectedTexFormula, texFormula);
		}


		TEST_METHOD(OperatorInTexFormatIsSymbol)
		{
			string reversePolishEntry = "A B -";
			string expectedTexFormula = "$ A - B $";

			string texFormula = convertFormulaToTex(reversePolishEntry);

			Assert::AreEqual(expectedTexFormula, texFormula);
		}



		TEST_METHOD(OperatorInTexFormatIsSetOfCharacters)
		{
			string reversePolishEntry = "A B ..";
			string expectedTexFormula = "$ A .. B $";

			string texFormula = convertFormulaToTex(reversePolishEntry);

			Assert::AreEqual(expectedTexFormula, texFormula);
		}


		TEST_METHOD(ComplexTest1)
		{
			string reversePolishEntry = "i 1 = n a x i _ y i _ + * summator() 256 12.271 a / +- x 3 pow() - = ";
			string expectedTexFormula = "$ \\sum_ {i = 1} ^ {n} {a \\cdot (x _ i + y _ i)} = 256 \\pm 12.271 \\div a - x ^ {3} $";

			string texFormula = convertFormulaToTex(reversePolishEntry);

			Assert::AreEqual(expectedTexFormula, texFormula);
		}

		TEST_METHOD(ComplexTest2)
		{
			string reversePolishEntry = "A all() B in() A exist() B & 1 = B C A | noin() && || 1 2 , 100 .. || ";
			string expectedTexFormula = "$ \\forall {A} \\in B \\vee \\exists {A} \\cap B = 1 \\wedge B \\notin (C \\cup A) \\vee (1 , 2 .. 100) $";

			string texFormula = convertFormulaToTex(reversePolishEntry);

			Assert::AreEqual(expectedTexFormula, texFormula);
		}

		TEST_METHOD(ExpressOfOperands)
		{
			string reversePolishEntry = "a b c +";
			Exception expectedException = EXCESS_OF_OPERANDS_EXCEPTION;
			Exception exception = EMPTY_STRING_EXCEPTION;

			try {
				string texFormula = convertFormulaToTex(reversePolishEntry);
			}
			catch (Exception actualException) {

				exception = actualException;
			}


			Assert::IsTrue(expectedException == exception);
		}
	};
}
