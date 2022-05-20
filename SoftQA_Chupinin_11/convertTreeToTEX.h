#pragma once

#include "ExpressionTree.h"

string convertFormulaToTex(string& reversePolishEntry);

ExpressionTree* convertReversePolishEntryToTree(vector<string>& reversePolishEntryElements);

string convertSubFormulaToTex(ExpressionTree* current, int& maxPriority);