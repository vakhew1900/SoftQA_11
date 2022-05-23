#include "ConvertToTEX.h"
#include "boost/lexical_cast.hpp"

bool isNumber(const string& str)
{
    int minus = 0; // минус не найден
    int point = 0; // точка не найдена
    bool isNumber = 1; // считать, что строка является номером
    int numberSize = str.size(); // количество значащих цифр

    try {
        double num = boost::lexical_cast<double> (str); // перевод из строки в число
    }
    catch (boost::bad_lexical_cast&) { // перевод не был осуществлен
        isNumber = 0; // считать, что строка не является числом
    }

    minus = str.find("-"); // найти в строке минус

    if (minus != -1) { // минус найден
        numberSize--; // уменьшить количество значащих цифр на единицу
    }

    point = str.find("."); // найти точку в строке
    
    if (point != -1) { // точка найдена
        numberSize--; // уменьшить количество значащих цифр на единицу
    }

    if (numberSize > 20) // количество значащих цифр в строке больше 20
        isNumber = 0; // считать, что строка не является числом

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
        if (str == oneOperand[i]) // оператор равен строке
            numberOfOperands = 1; // считать, что количество операндов у оператора равна одному

    for (int i = 0; i < twoOperands.size(); i++) // для всех операторов с двумя операндами
        if (str == twoOperands[i]) //  оператор в строке
            numberOfOperands = 2; // считать, что количество операндов у оператора равна двум

    for (int i = 0; i < threeOperands.size(); i++) // для всех операторов с тремя операндами
        if (str == threeOperands[i]) // оператор равен строке
            numberOfOperands = 3; // считать, что количество операндов у оператора равна трем

    return numberOfOperands; // вернуть количество операндов у оператора, если строка является оператором, иначе вернуть -1
}

bool isGreekLetter(const string& str)
{
    string workingStr = "\\" + str; // добавить \ перед началом строки, для того, чтобы получить формат записи для TEX

    vector <string> upperGreekLetter = { "\\Alpha", "\\Beta", "\\Gamma", "\\Epsilon", "\\Zeta", "\\Eta", "\\Theta",
    "\\Iota", "\\Kappa", "\\Lambda", "\\Mu", "\\Nu", "\\Xi", "\\Omicron", "\\Pi", "\\Rho", "\\Sigma", "\\Tau", "\\Upsilon",
    "\\Phi", "\\Chi", "\\Psi", "\\Omega" }; // греческие заглавные буквы

    vector <string> lowerGreekLetter = { "\\alpha", "\\beta", "\\gamma", "\\epsilon", "\\zeta", "\\eta", "\\theta",
    "\\iota", "\\kappa", "\\lambda", "\\mu", "\\nu", "\\xi", "\\omicron", "\\pi", "\\rho", "\\sigma", "\\tau", "\\upsilon",
    "\\phi", "\\chi", "\\psi", "\\omega" }; // греческие маленькие буквы

    bool isGreekLetter = 0; // считать, что строка не является греческой буквой

    for (int i = 0; i < upperGreekLetter.size(); i++) {  // для всех заглавных греческих букв
        if (workingStr == upperGreekLetter[i]) //  строка является заглавной греческой буквой
            isGreekLetter = 1; // считать, что строка  является греческой буквой
    }

    for (int i = 0; i < lowerGreekLetter.size(); i++) { // для всех маленьких букв
        if (workingStr == lowerGreekLetter[i]) //  строка является заглавной греческой буквой
            isGreekLetter = 1; // считать, что строка не является греческой буквой
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
    }; // вектор векторов нулевой вектор - это вектор элементов с приоритетом 0, первый вектор - вектор элементов с приоритетом - 1 и т.д.

    int priority = -1; // считать, что строка не является оператором

    for (int i = 0; i < priorityOperators.size(); i++) { // для всех приоритетов
        for (int j = 0; j < priorityOperators[i].size(); j++) { // для всех операторов с приоритетом i
            if (priorityOperators[i][j] == str) // строка равна оператору
                priority = i; // приоритет строки равен приоритету оператора
        }
    }

    return priority;
}

string convertOperatorToTex(const string& str)
{
    // словарь оператор. Ключ - оператор в Си формате, значение - оператор в TEX-формате
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