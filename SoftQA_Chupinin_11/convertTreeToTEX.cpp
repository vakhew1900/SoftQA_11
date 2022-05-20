#include "convertTreeToTEX.h"

ExpressionTree* convertReversePolishEntryToTree(vector<string>& reversePolishEntryElements)
{
	int lastElementNumber = reversePolishEntryElements.size() - 1;
	string value = reversePolishEntryElements[lastElementNumber];
	reversePolishEntryElements.pop_back();

	ExpressionTree* current = new ExpressionTree(value);


	if (current->getExpressionElementType() == OPERATOR && reversePolishEntryElements.size() >= current->getOperandsCount()) {

		vector<ExpressionTree*> operands(current->getOperandsCount());
		for (int i = current->getOperandsCount() - 1; i >= 0; i--) {
			auto p = convertReversePolishEntryToTree(reversePolishEntryElements);
			operands[i] = p;
		}

		for (int i = 0; i < operands.size(); i++) {
			current->addChild(operands[i]);
		}
	}
	else if (current->getExpressionElementType() == OPERATOR && reversePolishEntryElements.size() < current->getOperandsCount())
	{
		// выкидываем исключение
	}

	if (current->getValue() == "/") {
		cout << "YES";
	}
	//cout << current->getValue() << "\n";

	return current;
}