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
		string fileName(argv[1]);
		readFile(fileName, s);

		string ans = convertFormulaToTex(s);

		cout << ans << "\n";
	}
	catch (Exception ex)
	{
		handleExceptions(ex);
	}
}


//string s;
//getline(cin, s);
//string ans;
//try {
//    ans = convertFormulaToTex(s);
//}
//catch (Exception ex)
//{
//    handleExceptions(ex);
//}
//cout << ans << "\n";