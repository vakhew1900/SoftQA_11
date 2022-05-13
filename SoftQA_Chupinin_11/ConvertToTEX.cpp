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