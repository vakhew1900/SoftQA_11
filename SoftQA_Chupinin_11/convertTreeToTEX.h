#pragma once

#include "ExpressionTree.h"

string convertFormulaToTex(const string& reversePolishEntry);

ExpressionTree* convertReversePolishEntryToTree(vector<string>& reversePolishEntryElements);

string convertSubFormulaToTex(ExpressionTree* current, int& maxPriority);