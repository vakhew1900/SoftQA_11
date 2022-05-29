/*!	
*	 \file
*	\brief ���� �������� ��������� ������� �������� �������� �������� ������ � tex-�������, � ����� ����������� �������� ��������� ������ � ������ ���������
*	
*	���� �������� ��������� ������� �������� �������� �������� ������ � tex-�������, 
*	� ����� ����������� �������� ��������� ������ � ������ ���������. ������ �������� ����������� ����������
*/

#pragma once
#include "ExpressionTree.h"


/*!	\brief �������������� �������� �������� ������ � tex-�������
*	\param[in] reversePolishEntry - �������� �������� ������
*	\return ������ tex-�������
*	\throw LACK_OF_OPERANDS_EXCEPTION -  ���������� ��������� ��� ��������� ������������
*	\throw INCORRECT_DIAPOSON_EXCEPTION - ���������� �������� ���� ������ 20
*	\throw INCORRECT_VAL_FORMAT_EXCEPTION - � �������� �������� ������ ���� ������������ �������
*	\throw EXCESS_OF_OPERANDS_EXCEPTION -  ����������� ��������� � �������� �������� ������
*/
string convertFormulaToTex(const string& reversePolishEntry);

/*!	\brief �������������� �������� �������� ������ � ������ ���������
*	\param[in] reversePolishEntryElements - ������ ��������� �������� �������� ������
*	\return ��������� �� ������� ������ ���������
*	\throw LACK_OF_OPERANDS_EXCEPTION - ���������� ��������� ��� ��������� ������������
*	\throw INCORRECT_DIAPOSON_EXCEPTION - ���������� �������� ���� ������ 20
*	\throw INCORRECT_VAL_FORMAT_EXCEPTION - � �������� �������� ������ ���� ������������ �������
*/
ExpressionTree* convertReversePolishEntryToTree(vector<string>& reversePolishEntryElements);

/*!	\brief �������������� ���������� � tex-�������
*	\param[in] current - ������� ������ ���������
*	\param[out] curPriority - ��������� �������
*	\return - tex-�������
*/
string convertSubFormulaToTex(ExpressionTree* current, int& curPriority);