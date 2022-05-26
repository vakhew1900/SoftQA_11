#include "convertTreeToTEX.h"
#include <boost/algorithm/string.hpp>
#include <boost/regex.hpp>
#include "boost/lexical_cast.hpp"

ExpressionTree* convertReversePolishEntryToTree(vector<string>& reversePolishEntryElements)
{
	int lastElementNumber = reversePolishEntryElements.size() - 1; // ����� ���������� �������� � �������� �������� ������


	if (lastElementNumber < 0) { // ��������� ������ ���
		throw LACK_OF_OPERANDS_EXCEPTION; // ��������� ����������
	}

	string value = reversePolishEntryElements[lastElementNumber];  // ��������� ������� �������� �������� �����
	reversePolishEntryElements.pop_back(); // ������� ������� � ����� �������
	ExpressionTree* current;

	if (isNumber(value) && value[0] == '-') // ������� �������� �������� ������ �������� ������������� ������
	{
		current = new ExpressionTree("--"); // ������� ����� ������� � ���� ������ �� ��������� ���������� ������
		value.erase(0,1); // ������� ����� �� ��������
		reversePolishEntryElements.push_back(value); // ��������� �������� � ������ ��������� �������� �������� ������
	}
	else {
		 current = new ExpressionTree(value); // ������� ����� ������� � ���� ������
	}
	bool is_number = 1; // �������, ��� ��������� ������� �������� �������� ������ �������� ������

	try {
		double num = boost::lexical_cast<double> (value); // ������� �� ������ � �����
	}
	catch (boost::bad_lexical_cast&) { // ������� �� ��� �����������
		is_number = 0; // �������, ��� ������ �� �������� ������
	}

	if (isNumber(value) == 0 && is_number == 1) { // ���������� �������� ���� ������ 20
		throw INCORRECT_DIAPOSON_EXCEPTION; // ��������� ����������
	}


	if (current->getExpressionElementType() == OPERATOR && reversePolishEntryElements.size() >= current->getOperandsCount()) { // ����� ������� �������� ���������� � ���������� ��������� � ������� ����������, ����� ��������� �� ���������� ��� ������ ��������

		vector<ExpressionTree*> operands(current->getOperandsCount()); // ���������� ���������� ��������� ���������
		for (int i = current->getOperandsCount() - 1; i >= 0; i--) { // ��� ���� ��������� ���������
			auto p = convertReversePolishEntryToTree(reversePolishEntryElements); // ������� ������� ���������
			operands[i] = p; 
		}

		for (int i = 0; i < operands.size(); i++) { // ��������� ������� ���������
			current->addChild(operands[i]);
		}
	}
	else if (current->getExpressionElementType() == OPERATOR && reversePolishEntryElements.size() < current->getOperandsCount()) // ���������� ��������� ������ ������������ ��� ������� ���������
	{
		throw LACK_OF_OPERANDS_EXCEPTION; // ��������� ����������
	}
	else if (current->getExpressionElementType() == UNDEFINED) // ������� ������ �������� �������������� ��������� �������� �������� ������
	{
		throw INCORRECT_VAL_FORMAT_EXCEPTION; // ��������� ����������
	}

	return current;
}


string convertSubFormulaToTex(ExpressionTree* current, int& curPriority)
{

	string subFormula; // �������, ��� ��������� �� �������

	if (current->getExpressionElementType() == OPERATOR) { // ���� ����������� ������� �������� ����������

		curPriority = current->getOperatorPriority(); // ���������� ���������
		string operands[MAX_OPERAND_COUNT] = {}; // ������ ���������
		int priority[MAX_OPERAND_COUNT] = {}; // ������  ���������� ���������

		for (int i = current->getOperandsCount() - 1; i >= 0; i--) { // ��� ���� ��������� ���������
			operands[i] = convertSubFormulaToTex(current->getChild(i), priority[i]); // ������� ������� � ��� ���������
		}


		int currentOperandsCount = current->getOperandsCount(); // ���������� ��������� � ���������
		string operatorTex = current->getTexFormat(); // ��������� �������� � tex-������

		if (currentOperandsCount == 1 && current-> getValue() != "--") { // ���������� ��������� �����  1 � �������� �� �������� ��������� �������
			subFormula = operatorTex + " {" + operands[0] + "}"; // ��������� ��������� � tex-������
		}

		if (currentOperandsCount == 1 && current->getValue() == "--") { // ���������� ��������� �����  1 � ��������  �������� ��������� �������
			subFormula = operatorTex + operands[0]; // ��������� ��������� � tex-������
		}

		if (currentOperandsCount == 2) // ���������� ��������� ����� 2
		{
			string value = current->getValue(); // �������� �������

			if (value == "sqrt()") { // �������� �������� ������
				subFormula = operatorTex + "[ " + operands[0] + " ]" + " { " + operands[1] + " }"; // ��������� ��������� � tex-������
			}

			else if (value == "frac()") { // �������� �������� ������
				subFormula = operatorTex + "{ " + operands[0] + " }" + " { " + operands[1] + " }"; // ��������� ��������� � tex-������
			}
			else {

				if (curPriority < priority[0]) operands[0] = "(" + operands[0] + ")"; // ���� ��������� ������� �������� ���� ���������� �������� ������ ��������, ����� ����� ������� � ������
				

				if (value == "pow()") // �������� �������� ����������� � �������
				{
					subFormula = operands[0] + " " + operatorTex + " {" + operands[1] + "}";
				}
				else {
					if (curPriority < priority[1]) operands[1] = "(" + operands[1] + ")"; // ���� ��������� ������� �������� ���� ���������� �������� ������� ��������, ����� ������ ������� � ������
					if (operands[1][0] == '-' ) operands[1] = "(" + operands[1] + ")"; // ���� ������ ������� ���������� � ������, �� ����������� ��������� ������� � ������ 
					subFormula = operands[0] + " " + operatorTex + " " + operands[1];
				}
			}

		}

		if (currentOperandsCount == 3) { // ���������� ��������� ����� 3
			subFormula = operatorTex + "_ {" + operands[0] + "} ^ {" + operands[1] + "}" + " {" + operands[2] + "}"; // ��������� ��������� � tex-������
		}

	}

	else if (current->getExpressionElementType() == GREEKLETTER) { // ������ �������� ��������� ������
		subFormula = current->getTexFormat(); // ��������� � TEX-������
	}
	else
	{
		subFormula = current->getValue(); // ����� �������, ��� ���������� ����� �������
	}

	return subFormula;
}


string convertFormulaToTex(const string& reversePolishEntry)
{
	string seps = " \t"; // �����������
	vector <string> reversePolishEntryElements; // ������ ��������� �������� �������� ������
	
	string workingReversePolishEntry = reversePolishEntry; // ������� ����� �������� �������� ������, � ������� � ����� ��������

	while (seps.find(workingReversePolishEntry[workingReversePolishEntry.size() - 1]) != -1) // ���� � ����� ������ �������� �������� ������ ������������ �����������
	{
		workingReversePolishEntry.pop_back(); // ������� �����������
	}

	
	boost::split(reversePolishEntryElements, workingReversePolishEntry,boost::is_any_of(seps), boost ::token_compress_on); // ����������� ������ ��������  �������� ������ � ������ ��������� �������� �������� ������

	ExpressionTree* tree = NULL; // ������� ������� ������

	try {
		tree = convertReversePolishEntryToTree(reversePolishEntryElements); // ����������� �������� �������� ������ � ������ ���������
	}
	catch (Exception ex) {
		throw ex;
	}

	if (reversePolishEntryElements.size() != 0) { // � ������� �������� ��������  �������� �������� ����������������� ��������
		throw EXCESS_OF_OPERANDS_EXCEPTION; // ������ ����������
	}


	int maxPriority = 0; // ���������
	string texFormula = "$ " + convertSubFormulaToTex(tree, maxPriority) + " $"; // ����������� ������ tex-�������. ������� � ����� ���������� ���� $.

	tree->deleteTree(); // ������� ������

	return texFormula;
}