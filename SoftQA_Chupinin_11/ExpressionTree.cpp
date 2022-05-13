#include "ExpressionTree.h"

ExpressionTree::ExpressionTree() : expressionElementType(VAR), value("x")
{
}

ExpressionTree::~ExpressionTree()
{
}

ExpressionTree::ExpressionTree(const string value)
{
	this->value = value;

	if (isOperator(value) != -1) {
		this->expressionElementType = OPERATOR;
		this->texFormat = convertOperatorToTex(value);
		this->operatorPriority = getPriorityOfOperator(value);
		this->operandsCount = isOperator(value);
	}
	else if (isNumber(value))
	{
		this->expressionElementType = NUMBER;
	}
	else if (isGreekLetter(value))
	{
		this->expressionElementType = GREEKLETTER;
		this->texFormat = "\\" + value;
	}
	else if (isVar(value)) {
		this->expressionElementType = VAR;
	}
	else
	{
		this->expressionElementType = UNDEFINED;
	}
}