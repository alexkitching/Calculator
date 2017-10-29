////////////////////////////////////////////////////////////////////
// File: <InfixtoPostfix.h>
// Author: <Alex Kitching>
// Date Created: <3/4/17>
// Brief: <Header file for the InfixtoPostfix Class.>
////////////////////////////////////////////////////////////////////
#ifndef INFIXTOPOSTFIX_H_
#define INFIXTOPOSTFIX_H_

#include <iostream>
#include <string.h>
#include <string>
#include <stack>
#include <vector>
#include <iterator>
#include <cctype>
#include <math.h>
#include "Operations.h"

class Calc
{
public:
	Calc() {}; // Constructor
	~Calc() {}; // Destructor

				//Calculate Function
	float Calculate(std::string a_sInput);


private:
	// Infix to Postfix Function
	void Convert();
	void AddtoResultVector();

	// Op Conversion Function
	void ScanAndConvert();

	// Comparison Functions
	bool IsOperator(char a_char);
	bool IsOperator(std::string a_stringChar);
	bool IsSubtract(char a_char);
	bool IsOperand(char a_char);
	bool IsOperand(std::string a_stringChar);
	bool IsLeftParenthesis(char a_char);
	bool IsLeftParenthesis(std::string a_stringChar);
	bool IsRightParenthesis(char a_char);
	bool IsRightParenthesis(std::string a_stringChar);

	// Precedence Check
	bool IsHigherPriority(char a_op1, char a_op2);

	// Get Operator Priority 
	int GetOperatorPriority(char a_op);
	int IsRightAssociative(char a_op);

	// IsMinusNumber
	bool bIsMinus;

	// Input String
	std::string sInputString;

	// Conversion Variables
	std::stack<char> operatorStack;
	std::string sMemory;

	// Return Result Vector
	std::vector<std::string> resultvString;
};

#endif //!Operations_H_