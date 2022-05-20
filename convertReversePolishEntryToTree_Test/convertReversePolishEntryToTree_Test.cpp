#include "pch.h"
#include "CppUnitTest.h"
#include "../SoftQA_Chupinin_11/convertTreeToTEX.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace convertReversePolishEntryToTreeTest
{
	TEST_CLASS(convertReversePolishEntryToTreeTest)
	{
	public:
		
		string treeToReversePolishEntry(ExpressionTree* tree) {

			string result;
			bool first = 0;
			for (int i = 0; i < tree->getOperandsCount(); i++) {
				if (!first)
				{
					result += treeToReversePolishEntry(tree->getChild(i));
					first = 1;
				}
				else
				{
					result += " " + treeToReversePolishEntry(tree->getChild(i));
				}
			}

			if (!first)
			{
				result += tree->getValue();
			}
			else
			{
				result += " " + tree->getValue();
			}

			return result;
		}

		TEST_METHOD(TypeTest)
		{
			vector <string> reversePolishEntryElements = { "A", "B", "||" };
			string expectedResult = "A B ||";

			ExpressionTree* tree;

			tree = convertReversePolishEntryToTree(reversePolishEntryElements);

			string result = treeToReversePolishEntry(tree);
			Assert::AreEqual(expectedResult, result);
		}


		TEST_METHOD(ZeroOperators)
		{
			vector<string> reversePolishEntryElements = { "A" };
			string expectedResult = "A";

			ExpressionTree* tree;

			tree = convertReversePolishEntryToTree(reversePolishEntryElements);

			string result = treeToReversePolishEntry(tree);
			Assert::AreEqual(expectedResult, result);

		}

		TEST_METHOD(OneOfOperandsIsGreekLetter)
		{
			vector<string> reversePolishEntryElements = { "alpha", "B", "||" };
			string expectedResult = "alpha B ||";

			ExpressionTree* tree;

			tree = convertReversePolishEntryToTree(reversePolishEntryElements);

			string result = treeToReversePolishEntry(tree);
			Assert::AreEqual(expectedResult, result);
		}


		TEST_METHOD(OneOfOperandsIsNumber)
		{
			vector<string> reversePolishEntryElements = { "11.5", "B", "||" };
			string expectedResult = "11.5 B ||";

			ExpressionTree* tree;

			tree = convertReversePolishEntryToTree(reversePolishEntryElements);

			string result = treeToReversePolishEntry(tree);
			Assert::AreEqual(expectedResult, result);
		}

		TEST_METHOD(OperatorWithOneOperand)
		{
			vector<string> reversePolishEntryElements = { "B", "!" };
			string expectedResult = "B !";

			ExpressionTree* tree;

			tree = convertReversePolishEntryToTree(reversePolishEntryElements);

			string result = treeToReversePolishEntry(tree);
			Assert::AreEqual(expectedResult, result);
		}

		TEST_METHOD(OperatorWithThreeOperands)
		{
			vector<string> reversePolishEntryElements = { "A", "B", "C", "summator()" };
			string expectedResult = "A B C summator()";

			ExpressionTree* tree;

			tree = convertReversePolishEntryToTree(reversePolishEntryElements);

			string result = treeToReversePolishEntry(tree);
			Assert::AreEqual(expectedResult, result);
		}

		TEST_METHOD(OperatorWithThreeOperandsThereAreGreekLetterNumber)
		{
			vector<string> reversePolishEntryElements = { "alpha", "B", "11.5", "summator()" };
			string expectedResult = "alpha B 11.5 summator()";

			ExpressionTree* tree;

			tree = convertReversePolishEntryToTree(reversePolishEntryElements);

			string result = treeToReversePolishEntry(tree);
			Assert::AreEqual(expectedResult, result);
		}

		TEST_METHOD(TwoOperandsWithOnePrioritet)
		{
			vector<string> reversePolishEntryElements = { "A", "B", "||", "C", "||" };
			string expectedResult = "A B || C ||";

			ExpressionTree* tree;

			tree = convertReversePolishEntryToTree(reversePolishEntryElements);

			string result = treeToReversePolishEntry(tree);
			Assert::AreEqual(expectedResult, result);
		}
		TEST_METHOD(TwoOperandsWithDifferentPrioritetAndOperatorWithLowePrioritetisExecuteLater)
		{
			vector<string> reversePolishEntryElements = { "A", "B", "/", "C", "+" };
			string expectedResult = "A B / C +";

			ExpressionTree* tree;

			tree = convertReversePolishEntryToTree(reversePolishEntryElements);

			string result = treeToReversePolishEntry(tree);
			Assert::AreEqual(expectedResult, result);
		}

		TEST_METHOD(TwoOperandsWithDifferentPrioritetAndOperatorWithLowePrioritetisExecuteEalier)
		{
			vector<string> reversePolishEntryElements = { "A", "B", "+", "C", "*" };
			string expectedResult = "A B + C *";

			ExpressionTree* tree;

			tree = convertReversePolishEntryToTree(reversePolishEntryElements);

			string result = treeToReversePolishEntry(tree);
			Assert::AreEqual(expectedResult, result);
		}

		TEST_METHOD(theOperatorConsistsOfOneCharacter)
		{
			vector<string> reversePolishEntryElements = { "A", "B", "+" };
			string expectedResult = "A B +";

			ExpressionTree* tree;

			tree = convertReversePolishEntryToTree(reversePolishEntryElements);

			string result = treeToReversePolishEntry(tree);
			Assert::AreEqual(expectedResult, result);
		}



		TEST_METHOD(OperatorIsFunctionIn—Format)
		{
			vector<string> reversePolishEntryElements = { "A", "B", "in()" };
			string expectedResult = "A B in()";

			ExpressionTree* tree;

			tree = convertReversePolishEntryToTree(reversePolishEntryElements);

			string result = treeToReversePolishEntry(tree);
			Assert::AreEqual(expectedResult, result);
		}


		TEST_METHOD(OperatorInTexFormatIsSymbol)
		{
			vector<string> reversePolishEntryElements = { "A", "B", "-" };
			string expectedResult = "A B -";

			ExpressionTree* tree;

			tree = convertReversePolishEntryToTree(reversePolishEntryElements);

			string result = treeToReversePolishEntry(tree);
			Assert::AreEqual(expectedResult, result);
		}



		TEST_METHOD(OperatorInTexFormatIsSetOfCharacters)
		{
			vector<string> reversePolishEntryElements = { "A", "B", ".." };
			string expectedResult = "A B ..";

			ExpressionTree* tree;

			tree = convertReversePolishEntryToTree(reversePolishEntryElements);

			string result = treeToReversePolishEntry(tree);
			Assert::AreEqual(expectedResult, result);
		}



		TEST_METHOD(ComplexTest1)
		{
			vector<string> reversePolishEntryElements = { "i", "1", "=", "n", "a", "x", "i", "_", "y", "i", "_", "+", "*", "summator()", "256", "12.271", "a", "/", "+-", "x", "3", "pow()", "-", "=" };
			string expectedResult = "i 1 = n a x i _ y i _ + * summator() 256 12.271 a / +- x 3 pow() - =";

			ExpressionTree* tree;

			tree = convertReversePolishEntryToTree(reversePolishEntryElements);

			string result = treeToReversePolishEntry(tree);
			Assert::AreEqual(expectedResult, result);
		}
	};
}
