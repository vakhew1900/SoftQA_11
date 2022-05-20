#include "convertTreeToTEX.h"

ExpressionTree* convertReversePolishEntryToTree(vector<string>& reversePolishEntryElements)
{
	int lastElementNumber = reversePolishEntryElements.size() - 1; // ����� ���������� �������� � �������� �������� ������
	string value = reversePolishEntryElements[lastElementNumber];  // ��������� ������� �������� �������� �����
	reversePolishEntryElements.pop_back(); // ������� ������� � ����� �������

	ExpressionTree* current = new ExpressionTree(value); // ������� ����� ������� � ���� ������


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
	else if (current->getExpressionElementType() == OPERATOR && reversePolishEntryElements.size() < current->getOperandsCount())
	{
		// ���������� ����������
	}
	
	return current;
}


string convertSubFormulaToTex(ExpressionTree* current, int& curPriority)
{

	string subFormula; // �������, ��� ��������� �� �������

	if (current->getExpressionElementType() == OPERATOR) { // ���� ����������� ������� �������� ����������


		string operands[MAX_OPERAND_COUNT] = {}; // ������ ���������
		int priority[MAX_OPERAND_COUNT]; // ������  ���������� ���������

		for (int i = current->getOperandsCount() - 1; i >= 0; i--) { // ��� ���� ��������� ���������
			operands[i] = convertSubFormulaToTex(current->getChild(i), priority[i]); // ������� ������� � ��� ���������
		}


		int currentOperandsCount = current->getOperandsCount(); // ���������� ��������� � ���������
		string operatorTex = current->getTexFormat(); // ��������� �������� � tex-������

		if (currentOperandsCount == 1) { // ���������� ��������� �����  1
			subFormula = operatorTex + " {" + operands[0] + "}"; // ��������� ��������� � tex-������
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

				curPriority = current->getOperatorPriority(); // ���������� ���������

				if (curPriority < priority[0]) operands[0] = "(" + operands[0] + ")"; // ���� ��������� ������� �������� ���� ���������� �������� ������ ��������, ����� ����� ������� � ������
				if (curPriority < priority[1]) operands[1] = "(" + operands[1] + ")"; // ���� ��������� ������� �������� ���� ���������� �������� ������� ��������, ����� ������ ������� � ������

				if (value == "pow()") // ����
				{
					subFormula = operands[0] + " " + operatorTex + " {" + operands[1] + "}";
				}
				else
					subFormula = operands[0] + " " + operatorTex + " " + operands[1];
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