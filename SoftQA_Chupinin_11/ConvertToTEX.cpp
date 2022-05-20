#include "ConvertToTEX.h"


bool isNumber(const string& str)
{
    int minus = 0;
    int point = 0;
    bool isNumber = 1;
    int numberSize = str.size();

    for (int i = 0; i < str.size(); i++)
    {
        if (str[i] == '-')
            minus++;
        else  if (str[i] == '.')
            point++;
        else if (!isdigit(str[i]))
            isNumber = 0;
    }

    if (point)
    {
        if (point > 1 || str[0] == '.' || str[str.size() - 1] == '.')
            isNumber = 0;
        numberSize--;
    }

    if (minus)
    {
        if (minus > 1 || str[0] != '-')
            isNumber = 0;
        numberSize--;
    }

    if (numberSize > 20)
        isNumber = 0;

    return isNumber;

}


int isOperator(const string& str)
{
    int numberOfOperands = -1; // Считать, что строка не является оператором

    const vector<string> oneOperand = { "!", "all()", "exist()" }; // массив операторов с одним операндом

    const vector<string> twoOperands = { "+", "-", "/", "*", "+-", "-+", "%", "=", "!=", ">=", "<=", ">", "<",
         "&&", "||", ",", "..", "&", "|", "pow()", "sqrt()", "in()", "noin()", "_", "frac()" }; // массив операторов с двумя операндами

    const vector <string> threeOperands = { "summator()" }; // массив операторов с тремя операндами

    for (int i = 0; i < oneOperand.size(); i++) // для всех операторов с одним операндом
        if (str == oneOperand[i]) // если оператор равен строке
            numberOfOperands = 1; // считать, что количество операндов у оператора равна одному

    for (int i = 0; i < twoOperands.size(); i++) // для всех операторов с двумя операндами
        if (str == twoOperands[i]) // если оператор в строке
            numberOfOperands = 2; // считать, что количество операндов у оператора равна двум

    for (int i = 0; i < threeOperands.size(); i++) // для всех операторов с тремя операндами
        if (str == threeOperands[i]) // если оператор равен строке
            numberOfOperands = 3; // считать, что количество операндов у оператора равна трем

    return numberOfOperands; // вернуть количество операндов у оператора, если строка является оператором, иначе вернуть -1
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

int getPriorityOfOperator(const string& str) {

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

string convertOperatorToTex(const string& str)
{
    map <string, string> operatorTex = { {"+", "+"}, {"-", "-"}, {"/", "\\div"}, {"*", "\\cdot"},
        {"+-", "\\pm"}, {"-+","\\mp"}, {"%", "\\mod"}, {"=", "="}, {">=", "\\geq"}, {"<=", "\\leq"},
        {"!=", "\\neq"}, {">",">"}, {"<","<"}, {"&&", "\\wedge"},{"||","\\vee"}, {"&","\\cap"}, {"|","\\cup"}, {",", ","},
        {"..", ".."}, {"frac()", "\\frac"}, {"pow()","^"}, {"_","_"}, {"sqrt()","\\sqrt"}, {"in()", "\\in"}, {"noin()", "\\notin"},
        {"!","\\overline"}, {"all()", "\\forall"}, {"exist()", "\\exists"}, {"summator()","\\sum"} };


    return operatorTex[str];
}

vector<string> split(string& str, string& seps)
{
    char* cstr = const_cast<char*>(str.c_str());
    char* elementOfArr;
    vector<string> arr;
    elementOfArr = strtok(cstr, seps.c_str());
    while (elementOfArr != NULL) {
        arr.push_back(elementOfArr);
        elementOfArr = strtok(NULL, seps.c_str());
    }
    return arr;
}