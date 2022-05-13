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

string ExpressionTree::getValue()
{
	return this->value;
}

int ExpressionTree::getOperandsCount()
{
	return this->operandsCount;
}

int ExpressionTree::getOperatorPriority()
{
	return this->operatorPriority;
}

ExpressionTree* ExpressionTree::getChild(int number)
{
	if (number > MAX_OPERAND_COUNT)
		return NULL;

	return this->children[number];
}

vector <ExpressionTree*> ExpressionTree::getChildren()
{
	return children;
}



ExpressionElementType ExpressionTree::getExpressionElementType()
{
	return this->expressionElementType;
}

string ExpressionTree::getTexFormat()
{
	return this->texFormat;
}


void ExpressionTree::addChild(ExpressionTree* child)
{
	this->children.push_back(child);
}

void ExpressionTree::addChild(string value)
{

	ExpressionTree* child = new ExpressionTree(value);
	this->addChild(child);

}

void ExpressionTree::deleteTree()
{
	for (int i = 0; i < this->operandsCount; i++) {
		children[i]->deleteTree();
	}

	delete this;
}
