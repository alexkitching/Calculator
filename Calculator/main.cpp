////////////////////////////////////////////////////////////////////
// File: <main.cpp>
// Author: <Alex Kitching>
// Date Created: <15/02/17>
// Brief: <Source file for the Main Function.>
////////////////////////////////////////////////////////////////////

#include <iostream>
#include <string.h>


#include "CalculatorForm.h"

using namespace System;
using namespace System::Windows::Forms;
using namespace Calculator;

int main(int argv, char* argc[])
{
	CalculatorForm form;
	Application::Run(%form);
	return 0;
}