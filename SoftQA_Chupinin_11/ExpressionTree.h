#pragma once
#include "ConvertToTEX.h"
#include <iostream>
using namespace std;


enum ExpressionElementType {
	NUMBER,
	VAR,
	OPERATOR,
	GREEKLETTER,
	UNDEFINED
};



class ExpressionTree
{
private:
	ExpressionElementType expressionElementType;
	string value;
	string texFormat;
	int operandsCount = 0;
	int operatorPriority;
	vector <ExpressionTree*> children;
public:

	ExpressionTree();
	ExpressionTree(string value);
	~ExpressionTree();

	string getValue();
	int getOperandsCount();
	int getOperatorPriority();
	ExpressionTree* getChild(int number);
	vector<ExpressionTree*> getChildren();

	ExpressionElementType getExpressionElementType();
	string getTexFormat();
	void addChild(string value);
	void addChild(ExpressionTree* child);
	void deleteTree();
};

