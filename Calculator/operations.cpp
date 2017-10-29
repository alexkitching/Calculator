////////////////////////////////////////////////////////////////////
// File: <operations.cpp>
// Author: <Alex Kitching>
// Date Created: <15/02/17>
// Brief: <Source file for the Operations Class.>
////////////////////////////////////////////////////////////////////

#include "operations.h"

#include <math.h>

float Addition(float const a_value1, float const a_value2)
{
	return a_value1 + a_value2;
}

float Subtraction(float const a_value1, float const a_value2)
{
	return a_value1 - a_value2;
}

float Multiplication(float const a_value1, float const a_value2)
{
	return a_value1 * a_value2;
}

float Division(float const a_value1, float const a_value2)
{
	return a_value1 / a_value2;
}

float Power(float const a_value1, float const a_value2)
{
	return powf(a_value1, a_value2);
}

float Modulus(float const a_value1, float const a_value2)
{
	return fmodf(a_value1, a_value2);
}

float Inverse(float const a_value)
{
	return 1 / a_value;
}

float SquareRoot(float const a_value)
{
	return sqrtf(a_value);
}

float Sin(float const a_value)
{
	return sinf(a_value);
}

float Cos(float const a_value)
{
	return cosf(a_value);
}

float Tan(float const a_value)
{
	return tanf(a_value);
}

