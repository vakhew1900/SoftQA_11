#include "pch.h"
#include "CppUnitTest.h"
#include "../SoftQA_Chupinin_11/convertTreeToTEX.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace convertSubFornulaToTexTest
{
	TEST_CLASS(convertSubFornulaToTexTest)
	{
	public:
		
		TEST_METHOD(TypeTest)
		{
			vector<string> reversePolishEntryElements = { "A", "B", "||" };
			string expectedTexFormula = "A \\vee B";

			ExpressionTree* tree = NULL;
			tree = convertReversePolishEntryToTree(reversePolishEntryElements);
			int maxPriority = 0;

			string texFormula = convertSubFormulaToTex(tree, maxPriority);

			Assert::AreEqual(expectedTexFormula, texFormula);
		}

		TEST_METHOD(ZeroOperators)
		{
			vector<string> reversePolishEntryElements = { "A" };
			string expectedTexFormula = "A";

			ExpressionTree* tree = NULL;
			tree = convertReversePolishEntryToTree(reversePolishEntryElements);
			int maxPriority = 0;

			string texFormula = convertSubFormulaToTex(tree, maxPriority);

			Assert::AreEqual(expectedTexFormula, texFormula);
		}

		TEST_METHOD(OneOfOperandsIsGreekLetter)
		{
			vector<string> reversePolishEntryElements = { "alpha", "B", "||" };
			string expectedTexFormula = "\\alpha \\vee B";

			ExpressionTree* tree = NULL;
			tree = convertReversePolishEntryToTree(reversePolishEntryElements);
			int maxPriority = 0;

			string texFormula = convertSubFormulaToTex(tree, maxPriority);

			Assert::AreEqual(expectedTexFormula, texFormula);
		}


		TEST_METHOD(OneOfOperandsIsNumber)
		{
			vector<string> reversePolishEntryElements = { "11.5", "B", "||" };
			string expectedTexFormula = "11.5 \\vee B";

			ExpressionTree* tree = NULL;
			tree = convertReversePolishEntryToTree(reversePolishEntryElements);
			int maxPriority = 0;

			string texFormula = convertSubFormulaToTex(tree, maxPriority);

			Assert::AreEqual(expectedTexFormula, texFormula);
		}

		TEST_METHOD(OperatorWithOneOperand)
		{
			vector<string> reversePolishEntryElements = { "B", "!" };
			string expectedTexFormula = "\\overline {B}";

			ExpressionTree* tree = NULL;
			tree = convertReversePolishEntryToTree(reversePolishEntryElements);
			int maxPriority = 0;

			string texFormula = convertSubFormulaToTex(tree, maxPriority);

			Assert::AreEqual(expectedTexFormula, texFormula);
		}

		TEST_METHOD(OperatorWithThreeOperands)
		{
			vector<string> reversePolishEntryElements = { "A", "B", "C", "summator()" };
			string expectedTexFormula = "\\sum_ {A} ^ {B} {C}";

			ExpressionTree* tree = NULL;
			tree = convertReversePolishEntryToTree(reversePolishEntryElements);
			int maxPriority = 0;

			string texFormula = convertSubFormulaToTex(tree, maxPriority);

			Assert::AreEqual(expectedTexFormula, texFormula);
		}

		TEST_METHOD(OperatorWithThreeOperandsThereAreGreekLetterNumber)
		{
			vector<string> reversePolishEntryElements = { "alpha", "B", "11.5", "summator()" };
			string expectedTexFormula = "\\sum_ {\\alpha} ^ {B} {11.5}";

			ExpressionTree* tree = NULL;
			tree = convertReversePolishEntryToTree(reversePolishEntryElements);
			int maxPriority = 0;

			string texFormula = convertSubFormulaToTex(tree, maxPriority);

			Assert::AreEqual(expectedTexFormula, texFormula);
		}

		TEST_METHOD(TwoOperandsWithOnePrioritet)
		{
			vector<string> reversePolishEntryElements = { "A", "B", "||", "C", "||" };
			string expectedTexFormula = "A \\vee B \\vee C";

			ExpressionTree* tree = NULL;
			tree = convertReversePolishEntryToTree(reversePolishEntryElements);
			int maxPriority = 0;

			string texFormula = convertSubFormulaToTex(tree, maxPriority);

			Assert::AreEqual(expectedTexFormula, texFormula);
		}
		TEST_METHOD(TwoOperandsWithDifferentPrioritetAndOperatorWithLowePrioritetisExecuteLater)
		{
			vector<string> reversePolishEntryElements = { "A", "B", "/", "C", "+" };
			string expectedTexFormula = "A \\div B + C";

			ExpressionTree* tree = NULL;
			tree = convertReversePolishEntryToTree(reversePolishEntryElements);
			int maxPriority = 0;

			string texFormula = convertSubFormulaToTex(tree, maxPriority);

			Assert::AreEqual(expectedTexFormula, texFormula);
		}

		TEST_METHOD(TwoOperandsWithDifferentPrioritetAndOperatorWithLowePrioritetisExecuteEalier)
		{
			vector<string> reversePolishEntryElements = { "A", "B", "+", "C", "*" };
			string expectedTexFormula = "(A + B) \\cdot C";

			ExpressionTree* tree = NULL;
			tree = convertReversePolishEntryToTree(reversePolishEntryElements);
			int maxPriority = 0;

			string texFormula = convertSubFormulaToTex(tree, maxPriority);

			Assert::AreEqual(expectedTexFormula, texFormula);
		}

		TEST_METHOD(theOperatorConsistsOfOneCharacter)
		{
			vector<string> reversePolishEntryElements = { "A", "B", "+" };
			string expectedTexFormula = "A + B";

			ExpressionTree* tree = NULL;
			tree = convertReversePolishEntryToTree(reversePolishEntryElements);
			int maxPriority = 0;

			string texFormula = convertSubFormulaToTex(tree, maxPriority);

			Assert::AreEqual(expectedTexFormula, texFormula);
		}



		TEST_METHOD(OperatorIsFunctionIn—Format)
		{
			vector<string> reversePolishEntryElements = { "A", "B", "in()" };
			string expectedTexFormula = "A \\in B";

			ExpressionTree* tree = NULL;
			tree = convertReversePolishEntryToTree(reversePolishEntryElements);
			int maxPriority = 0;

			string texFormula = convertSubFormulaToTex(tree, maxPriority);

			Assert::AreEqual(expectedTexFormula, texFormula);
		}


		TEST_METHOD(OperatorInTexFormatIsSymbol)
		{
			vector<string> reversePolishEntryElements = { "A", "B", "-" };
			string expectedTexFormula = "A - B";

			ExpressionTree* tree = NULL;
			tree = convertReversePolishEntryToTree(reversePolishEntryElements);
			int maxPriority = 0;

			string texFormula = convertSubFormulaToTex(tree, maxPriority);

			Assert::AreEqual(expectedTexFormula, texFormula);
		}



		TEST_METHOD(OperatorInTexFormatIsSetOfCharacters)
		{
			vector<string> reversePolishEntryElements = { "A", "B", ".." };
			string expectedTexFormula = "A .. B";

			ExpressionTree* tree = NULL;
			tree = convertReversePolishEntryToTree(reversePolishEntryElements);
			int maxPriority = 0;

			string texFormula = convertSubFormulaToTex(tree, maxPriority);

			Assert::AreEqual(expectedTexFormula, texFormula);
		}



		TEST_METHOD(MultiplicationOfTwoVariableOfDifferentLength)
		{
			vector<string> reversePolishEntryElements = { "ABC", "B", "*" };
			string expectedTexFormula = "ABC \\cdot B";

			ExpressionTree* tree = NULL;
			tree = convertReversePolishEntryToTree(reversePolishEntryElements);
			int maxPriority = 0;

			string texFormula = convertSubFormulaToTex(tree, maxPriority);

			Assert::AreEqual(expectedTexFormula, texFormula);
		}


		TEST_METHOD(MultiplicationOfNumberAndVariable)
		{
			vector<string> reversePolishEntryElements = { "10", "A", "*" };
			string expectedTexFormula = "10A";

			ExpressionTree* tree = NULL;
			tree = convertReversePolishEntryToTree(reversePolishEntryElements);
			int maxPriority = 0;

			string texFormula = convertSubFormulaToTex(tree, maxPriority);

			Assert::AreEqual(expectedTexFormula, texFormula);
		}

		TEST_METHOD(MultiplicationOfVariableAndNumber)
		{
			vector<string> reversePolishEntryElements = { "A", "10", "*" };
			string expectedTexFormula = "10A";

			ExpressionTree* tree = NULL;
			tree = convertReversePolishEntryToTree(reversePolishEntryElements);
			int maxPriority = 0;

			string texFormula = convertSubFormulaToTex(tree, maxPriority);

			Assert::AreEqual(expectedTexFormula, texFormula);
		}
		TEST_METHOD(MultiplicationOfNumberAndGreekLetter)
		{
			vector<string> reversePolishEntryElements = { "alpha", "10", "*" };
			string expectedTexFormula = "10\\alpha";

			ExpressionTree* tree = NULL;
			tree = convertReversePolishEntryToTree(reversePolishEntryElements);
			int maxPriority = 0;

			string texFormula = convertSubFormulaToTex(tree, maxPriority);

			Assert::AreEqual(expectedTexFormula, texFormula);
		}

		TEST_METHOD(ComplexTest1)
		{
			vector<string> reversePolishEntryElements = { "i", "1", "=", "n", "a", "x", "i", "_", "y", "i", "_", "+", "*", "summator()", "256", "12.271", "a", "/", "+-", "x", "3", "pow()", "-", "=" };
			string expectedTexFormula = "\\sum_ {i = 1} ^ {n} {a \\cdot (x _ i + y _ i)} = 256 \\pm 12.271 \\div a - x ^ {3}";

			ExpressionTree* tree = NULL;
			tree = convertReversePolishEntryToTree(reversePolishEntryElements);
			int maxPriority = 0;

			string texFormula = convertSubFormulaToTex(tree, maxPriority);

			Assert::AreEqual(expectedTexFormula, texFormula);
		}

		TEST_METHOD(ComplexTest2)
		{
			vector<string> reversePolishEntryElements = { "A", "all()", "B", "in()", "A", "exist()", "B", "&", "1", "=", "B", "C", "A", "|", "noin()", "&&", "||", "1", "2", ",", "100", "..", "||" };
			string expectedTexFormula = "\\forall {A} \\in B \\vee \\exists {A} \\cap B = 1 \\wedge B \\notin (C \\cup A) \\vee (1 , 2 .. 100)";

			ExpressionTree* tree = NULL;
			tree = convertReversePolishEntryToTree(reversePolishEntryElements);
			int maxPriority = 0;

			string texFormula = convertSubFormulaToTex(tree, maxPriority);

			Assert::AreEqual(expectedTexFormula, texFormula);
		}


		TEST_METHOD(SumWithNegative)
		{
			vector<string> reversePolishEntryElements = { "a",  "-2", "+" };
			string expectedTexFormula = "a + (-2)";
			ExpressionTree* tree = NULL;
			tree = convertReversePolishEntryToTree(reversePolishEntryElements);
			int maxPriority = 0;

			string texFormula = convertSubFormulaToTex(tree, maxPriority);

			Assert::AreEqual(expectedTexFormula, texFormula);
		}


		TEST_METHOD(MulWithNegative)
		{
			vector<string> reversePolishEntryElements = { "a",  "-2", "*" };
			string expectedTexFormula = "-2a";
			ExpressionTree* tree = NULL;
			tree = convertReversePolishEntryToTree(reversePolishEntryElements);
			int maxPriority = 0;

			string texFormula = convertSubFormulaToTex(tree, maxPriority);

			Assert::AreEqual(expectedTexFormula, texFormula);
		}

		TEST_METHOD(PowWithNegative)
		{
			vector<string> reversePolishEntryElements = { "-1",  "-2", "pow()" };
			string expectedTexFormula = "(-1) ^ {-2}";
			ExpressionTree* tree = NULL;
			tree = convertReversePolishEntryToTree(reversePolishEntryElements);
			int maxPriority = 0;

			string texFormula = convertSubFormulaToTex(tree, maxPriority);

			Assert::AreEqual(expectedTexFormula, texFormula);
		}
		

		TEST_METHOD(SeveralOperandsWithNegativeAndValue)
		{
			vector<string> reversePolishEntryElements = { "a", "-1", "b", "*", "+"};
			string expectedTexFormula = "a + (-1b)";
			ExpressionTree* tree = NULL;
			tree = convertReversePolishEntryToTree(reversePolishEntryElements);
			int maxPriority = 0;

			string texFormula = convertSubFormulaToTex(tree, maxPriority);

			Assert::AreEqual(expectedTexFormula, texFormula);
		}


		TEST_METHOD(SeveralOperandsWithTwoNegative)
		{
			vector<string> reversePolishEntryElements = { "a", "-1", "2", "*", "+" };
			string expectedTexFormula = "a + (-1) \\cdot 2";
			ExpressionTree* tree = NULL;
			tree = convertReversePolishEntryToTree(reversePolishEntryElements);
			int maxPriority = 0;

			string texFormula = convertSubFormulaToTex(tree, maxPriority);

			Assert::AreEqual(expectedTexFormula, texFormula);
		}

		TEST_METHOD(Fraction)
		{
			vector<string> reversePolishEntryElements = { "a", "b", "frac()"};
			string expectedTexFormula = "\\frac { a } { b }";
			ExpressionTree* tree = NULL;
			tree = convertReversePolishEntryToTree(reversePolishEntryElements);
			int maxPriority = 0;

			string texFormula = convertSubFormulaToTex(tree, maxPriority);

			Assert::AreEqual(expectedTexFormula, texFormula);
		}

		TEST_METHOD(FractionWithComplexNumeratorAndMarker)
		{
			vector<string> reversePolishEntryElements = { "a", "b", "+", "10", "a", "*", "frac()" };
			string expectedTexFormula = "\\frac { a + b } { 10a }";
			ExpressionTree* tree = NULL;
			tree = convertReversePolishEntryToTree(reversePolishEntryElements);
			int maxPriority = 0;

			string texFormula = convertSubFormulaToTex(tree, maxPriority);

			Assert::AreEqual(expectedTexFormula, texFormula);
		}


		TEST_METHOD(Sqrt)
		{
			vector<string> reversePolishEntryElements = { "a", "b", "sqrt()"};
			string expectedTexFormula = "\\sqrt [ a ] { b }";
			ExpressionTree* tree = NULL;
			tree = convertReversePolishEntryToTree(reversePolishEntryElements);
			int maxPriority = 0;

			string texFormula = convertSubFormulaToTex(tree, maxPriority);

			Assert::AreEqual(expectedTexFormula, texFormula);
		}


		TEST_METHOD(SqrtWithComplexOperands)
		{
			vector<string> reversePolishEntryElements = { "a", "b", "+", "c", "d", "+", "sqrt()" };
			string expectedTexFormula = "\\sqrt [ a + b ] { c + d }";
			ExpressionTree* tree = NULL;
			tree = convertReversePolishEntryToTree(reversePolishEntryElements);
			int maxPriority = 0;

			string texFormula = convertSubFormulaToTex(tree, maxPriority);

			Assert::AreEqual(expectedTexFormula, texFormula);
		}


		TEST_METHOD(SqrtFirstOperandIs2)
		{
			vector<string> reversePolishEntryElements = { "2", "b", "sqrt()" };
			string expectedTexFormula = "\\sqrt { b }";
			ExpressionTree* tree = NULL;
			tree = convertReversePolishEntryToTree(reversePolishEntryElements);
			int maxPriority = 0;

			string texFormula = convertSubFormulaToTex(tree, maxPriority);

			Assert::AreEqual(expectedTexFormula, texFormula);
		}

	};
}
