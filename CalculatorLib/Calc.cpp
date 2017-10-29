////////////////////////////////////////////////////////////////////
// File: <InfixtoPostfix.cpp>
// Author: <Alex Kitching>
// Date Created: <3/4/17>
// Brief: <Source file for the InfixtoPostfix Class.>
////////////////////////////////////////////////////////////////////

#include "Calc.h"
#define _USE_MATH_DEFINES 
#include <math.h>

float Calc::Calculate(std::string a_sInput)
{
	// Store Input String
	sInputString = a_sInput;

	// Print Infix Equation
	std::cout << sInputString << std::endl;

	// Scan for Advanced Ops and Convert to single char form
	ScanAndConvert();

	// Convert Infix Equation to Postfix
	Convert();

	std::stack<float> memoryStack; // Number Memory Stack
	for (std::vector<std::string>::iterator iter = resultvString.begin(); iter != resultvString.end(); ++iter) // Iterate through Result Vector String
	{
		// Print Postfix Equation
		std::cout << *iter; // Print Current String
		std::string sIter = *iter; // Dereference Iterator to String
		if (IsOperator(sIter)) // String is Op
		{
			// Declare Temporary Variables
			float fValue2;
			float fValue1;
			float fResult;

			if (sIter == "+") // Addition
			{
				// Set Values
				fValue2 = memoryStack.top();
				memoryStack.pop();
				fValue1 = memoryStack.top();
				memoryStack.pop();
				// Perform Calculation and Store Result
				fResult = Addition(fValue1, fValue2);
				memoryStack.push(fResult);
			}
			else if (sIter == "-") // Subtraction
			{
				// Set Values
				fValue2 = memoryStack.top();
				memoryStack.pop();
				fValue1 = memoryStack.top(); 
				memoryStack.pop(); 

				// Perform Calculation and Store Result
				fResult = Subtraction(fValue1, fValue2);
				memoryStack.push(fResult);
			}
			else if (sIter == "*") // Multiplication
			{
				// Set Values
				fValue2 = memoryStack.top();
				memoryStack.pop();
				fValue1 = memoryStack.top();
				memoryStack.pop();

				// Perform Calculation and Store Result
				fResult = Multiplication(fValue1, fValue2);
				memoryStack.push(fResult);
			}
			else if (sIter == "/") // Division
			{
				// Set Values
				fValue2 = memoryStack.top();
				memoryStack.pop();
				fValue1 = memoryStack.top();
				memoryStack.pop();

				// Perform Calculation and Store Result
				fResult = Division(fValue1, fValue2);
				memoryStack.push(fResult);
			}
			else if (sIter == "%") // Modulus
			{
				// Set Values
				fValue2 = memoryStack.top();
				memoryStack.pop();
				fValue1 = memoryStack.top();
				memoryStack.pop();

				// Perform Calculation and Store Result
				fResult = Modulus(fValue1, fValue2);
				memoryStack.push(fResult);
			}
			else if (sIter == "^") // Power Calculation
			{
				// Set Values
				fValue2 = memoryStack.top();
				memoryStack.pop();
				fValue1 = memoryStack.top();
				memoryStack.pop();

				// Perform Calculation and Store Result
				fResult = Power(fValue1, fValue2);
				memoryStack.push(fResult);
			}
			else if (sIter == "#") // Square Root Calculation
			{
				// Set Value
				fValue1 = memoryStack.top();
				memoryStack.pop();

				// Perform Calculation and Store Result
				fResult = SquareRoot(fValue1);
				memoryStack.push(fResult);
			}
			else if (sIter == "s") // Sin Calculation
			{
				// Set Value
				fValue1 = memoryStack.top();
				memoryStack.pop();

				// Convert Value to Radians for Caluclation
				fValue1 *= (float) (M_PI / 180);

				// Perform Calculation and Store Result
				fResult = Sin(fValue1);
				memoryStack.push(fResult);
			}
			else if (sIter == "c") // Cos Calculation
			{
				// Set Value
				fValue1 = memoryStack.top();
				memoryStack.pop();

				// Convert Value to Radians for Caluclation
				fValue1 *= (float)(M_PI / 180);

				// Perform Calculation and Store Result
				fResult = Cos(fValue1);
				memoryStack.push(fResult);
			}
			else if (sIter == "t") // Tan Calculation
			{
				// Set Value
				fValue1 = memoryStack.top();
				memoryStack.pop();

				// Convert Value to Radians for Caluclation
				fValue1 *= (float)(M_PI / 180);

				// Perform Calculation and Store Result
				fResult = Tan(fValue1);
				memoryStack.push(fResult);
			}
		}
		else if (IsOperand(sIter))
		{
			memoryStack.push(std::stof(*iter)); // Add to Memory Stack
		}
	}
	std::cout << std::endl;

	float fResult = memoryStack.top(); // Retrieve Result from Stack
	memoryStack.pop(); // Empty Stack

	return fResult; // Return Result
}

void Calc::Convert()
{
	for (auto& iter : sInputString) // Iterate through each element of String
	{
		if (IsOperand(iter)) // If We are a Number
		{
			if (!sMemory.empty()) // And the memory is not empty
			{
				if (IsOperator(sMemory.back())) // And the last element of memory is an Op
				{
					if (IsSubtract(sMemory.back()) && bIsMinus) // Last Element is Subtract Operator
					{
						bIsMinus = false;
					}
					else
					{
						AddtoResultVector();
					}
					sMemory += iter; // Add the Number to the memory
				}
				else // The last element of memory is not an Op
				{
					sMemory += iter; // Add the Number to the memory
				}
			}
			else // The memory is empty
			{
				sMemory += iter; // Add the number to the memory
			}
		}
		// If Character is an Op, pop 2 elements from stack, perform operation and push result back.
		else // Must be an Op or Parenthesis
		{
			if (IsOperator(iter)) // If We are an Op
			{
				if (!sMemory.empty()) // If MemoryStack is not empty
				{
					AddtoResultVector();
				}
				// Check for Minus Number
				if (IsSubtract(iter)) // Is Subtract Op
				{
					if (!resultvString.empty()) // Result String is not Empty
					{
						if (resultvString.size() >= 2)
						{
							if (!IsOperand(resultvString.end()[-1]) && !IsOperand(resultvString.end()[-2]))
							{
								// Last Two Elements are not numbers (Must be a negative)
								sMemory += iter; // Add Minus to Memory
								bIsMinus = true; // Memory is Minus
							}
						}
						else // Less Than 2 Elements
						{
							if (!operatorStack.empty())
							{
								// Is Negative Number
								sMemory += iter; // Add Minus to Memory
								bIsMinus = true; // Memory is Minus
							}
						}
					}
					else // Result is Empty
					{
						sMemory += iter; // Add Minus to Memory
						bIsMinus = true; // Memory is Minus
					}
				}
				// If Not Minus Number add operator
				if (!bIsMinus)
				{
					while (!operatorStack.empty() && !IsLeftParenthesis(operatorStack.top()) && IsHigherPriority(operatorStack.top(), iter))
						// Stack not empty, nor was last Op left parenthesis and previous Op is higher priority than current Op
					{
						sMemory += operatorStack.top(); // Add last Op to memory
						resultvString.push_back(sMemory); // Add Memory to result vector
						sMemory.clear(); // Clear Memory
						operatorStack.pop(); // Remove Last Op from stack
					}
					operatorStack.push(iter); // Add new Op to stack
				}
			}
			else if (IsLeftParenthesis(iter)) // We are Left Parenthesis
			{
				operatorStack.push(iter); // Add to Op Stack
			}
			else if (IsRightParenthesis(iter))  // We are Right Parenthesis
			{
				if (!sMemory.empty()) // If MemoryStack is not empty
				{
					AddtoResultVector();
				}
				while (!operatorStack.empty()) // While Op Stack Not Empty
				{
					if (IsLeftParenthesis(operatorStack.top())) // Is Left Parenthesis
					{
						operatorStack.pop(); // Remove Left Parenthesis
						break; // Stop Removing Ops from Stack
					}
					// Add Op to Memory
					sMemory += operatorStack.top();
					operatorStack.pop();
				}
			}
		}
	}
	while (!sMemory.empty()) // Push back any last numbers before operators
	{
		AddtoResultVector();
	}
	while (!operatorStack.empty()) // Push back and remaining operators
	{
		sMemory += operatorStack.top();
		operatorStack.pop();

		AddtoResultVector();
	}
}

void Calc::AddtoResultVector() // Add Memory to Result
{
	resultvString.push_back(sMemory);
	sMemory.clear();
}

void Calc::ScanAndConvert()
{
	//Check for sqrt in string and replace with # Op
	if (sInputString.find("sqrt") != std::string::npos)
	{
		// Found sqrt string
		size_t pos = sInputString.find("sqrt"); // Get Start Position of sqrt substring
		sInputString.replace(pos, 4, "#"); // Replace sqrt with #
		ScanAndConvert(); // Run Check Again
	}
	else if (sInputString.find("sin") != std::string::npos)
	{
		// Found sin string
		size_t pos = sInputString.find("sin"); // Get Start Position of the sin substring

											   // Replace original sin with s
		sInputString.replace(pos, 3, "s");

		// Run Check Again
		ScanAndConvert();
	}
	else if (sInputString.find("cos") != std::string::npos)
	{
		// Found cos string
		size_t pos = sInputString.find("cos"); // Get Start Position of the cos substring

											   // Replace original cos with c
		sInputString.replace(pos, 3, "c");

		// Run Check Again
		ScanAndConvert();
	}
	else if (sInputString.find("tan") != std::string::npos)
	{
		// Found tan string
		size_t pos = sInputString.find("tan"); // Get Start Position of the tan substring

											   // Replace original tan with t
		sInputString.replace(pos, 3, "t");

		// Run Check Again
		ScanAndConvert();
	}
	else if (sInputString.find("pi") != std::string::npos)
	{
		// Found pi string
		size_t pos = sInputString.find("pi"); // Get Start Position of the pi substring
		sInputString.replace(pos, 2, "3.14159265359");
		ScanAndConvert(); // Run Check Again
	}
}

bool Calc::IsOperator(char a_char)
{
	if (a_char == '+' || a_char == '-' || a_char == '*' || a_char == '/' || a_char == '^' || a_char == '%' || a_char == '#' ||
		a_char == 's' || a_char == 'c' || a_char == 't')
	{
		return true; // Is Operator
	}
	// Else
	return false;
}

bool Calc::IsOperator(std::string a_stringChar)
{
	if (a_stringChar == "+" || a_stringChar == "-" || a_stringChar == "*" || a_stringChar == "/" || a_stringChar == "^" || a_stringChar == "%" || a_stringChar == "#" ||
		a_stringChar == "s" || a_stringChar == "c" || a_stringChar == "t")
	{
		return true; // Is Operator
	}
	// Else
	return false;
}

bool Calc::IsSubtract(char a_char)
{
	if (a_char == '-')
	{
		return true; // Is Operator
	}
	// Else
	return false;
}

bool Calc::IsOperand(char a_char)
{
	if (!IsOperator(a_char) && !IsLeftParenthesis(a_char) && !IsRightParenthesis(a_char))
	{
		return true;
	}
	// Else
	return false;
}

bool Calc::IsOperand(std::string a_stringChar)
{
	if (!IsOperator(a_stringChar) && !IsLeftParenthesis(a_stringChar) && !IsRightParenthesis(a_stringChar))
	{
		return true;
	}
	// Else
	return false;
}

bool Calc::IsLeftParenthesis(char a_char)
{
	if (a_char == '(')
	{
		return true;
	}
	// Else
	return false;
}

bool Calc::IsLeftParenthesis(std::string a_stringChar)
{
	if (a_stringChar == "(")
	{
		return true;
	}
	// Else
	return false;
}

bool Calc::IsRightParenthesis(char a_char)
{
	if (a_char == ')')
	{
		return true;
	}
	// Else
	return false;
}

bool Calc::IsRightParenthesis(std::string a_stringChar)
{
	if (a_stringChar == ")")
	{
		return true;
	}
	// Else
	return false;
}

bool Calc::IsHigherPriority(char a_op1, char a_op2)
{
	// Retreive Operator Priorities
	int op1Priority = GetOperatorPriority(a_op1);
	int op2Priority = GetOperatorPriority(a_op2);

	// If Operators have equal priority return true if left associative.
	if (op1Priority == op2Priority)
	{
		if (IsRightAssociative(a_op1))
		{
			return false; // Return false if right associative.
		}
		else
		{
			return true;
		}
	}
	// If operator is left-associative, left has priority.
	return op1Priority > op2Priority ? true : false;
}

int Calc::GetOperatorPriority(char a_op)
{
	int priority = -1;
	switch (a_op)
	{
		// LOWEST PRIORITY
	case '+':
	case '-':
		priority = 1;
		break;
	case '*':
	case '/':
	case '%':
		priority = 2;
		break;
	case '^':
	case '#':
	case 's':
	case 'c':
	case 't':
		priority = 3;
		break;
		// HIGHEST PRIORITY
	}
	return priority;
}

int Calc::IsRightAssociative(char a_op)
{
	if (a_op == '^')
	{
		return true;
	}
	return false;
}
