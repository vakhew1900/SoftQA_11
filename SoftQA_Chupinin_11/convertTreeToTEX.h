/*!	
*	 \file
*	\brief Файл содержит заголовки функций перевода обратной польской записи в tex-Формулу, а также конвертация обратной пользской записи в дерево выражений
*	
*	Файл содержит заголовки функций перевода обратной польской записи в tex-Формулу, 
*	а также конвертация обратной пользской записи в дерево выражений. Данные операции выполняются рекурсивно
*/

#pragma once
#include "ExpressionTree.h"


/*!	\brief Конвертировать обратную польскую запись в tex-формулу
*	\param[in] reversePolishEntry - обратная польская запись
*	\return строка tex-формулы
*	\throw LACK_OF_OPERANDS_EXCEPTION -  количество операндов для оператора недостаточно
*	\throw INCORRECT_DIAPOSON_EXCEPTION - количество значащих цифр больше 20
*	\throw INCORRECT_VAL_FORMAT_EXCEPTION - в обратной польской записи есть неопознанный элемент
*	\throw EXCESS_OF_OPERANDS_EXCEPTION -  переизбыток операндов в обратной польской записи
*/
string convertFormulaToTex(const string& reversePolishEntry);

/*!	\brief Конвертировать обратную польскую запись в дерево выражений
*	\param[in] reversePolishEntryElements - вектор элементов обратной польской записи
*	\return указатель на вершину дерева выражений
*	\throw LACK_OF_OPERANDS_EXCEPTION - количество операндов для оператора недостаточно
*	\throw INCORRECT_DIAPOSON_EXCEPTION - количество значащих цифр больше 20
*	\throw INCORRECT_VAL_FORMAT_EXCEPTION - в обратной польской записи есть неопознанный элемент
*/
ExpressionTree* convertReversePolishEntryToTree(vector<string>& reversePolishEntryElements);

/*!	\brief Конвертировать подформулу в tex-формулу
*	\param[in] current - вершина дерева выражений
*	\param[out] curPriority - приоритет вершины
*	\return - tex-формула
*/
string convertSubFormulaToTex(ExpressionTree* current, int& curPriority);