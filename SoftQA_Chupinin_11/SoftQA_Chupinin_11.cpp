#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "convertTreeToTEX.h"
#include <string>

using namespace std;

int main(int argc, char* argv[])
{
    string s;
    getline(cin, s);

    string ans = convertFormulaToTex(s);
    cout << ans << "\n";
}
