/*!
* \file
* \brief ������������ ���� � ����������� ��������������� �������, � ����� ������������ ����������
* 
* ������ ���� �������� ��������� �������, ����������� ��� ������������� �������� �������� �������� ������,
* ������ � ������ � ����,  ������� ��������� ������, ����������� ���������� ��������� � �������� �������� ������, 
* � ����� ������������ ����������
* 
*/


#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <map>

using namespace std;


//! ������������ ���������� ��������� ���������
const int MAX_OPERAND_COUNT = 3; 

//! ������������ ������
enum Exception
{
	EMPTY_STRING_EXCEPTION, ///< ������ ������ 
	FILE_IN_NOT_FOUND_EXCEPTION, ///< ���� c �������� ������� �� ������
	INCORRECT_EXTENSION_EXCEPTION, ///< �������� ���������� �����
	INCORRECT_VAL_FORMAT_EXCEPTION, ///< �������� ������ ��� �������� �������� �������� ������
	INCORRECT_DIAPOSON_EXCEPTION, ///< �������� �������� ��� ����� � �������� �������� ������
	EXCESS_OF_OPERANDS_EXCEPTION, ///< ���������� ��������� ������ ������������
	LACK_OF_OPERANDS_EXCEPTION, ///< ���������� ��������� ������ ������������
	LACK_OF_CONSOLE_ARGUMENT, ///< ���������� ���������� ������� ������ ������������
	INCORRECT_EXTENSION_OUTPUT_EXCEPTION, ///< �������� ���������� ��������� �����
	UNKNOWN_EXCEPTION ///< ����������� ����������
	
};


/*! \brief ����������, �������� �� ������ ����������
*	\param[in] str - ������
*	\return - ���� ������ �������� ����������, �� true, ����� false
*/
bool isVar(const string& str);


/*!	\brief ����������, �������� �� ������ ������
*	\param[in] str - ������
*	\param[in]  nSignificantDigits  - ���������� ��������  ���� � ������
*	\return - ���� ������ �������� ������, �� true, ����� false
*/
bool isNumber(const string& str, int  nSignificantDigits = 100);


/*!	\brief ����������, �������� �� ������ ��������� ������
*	\param[in] str - ������
*	\return - ���� ������ �������� ��������� ������, �� true, ����� false
*/
bool isGreekLetter(const string& str);


/*!	\brief ����������, �������� �� ������ ����������
*	\param[in] str - ������
*	\return - ���� ������ �������� ����������, ��  ���������� ���������, ����� -1
*/
int isOperator(const string& str);


/*!	\brief ����������� ��������� ���������
*	\param[in] str - ������ 
*	\return - ���� ������ �������� ����������, �� ��������� ���������, ����� -1
*/
int getPriorityOfOperator(const string& str);


/*!	\brief ���������� ������
*	\param[in]	exception - ����������
*/
void handleExceptions(Exception exception);

/*!	\brief �������������� �������� �� C-������� � tex-������
*	\param[in] str - ������, ���������� ����������
*	\return - �������� � tex-�������
*/
string convertOperatorToTex(const string& str);

/*!	\brief ��������� ���������� �����
*	\param[in] fileName - ��� �������� �����
*	\param[out] reversePolishEntry - �������� �������� ������
*	\throw INCORRECT_EXTENSION_EXCEPTION - ���� ����� �������� ����������
*	\throw FILE_IN_NOT_FOUND_EXCEPTION - ���� �� ������
*	\throw EMPTY_STRING_EXCEPTION - ���� �������� ������ ������
*/
void readFile(string& fileName, string& reversePolishEntry);

/*!	\brief �������� � ����
*	\param[in] fileName - ��� ��������� �����
*	\param[in] texFormula - tex-�������, ������� �� ������ �������� � ����
*/
void writeToFile(string& fileName, string& texFormula);