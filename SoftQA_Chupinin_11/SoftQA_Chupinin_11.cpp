#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "convertTreeToTEX.h"
#include <string>
#include <boost/algorithm/string.hpp>

using namespace std;

int main(int argc, char* argv[])
{	
	setlocale(LC_ALL, "Russian");
    string s;

	try
	{	
		if (argc < 3) { // аргументов консоли меньше трех
			throw LACK_OF_CONSOLE_ARGUMENT; // выбросить исключение
		}

		string inputFileName(argv[1]); //  имя файла со входными данными
		string outputFileName(argv[2]); // имя файла с выходными данными
		string extension = ".tex"; // допустимое расширение файла

		bool isEndWith = boost::algorithm::ends_with(outputFileName, extension); 

		if (!isEndWith) // переменная имеет неправильное расширение
		{ 
			throw INCORRECT_EXTENSION_OUTPUT_EXCEPTION; // выбросить исключение
		}

		readFile(inputFileName, s); // прочитать данные с файла

		string ans = convertFormulaToTex(s); // преобразовать обратную польскую запись в tex-формулу
	
		writeToFile(outputFileName, ans); // записать данные в файл
	}
	catch (Exception ex) // выброшено исключение
	{
		handleExceptions(ex); // обработать исключение
	}
}


 