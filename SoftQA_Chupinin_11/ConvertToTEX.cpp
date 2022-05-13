#include "ConvertToTEX.h"


int isOperator(const string& str)
{
    int numberOfOperands = -1;

    const vector<string> oneOperand = { "!", "all()", "exist()" };

    const vector<string> twoOperands = { "+", "-", "/", "*", "+-", "-+", "%", "=", "!=", ">=", "<=", ">", "<",
         "&&", "||", ",", "..", "&", "|", "pow()", "sqrt()", "in()", "noin()", "_", "frac()" };

    const vector <string> threeOperands = { "summator()" };

    for (int i = 0; i < oneOperand.size(); i++)
        if (str == oneOperand[i])
            numberOfOperands = 1;

    for (int i = 0; i < twoOperands.size(); i++)
        if (str == twoOperands[i])
            numberOfOperands = 2;

    for (int i = 0; i < threeOperands.size(); i++)
        if (str == threeOperands[i])
            numberOfOperands = 3;

    return numberOfOperands;
}

bool isGreekLetter(const string& str)
{
    string workingStr = "\\" + str;

    vector <string> upperGreekLetter = { "\\Alpha", "\\Beta", "\\Gamma", "\\Epsilon", "\\Zeta", "\\Eta", "\\Theta",
    "\\Iota", "\\Kappa", "\\Lambda", "\\Mu", "\\Nu", "\\Xi", "\\Omicron", "\\Pi", "\\Rho", "\\Sigma", "\\Tau", "\\Upsilon",
    "\\Phi", "\\Chi", "\\Psi", "\\Omega" };

    vector <string> lowerGreekLetter = { "\\alpha", "\\beta", "\\gamma", "\\epsilon", "\\zeta", "\\eta", "\\theta",
    "\\iota", "\\kappa", "\\lambda", "\\mu", "\\nu", "\\xi", "\\omicron", "\\pi", "\\rho", "\\sigma", "\\tau", "\\upsilon",
    "\\phi", "\\chi", "\\psi", "\\omega" };

    bool isGreekLetter = 0;

    for (int i = 0; i < upperGreekLetter.size(); i++) {
        if (workingStr == upperGreekLetter[i])
            isGreekLetter = 1;
    }

    for (int i = 0; i < lowerGreekLetter.size(); i++) {
        if (workingStr == lowerGreekLetter[i])
            isGreekLetter = 1;
    }

    return isGreekLetter;
}

bool isVar(const string& str) {

    bool isVar = 1; // Считать, что строка является переменной

    for (int i = 0; i < str.size(); i++) { // для всех элементов строки

        if (str[i] != '_' && !isalnum(str[i]))  // элемент строки не является буквой, числом или нижнем подчеркиванием
            isVar = 0; // Cчитать, что строка не является переменной
    }

    int varSize = str.size(); // длина строки
    if (isdigit(str[0])) isVar = 0; //если первый элемент строки является числом, считать, что строка не является переменной 
    if (varSize > 10) isVar = 0; //если длина строки больше 10 , считать, что строка не является переменной 


    return isVar;
}

int getPriorityOfOperator(string& str) {

    vector <vector<string>> priorityOperators{
     { "all()", "exist()", "_", "!", "summator()"},
     { "in()", "noin()"},
     {"pow()", "sqrt()"},
     { "*", "/", "%", "frac()", "&"},
     { "+", "-", "+-", "-+", "|"},
     { ">=", "<=", ">", "<" },
     { "=", "!=" },
     { "&&" },
     { "||" },
     { ",", ".." }
    };

    int priority = -1; // int priority = 0 - не проверял -1
    for (int i = 0; i < priorityOperators.size(); i++) {
        for (int j = 0; j < priorityOperators[i].size(); j++) {
            if (priorityOperators[i][j] == str)
                priority = i;
        }
    }

    return priority;
}
