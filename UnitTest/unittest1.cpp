#include "stdafx.h"
#include "CppUnitTest.h"
#include "..\CalculatorLib\Calc.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest
{		
	TEST_CLASS(UnitTest1)
	{
	public:
		Calc calc;
		TEST_METHOD(Addition)
		{
			Assert::AreEqual(2.f, calc.Calculate("1+1"));
		}

		TEST_METHOD(Subtraction)
		{
			Assert::AreEqual(0.f, calc.Calculate("1-1"));
		}

		TEST_METHOD(Multiplication)
		{
			Assert::AreEqual(6.f, calc.Calculate("2*3"));
		}

		TEST_METHOD(Division)
		{
			Assert::AreEqual(2.f, calc.Calculate("4/2"));
		}

		TEST_METHOD(DecimalHandling)
		{
			Assert::AreEqual(2.2f, calc.Calculate("1.2+1"));
		}

		TEST_METHOD(NegativeHandling)
		{
			Assert::AreEqual(1.f, calc.Calculate("-1+2"));
		}

		TEST_METHOD(ParenthesisHandling)
		{
			// Correct Priority Answer
			Assert::AreEqual(4.f, calc.Calculate("(1+1)*2"));
			// Incorrect Priority Answer
			Assert::AreNotEqual(3.f, calc.Calculate("(1+1)*2"));
		}

		TEST_METHOD(SquareRoot)
		{
			Assert::AreEqual(6.f, calc.Calculate("sqrt36"));
		}

		TEST_METHOD(Inverse)
		{
			Assert::AreEqual(10.f, calc.Calculate("0.1^-1"));
		}

		TEST_METHOD(Modulus)
		{
			Assert::AreEqual(2.f, calc.Calculate("2%3"));
		}

		TEST_METHOD(Sin)
		{
			Assert::AreEqual(1.f, calc.Calculate("sin90"));
		}

		TEST_METHOD(Cos)
		{
			Assert::AreEqual(0.9998477f, calc.Calculate("cos1"));
		}

		TEST_METHOD(Tan)
		{
			Assert::AreEqual(1.f, calc.Calculate("tan45"));
		}

		TEST_METHOD(Pi)
		{
			Assert::AreEqual(3.14159274f, calc.Calculate("pi"));
		}

		TEST_METHOD(AdditionSubtractionPriority)
		{
			// Correct Priority Answer
			Assert::AreEqual(6.f, calc.Calculate("4+6-7+3"));
		}

		TEST_METHOD(AdditionMultiplicationPriority)
		{
			// Correct Priority Answer
			Assert::AreEqual(14.f, calc.Calculate("2+3*4"));
			// Incorrect Priority Answer
			Assert::AreNotEqual(20.f, calc.Calculate("2+3*4"));
		}

		TEST_METHOD(AdditionDivisionPriority)
		{
			// Correct Priority Answer
			Assert::AreEqual(4.f, calc.Calculate("2+4/2"));
			// Incorrect Priority Answer
			Assert::AreNotEqual(3.f, calc.Calculate("2+4/2"));
		}

		TEST_METHOD(AdditionModulusPriority)
		{
			// Correct Priority Answer
			Assert::AreEqual(2.f, calc.Calculate("1+3%2"));
			// Incorrect Priority Answer
			Assert::AreNotEqual(0.f, calc.Calculate("1+3%2"));
		}

		TEST_METHOD(AdditionPowerPriority)
		{
			// Correct Priority Answer
			Assert::AreEqual(10.f, calc.Calculate("1+3^2"));
			// Incorrect Priority Answer
			Assert::AreNotEqual(16.f, calc.Calculate("1+3^2"));
		}

		TEST_METHOD(AdditionSqrtPriority)
		{
			// Correct Priority Answer
			Assert::AreEqual(3.f, calc.Calculate("1+sqrt4"));
			// Incorrect Priority Answer
			// Calc would break attempting to add an operator
		}

		TEST_METHOD(AdditionSinPriority)
		{
			// Correct Priority Answer
			Assert::AreEqual(2.f, calc.Calculate("1+sin90"));
			// Incorrect Priority Answer
			// Calc would break attempting to add an operator
		}

		TEST_METHOD(AdditionCosPriority)
		{
			// Correct Priority Answer
			Assert::AreEqual(1.9998477f, calc.Calculate("1+cos1"));
			// Incorrect Priority Answer
			// Calc would break attempting to add an operator
		}

		TEST_METHOD(AdditionTanPriority)
		{
			// Correct Priority Answer
			Assert::AreEqual(2.f, calc.Calculate("1+tan45"));
			// Incorrect Priority Answer
			// Calc would break attempting to add an operator
		}

		TEST_METHOD(SubtractMultiplicationPriority)
		{
			// Correct Priority Answer
			Assert::AreEqual(-10.f, calc.Calculate("2-3*4"));
			// Incorrect Priority Answer
			Assert::AreNotEqual(-4.f, calc.Calculate("2-3*4"));
		}

		TEST_METHOD(SubtractDivisionPriority)
		{
			// Correct Priority Answer
			Assert::AreEqual(0.f, calc.Calculate("2-4/2"));
			// Incorrect Priority Answer
			Assert::AreNotEqual(-1.f, calc.Calculate("2-4/2"));
		}

		TEST_METHOD(SubtractModulusPriority)
		{
			// Correct Priority Answer
			Assert::AreEqual(-1.f, calc.Calculate("2-7%4"));
			// Incorrect Priority Answer
			Assert::AreNotEqual(3.f, calc.Calculate("2-7%4"));
		}

		TEST_METHOD(SubtractPowerPriority)
		{
			// Correct Priority Answer
			Assert::AreEqual(-8.f, calc.Calculate("1-3^2"));
			// Incorrect Priority Answer
			Assert::AreNotEqual(-4.f, calc.Calculate("1-3^2"));
		}

		TEST_METHOD(SubtractSqrtPriority)
		{
			// Correct Priority Answer
			Assert::AreEqual(-1.f, calc.Calculate("1-sqrt4"));
			// Incorrect Priority Answer
			// Calc would break attempting to add an operator
		}

		TEST_METHOD(SubtractSinPriority)
		{
			// Correct Priority Answer
			Assert::AreEqual(0.f, calc.Calculate("1-sin90"));
			// Incorrect Priority Answer
			// Calc would break attempting to add an operator
		}

		TEST_METHOD(SubtractCosPriority)
		{
			// Correct Priority Answer
			Assert::AreEqual(0.000152289867f, calc.Calculate("1-cos1"));
			// Incorrect Priority Answer
			// Calc would break attempting to add an operator
		}

		TEST_METHOD(SubtractTanPriority)
		{
			// Correct Priority Answer
			Assert::AreEqual(0.f, calc.Calculate("1-tan45"));
			// Incorrect Priority Answer
			// Calc would break attempting to add an operator
		}

		TEST_METHOD(DivisionMultiplicationPriority)
		{
			// Correct Priority Answer
			Assert::AreEqual(17.f, calc.Calculate("4*5/2+7"));
		}
	};
}