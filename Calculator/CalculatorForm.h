#pragma once

#ifndef CALCULATORFORM_H_
#define CALCULATORFORM_H_

#include <string>
#include <stack>

namespace Calculator {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for CalculatorForm
	/// </summary>
	public ref class CalculatorForm : public System::Windows::Forms::Form
	{
	public:
		CalculatorForm(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~CalculatorForm()
		{
			if (components)
			{
				delete components;
			}
		}

	protected:
	private: System::Windows::Forms::Button^  bOne;
	private: System::Windows::Forms::Button^  bTwo;
	private: System::Windows::Forms::Button^  bThree;
	private: System::Windows::Forms::Button^  bZero;
	private: System::Windows::Forms::Button^  bFour;
	private: System::Windows::Forms::Button^  bFive;
	private: System::Windows::Forms::Button^  bSix;
	private: System::Windows::Forms::Button^  bSeven;
	private: System::Windows::Forms::Button^  bEight;
	private: System::Windows::Forms::Button^  bNine;
	private: System::Windows::Forms::Button^  bPoint;
	private: System::Windows::Forms::Button^  bClear;
	private: System::Windows::Forms::Button^  bEquals;
	private: System::Windows::Forms::Button^  bAdd;
	private: System::Windows::Forms::Button^  bMinus;
	private: System::Windows::Forms::Button^  bMultiply;
	private: System::Windows::Forms::Button^  bDivide;
	private: System::Windows::Forms::Label^  lInput;

	private: System::Windows::Forms::Button^  bMPlus;
	private: System::Windows::Forms::Button^  bMClear;

	private: System::Windows::Forms::Button^  bClearLast;
	private: System::Windows::Forms::Button^  bRoot;
	private: System::Windows::Forms::Button^  bInverse;
	private: System::Windows::Forms::Label^  lMemory;
	private: System::Windows::Forms::Button^  bMRecall;
	private: System::Windows::Forms::Button^  bPower;
	private: System::Windows::Forms::Button^  bLeftParenthesis;
	private: System::Windows::Forms::Button^  bRightParenthesis;
	private: System::Windows::Forms::Button^  bModulus;
	private: System::Windows::Forms::Button^  bPi;
	private: System::Windows::Forms::Button^  bSin;
	private: System::Windows::Forms::Button^  bCos;
	private: System::Windows::Forms::Button^  bTan;










	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->bOne = (gcnew System::Windows::Forms::Button());
			this->bTwo = (gcnew System::Windows::Forms::Button());
			this->bThree = (gcnew System::Windows::Forms::Button());
			this->bZero = (gcnew System::Windows::Forms::Button());
			this->bFour = (gcnew System::Windows::Forms::Button());
			this->bFive = (gcnew System::Windows::Forms::Button());
			this->bSix = (gcnew System::Windows::Forms::Button());
			this->bSeven = (gcnew System::Windows::Forms::Button());
			this->bEight = (gcnew System::Windows::Forms::Button());
			this->bNine = (gcnew System::Windows::Forms::Button());
			this->bPoint = (gcnew System::Windows::Forms::Button());
			this->bClear = (gcnew System::Windows::Forms::Button());
			this->bEquals = (gcnew System::Windows::Forms::Button());
			this->bAdd = (gcnew System::Windows::Forms::Button());
			this->bMinus = (gcnew System::Windows::Forms::Button());
			this->bMultiply = (gcnew System::Windows::Forms::Button());
			this->bDivide = (gcnew System::Windows::Forms::Button());
			this->lInput = (gcnew System::Windows::Forms::Label());
			this->bMPlus = (gcnew System::Windows::Forms::Button());
			this->bMClear = (gcnew System::Windows::Forms::Button());
			this->bClearLast = (gcnew System::Windows::Forms::Button());
			this->bRoot = (gcnew System::Windows::Forms::Button());
			this->bInverse = (gcnew System::Windows::Forms::Button());
			this->lMemory = (gcnew System::Windows::Forms::Label());
			this->bMRecall = (gcnew System::Windows::Forms::Button());
			this->bPower = (gcnew System::Windows::Forms::Button());
			this->bLeftParenthesis = (gcnew System::Windows::Forms::Button());
			this->bRightParenthesis = (gcnew System::Windows::Forms::Button());
			this->bModulus = (gcnew System::Windows::Forms::Button());
			this->bPi = (gcnew System::Windows::Forms::Button());
			this->bSin = (gcnew System::Windows::Forms::Button());
			this->bCos = (gcnew System::Windows::Forms::Button());
			this->bTan = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// bOne
			// 
			this->bOne->Location = System::Drawing::Point(12, 266);
			this->bOne->Name = L"bOne";
			this->bOne->Size = System::Drawing::Size(42, 35);
			this->bOne->TabIndex = 1;
			this->bOne->Text = L"1";
			this->bOne->UseVisualStyleBackColor = true;
			this->bOne->Click += gcnew System::EventHandler(this, &CalculatorForm::bOne_Click);
			// 
			// bTwo
			// 
			this->bTwo->Location = System::Drawing::Point(59, 267);
			this->bTwo->Name = L"bTwo";
			this->bTwo->Size = System::Drawing::Size(42, 35);
			this->bTwo->TabIndex = 2;
			this->bTwo->Text = L"2";
			this->bTwo->UseVisualStyleBackColor = true;
			this->bTwo->Click += gcnew System::EventHandler(this, &CalculatorForm::bTwo_Click);
			// 
			// bThree
			// 
			this->bThree->Location = System::Drawing::Point(107, 267);
			this->bThree->Name = L"bThree";
			this->bThree->Size = System::Drawing::Size(42, 35);
			this->bThree->TabIndex = 3;
			this->bThree->Text = L"3";
			this->bThree->UseVisualStyleBackColor = true;
			this->bThree->Click += gcnew System::EventHandler(this, &CalculatorForm::bThree_Click);
			// 
			// bZero
			// 
			this->bZero->Location = System::Drawing::Point(13, 308);
			this->bZero->Name = L"bZero";
			this->bZero->Size = System::Drawing::Size(88, 35);
			this->bZero->TabIndex = 4;
			this->bZero->Text = L"0";
			this->bZero->UseVisualStyleBackColor = true;
			this->bZero->Click += gcnew System::EventHandler(this, &CalculatorForm::bZero_Click);
			// 
			// bFour
			// 
			this->bFour->Location = System::Drawing::Point(11, 226);
			this->bFour->Name = L"bFour";
			this->bFour->Size = System::Drawing::Size(42, 35);
			this->bFour->TabIndex = 5;
			this->bFour->Text = L"4";
			this->bFour->UseVisualStyleBackColor = true;
			this->bFour->Click += gcnew System::EventHandler(this, &CalculatorForm::bFour_Click);
			// 
			// bFive
			// 
			this->bFive->Location = System::Drawing::Point(59, 226);
			this->bFive->Name = L"bFive";
			this->bFive->Size = System::Drawing::Size(42, 35);
			this->bFive->TabIndex = 6;
			this->bFive->Text = L"5";
			this->bFive->UseVisualStyleBackColor = true;
			this->bFive->Click += gcnew System::EventHandler(this, &CalculatorForm::bFive_Click);
			// 
			// bSix
			// 
			this->bSix->Location = System::Drawing::Point(107, 226);
			this->bSix->Name = L"bSix";
			this->bSix->Size = System::Drawing::Size(42, 35);
			this->bSix->TabIndex = 7;
			this->bSix->Text = L"6";
			this->bSix->UseVisualStyleBackColor = true;
			this->bSix->Click += gcnew System::EventHandler(this, &CalculatorForm::bSix_Click);
			// 
			// bSeven
			// 
			this->bSeven->Location = System::Drawing::Point(11, 185);
			this->bSeven->Name = L"bSeven";
			this->bSeven->Size = System::Drawing::Size(42, 35);
			this->bSeven->TabIndex = 8;
			this->bSeven->Text = L"7";
			this->bSeven->UseVisualStyleBackColor = true;
			this->bSeven->Click += gcnew System::EventHandler(this, &CalculatorForm::bSeven_Click);
			// 
			// bEight
			// 
			this->bEight->Location = System::Drawing::Point(59, 185);
			this->bEight->Name = L"bEight";
			this->bEight->Size = System::Drawing::Size(42, 35);
			this->bEight->TabIndex = 9;
			this->bEight->Text = L"8";
			this->bEight->UseVisualStyleBackColor = true;
			this->bEight->Click += gcnew System::EventHandler(this, &CalculatorForm::bEight_Click);
			// 
			// bNine
			// 
			this->bNine->Location = System::Drawing::Point(107, 185);
			this->bNine->Name = L"bNine";
			this->bNine->Size = System::Drawing::Size(42, 35);
			this->bNine->TabIndex = 10;
			this->bNine->Text = L"9";
			this->bNine->UseVisualStyleBackColor = true;
			this->bNine->Click += gcnew System::EventHandler(this, &CalculatorForm::bNine_Click);
			// 
			// bPoint
			// 
			this->bPoint->Location = System::Drawing::Point(107, 308);
			this->bPoint->Name = L"bPoint";
			this->bPoint->Size = System::Drawing::Size(42, 35);
			this->bPoint->TabIndex = 11;
			this->bPoint->Text = L".";
			this->bPoint->UseVisualStyleBackColor = true;
			this->bPoint->Click += gcnew System::EventHandler(this, &CalculatorForm::bPoint_Click);
			// 
			// bClear
			// 
			this->bClear->Location = System::Drawing::Point(60, 145);
			this->bClear->Name = L"bClear";
			this->bClear->Size = System::Drawing::Size(42, 35);
			this->bClear->TabIndex = 12;
			this->bClear->Text = L"C";
			this->bClear->UseVisualStyleBackColor = true;
			this->bClear->Click += gcnew System::EventHandler(this, &CalculatorForm::bClear_Click);
			// 
			// bEquals
			// 
			this->bEquals->Location = System::Drawing::Point(203, 267);
			this->bEquals->Name = L"bEquals";
			this->bEquals->Size = System::Drawing::Size(42, 76);
			this->bEquals->TabIndex = 13;
			this->bEquals->Text = L"=";
			this->bEquals->UseVisualStyleBackColor = true;
			this->bEquals->Click += gcnew System::EventHandler(this, &CalculatorForm::bEquals_Click);
			// 
			// bAdd
			// 
			this->bAdd->Location = System::Drawing::Point(155, 308);
			this->bAdd->Name = L"bAdd";
			this->bAdd->Size = System::Drawing::Size(42, 35);
			this->bAdd->TabIndex = 14;
			this->bAdd->Text = L"+";
			this->bAdd->UseVisualStyleBackColor = true;
			this->bAdd->Click += gcnew System::EventHandler(this, &CalculatorForm::bAdd_Click);
			// 
			// bMinus
			// 
			this->bMinus->Location = System::Drawing::Point(155, 267);
			this->bMinus->Name = L"bMinus";
			this->bMinus->Size = System::Drawing::Size(42, 35);
			this->bMinus->TabIndex = 15;
			this->bMinus->Text = L"-";
			this->bMinus->UseVisualStyleBackColor = true;
			this->bMinus->Click += gcnew System::EventHandler(this, &CalculatorForm::bMinus_Click);
			// 
			// bMultiply
			// 
			this->bMultiply->Location = System::Drawing::Point(155, 226);
			this->bMultiply->Name = L"bMultiply";
			this->bMultiply->Size = System::Drawing::Size(42, 35);
			this->bMultiply->TabIndex = 16;
			this->bMultiply->Text = L"*";
			this->bMultiply->UseVisualStyleBackColor = true;
			this->bMultiply->Click += gcnew System::EventHandler(this, &CalculatorForm::bMultiply_Click);
			// 
			// bDivide
			// 
			this->bDivide->Location = System::Drawing::Point(155, 185);
			this->bDivide->Name = L"bDivide";
			this->bDivide->Size = System::Drawing::Size(42, 35);
			this->bDivide->TabIndex = 17;
			this->bDivide->Text = L"/";
			this->bDivide->UseVisualStyleBackColor = true;
			this->bDivide->Click += gcnew System::EventHandler(this, &CalculatorForm::bDivide_Click);
			// 
			// lInput
			// 
			this->lInput->BackColor = System::Drawing::SystemColors::Window;
			this->lInput->BorderStyle = System::Windows::Forms::BorderStyle::Fixed3D;
			this->lInput->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lInput->Location = System::Drawing::Point(12, 27);
			this->lInput->Name = L"lInput";
			this->lInput->RightToLeft = System::Windows::Forms::RightToLeft::No;
			this->lInput->Size = System::Drawing::Size(231, 30);
			this->lInput->TabIndex = 18;
			this->lInput->Text = L"0";
			this->lInput->TextAlign = System::Drawing::ContentAlignment::TopRight;
			// 
			// bMPlus
			// 
			this->bMPlus->Location = System::Drawing::Point(60, 62);
			this->bMPlus->Name = L"bMPlus";
			this->bMPlus->Size = System::Drawing::Size(42, 35);
			this->bMPlus->TabIndex = 20;
			this->bMPlus->Text = L"M+";
			this->bMPlus->UseVisualStyleBackColor = true;
			this->bMPlus->Click += gcnew System::EventHandler(this, &CalculatorForm::bMPlus_Click);
			// 
			// bMClear
			// 
			this->bMClear->Location = System::Drawing::Point(107, 62);
			this->bMClear->Name = L"bMClear";
			this->bMClear->Size = System::Drawing::Size(42, 35);
			this->bMClear->TabIndex = 21;
			this->bMClear->Text = L"MC";
			this->bMClear->UseVisualStyleBackColor = true;
			this->bMClear->Click += gcnew System::EventHandler(this, &CalculatorForm::bMClear_Click);
			// 
			// bClearLast
			// 
			this->bClearLast->Location = System::Drawing::Point(12, 145);
			this->bClearLast->Name = L"bClearLast";
			this->bClearLast->Size = System::Drawing::Size(42, 35);
			this->bClearLast->TabIndex = 22;
			this->bClearLast->Text = L"CE";
			this->bClearLast->UseVisualStyleBackColor = true;
			this->bClearLast->Click += gcnew System::EventHandler(this, &CalculatorForm::bClearLast_Click);
			// 
			// bRoot
			// 
			this->bRoot->Location = System::Drawing::Point(203, 144);
			this->bRoot->Name = L"bRoot";
			this->bRoot->Size = System::Drawing::Size(42, 35);
			this->bRoot->TabIndex = 23;
			this->bRoot->Text = L"sqrt";
			this->bRoot->UseVisualStyleBackColor = true;
			this->bRoot->Click += gcnew System::EventHandler(this, &CalculatorForm::bRoot_Click);
			// 
			// bInverse
			// 
			this->bInverse->Location = System::Drawing::Point(203, 226);
			this->bInverse->Name = L"bInverse";
			this->bInverse->Size = System::Drawing::Size(42, 35);
			this->bInverse->TabIndex = 24;
			this->bInverse->Text = L"1/x";
			this->bInverse->UseVisualStyleBackColor = true;
			this->bInverse->Click += gcnew System::EventHandler(this, &CalculatorForm::bInverse_Click);
			// 
			// lMemory
			// 
			this->lMemory->BorderStyle = System::Windows::Forms::BorderStyle::Fixed3D;
			this->lMemory->Location = System::Drawing::Point(12, 4);
			this->lMemory->Name = L"lMemory";
			this->lMemory->Size = System::Drawing::Size(231, 18);
			this->lMemory->TabIndex = 25;
			this->lMemory->Text = L"0";
			// 
			// bMRecall
			// 
			this->bMRecall->Location = System::Drawing::Point(12, 62);
			this->bMRecall->Name = L"bMRecall";
			this->bMRecall->Size = System::Drawing::Size(42, 35);
			this->bMRecall->TabIndex = 26;
			this->bMRecall->Text = L"MR";
			this->bMRecall->UseVisualStyleBackColor = true;
			this->bMRecall->Click += gcnew System::EventHandler(this, &CalculatorForm::bMRecall_Click);
			// 
			// bPower
			// 
			this->bPower->Location = System::Drawing::Point(155, 144);
			this->bPower->Name = L"bPower";
			this->bPower->Size = System::Drawing::Size(42, 35);
			this->bPower->TabIndex = 27;
			this->bPower->Text = L"^x";
			this->bPower->UseVisualStyleBackColor = true;
			this->bPower->Click += gcnew System::EventHandler(this, &CalculatorForm::bPower_Click);
			// 
			// bLeftParenthesis
			// 
			this->bLeftParenthesis->Location = System::Drawing::Point(155, 103);
			this->bLeftParenthesis->Name = L"bLeftParenthesis";
			this->bLeftParenthesis->Size = System::Drawing::Size(42, 35);
			this->bLeftParenthesis->TabIndex = 28;
			this->bLeftParenthesis->Text = L"(";
			this->bLeftParenthesis->UseVisualStyleBackColor = true;
			this->bLeftParenthesis->Click += gcnew System::EventHandler(this, &CalculatorForm::bLeftParenthesis_Click);
			// 
			// bRightParenthesis
			// 
			this->bRightParenthesis->Location = System::Drawing::Point(201, 104);
			this->bRightParenthesis->Name = L"bRightParenthesis";
			this->bRightParenthesis->Size = System::Drawing::Size(42, 35);
			this->bRightParenthesis->TabIndex = 29;
			this->bRightParenthesis->Text = L")";
			this->bRightParenthesis->UseVisualStyleBackColor = true;
			this->bRightParenthesis->Click += gcnew System::EventHandler(this, &CalculatorForm::bRightParenthesis_Click);
			// 
			// bModulus
			// 
			this->bModulus->Location = System::Drawing::Point(203, 185);
			this->bModulus->Name = L"bModulus";
			this->bModulus->Size = System::Drawing::Size(42, 35);
			this->bModulus->TabIndex = 30;
			this->bModulus->Text = L"%";
			this->bModulus->UseVisualStyleBackColor = true;
			this->bModulus->Click += gcnew System::EventHandler(this, &CalculatorForm::bModulus_Click);
			// 
			// bPi
			// 
			this->bPi->Location = System::Drawing::Point(107, 144);
			this->bPi->Name = L"bPi";
			this->bPi->Size = System::Drawing::Size(42, 35);
			this->bPi->TabIndex = 31;
			this->bPi->Text = L"pi";
			this->bPi->UseVisualStyleBackColor = true;
			this->bPi->Click += gcnew System::EventHandler(this, &CalculatorForm::bPi_Click);
			// 
			// bSin
			// 
			this->bSin->Location = System::Drawing::Point(13, 104);
			this->bSin->Name = L"bSin";
			this->bSin->Size = System::Drawing::Size(42, 35);
			this->bSin->TabIndex = 32;
			this->bSin->Text = L"sin";
			this->bSin->UseVisualStyleBackColor = true;
			this->bSin->Click += gcnew System::EventHandler(this, &CalculatorForm::bSin_Click);
			// 
			// bCos
			// 
			this->bCos->Location = System::Drawing::Point(59, 104);
			this->bCos->Name = L"bCos";
			this->bCos->Size = System::Drawing::Size(42, 35);
			this->bCos->TabIndex = 33;
			this->bCos->Text = L"cos";
			this->bCos->UseVisualStyleBackColor = true;
			this->bCos->Click += gcnew System::EventHandler(this, &CalculatorForm::bCos_Click);
			// 
			// bTan
			// 
			this->bTan->Location = System::Drawing::Point(107, 104);
			this->bTan->Name = L"bTan";
			this->bTan->Size = System::Drawing::Size(42, 35);
			this->bTan->TabIndex = 34;
			this->bTan->Text = L"tan";
			this->bTan->UseVisualStyleBackColor = true;
			this->bTan->Click += gcnew System::EventHandler(this, &CalculatorForm::bTan_Click);
			// 
			// CalculatorForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(256, 355);
			this->Controls->Add(this->bTan);
			this->Controls->Add(this->bCos);
			this->Controls->Add(this->bSin);
			this->Controls->Add(this->bPi);
			this->Controls->Add(this->bModulus);
			this->Controls->Add(this->bRightParenthesis);
			this->Controls->Add(this->bLeftParenthesis);
			this->Controls->Add(this->bPower);
			this->Controls->Add(this->bMRecall);
			this->Controls->Add(this->lMemory);
			this->Controls->Add(this->bInverse);
			this->Controls->Add(this->bRoot);
			this->Controls->Add(this->bClearLast);
			this->Controls->Add(this->bMClear);
			this->Controls->Add(this->bMPlus);
			this->Controls->Add(this->lInput);
			this->Controls->Add(this->bDivide);
			this->Controls->Add(this->bMultiply);
			this->Controls->Add(this->bMinus);
			this->Controls->Add(this->bAdd);
			this->Controls->Add(this->bEquals);
			this->Controls->Add(this->bClear);
			this->Controls->Add(this->bPoint);
			this->Controls->Add(this->bNine);
			this->Controls->Add(this->bEight);
			this->Controls->Add(this->bSeven);
			this->Controls->Add(this->bSix);
			this->Controls->Add(this->bFive);
			this->Controls->Add(this->bFour);
			this->Controls->Add(this->bZero);
			this->Controls->Add(this->bThree);
			this->Controls->Add(this->bTwo);
			this->Controls->Add(this->bOne);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedSingle;
			this->KeyPreview = true;
			this->MaximizeBox = false;
			this->Name = L"CalculatorForm";
			this->Text = L"Calculator";
			this->Load += gcnew System::EventHandler(this, &CalculatorForm::CalculatorForm_Load);
			this->ResumeLayout(false);

		}
#pragma endregion

		// Event Handlers
		// OnLoad
private: System::Void CalculatorForm_Load(System::Object^  sender, System::EventArgs^  e);
		// KeyPress
private: System::Void CalculatorForm_KeyPress(Object^ sender, KeyPressEventArgs^ e);
		// Numbers
private: System::Void bZero_Click(System::Object^  sender, System::EventArgs^  e);
private: System::Void bOne_Click(System::Object^  sender, System::EventArgs^  e);
private: System::Void bTwo_Click(System::Object^  sender, System::EventArgs^  e);
private: System::Void bThree_Click(System::Object^  sender, System::EventArgs^  e);
private: System::Void bFour_Click(System::Object^  sender, System::EventArgs^  e);
private: System::Void bFive_Click(System::Object^  sender, System::EventArgs^  e);
private: System::Void bSix_Click(System::Object^  sender, System::EventArgs^  e);
private: System::Void bSeven_Click(System::Object^  sender, System::EventArgs^  e);
private: System::Void bEight_Click(System::Object^  sender, System::EventArgs^  e);
private: System::Void bNine_Click(System::Object^  sender, System::EventArgs^  e);
private: System::Void bPi_Click(System::Object^  sender, System::EventArgs^  e);
		 // Parenthesis
private: System::Void bLeftParenthesis_Click(System::Object^  sender, System::EventArgs^  e);
private: System::Void bRightParenthesis_Click(System::Object^  sender, System::EventArgs^  e);
		 // Operations
private: System::Void bAdd_Click(System::Object^  sender, System::EventArgs^  e);
private: System::Void bMinus_Click(System::Object^  sender, System::EventArgs^  e);
private: System::Void bMultiply_Click(System::Object^  sender, System::EventArgs^  e);
private: System::Void bDivide_Click(System::Object^  sender, System::EventArgs^  e);
		 // Advanced Operations
private: System::Void bPower_Click(System::Object^  sender, System::EventArgs^  e);
private: System::Void bModulus_Click(System::Object^  sender, System::EventArgs^  e);
private: System::Void bRoot_Click(System::Object^  sender, System::EventArgs^  e);
private: System::Void bInverse_Click(System::Object^  sender, System::EventArgs^  e);
private: System::Void bSin_Click(System::Object^  sender, System::EventArgs^  e);
private: System::Void bCos_Click(System::Object^  sender, System::EventArgs^  e);
private: System::Void bTan_Click(System::Object^  sender, System::EventArgs^  e);
		 // Decimal Point
private: System::Void bPoint_Click(System::Object^  sender, System::EventArgs^  e);
		 // Memory Functions
private: System::Void bMPlus_Click(System::Object^  sender, System::EventArgs^  e);
private: System::Void bMClear_Click(System::Object^  sender, System::EventArgs^  e);
private: System::Void bMRecall_Click(System::Object^  sender, System::EventArgs^  e);
		 // Clear Functions
private: System::Void bClear_Click(System::Object^  sender, System::EventArgs^  e);
private: System::Void bClearLast_Click(System::Object^  sender, System::EventArgs^  e);
		 // Calculate Functions
private: System::Void bEquals_Click(System::Object^  sender, System::EventArgs^  e);

		 // Update Input Functions
		 void InsertValue(System::String^ a_sValue);
		 void InsertAdd();
		 void InsertMinus();
		 void InsertMultiply();
		 void InsertDivide();
		 void InsertPower();
		 void InsertModulus();
		 void InsertInverse();
		 void InsertDecimal();
		 void InsertPi();
		 void InsertLeftParenthesis();
		 void InsertRightParenthesis();
		 void InsertSqrtorTrig(System::String^ a_sOp);
		 void AddtoMemory();
		 void ClearMemory();
		 void RecallMemory();
		 void Clear();
		 void ClearLast();
		 void Equals();

		 void RefreshInputString();
		 void AddElemSize(int a_size);
		 void RemoveElemSize();
		 void EraseInputElemStack();
		 void EraseMemoryElemStack();

		 // Validation Functions
		 bool CanInsertOperator();
		 bool CanInsertSqrtOrTrig();
		 bool CanInsertLeftParenthesis();
		 bool CanInsertRightParenthesis();
		 bool CanInsertDecimalPoint();

		 bool IsOperator(char a_char);
		 bool IsSubtract(char a_char);
		 bool IsParenthesis(char a_char);
		 bool IsRightParenthesis(char a_char);
		 bool IsLeftParenthesis(char a_char);
		 bool IsTrigOp(const char* a_char);
		 bool IsSqrt(const char* a_char);
		 bool IsPi(char a_char);
		 bool IsPower(char a_char);
		 bool IsDecimal(char a_char);
		 bool IsZero(System::String^ a_systemStringChar);
		 bool IsZero(std::string a_stringChar);
		 bool IsZero(char a_char);

		 void TrimZerosRecursively();
};
}

#endif
