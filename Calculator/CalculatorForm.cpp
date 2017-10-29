#include "CalculatorForm.h"
#include <iostream>
#include <ctype.h>
#include <msclr\marshal_cppstd.h>
#include "..\CalculatorLib\Calc.h"

using namespace Calculator;

#pragma region Variables
std::string sInput; // Main Input/Output String
std::stack<int> sInputElemSize; 
std::stack<int> sMemoryElemSize;
bool bNewZeroAdded = false;
int iNumParenthesisOpen = 0;
bool bEquationIncomplete = false;
bool bDecimalPointPlaced = false;
#pragma endregion

#pragma region Event Handlers

System::Void Calculator::CalculatorForm::CalculatorForm_Load(System::Object ^ sender, System::EventArgs ^ e)
{
	AddElemSize(1);
}

System::Void Calculator::CalculatorForm::CalculatorForm_KeyPress(Object ^ sender, KeyPressEventArgs ^ e)
{
	if ((e->KeyChar >= '0') && (e->KeyChar <= '9') || (e->KeyChar == '+') || (e->KeyChar == '-') || (e->KeyChar == '*') || (e->KeyChar == '/') ||
		(e->KeyChar == '^') || (e->KeyChar == '%') || (e->KeyChar == '(') || (e->KeyChar == ')') || (e->KeyChar == '.') || (e->KeyChar == '=')) // Input Key Pressed
	{
		switch (e->KeyChar) 
		{
		case '0':
			InsertValue(bZero->Text);
			break;
		case '1':
			InsertValue(bOne->Text);
			break;
		case '2':
			InsertValue(bTwo->Text);
			break;
		case '3':
			InsertValue(bThree->Text);
			break;
		case '4':
			InsertValue(bFour->Text);
			break;
		case '5':
			InsertValue(bFive->Text);
			break;
		case '6':
			InsertValue(bSix->Text);
			break;
		case '7':
			InsertValue(bSeven->Text);
			break;
		case '8':
			InsertValue(bEight->Text);
			break;
		case '9':
			InsertValue(bNine->Text);
			break;
		case '+':
			InsertAdd();
			break;
		case '-':
			InsertMinus();
			break;
		case '*':
			InsertMultiply();
			break;
		case '/':
			InsertDivide();
			break;
		case '^':
			InsertPower();
			break;
		case '%':
			InsertModulus();
			break;
		case '(':
			InsertLeftParenthesis();
			break;
		case ')':
			InsertRightParenthesis();
			break;
		case '.':
			InsertDecimal();
			break;
		case '=':
			Equals();
			break;
		}
	}
}

// Numbers
System::Void Calculator::CalculatorForm::bZero_Click(System::Object^  sender, System::EventArgs^  e)
{
	InsertValue(bZero->Text);
}

System::Void Calculator::CalculatorForm::bOne_Click(System::Object ^ sender, System::EventArgs ^ e)
{
	InsertValue(bOne->Text);
}

System::Void Calculator::CalculatorForm::bTwo_Click(System::Object ^ sender, System::EventArgs ^ e)
{
	InsertValue(bTwo->Text);
}

System::Void Calculator::CalculatorForm::bThree_Click(System::Object ^ sender, System::EventArgs ^ e)
{
	InsertValue(bThree->Text);
}

System::Void Calculator::CalculatorForm::bFour_Click(System::Object ^ sender, System::EventArgs ^ e)
{
	InsertValue(bFour->Text);
}

System::Void Calculator::CalculatorForm::bFive_Click(System::Object ^ sender, System::EventArgs ^ e)
{
	InsertValue(bFive->Text);
}

System::Void Calculator::CalculatorForm::bSix_Click(System::Object ^ sender, System::EventArgs ^ e)
{
	InsertValue(bSix->Text);
}

System::Void Calculator::CalculatorForm::bSeven_Click(System::Object ^ sender, System::EventArgs ^ e)
{
	InsertValue(bSeven->Text);
}

System::Void Calculator::CalculatorForm::bEight_Click(System::Object ^ sender, System::EventArgs ^ e)
{
	InsertValue(bEight->Text);
}

System::Void Calculator::CalculatorForm::bNine_Click(System::Object ^ sender, System::EventArgs ^ e)
{
	InsertValue(bNine->Text);
}

System::Void Calculator::CalculatorForm::bPi_Click(System::Object ^ sender, System::EventArgs ^ e)
{
	InsertPi();
}

// Parenthesis
System::Void Calculator::CalculatorForm::bLeftParenthesis_Click(System::Object ^ sender, System::EventArgs ^ e)
{
	InsertLeftParenthesis();
}

System::Void Calculator::CalculatorForm::bRightParenthesis_Click(System::Object ^ sender, System::EventArgs ^ e)
{
	InsertRightParenthesis();
}

// Operations
System::Void Calculator::CalculatorForm::bAdd_Click(System::Object ^ sender, System::EventArgs ^ e)
{
	InsertAdd();
}

System::Void Calculator::CalculatorForm::bMinus_Click(System::Object ^ sender, System::EventArgs ^ e)
{
	InsertMinus();
}

System::Void Calculator::CalculatorForm::bMultiply_Click(System::Object ^ sender, System::EventArgs ^ e)
{
	InsertMultiply();
}

System::Void Calculator::CalculatorForm::bDivide_Click(System::Object ^ sender, System::EventArgs ^ e)
{
	InsertDivide();
}

// Advanced Operations
System::Void Calculator::CalculatorForm::bPower_Click(System::Object ^ sender, System::EventArgs ^ e)
{
	InsertPower();
}

System::Void Calculator::CalculatorForm::bModulus_Click(System::Object ^ sender, System::EventArgs ^ e)
{
	InsertModulus();
}

System::Void Calculator::CalculatorForm::bRoot_Click(System::Object ^ sender, System::EventArgs ^ e)
{
	InsertSqrtorTrig(bRoot->Text);
}

System::Void Calculator::CalculatorForm::bInverse_Click(System::Object ^ sender, System::EventArgs ^ e)
{
	InsertInverse();
}

System::Void Calculator::CalculatorForm::bSin_Click(System::Object ^ sender, System::EventArgs ^ e)
{
	InsertSqrtorTrig(bSin->Text);
}

System::Void Calculator::CalculatorForm::bCos_Click(System::Object ^ sender, System::EventArgs ^ e)
{
	InsertSqrtorTrig(bCos->Text);
}

System::Void Calculator::CalculatorForm::bTan_Click(System::Object ^ sender, System::EventArgs ^ e)
{
	InsertSqrtorTrig(bTan->Text);
}

System::Void Calculator::CalculatorForm::bPoint_Click(System::Object ^ sender, System::EventArgs ^ e)
{
	InsertDecimal();
}

// Memory Functions
System::Void Calculator::CalculatorForm::bMPlus_Click(System::Object ^ sender, System::EventArgs ^ e)
{
	AddtoMemory();
}

System::Void Calculator::CalculatorForm::bMClear_Click(System::Object ^ sender, System::EventArgs ^ e)
{
	ClearMemory();
}

System::Void Calculator::CalculatorForm::bMRecall_Click(System::Object ^ sender, System::EventArgs ^ e)
{
	RecallMemory();
}

System::Void Calculator::CalculatorForm::bClear_Click(System::Object ^ sender, System::EventArgs ^ e)
{
	Clear();
}

System::Void Calculator::CalculatorForm::bClearLast_Click(System::Object ^ sender, System::EventArgs ^ e)
{
	ClearLast();
}

// Calculate Functions
System::Void Calculator::CalculatorForm::bEquals_Click(System::Object ^ sender, System::EventArgs ^ e)
{
	Equals();
}

// Update Input Functions
void Calculator::CalculatorForm::InsertValue(System::String^ a_sValue)
{
	RefreshInputString();

	if (IsZero(a_sValue)) // Value is Zero
	{
		if (!IsZero(sInput)) // Input is not Zero
		{
			if (bEquationIncomplete) 
			{
				bEquationIncomplete = false; // No Longer Incomplete
			}
			if (IsPi(sInput.back()))
			{
				lInput->Text += "*" + a_sValue;
				AddElemSize(1);
				AddElemSize(lInput->Text->Length);
			}
			else
			{
				lInput->Text += a_sValue; // Add Value to Equation
				AddElemSize(lInput->Text->Length);
			}
		}
		else // Input is Zero
		{
			bNewZeroAdded = true;
		}
	}
	else // Value other than 0
	{
		if (bEquationIncomplete) 
		{
			bEquationIncomplete = false;  // No Longer Incomplete
		}
		if (sInput != "0") // If Input has changed
		{
			if (bNewZeroAdded)
			{
				bNewZeroAdded = false;
			}
			lInput->Text += a_sValue; // Add Value to Equation
			AddElemSize(lInput->Text->Length);
		}
		else
		{
			lInput->Text = a_sValue; // Set Input to Value
			
			// Update Element Size
			RemoveElemSize();
			AddElemSize(a_sValue->Length);
		}
	}
}

void Calculator::CalculatorForm::InsertAdd()
{
	RefreshInputString();
	if (CanInsertOperator())  // If Operator Can be Inserted
	{
		if (bNewZeroAdded) // Input is New Zero Single Zero
		{
			bNewZeroAdded = false; // No Longer New Single Zero
		}

		if (bDecimalPointPlaced) // If Decimal Point is open
		{
			bDecimalPointPlaced = false; // Decimal Point now closed
		}
		bEquationIncomplete = true; // Equation now incomplete
		this->lInput->Text += "+"; // Add + to Equation
		AddElemSize(1);
	}
}

void Calculator::CalculatorForm::InsertMinus()
{
	RefreshInputString();
	if (IsZero(sInput)) // Input Hasn't Changed
	{
		if (bNewZeroAdded) // Input is New Zero Single Zero
		{
			bNewZeroAdded = false; // No Longer New Single Zero
			bEquationIncomplete = true; // Equation now incomplete
			this->lInput->Text += "-"; // Add - to Equation
			AddElemSize(1);
		}
		else // Input is Default Zero
		{
			bEquationIncomplete = true; // Equation now incomplete
			this->lInput->Text = "-"; // Sets Equation to -
			EraseInputElemStack();
			AddElemSize(1);
		}
	}
	else // Input has changed
	{
		if (CanInsertOperator())  // If Operator Can be Inserted
		{
			if (bNewZeroAdded) // Input is New Zero Single Zero
			{
				bNewZeroAdded = false; // No Longer New Single Zero
			}

			if (bDecimalPointPlaced) // If Decimal Point is open
			{
				bDecimalPointPlaced = false; // Decimal Point now closed
			}
			bEquationIncomplete = true; // Equation now incomplete
			this->lInput->Text += "-"; // Add - to Equation
			AddElemSize(1);
		}
		else if (IsPower(sInput.back())) // Last Op Was Power
		{
			// Equation Still Incomplete from Power
			this->lInput->Text += "-"; // Add - to Equation
			AddElemSize(1);
		}
		else // Last Element was Operator
		{
			if (sInput.length() == 1)
			{
				// Do nothing
			}
			else if (sInput.length() > 1) // Length of Equation is Longer than 1
			{
				if (sInput.length() > 2) // Length of Equation is Longer than 2
				{
					if (IsOperator(sInput[sInput.length() - 1]) && IsOperator(sInput[sInput.length() - 2])) // If Last two Elements are Operators
					{
						// Do Nothing
					}
					else if (IsLeftParenthesis(sInput[sInput.length() - 2])) // If Send to last Operator was Left Parenthesis
					{
						// Do Nothing
					}
					else
					{
						this->lInput->Text += "-"; // Add - to Equation
						AddElemSize(1);
					}
				}
				else if (IsOperator(sInput[sInput.length() - 1])) // If Second to last element is operator
				{
					this->lInput->Text += "-"; // Add - to Equation
					AddElemSize(1);
				}
			}
			else
			{
				this->lInput->Text += "-"; // Add - to Equation
				AddElemSize(1);
			}
		}
	}
}

void Calculator::CalculatorForm::InsertMultiply()
{
	RefreshInputString();
	if (CanInsertOperator())  // If Operator Can be Inserted
	{
		if (bNewZeroAdded) // Input is New Zero Single Zero
		{
			bNewZeroAdded = false; // No Longer New Single Zero
		}

		if (bDecimalPointPlaced) // If Decimal Point is open
		{
			bDecimalPointPlaced = false;// Decimal Point now closed
		}
		bEquationIncomplete = true; // Equation now incomplete
		this->lInput->Text += "*"; // Add * to Equation
		AddElemSize(1);
	}
}

void Calculator::CalculatorForm::InsertDivide()
{
	RefreshInputString();
	if (CanInsertOperator())  // If Operator Can be Inserted
	{
		if (bNewZeroAdded) // Input is New Zero Single Zero
		{
			bNewZeroAdded = false; // No Longer New Single Zero
		}

		if (bDecimalPointPlaced) // If Decimal Point is open
		{
			bDecimalPointPlaced = false; // Decimal Point now closed
		}
		bEquationIncomplete = true; // Equation now incomplete
		this->lInput->Text += "/"; // Add / to Equation
		AddElemSize(1);
	}
}

void Calculator::CalculatorForm::InsertPower()
{
	RefreshInputString();
	if (CanInsertOperator()) // If Operator Can be Inserted 
	{
		if (bNewZeroAdded) // Input is New Zero Single Zero
		{
			bNewZeroAdded = false; // No Longer New Single Zero
		}

		if (bDecimalPointPlaced) // If Decimal Point is open
		{
			bDecimalPointPlaced = false; // Decimal Point now closed
		}
		bEquationIncomplete = true; // Equation now incomplete
		this->lInput->Text += "^"; // Add ^ to Equation
		AddElemSize(1);
	}
}

void Calculator::CalculatorForm::InsertModulus()
{
	RefreshInputString();
	if (CanInsertOperator())  // If Operator Can be Inserted
	{
		if (bNewZeroAdded) // Input is New Zero Single Zero
		{
			bNewZeroAdded = false; // No Longer New Single Zero
		}

		if (bDecimalPointPlaced) // If Decimal Point is open
		{
			bDecimalPointPlaced = false; // Decimal Point now closed
		}
		bEquationIncomplete = true; // Equation now incomplete
		this->lInput->Text += "%"; // Add % to Equation
		AddElemSize(1);
	}
}

void Calculator::CalculatorForm::InsertInverse()
{
	RefreshInputString();
	if (CanInsertOperator())
	{
		if (bNewZeroAdded) // Input is New Zero Single Zero
		{
			bNewZeroAdded = false; // No Longer New Single Zero
		}

		if (bDecimalPointPlaced) // If Decimal Point is open
		{
			bDecimalPointPlaced = false; // Decimal Point now closed
		}

		if (bEquationIncomplete)
		{
			bEquationIncomplete = false;
		}
		this->lInput->Text += "^-1"; // Add ^-1 to Equation

		for (int i = 0; i < 3; i++)
		{
			AddElemSize(1);
		}
	}
}

void Calculator::CalculatorForm::InsertDecimal()
{
	RefreshInputString();
	if (CanInsertDecimalPoint()) // If Decimal Point Can be Inserted
	{
		if (bNewZeroAdded) // Input is New Zero Single Zero
		{
			bNewZeroAdded = false; // No Longer New Single Zero
		}

		bDecimalPointPlaced = true; // Decimal Point now open
		bEquationIncomplete = true; // Equation now incomplete
		this->lInput->Text += "."; // Add . to Equation
		AddElemSize(1);
	}
}

void Calculator::CalculatorForm::InsertPi()
{
	RefreshInputString();

	if (bEquationIncomplete)
	{
		bEquationIncomplete = false;
	}

	if (sInput != "0") // If Input has changed
	{
		if (bNewZeroAdded)
		{
			bNewZeroAdded = false;
		}
		if (isdigit(sInput.back()) || IsPi(sInput.back())) // If Last Item was digit
		{
			lInput->Text += "*pi";
			AddElemSize(1);
			AddElemSize(2);
		}
		else if (IsDecimal(sInput.back())) // Last Item Was Decimal
		{
			// Do Nothing
		}
		else
		{
			lInput->Text += "pi";
			AddElemSize(2);
		}
	}
	else
	{
		lInput->Text = "pi";
		AddElemSize(2);
	}
}

void Calculator::CalculatorForm::InsertLeftParenthesis()
{
	RefreshInputString();
	if (IsZero(sInput)) // If Input hasn't changed
	{
		if (bNewZeroAdded) // New Zero Added
		{
			bNewZeroAdded = false; // No Longer New Single Zero
			++iNumParenthesisOpen; // Parenthesis now open
			this->lInput->Text += "("; // Add ( to Equation
			AddElemSize(1);
		}
		else // Default Zero Remains
		{
			++iNumParenthesisOpen; // Parenthesis now open
			this->lInput->Text = "("; // Set Equation to (
			AddElemSize(1);
		}
	}
	else // Input has changed
	{
		if (CanInsertLeftParenthesis()) // If Left Parenthesis can be inserted
		{
			if (isdigit(sInput.back())) // Last Item Entered is Digit
			{
				if (bDecimalPointPlaced) // If Decimal Point is open
				{
					bDecimalPointPlaced = false; // Decimal Point now closed
				}
				++iNumParenthesisOpen; // Parenthesis now open
				this->lInput->Text += "*("; // Add *( to Equation
				AddElemSize(1);
				AddElemSize(1);
			}
			else if (IsRightParenthesis(sInput.back())) // Last Item Entered is Right Parenthesis
			{
				if (bDecimalPointPlaced) // If Decimal Point is open
				{
					bDecimalPointPlaced = false; // Decimal Point now closed
				}
				++iNumParenthesisOpen; // Parenthesis now open
				this->lInput->Text += "+("; // Add +( to Equation
				AddElemSize(1);
				AddElemSize(1);
			}
			else // Last Item Entered is Operator 
			{
				if (bDecimalPointPlaced) // If Decimal
				{
					bDecimalPointPlaced = false; // Decimal Point now closed
				}
				++iNumParenthesisOpen; // Parenthesis now open
				this->lInput->Text += "("; // Add ( to Equation
				AddElemSize(1);
			}
		}
	}
}

void Calculator::CalculatorForm::InsertRightParenthesis()
{
	RefreshInputString();
	if (CanInsertRightParenthesis()) // If Right Parenthesis can be inserted
	{
		if (bDecimalPointPlaced) // If Decimal Point is open
		{
			bDecimalPointPlaced = false; // Decimal Point now closed
		}
		--iNumParenthesisOpen; // Parenthesis now closed
		if (bEquationIncomplete && iNumParenthesisOpen == 0) // If Equation is Incomplete and Parenthesis are all closed
		{
			bEquationIncomplete = false; // Equation is no longer Incomplete
		}
		this->lInput->Text += ")"; // Add ) to Equation
		AddElemSize(1);
	}
}

void Calculator::CalculatorForm::InsertSqrtorTrig(System::String ^ a_sOp)
{
	RefreshInputString();
	if (IsZero(sInput) && !bNewZeroAdded) // Input Hasn't Changed
	{
		if (bDecimalPointPlaced) // And if Decimal Point is open
		{
			bDecimalPointPlaced = false; // Decimal Point now closed
		}
		bEquationIncomplete = true; // Equation now incomplete
		this->lInput->Text = a_sOp + "("; // Add sqrt to Equation

										  // Open Parenthesis
		++iNumParenthesisOpen;

		// Update Element Size
		RemoveElemSize();
		AddElemSize(a_sOp->Length + 1);
	}
	else // Input has changed
	{
		if (CanInsertSqrtOrTrig()) // If op Can be Inserted
		{
			if (bNewZeroAdded) // Input is New Zero Single Zero
			{
				bNewZeroAdded = false; // No Longer New Single Zero
			}

			if (isdigit(sInput.back())) // Last Item Entered is Digit
			{
				if (bDecimalPointPlaced) // If Decimal Point is open
				{
					bDecimalPointPlaced = false; // Decimal Point now closed
				}

				this->lInput->Text += "*" + a_sOp + "("; // Add *op( to Equation

														 // Open Parenthesis
				++iNumParenthesisOpen;

				// Update Element Size
				AddElemSize(1);
				AddElemSize(a_sOp->Length + 1);
			}
			else if (IsRightParenthesis(sInput.back())) // Last Item Entered is Right Parenthesis
			{
				if (bDecimalPointPlaced) // If Decimal Point is open
				{
					bDecimalPointPlaced = false; // Decimal Point now closed
				}

				this->lInput->Text += "+" + a_sOp + "("; // Add +op to Equation

														 // Open Parenthesis
				++iNumParenthesisOpen;

				// Update Element Size
				AddElemSize(1);
				AddElemSize(a_sOp->Length + 1);
			}
			else // Must be Operator or Left Parenthesis
			{
				if (bDecimalPointPlaced) // And if Decimal Point is open
				{
					bDecimalPointPlaced = false; // Decimal Point now closed
				}

				this->lInput->Text += a_sOp + "("; // Add op to Equation

												   // Open Parenthesis
				++iNumParenthesisOpen;

				// Update Element Size
				AddElemSize(a_sOp->Length + 1);
			}
		}
	}
}

void Calculator::CalculatorForm::AddtoMemory()
{
	this->lMemory->Text = this->lInput->Text; // Set Memory Label Text Equal to Input Label Text

	if (bNewZeroAdded)
	{
		bNewZeroAdded = false;
	}

	// Replace MemoryElemSize with InputElemSize 
	sMemoryElemSize = sInputElemSize;
	// Wipe InputElemSize
	EraseInputElemStack();

	this->lInput->Text = "0"; // Reset Input Label Text to Zero
	AddElemSize(1);
}

void Calculator::CalculatorForm::ClearMemory()
{
	// Wipe MemoryElemSize
	EraseMemoryElemStack();

	this->lMemory->Text = "0"; // Reset Memory Label Text to Zero
}

void Calculator::CalculatorForm::RecallMemory()
{
	this->lInput->Text = this->lMemory->Text; // Set Input Label Text Equal to Memory Label Text
	if (bNewZeroAdded)
	{
		bNewZeroAdded = false;
	}
	// Replace InputElemSize with MemoryElemSize 
	sInputElemSize = sMemoryElemSize;

	// Wipe MemoryElemSize
	EraseMemoryElemStack();

	this->lMemory->Text = "0"; // Reset Memory Label Text to Zero
}

void Calculator::CalculatorForm::Clear()
{
	if (bNewZeroAdded)
	{
		bNewZeroAdded = false;
	}

	if (iNumParenthesisOpen != 0)
	{
		iNumParenthesisOpen = 0;
	}

	// Wipe InputElemSize
	EraseInputElemStack();

	this->lInput->Text = "0"; // Reset Input Label Text to Zero
	AddElemSize(1);
}

void Calculator::CalculatorForm::ClearLast()
{
	if (!IsZero(lInput->Text)) // If Input Label Text is not Zero
	{
		RefreshInputString();

		if (sInput.length() - sInputElemSize.top() == 0)
		{
			// Last Element of Input
			sInput = "0"; // Set Input to 0

			if (iNumParenthesisOpen != 0)
			{
				iNumParenthesisOpen = 0;
			}

			// Set Last ElementSize to 1
			sInputElemSize.top() = 1;
		}
		else
		{
			// Check If Removing Parenthesis and Adjust Number of Parenthesis Open Accordingly
			if (IsRightParenthesis(sInput.back()))
			{
				++iNumParenthesisOpen;
			}
			else if (IsLeftParenthesis(sInput.back()))
			{
				--iNumParenthesisOpen;
			}

			// Remove Last Element
			for (int i = 0; i < sInputElemSize.top(); i++)
			{
				sInput.pop_back();
			}

			// Remove Last Element Size from Stack
			RemoveElemSize();
		}



		// Check Equation Isn't Complete
		if (IsDecimal(sInput.back()) || IsOperator(sInput.back()))
		{
			bEquationIncomplete = true;
		}
		String^ SystemInputString = gcnew String(sInput.c_str()); // Convert C++ String to new Windows String
		this->lInput->Text = SystemInputString; // Set Input Label Text Equal to new Windows String
	}
	else // Input Label Text is Zero
	{
		if (bNewZeroAdded) // Input is New Zero Single Zero
		{
			bNewZeroAdded = false; // No Longer New Single Zero
		}
	}
}

void Calculator::CalculatorForm::Equals()
{
	RefreshInputString();

	if (IsZero(sInput))
	{
		// Do Nothing
	}
	else  if (iNumParenthesisOpen != 0) // Parenthesis Left Open
	{
		MessageBox::Show("Please Close All Parenthesis", "Calculator", MessageBoxButtons::OK, MessageBoxIcon::Warning); // Display Messagebox
	}
	else if (bEquationIncomplete) // Equation not Complete
	{
		MessageBox::Show("Incomplete Equation Entered", "Calculator", MessageBoxButtons::OK, MessageBoxIcon::Warning); // Display Messagebox
	}
	else // Can Compute Equation
	{
		Calc calculator; // Create new Instance of Calc Class
		float fResult = calculator.Calculate(sInput); // Calculate Equation and store returned float
		sInput.clear(); // Clear Input String
		sInput = std::to_string(fResult); // Set Main Input/Output String Equal to returned float

										  // Replace ElemStack with new Elements
		EraseInputElemStack();
		for (int i = 0; i < sInput.length(); i++)
		{
			AddElemSize(1);
		}
		TrimZerosRecursively(); // Remove Excess Zeros from String
		String^ SystemOutputString = gcnew String(sInput.c_str()); // Convert C++ String to new Windows String
		this->lInput->Text = SystemOutputString; // Set Input Label Text Equal to new Windows String
	}
}

void Calculator::CalculatorForm::RefreshInputString()
{
	sInput = msclr::interop::marshal_as<std::string>(lInput->Text); // Convert Input Windows String to C++ String
}

void Calculator::CalculatorForm::AddElemSize(int a_size)
{
	sInputElemSize.push(a_size); 
}

void Calculator::CalculatorForm::RemoveElemSize()
{
	sInputElemSize.pop();
}

void Calculator::CalculatorForm::EraseInputElemStack()
{
	// Wipe InputElemSize
	while (!sInputElemSize.empty())
	{
		sInputElemSize.pop();
	}
}

void Calculator::CalculatorForm::EraseMemoryElemStack()
{
	// Wipe MemoryElemSize
	while (!sMemoryElemSize.empty())
	{
		sMemoryElemSize.pop();
	}
}

bool Calculator::CalculatorForm::CanInsertOperator()
{
	if (IsOperator(sInput.back())|| IsLeftParenthesis(sInput.back()) || IsDecimal(sInput.back()))
	{
		// If Last Input was Operator, Left Parenthesis, Square Root or Decimal Point
		return false;
	}
	else // Last Input not Operator, Left Parenthesis, Square Root or Decimal Point
	{
		return true;
	}
}

bool Calculator::CalculatorForm::CanInsertSqrtOrTrig()
{
	if (sInput.length() < 4) // Input less than 4
	{
		if (IsDecimal(sInput.back()))
		{
			// If Last Input was  Decimal Point
			return false;
		}
	}
	if (sInput.length() == 4)
	{
		const char *c_clast_4 = &sInput[sInput.length() - 4];
		if (IsDecimal(sInput.back()) || IsTrigOp(c_clast_4) || IsSqrt(c_clast_4))
		{
			// If Last Input was  Decimal Point, Sqrt or Trig Function
			return false;
		}
	}
	else if (sInput.length() == 5)
	{
		const char *c_clast_5 = &sInput[sInput.length() - 5];
		if (IsDecimal(sInput.back()) || IsTrigOp(c_clast_5) || IsSqrt(c_clast_5))
		{
			// If Last Input was  Decimal Point, Sqrt or Trig Function
			return false;
		}
	}
	else if (sInput.length() >= 6)
	{
		const char *c_clast_six = &sInput[sInput.length() - 6];
		if (IsDecimal(sInput.back()) || IsTrigOp(c_clast_six) || IsSqrt(c_clast_six))
		{
			// If Last Input was  Decimal Point, Sqrt or Trig Function
			return false;
		}
	}

	// Can Insert
	return true;
}

bool Calculator::CalculatorForm::CanInsertLeftParenthesis()
{
	if (IsLeftParenthesis(sInput.back()) || IsDecimal(sInput.back())) //  If Last Input was left Parenthesis
	{
		return false;
	}
	else if (sInput.length() == 1 && IsSubtract(sInput.back())) // If Input is '-'
	{
		return false;
	}
	return true; // Last Input not Left Parenthesis
}

bool Calculator::CalculatorForm::CanInsertRightParenthesis()
{
	if (iNumParenthesisOpen != 0) // If Parenthesis Open
	{
		if (CanInsertOperator()) // If can Insert Operator
		{
			return true; // Can Insert
		}
	}
	return false; // Cannot Insert
}

bool Calculator::CalculatorForm::CanInsertDecimalPoint()
{
	if (!bDecimalPointPlaced) // If Decimal Point Closed
	{
		if (!IsOperator(sInput.back()) && !IsParenthesis(sInput.back()) && !IsPi(sInput.back())) // If Last Input was not Operator, Parenthesis or Pi
		{ 
			// Can Insert Decimal Point
			return true;
		}
	}
	return false;
}

bool Calculator::CalculatorForm::IsOperator(char a_char)
{
	if (a_char == '+' || a_char == '-' || a_char == '*' || a_char == '/' || a_char == '^' || a_char == '%' || a_char == '#' || a_char == 'n' || a_char == 's' || a_char == 't') // Is Operator
	{
		return true;
	}
	// Else
	return false;
}

bool Calculator::CalculatorForm::IsSubtract(char a_char)
{
	if (a_char == '-') // Is Subtract
	{
		return true;
	}
	// Else
	return false;
}

bool Calculator::CalculatorForm::IsParenthesis(char a_char)
{
	if (a_char == '(' || a_char == ')') // Is Parenthesis
	{
		return true;
	}
	// Else
	return false;
}

bool Calculator::CalculatorForm::IsRightParenthesis(char a_char)
{
	if (a_char == ')') // Is Right Parenthesis
	{
		return true;
	}
	// Else
	return false;
}

bool Calculator::CalculatorForm::IsLeftParenthesis(char a_char)
{
	if (a_char == '(') // Is Left Parenthesis
	{
		return true;
	}
	// Else
	return false;
}

bool Calculator::CalculatorForm::IsTrigOp(const char* a_char)
{
	if (strcmp(a_char, "sin(") == 0 || strcmp(a_char, "cos(") == 0 || strcmp(a_char, "tan(") == 0 ) // Is Trig Function
	{
		return true;
	}
	// Else
	return false;
}

bool Calculator::CalculatorForm::IsSqrt(const char* a_char)
{
	if (strcmp(a_char, "sqrt(") == 0) // Is Sqrt
	{
		return true;
	}
	// Else
	return false;
}

bool Calculator::CalculatorForm::IsPi(char a_char)
{
	if (a_char == 'i') // Is Pi
	{
		return true;
	}
	// Else
	return false;
}

bool Calculator::CalculatorForm::IsPower(char a_char)
{
	if (a_char == '^') // Is Power
	{
		return true;
	}
	// Else
	return false;
}

bool Calculator::CalculatorForm::IsDecimal(char a_char)
{
	if (a_char == '.') // Is Decimal
	{
		return true;
	}
	// Else
	return false;
}

bool Calculator::CalculatorForm::IsZero(System::String ^ a_systemStringChar)
{
	if (a_systemStringChar == "0") // Is Zero
	{
		return true;
	}
	// Else
	return false;
}

bool Calculator::CalculatorForm::IsZero(std::string a_stringChar)
{
	if (a_stringChar == "0") // Is Zero
	{
		return true;
	}
	// Else
	return false;
}

bool Calculator::CalculatorForm::IsZero(char a_char)
{
	if (a_char == '0') // Is Zero
	{
		return true;
	}
	// Else
	return false;
}

void Calculator::CalculatorForm::TrimZerosRecursively()
{
	if (IsDecimal(sInput.back())) // If Last Element of Input String is Decimal Point
	{
		sInput.pop_back(); // Remove Last Element of Input String
	}
	else if (IsZero(sInput.back())) // If Last Element of Input String is 0
	{
		sInput.pop_back(); // Remove Last Element of Input String
		TrimZerosRecursively(); // Call This Function again to repeat
	}
}

#pragma endregion