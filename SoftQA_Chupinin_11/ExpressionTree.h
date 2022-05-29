/*!
*	\file
*	\brief ���� �������� ������������ ����� ��������� �������� �������� ������, � ����� ����� ������ ���������
* 
*	������ ���� �������� ����� ������ ��������� � ����������� ��������, ��������������, � ����� ������������
*	����� ��������� �������� �������� ������
*/

#pragma once
#include "ConvertToTEX.h"
#include <iostream>
using namespace std;

//! ���� ��������� �������� �������� ������
enum ExpressionElementType {
	NUMBER, ///< �����
	VAR, ///< ����������
	OPERATOR, ///< ��������
	GREEKLETTER, ///< ��������� �����
	UNDEFINED ///< �������������� ������� �������� �������� ������
};


/*!	\brief  ������ ���������
*	
*	����� ������ ���������. ����� �������� ��������, tex-������ ��������, ���������� ��������� � ��������� ���������.
*/
class ExpressionTree
{
private:

	//! ��� ������� �������� �������� ������
	ExpressionElementType expressionElementType;
	
	//! �������� ������ ���������
	string value;

	//! �������� � tex-�������
	string texFormat;

	//! ���������� ���������
	int operandsCount = 0;

	//! ��������� ���������
	int operatorPriority;

	//!	������ ���������� ��  ����� �������
	vector <ExpressionTree*> children;
public:

	/*!
	*	\brief ����������� �� ���������
	*/
	ExpressionTree();

	/*!	\brief �����������, ������� ��������� ��������
	*	\param[in] value - �������� �������
	*/
	ExpressionTree(const string value);

	/*!	\brief ���������� �� ���������
	*/
	~ExpressionTree();

	/*! \brief ���������� �������� �������
	*	\return - �������� �������
	*/
	string getValue();

	/*!	\brief ���������� ���������� ���������
	*	\return - ���������� ���������
	*/
	int getOperandsCount();

	/*!	\brief ���������� ��������� ���������
	*	\return - ��������� ���������
	*/
	int getOperatorPriority();

	/*!	\brief ���������� ��������� �� �������
	*	\param[in] number - ����� �������
	*	\return - ��������� �� �������
	*/
	ExpressionTree* getChild(int number);

	/*	\brief ���������� ������ ���������� �� �����
	*	\return - ������ ���������� �� �����
	*/
	vector<ExpressionTree*> getChildren();
	
	/*!	\brief ���������� ��� �������� �������� �������� ������
	*	\return - ��� �������� �������� �������� ������
	*/
	ExpressionElementType getExpressionElementType();

	/*!	\brief ���������� tex-������ �������� �������
	*	\return - tex-������ �������� �������
	*/
	string getTexFormat();

	/*!	\brief ��������� ������� �������
	*	\param[in] value - �������� ������� ��������
	*/
	void addChild(const string value);

	/*!	\brief ��������� ������� �������
	*	\param[in] child - ��������� �� �������-�������  
	*/
	void addChild(ExpressionTree* child);

	/*!	\brief �������� ������� � ���� ��� �����
	*/
	void deleteTree();
};

