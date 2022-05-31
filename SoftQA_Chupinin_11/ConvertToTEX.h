/*!
* \file
* \brief Заголовочный файл с заголовками вспомогательных функций, а также перечисление исключений
* 
* Данный файл содержит заголовки функций, необходимых для идентификации элемента обратной польской записи,
* чтение и записи в файл,  функцию обработки ошибок, определение параметров оператора в обратной польской записи, 
* а также перечисление исключений
* 
*/


#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <map>

using namespace std;


//! Максимальное количество операндов оператора
const int MAX_OPERAND_COUNT = 3; 

//! Перечисление ошибок
enum Exception
{
	EMPTY_STRING_EXCEPTION, ///< Пустая строка 
	FILE_IN_NOT_FOUND_EXCEPTION, ///< Файл c входными данными не найден
	INCORRECT_EXTENSION_EXCEPTION, ///< Неверное расширение файла
	INCORRECT_VAL_FORMAT_EXCEPTION, ///< Неверный формат для элемента обратной польской записи
	INCORRECT_DIAPOSON_EXCEPTION, ///< Неверный диапозон для чисел в обратной польской записи
	EXCESS_OF_OPERANDS_EXCEPTION, ///< Количество операндов больше необходимого
	LACK_OF_OPERANDS_EXCEPTION, ///< Количество операндов меньше необходимого
	LACK_OF_CONSOLE_ARGUMENT, ///< Количество аргументов консоли меньше необходимого
	INCORRECT_EXTENSION_OUTPUT_EXCEPTION, ///< Неверное расширение выходного файла
	UNKNOWN_EXCEPTION ///< Неизвестное исключение
	
};


/*! \brief Определяет, является ли строка переменной
*	\param[in] str - строка
*	\return - если строка является переменной, то true, иначе false
*/
bool isVar(const string& str);


/*!	\brief Определяет, является ли строка числом
*	\param[in] str - строка
*	\param[in]  nSignificantDigits  - количество значащих  цифр в строке
*	\return - если строка ялвяется числом, то true, иначе false
*/
bool isNumber(const string& str, int  nSignificantDigits = 100);


/*!	\brief Определяет, является ли строка греческой буквой
*	\param[in] str - строка
*	\return - если строка ялвяется греческой буквой, то true, иначе false
*/
bool isGreekLetter(const string& str);


/*!	\brief Определяет, является ли строка оператором
*	\param[in] str - строка
*	\return - если строка ялвяется оператором, то  количество операндов, иначе -1
*/
int isOperator(const string& str);


/*!	\brief Определяпет приоритет оператора
*	\param[in] str - строка 
*	\return - если строка является оператором, то приоритет оператора, иначе -1
*/
int getPriorityOfOperator(const string& str);


/*!	\brief Обработать ошибку
*	\param[in]	exception - исключение
*/
void handleExceptions(Exception exception);

/*!	\brief Конвертировать оператор из C-формата в tex-формат
*	\param[in] str - строка, являющаяся оператором
*	\return - оператор в tex-формате
*/
string convertOperatorToTex(const string& str);

/*!	\brief Прочитать содержимое файла
*	\param[in] fileName - имя входного файла
*	\param[out] reversePolishEntry - обратная польская запись
*	\throw INCORRECT_EXTENSION_EXCEPTION - файл имеет неверное расширение
*	\throw FILE_IN_NOT_FOUND_EXCEPTION - файл не найден
*	\throw EMPTY_STRING_EXCEPTION - файл содержит пустую строку
*/
void readFile(string& fileName, string& reversePolishEntry);

/*!	\brief Записать в файл
*	\param[in] fileName - имя выходного файла
*	\param[in] texFormula - tex-формула, которую мы должны записать в файл
*/
void writeToFile(string& fileName, string& texFormula);