/*!
*   \file
*   \brief ���� �������� ���������� ������� ��������������� �������
*   
* ������ ���� �������� ���������� �������, ����������� ��� ������������� �������� �������� �������� ������,
* ������ � ������ � ����,  ������� ��������� ������, ����������� ���������� ��������� � �������� �������� ������, 
*/



#include "ConvertToTEX.h"
#include <boost/algorithm/string.hpp>
#include <fstream>
#include "boost/lexical_cast.hpp"

bool isNumber(const string& str)
{
    int minus = 0; // ����� �� ������
    int point = 0; // ����� �� �������
    bool isNumber = 1; // �������, ��� ������ �������� �������
    int numberSize = str.size(); // ���������� �������� ����

    try {
        double num = boost::lexical_cast<double> (str); // ������� �� ������ � �����
    }
    catch (boost::bad_lexical_cast&) { // ������� �� ��� �����������
        isNumber = 0; // �������, ��� ������ �� �������� ������
    }


    minus = count(str.begin(), str.end(), '-'); // ����� � ������ �����

    if (minus != -1) { // ����� ������
        numberSize-=minus; // ��������� ���������� �������� ���� �� �������
    }

    point = str.find("."); // ����� ����� � ������
    
    if (point != -1) { // ����� �������
        numberSize--; // ��������� ���������� �������� ���� �� �������
    }

    if (str.find("e") != -1 || str.find("E") != -1) // � ������ ������������ ���� ����������
    {
        isNumber = 0; // �������, ��� ������ �� �������� ������
    }

    if (numberSize > 20) // ���������� �������� ���� � ������ ������ 20
        isNumber = 0; // �������, ��� ������ �� �������� ������

    return isNumber;

}


int isOperator(const string& str)
{
    int numberOfOperands = -1; // �������, ��� ������ �� �������� ����������

    const vector<string> oneOperand = { "!", "all()", "exist()", "--"}; // ������ ���������� � ����� ���������

    const vector<string> twoOperands = { "+", "-", "/", "*", "+-", "-+", "%", "=", "!=", ">=", "<=", ">", "<",
         "&&", "||", ",", "..", "&", "|", "pow()", "sqrt()", "in()", "noin()", "_", "frac()"}; // ������ ���������� � ����� ����������

    const vector <string> threeOperands = { "summator()" }; // ������ ���������� � ����� ����������

    for (int i = 0; i < oneOperand.size(); i++) // ��� ���� ���������� � ����� ���������
        if (str == oneOperand[i]) // �������� ����� ������
            numberOfOperands = 1; // �������, ��� ���������� ��������� � ��������� ����� ������

    for (int i = 0; i < twoOperands.size(); i++) // ��� ���� ���������� � ����� ����������
        if (str == twoOperands[i]) //  �������� � ������
            numberOfOperands = 2; // �������, ��� ���������� ��������� � ��������� ����� ����

    for (int i = 0; i < threeOperands.size(); i++) // ��� ���� ���������� � ����� ����������
        if (str == threeOperands[i]) // �������� ����� ������
            numberOfOperands = 3; // �������, ��� ���������� ��������� � ��������� ����� ����

    return numberOfOperands; // ������� ���������� ��������� � ���������, ���� ������ �������� ����������, ����� ������� -1
}

bool isGreekLetter(const string& str)
{
    string workingStr = "\\" + str; // �������� \ ����� ������� ������, ��� ����, ����� �������� ������ ������ ��� TEX

    vector <string> upperGreekLetter = { "\\Alpha", "\\Beta", "\\Gamma", "\\Epsilon", "\\Zeta", "\\Eta", "\\Theta",
    "\\Iota", "\\Kappa", "\\Lambda", "\\Mu", "\\Nu", "\\Xi", "\\Omicron", "\\Pi", "\\Rho", "\\Sigma", "\\Tau", "\\Upsilon",
    "\\Phi", "\\Chi", "\\Psi", "\\Omega" }; // ��������� ��������� �����

    vector <string> lowerGreekLetter = { "\\alpha", "\\beta", "\\gamma", "\\epsilon", "\\zeta", "\\eta", "\\theta",
    "\\iota", "\\kappa", "\\lambda", "\\mu", "\\nu", "\\xi", "\\omicron", "\\pi", "\\rho", "\\sigma", "\\tau", "\\upsilon",
    "\\phi", "\\chi", "\\psi", "\\omega" }; // ��������� ��������� �����

    bool isGreekLetter = 0; // �������, ��� ������ �� �������� ��������� ������

    for (int i = 0; i < upperGreekLetter.size(); i++) {  // ��� ���� ��������� ��������� ����
        if (workingStr == upperGreekLetter[i]) //  ������ �������� ��������� ��������� ������
            isGreekLetter = 1; // �������, ��� ������  �������� ��������� ������
    }

    for (int i = 0; i < lowerGreekLetter.size(); i++) { // ��� ���� ��������� ����
        if (workingStr == lowerGreekLetter[i]) // ������ �������� ��������� ��������� ������
            isGreekLetter = 1; // �������, ��� ������ �� �������� ��������� ������
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

    // ������ �������� ������� ������ - ��� ������ ��������� � ����������� 0, ������ ������ - ������ ��������� � ����������� - 1 � �.�.
    vector <vector<string>> priorityOperators{
     { "all()", "exist()", "_", "!", "summator()"},
     { "in()", "noin()"},
     {"pow()", "sqrt()"},
     { "*", "/", "%", "frac()", "&"},
     { "+", "-", "+-", "-+", "|", "--"},
     { ">=", "<=", ">", "<" },
     { "=", "!=" },
     { "&&" },
     { "||" },
     { ",", ".." }
    }; 

    int priority = -1; // �������, ��� ������ �� �������� ����������

    for (int i = 0; i < priorityOperators.size(); i++) { // ��� ���� �����������
        for (int j = 0; j < priorityOperators[i].size(); j++) { // ��� ���� ���������� � ����������� i
            if (priorityOperators[i][j] == str) // ������ ����� ���������
                priority = i; // ��������� ������ ����� ���������� ���������
        }
    }

    return priority;
}

void handleExceptions(Exception exception)
{   
    setlocale(LC_ALL, "Russian");
    switch (exception)
    {
        case EMPTY_STRING_EXCEPTION:
            cerr << "�������� ������ ������" << endl;
            break;
    
        case FILE_IN_NOT_FOUND_EXCEPTION:
            cerr << "������� ������ ���� � �������� �������. ��������, ���� �� ����������" << endl;
            break;

        case INCORRECT_EXTENSION_EXCEPTION:
            cerr << "������� ������� ���������� �����. ���� ������ ����� ���������� .txt " << endl;
            break;

        case INCORRECT_VAL_FORMAT_EXCEPTION:
            cerr << "������������ ������� �������� �������� ������ " << endl;
            break;

        case INCORRECT_DIAPOSON_EXCEPTION:
            cerr << "���������� �������� ���� � ����� ������ ����������� ���������� " << endl;
            break;

        case EXCESS_OF_OPERANDS_EXCEPTION:
            cerr <<"���������� ��������  ������������ ��� ������� ���������� ��������� "<< endl;
            break;

        case LACK_OF_OPERANDS_EXCEPTION:
            cerr << "���������� �������� ������ ������������ ���������� " << endl;
            break;
        
        case LACK_OF_CONSOLE_ARGUMENT:
                cerr << "������������� ���������� ����������" << endl;
                break;

        case INCORRECT_EXTENSION_OUTPUT_EXCEPTION:
            cerr << "������������ ���������� �����. ���� ������ ����� ���������� .tex" << endl;
            break;

        case UNKNOWN_EXCEPTION:
            cerr << "����������� ������" << endl;
            break;

    }
    

}

string convertOperatorToTex(const string& str)
{
    // ������� ��������. ���� - �������� � �� �������, �������� - �������� � TEX-�������
    map <string, string> operatorTex = { {"+", "+"}, {"-", "-"}, {"/", "\\div"}, {"*", "\\cdot"},
        {"+-", "\\pm"}, {"-+","\\mp"}, {"%", "\\mod"}, {"=", "="}, {">=", "\\geq"}, {"<=", "\\leq"},
        {"!=", "\\neq"}, {">",">"}, {"<","<"}, {"&&", "\\wedge"},{"||","\\vee"}, {"&","\\cap"}, {"|","\\cup"}, {",", ","},
        {"..", ".."}, {"frac()", "\\frac"}, {"pow()","^"}, {"_","_"}, {"sqrt()","\\sqrt"}, {"in()", "\\in"}, {"noin()", "\\notin"},
        {"!","\\overline"}, {"all()", "\\forall"}, {"exist()", "\\exists"}, {"summator()","\\sum"}, {"--","-"} };

    return operatorTex[str]; 
}


void readFile(string& fileName, string& reversePolishEntry) {

    string extension = ".txt"; // ���������� ���������� �����

    bool isEndWith = boost::algorithm::ends_with(fileName, extension); 

    if (isEndWith) { // ���� ����� ����������� ����������
        ifstream fin(fileName); // ������� ����

        if (fin.fail()) { // ����� �� ����������
            throw FILE_IN_NOT_FOUND_EXCEPTION; // ��������� ����������
        }

        getline(fin, reversePolishEntry); // ������� ���������� �����

        if (reversePolishEntry.empty()) { // ��������� ������ ������ 
            throw EMPTY_STRING_EXCEPTION; // ��������� ����������
        }
    }
    else
    {
        throw INCORRECT_EXTENSION_EXCEPTION; // ��������� ����������
    }

}

void writeToFile(string& fileName, string& texFormula) {

    ofstream fout; // �����
    fout.open(fileName); // �������/������� ����
    fout << texFormula; // �������� ������ � ����
}