#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <map>

using namespace std;

const int MAX_OPERAND_COUNT = 3; // максимальное количество операндов


enum Exception
{
	EMPTY_STRING_EXCEPTION, //
	FILE_IN_NOT_FOUND_EXCEPTION,
	INCORRECT_EXTENSION_EXCEPTION,
	INCORRECT_VAL_FORMAT_EXCEPTION,
	INCORRECT_DIAPOSON_EXCEPTION,
	EXCESS_OF_OPERANDS_EXCEPTION,
	LACK_OF_OPERANDS_EXCEPTION,
	LACK_OF_CONSOLE_ARGUMENT,
	INCORRECT_EXTENSION_OUTPUT_EXCEPTION
};

bool isVar(const string& str);
bool isNumber(const string& str);
bool isGreekLetter(const string& str);
int isOperator(const string& str);
int getPriorityOfOperator(const string& str);

void handleExceptions(Exception exception);

string convertOperatorToTex(const string& str);

void readFile(string& fileName, string& reversePolishEntry);
void writeToFile(string& fileName, string& texFormula);