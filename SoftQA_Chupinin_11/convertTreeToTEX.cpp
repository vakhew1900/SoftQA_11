#include "convertTreeToTEX.h"

ExpressionTree* convertReversePolishEntryToTree(vector<string>& reversePolishEntryElements)
{
	int lastElementNumber = reversePolishEntryElements.size() - 1; // номер последнего элемента в обратной польской записи
	string value = reversePolishEntryElements[lastElementNumber];  // последний элемент обратной польской запии
	reversePolishEntryElements.pop_back(); // удаляем элемент в конце вектора

	ExpressionTree* current = new ExpressionTree(value); // создаем новую вершину в наше дерево


	if (current->getExpressionElementType() == OPERATOR && reversePolishEntryElements.size() >= current->getOperandsCount()) { // новая вершина является оператором и количество элементов в векторе достаточно, чтобы заполнить их операндами для данной операции

		vector<ExpressionTree*> operands(current->getOperandsCount()); // определяем количество операндов оператора
		for (int i = current->getOperandsCount() - 1; i >= 0; i--) { // для всех операндов оператора
			auto p = convertReversePolishEntryToTree(reversePolishEntryElements); // находим операнд оператора
			operands[i] = p; 
		}

		for (int i = 0; i < operands.size(); i++) { // добавляем операнд оператору
			current->addChild(operands[i]);
		}
	}
	else if (current->getExpressionElementType() == OPERATOR && reversePolishEntryElements.size() < current->getOperandsCount())
	{
		// выкидываем исключение
	}
	
	return current;
}