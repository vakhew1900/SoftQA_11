#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "convertTreeToTEX.h"
#include <string>

using namespace std;

int main(int argc, char* argv[])
{	
	setlocale(LC_ALL, "Russian");
    string s;

	try
	{
		cout << argv[1] << "\n";
		string inputFileName(argv[1]);
		readFile(inputFileName, s);

		string ans = convertFormulaToTex(s);
		
		string outputFileName(argv[2]);
		writeToFile(outputFileName, ans);
	}
	catch (Exception ex)
	{
		handleExceptions(ex);
	}
}


 