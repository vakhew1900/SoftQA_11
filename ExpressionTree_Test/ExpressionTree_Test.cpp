#include "pch.h"
#include "CppUnitTest.h"
#include "../SoftQA_Chupinin_11/ExpressionTree.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace ExpressionTreeTest
{
	TEST_CLASS(ExpressionTreeTest)
	{
	public:
		
		TEST_METHOD(StringIsVariable)
		{
			string str = "var";
			ExpressionElementType expectedElementType = VAR;
			ExpressionTree* tree = new ExpressionTree(str);

			Assert::IsTrue(expectedElementType == tree->getExpressionElementType());
		}

		TEST_METHOD(StringIsNumber)
		{
			string str = "11.5";
			ExpressionElementType expectedElementType = NUMBER;
			ExpressionTree* tree = new ExpressionTree(str);

			Assert::IsTrue(expectedElementType == tree->getExpressionElementType());
		}

		TEST_METHOD(StringIsGreekLetter)
		{
			string str = "Pi";
			ExpressionElementType expectedElementType = GREEKLETTER;
			ExpressionTree* tree = new ExpressionTree(str);

			Assert::IsTrue(expectedElementType == tree->getExpressionElementType());
		}

		TEST_METHOD(StringIsOperator)
		{
			string str = "frac()";
			ExpressionElementType expectedElementType = OPERATOR;
			int expectedOperandsCount = 2;
			int expectedPriority = 3;
			ExpressionTree* tree = new ExpressionTree(str);

			Assert::IsTrue(expectedElementType == tree->getExpressionElementType());
			Assert::AreEqual(expectedOperandsCount, tree->getOperandsCount());
			Assert::AreEqual(expectedPriority, tree->getOperatorPriority());
		}

		TEST_METHOD(StringIsUndefined)
		{
			string str = "$frac";
			ExpressionElementType expectedElementType = UNDEFINED;
			ExpressionTree* tree = new ExpressionTree(str);

			Assert::IsTrue(expectedElementType == tree->getExpressionElementType());
		}
	};
}
