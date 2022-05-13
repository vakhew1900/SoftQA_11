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