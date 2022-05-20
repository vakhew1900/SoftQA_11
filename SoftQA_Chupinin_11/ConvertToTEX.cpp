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
    int numberOfOperands = -1; // �������, ��� ������ �� �������� ����������

    const vector<string> oneOperand = { "!", "all()", "exist()" }; // ������ ���������� � ����� ���������

    const vector<string> twoOperands = { "+", "-", "/", "*", "+-", "-+", "%", "=", "!=", ">=", "<=", ">", "<",
         "&&", "||", ",", "..", "&", "|", "pow()", "sqrt()", "in()", "noin()", "_", "frac()" }; // ������ ���������� � ����� ����������

    const vector <string> threeOperands = { "summator()" }; // ������ ���������� � ����� ����������

    for (int i = 0; i < oneOperand.size(); i++) // ��� ���� ���������� � ����� ���������
        if (str == oneOperand[i]) // ���� �������� ����� ������
            numberOfOperands = 1; // �������, ��� ���������� ��������� � ��������� ����� ������

    for (int i = 0; i < twoOperands.size(); i++) // ��� ���� ���������� � ����� ����������
        if (str == twoOperands[i]) // ���� �������� � ������
            numberOfOperands = 2; // �������, ��� ���������� ��������� � ��������� ����� ����

    for (int i = 0; i < threeOperands.size(); i++) // ��� ���� ���������� � ����� ����������
        if (str == threeOperands[i]) // ���� �������� ����� ������
            numberOfOperands = 3; // �������, ��� ���������� ��������� � ��������� ����� ����

    return numberOfOperands; // ������� ���������� ��������� � ���������, ���� ������ �������� ����������, ����� ������� -1
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

    bool isVar = 1; // �������, ��� ������ �������� ����������

    for (int i = 0; i < str.size(); i++) { // ��� ���� ��������� ������

        if (str[i] != '_' && !isalnum(str[i]))  // ������� ������ �� �������� ������, ������ ��� ������ ��������������
            isVar = 0; // C������, ��� ������ �� �������� ����������
    }

    int varSize = str.size(); // ����� ������
    if (isdigit(str[0])) isVar = 0; //���� ������ ������� ������ �������� ������, �������, ��� ������ �� �������� ���������� 
    if (varSize > 10) isVar = 0; //���� ����� ������ ������ 10 , �������, ��� ������ �� �������� ���������� 


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

    int priority = -1; // int priority = 0 - �� �������� -1
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