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


string convertSubFormulaToTex(ExpressionTree* current, int& curPriority)
{

	string subFormula; // считать, что подстрока не найдены

	if (current->getExpressionElementType() == OPERATOR) { // если проверяемая вершина является оператором


		string operands[MAX_OPERAND_COUNT] = {}; // массив операндов
		int priority[MAX_OPERAND_COUNT]; // массив  приоритета операндов

		for (int i = current->getOperandsCount() - 1; i >= 0; i--) { // для всех операндов оператора
			operands[i] = convertSubFormulaToTex(current->getChild(i), priority[i]); // находим операнд и его приоритет
		}


		int currentOperandsCount = current->getOperandsCount(); // количество операндов у оператора
		string operatorTex = current->getTexFormat(); // переводим оператор в tex-формат

		if (currentOperandsCount == 1) { // количество операндов равно  1
			subFormula = operatorTex + " {" + operands[0] + "}"; // перевести подстроку в tex-формат
		}

		if (currentOperandsCount == 2) // количество операндов равно 2
		{
			string value = current->getValue(); // значение вершины

			if (value == "sqrt()") { // значение является корнем
				subFormula = operatorTex + "[ " + operands[0] + " ]" + " { " + operands[1] + " }"; // перевести подстроку в tex-формат
			}

			else if (value == "frac()") { // значение является дробью
				subFormula = operatorTex + "{ " + operands[0] + " }" + " { " + operands[1] + " }"; // перевести подстроку в tex-формат
			}
			else {

				curPriority = current->getOperatorPriority(); // корректный приоритет

				if (curPriority < priority[0]) operands[0] = "(" + operands[0] + ")"; // если приоритет текущей операции выше приоритета операции левого операнда, взять левый операнд в скобки
				if (curPriority < priority[1]) operands[1] = "(" + operands[1] + ")"; // если приоритет текущей операции выше приоритета операции правого операнда, взять правый операнд в скобки

				if (value == "pow()") // опер
				{
					subFormula = operands[0] + " " + operatorTex + " {" + operands[1] + "}";
				}
				else
					subFormula = operands[0] + " " + operatorTex + " " + operands[1];
			}

		}

		if (currentOperandsCount == 3) { // количество операндов равно 3
			subFormula = operatorTex + "_ {" + operands[0] + "} ^ {" + operands[1] + "}" + " {" + operands[2] + "}"; // перевести подстроку в tex-формат
		}

	}

	else if (current->getExpressionElementType() == GREEKLETTER) { // строка является греческой буквой
		subFormula = current->getTexFormat(); // перевести в TEX-формат
	}
	else
	{
		subFormula = current->getValue(); // иначе считать, что подформула равна значнию
	}

	return subFormula;
}