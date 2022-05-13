#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <map>

using namespace std;

const int MAX_OPERAND_COUNT = 3; // ������������ ���������� ���������


enum Exception
{
	EMPTY_STRING_EXCEPTION, //
	FILE_IN_NOT_FOUND_EXCEPTION,
	INCORRECT_EXTENSION_EXCEPTION,
	INCORRECT_VAL_FORMAT_EXCEPTION,
	INCORRECT_DIAPOSON_EXCEPTION,
	EXCESS_OF_OPERANDS_EXCEPTION,
	LACK_OF_OPERANDS_EXCEPTION

};

/*! �������������� �������� �������� ������ ��������� �� ����� �� � ������� TEX
	\param[in] reversePolishEntry  �������� �������� ������
	\return  ������ � tex �������
*/
string convertFormulaToTEX(string& reversePolishEntry);

string convertSubFormulaToTEX(vector<string>& reversePolishEntryElements, int& curIndex, int& maxPriority);

/*! ��������� ������ �� ������������
  \param[in] str ������
  \param[in] seps �����������
  \return  �������� ������
*/
vector<string> split(string& str, string& seps);

bool isVar(const string& str);
bool isNumber(const string& str);
bool isGreekLetter(const string& str);
int isOperator(const string& str);
int getPriorityOfOperator(string& str);
void makeExternalBrackets(string& str);


string convertOperatorToTex(string& str);