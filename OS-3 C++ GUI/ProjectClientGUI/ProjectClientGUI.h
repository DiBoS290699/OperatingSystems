#include <windows.h>
#include <stdio.h>
#include <conio.h>
#include <iostream>
#include <ctime>
#include <msclr\marshal_cppstd.h>
#undef max
using namespace std;

HANDLE hAllEvents[29];
bool a = 0; bool b = 0; bool c = 0; bool d = 0; bool E = 0; bool f = 0; bool g = 0; bool h = 0; bool i = 0;
bool j = 0; bool k = 0; bool l = 0; bool m = 0; bool n = 0; bool o = 0; bool p = 0; bool q = 0; bool r = 0;
bool s = 0; bool t = 0; bool u = 0; bool w = 0; bool v = 0; bool x = 0; bool y = 0; bool z = 0;

CHAR lpEventNameA[] = "A"; CHAR lpEventNameB[] = "B"; CHAR lpEventNameC[] = "C";
CHAR lpEventNameD[] = "D"; CHAR lpEventNameE[] = "E"; CHAR lpEventNameF[] = "F";
CHAR lpEventNameG[] = "G"; CHAR lpEventNameH[] = "H"; CHAR lpEventNameI[] = "I";
CHAR lpEventNameJ[] = "J"; CHAR lpEventNameK[] = "K"; CHAR lpEventNameL[] = "L";
CHAR lpEventNameM[] = "M"; CHAR lpEventNameN[] = "N"; CHAR lpEventNameO[] = "O";
CHAR lpEventNameP[] = "P"; CHAR lpEventNameQ[] = "Q"; CHAR lpEventNameR[] = "R";
CHAR lpEventNameS[] = "S"; CHAR lpEventNameT[] = "T"; CHAR lpEventNameU[] = "U";
CHAR lpEventNameW[] = "W"; CHAR lpEventNameV[] = "V"; CHAR lpEventNameX[] = "X";
CHAR lpEventNameY[] = "Y"; CHAR lpEventNameZ[] = "Z";; CHAR lpEventName6[] = "START";
CHAR lpEventName7[] = "SHOW"; CHAR lpEventName8[] = "WORK"; CHAR lpEventName9[] = "PASSWORD";
CHAR lpEventName10[] = "ACCEPT";
HANDLE hPassWord = CreateEvent(NULL, TRUE, FALSE, (LPWSTR)lpEventName9);
HANDLE hSem = CreateSemaphore(NULL, 3, 3, (LPWSTR)"SEM");
#pragma once
namespace ProjectClientGUI {
	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// ������ ��� MyForm1
	/// </summary>
	public ref class MyForm1 : public System::Windows::Forms::Form
	{
	public:
		MyForm1(void)
		{
			InitializeComponent();
			//
			//TODO: �������� ��� ������������
			//
		}

	protected:
		/// <summary>
		/// ���������� ��� ������������ �������.
		/// </summary>
		~MyForm1()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^ button1;
	protected:
	private: System::Windows::Forms::Button^ button2;
	private: System::Windows::Forms::Button^ button3;
	private: System::Windows::Forms::Button^ button4;
	private: System::Windows::Forms::Button^ button5;
	private: System::Windows::Forms::Button^ button6;
	private: System::Windows::Forms::Button^ button7;
	private: System::Windows::Forms::Button^ button8;
	private: System::Windows::Forms::Button^ button9;
	private: System::Windows::Forms::Button^ button10;
	private: System::Windows::Forms::Button^ button11;
	private: System::Windows::Forms::Button^ button12;
	private: System::Windows::Forms::Button^ button13;
	private: System::Windows::Forms::Button^ button14;
	private: System::Windows::Forms::Button^ button15;
	private: System::Windows::Forms::Button^ button16;
	private: System::Windows::Forms::Button^ button17;
	private: System::Windows::Forms::Button^ button18;
	private: System::Windows::Forms::Button^ button19;
	private: System::Windows::Forms::Button^ button20;
	private: System::Windows::Forms::Button^ button21;
	private: System::Windows::Forms::Button^ button22;
	private: System::Windows::Forms::Button^ button23;
	private: System::Windows::Forms::Button^ button24;
	private: System::Windows::Forms::Button^ button25;
	private: System::Windows::Forms::Button^ button26;
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::TextBox^ textBox1;
	private: System::Windows::Forms::Button^ button27;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::TextBox^ textBox2;
	private: System::Windows::Forms::Button^ button28;




	private:
		/// <summary>
		/// ��������� ���������� ������������.
		/// </summary>
		System::ComponentModel::Container^ components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// ������������ ����� ��� ��������� ������������ - �� ���������
		/// ���������� ������� ������ ��� ������ ��������� ����.
		/// </summary>
		void InitializeComponent(void)
		{
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->button3 = (gcnew System::Windows::Forms::Button());
			this->button4 = (gcnew System::Windows::Forms::Button());
			this->button5 = (gcnew System::Windows::Forms::Button());
			this->button6 = (gcnew System::Windows::Forms::Button());
			this->button7 = (gcnew System::Windows::Forms::Button());
			this->button8 = (gcnew System::Windows::Forms::Button());
			this->button9 = (gcnew System::Windows::Forms::Button());
			this->button10 = (gcnew System::Windows::Forms::Button());
			this->button11 = (gcnew System::Windows::Forms::Button());
			this->button12 = (gcnew System::Windows::Forms::Button());
			this->button13 = (gcnew System::Windows::Forms::Button());
			this->button14 = (gcnew System::Windows::Forms::Button());
			this->button15 = (gcnew System::Windows::Forms::Button());
			this->button16 = (gcnew System::Windows::Forms::Button());
			this->button17 = (gcnew System::Windows::Forms::Button());
			this->button18 = (gcnew System::Windows::Forms::Button());
			this->button19 = (gcnew System::Windows::Forms::Button());
			this->button20 = (gcnew System::Windows::Forms::Button());
			this->button21 = (gcnew System::Windows::Forms::Button());
			this->button22 = (gcnew System::Windows::Forms::Button());
			this->button23 = (gcnew System::Windows::Forms::Button());
			this->button24 = (gcnew System::Windows::Forms::Button());
			this->button25 = (gcnew System::Windows::Forms::Button());
			this->button26 = (gcnew System::Windows::Forms::Button());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->button27 = (gcnew System::Windows::Forms::Button());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->textBox2 = (gcnew System::Windows::Forms::TextBox());
			this->button28 = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(14, 60);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(45, 29);
			this->button1->TabIndex = 0;
			this->button1->Text = L"A";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &MyForm1::button1_Click);
			// 
			// button2
			// 
			this->button2->Location = System::Drawing::Point(65, 60);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(45, 29);
			this->button2->TabIndex = 1;
			this->button2->Text = L"B";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &MyForm1::button2_Click);
			// 
			// button3
			// 
			this->button3->Location = System::Drawing::Point(116, 60);
			this->button3->Name = L"button3";
			this->button3->Size = System::Drawing::Size(45, 29);
			this->button3->TabIndex = 2;
			this->button3->Text = L"C";
			this->button3->UseVisualStyleBackColor = true;
			this->button3->Click += gcnew System::EventHandler(this, &MyForm1::button3_Click);
			// 
			// button4
			// 
			this->button4->Location = System::Drawing::Point(167, 60);
			this->button4->Name = L"button4";
			this->button4->Size = System::Drawing::Size(45, 29);
			this->button4->TabIndex = 3;
			this->button4->Text = L"D";
			this->button4->UseVisualStyleBackColor = true;
			this->button4->Click += gcnew System::EventHandler(this, &MyForm1::button4_Click);
			// 
			// button5
			// 
			this->button5->Location = System::Drawing::Point(218, 60);
			this->button5->Name = L"button5";
			this->button5->Size = System::Drawing::Size(45, 29);
			this->button5->TabIndex = 4;
			this->button5->Text = L"E";
			this->button5->UseVisualStyleBackColor = true;
			this->button5->Click += gcnew System::EventHandler(this, &MyForm1::button5_Click);
			// 
			// button6
			// 
			this->button6->Location = System::Drawing::Point(167, 235);
			this->button6->Name = L"button6";
			this->button6->Size = System::Drawing::Size(96, 40);
			this->button6->TabIndex = 5;
			this->button6->Text = L" Z AND QUIT";
			this->button6->UseVisualStyleBackColor = true;
			this->button6->Click += gcnew System::EventHandler(this, &MyForm1::button6_Click);
			// 
			// button7
			// 
			this->button7->Location = System::Drawing::Point(14, 165);
			this->button7->Name = L"button7";
			this->button7->Size = System::Drawing::Size(45, 29);
			this->button7->TabIndex = 10;
			this->button7->Text = L"P";
			this->button7->UseVisualStyleBackColor = true;
			this->button7->Click += gcnew System::EventHandler(this, &MyForm1::button7_Click);
			// 
			// button8
			// 
			this->button8->Location = System::Drawing::Point(218, 130);
			this->button8->Name = L"button8";
			this->button8->Size = System::Drawing::Size(45, 29);
			this->button8->TabIndex = 9;
			this->button8->Text = L"O";
			this->button8->UseVisualStyleBackColor = true;
			this->button8->Click += gcnew System::EventHandler(this, &MyForm1::button8_Click);
			// 
			// button9
			// 
			this->button9->Location = System::Drawing::Point(116, 130);
			this->button9->Name = L"button9";
			this->button9->Size = System::Drawing::Size(45, 29);
			this->button9->TabIndex = 8;
			this->button9->Text = L"M";
			this->button9->UseVisualStyleBackColor = true;
			this->button9->Click += gcnew System::EventHandler(this, &MyForm1::button9_Click);
			// 
			// button10
			// 
			this->button10->Location = System::Drawing::Point(65, 130);
			this->button10->Name = L"button10";
			this->button10->Size = System::Drawing::Size(45, 29);
			this->button10->TabIndex = 7;
			this->button10->Text = L"L";
			this->button10->UseVisualStyleBackColor = true;
			this->button10->Click += gcnew System::EventHandler(this, &MyForm1::button10_Click);
			// 
			// button11
			// 
			this->button11->Location = System::Drawing::Point(14, 130);
			this->button11->Name = L"button11";
			this->button11->Size = System::Drawing::Size(45, 29);
			this->button11->TabIndex = 6;
			this->button11->Text = L"K";
			this->button11->UseVisualStyleBackColor = true;
			this->button11->Click += gcnew System::EventHandler(this, &MyForm1::button11_Click);
			// 
			// button12
			// 
			this->button12->Location = System::Drawing::Point(218, 95);
			this->button12->Name = L"button12";
			this->button12->Size = System::Drawing::Size(45, 29);
			this->button12->TabIndex = 15;
			this->button12->Text = L"J";
			this->button12->UseVisualStyleBackColor = true;
			this->button12->Click += gcnew System::EventHandler(this, &MyForm1::button12_Click);
			// 
			// button13
			// 
			this->button13->Location = System::Drawing::Point(167, 95);
			this->button13->Name = L"button13";
			this->button13->Size = System::Drawing::Size(45, 29);
			this->button13->TabIndex = 14;
			this->button13->Text = L"I";
			this->button13->UseVisualStyleBackColor = true;
			this->button13->Click += gcnew System::EventHandler(this, &MyForm1::button13_Click);
			// 
			// button14
			// 
			this->button14->Location = System::Drawing::Point(116, 95);
			this->button14->Name = L"button14";
			this->button14->Size = System::Drawing::Size(45, 29);
			this->button14->TabIndex = 13;
			this->button14->Text = L"H";
			this->button14->UseVisualStyleBackColor = true;
			this->button14->Click += gcnew System::EventHandler(this, &MyForm1::button14_Click);
			// 
			// button15
			// 
			this->button15->Location = System::Drawing::Point(65, 95);
			this->button15->Name = L"button15";
			this->button15->Size = System::Drawing::Size(45, 29);
			this->button15->TabIndex = 12;
			this->button15->Text = L"G";
			this->button15->UseVisualStyleBackColor = true;
			this->button15->Click += gcnew System::EventHandler(this, &MyForm1::button15_Click);
			// 
			// button16
			// 
			this->button16->Location = System::Drawing::Point(14, 95);
			this->button16->Name = L"button16";
			this->button16->Size = System::Drawing::Size(45, 29);
			this->button16->TabIndex = 11;
			this->button16->Text = L"F";
			this->button16->UseVisualStyleBackColor = true;
			this->button16->Click += gcnew System::EventHandler(this, &MyForm1::button16_Click);
			// 
			// button17
			// 
			this->button17->Location = System::Drawing::Point(14, 200);
			this->button17->Name = L"button17";
			this->button17->Size = System::Drawing::Size(45, 29);
			this->button17->TabIndex = 20;
			this->button17->Text = L"U";
			this->button17->UseVisualStyleBackColor = true;
			this->button17->Click += gcnew System::EventHandler(this, &MyForm1::button17_Click);
			// 
			// button18
			// 
			this->button18->Location = System::Drawing::Point(218, 165);
			this->button18->Name = L"button18";
			this->button18->Size = System::Drawing::Size(45, 29);
			this->button18->TabIndex = 19;
			this->button18->Text = L"T";
			this->button18->UseVisualStyleBackColor = true;
			this->button18->Click += gcnew System::EventHandler(this, &MyForm1::button18_Click);
			// 
			// button19
			// 
			this->button19->Location = System::Drawing::Point(167, 165);
			this->button19->Name = L"button19";
			this->button19->Size = System::Drawing::Size(45, 29);
			this->button19->TabIndex = 18;
			this->button19->Text = L"S";
			this->button19->UseVisualStyleBackColor = true;
			this->button19->Click += gcnew System::EventHandler(this, &MyForm1::button19_Click);
			// 
			// button20
			// 
			this->button20->Location = System::Drawing::Point(116, 165);
			this->button20->Name = L"button20";
			this->button20->Size = System::Drawing::Size(45, 29);
			this->button20->TabIndex = 17;
			this->button20->Text = L"R";
			this->button20->UseVisualStyleBackColor = true;
			this->button20->Click += gcnew System::EventHandler(this, &MyForm1::button20_Click);
			// 
			// button21
			// 
			this->button21->Location = System::Drawing::Point(65, 165);
			this->button21->Name = L"button21";
			this->button21->Size = System::Drawing::Size(45, 29);
			this->button21->TabIndex = 16;
			this->button21->Text = L"Q";
			this->button21->UseVisualStyleBackColor = true;
			this->button21->Click += gcnew System::EventHandler(this, &MyForm1::button21_Click);
			// 
			// button22
			// 
			this->button22->Location = System::Drawing::Point(167, 130);
			this->button22->Name = L"button22";
			this->button22->Size = System::Drawing::Size(45, 29);
			this->button22->TabIndex = 25;
			this->button22->Text = L"N";
			this->button22->UseVisualStyleBackColor = true;
			this->button22->Click += gcnew System::EventHandler(this, &MyForm1::button22_Click);
			// 
			// button23
			// 
			this->button23->Location = System::Drawing::Point(218, 200);
			this->button23->Name = L"button23";
			this->button23->Size = System::Drawing::Size(45, 29);
			this->button23->TabIndex = 24;
			this->button23->Text = L"Y";
			this->button23->UseVisualStyleBackColor = true;
			this->button23->Click += gcnew System::EventHandler(this, &MyForm1::button23_Click);
			// 
			// button24
			// 
			this->button24->Location = System::Drawing::Point(167, 200);
			this->button24->Name = L"button24";
			this->button24->Size = System::Drawing::Size(45, 29);
			this->button24->TabIndex = 23;
			this->button24->Text = L"X";
			this->button24->UseVisualStyleBackColor = true;
			this->button24->Click += gcnew System::EventHandler(this, &MyForm1::button24_Click);
			// 
			// button25
			// 
			this->button25->Location = System::Drawing::Point(116, 200);
			this->button25->Name = L"button25";
			this->button25->Size = System::Drawing::Size(45, 29);
			this->button25->TabIndex = 22;
			this->button25->Text = L"V";
			this->button25->UseVisualStyleBackColor = true;
			this->button25->Click += gcnew System::EventHandler(this, &MyForm1::button25_Click);
			// 
			// button26
			// 
			this->button26->Location = System::Drawing::Point(65, 200);
			this->button26->Name = L"button26";
			this->button26->Size = System::Drawing::Size(45, 29);
			this->button26->TabIndex = 21;
			this->button26->Text = L"W";
			this->button26->UseVisualStyleBackColor = true;
			this->button26->Click += gcnew System::EventHandler(this, &MyForm1::button26_Click);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(65, 44);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(136, 13);
			this->label1->TabIndex = 26;
			this->label1->Text = L"Enter your message";
			// 
			// textBox1
			// 
			this->textBox1->Location = System::Drawing::Point(83, 12);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(180, 20);
			this->textBox1->TabIndex = 27;
			this->textBox1->TextChanged += gcnew System::EventHandler(this, &MyForm1::textBox1_TextChanged);
			// 
			// button27
			// 
			this->button27->Location = System::Drawing::Point(14, 235);
			this->button27->Name = L"button27";
			this->button27->Size = System::Drawing::Size(147, 40);
			this->button27->TabIndex = 28;
			this->button27->Text = L"START";
			this->button27->UseVisualStyleBackColor = true;
			this->button27->Click += gcnew System::EventHandler(this, &MyForm1::button27_Click);
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(12, 15);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(65, 13);
			this->label2->TabIndex = 29;
			this->label2->Text = L"message";
			// 
			// textBox2
			// 
			this->textBox2->Location = System::Drawing::Point(34, 284);
			this->textBox2->Name = L"textBox2";
			this->textBox2->Size = System::Drawing::Size(100, 20);
			this->textBox2->TabIndex = 30;
			this->textBox2->TextChanged += gcnew System::EventHandler(this, &MyForm1::textBox2_TextChanged);
			// 
			// button28
			// 
			this->button28->Location = System::Drawing::Point(167, 281);
			this->button28->Name = L"button28";
			this->button28->Size = System::Drawing::Size(75, 23);
			this->button28->TabIndex = 31;
			this->button28->Text = L"Send password";
			this->button28->UseVisualStyleBackColor = true;
			this->button28->Click += gcnew System::EventHandler(this, &MyForm1::button28_Click);
			// 
			// MyForm1
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(284, 314);
			this->ControlBox = false;
			this->Controls->Add(this->button28);
			this->Controls->Add(this->textBox2);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->button27);
			this->Controls->Add(this->textBox1);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->button22);
			this->Controls->Add(this->button23);
			this->Controls->Add(this->button24);
			this->Controls->Add(this->button25);
			this->Controls->Add(this->button26);
			this->Controls->Add(this->button17);
			this->Controls->Add(this->button18);
			this->Controls->Add(this->button19);
			this->Controls->Add(this->button20);
			this->Controls->Add(this->button21);
			this->Controls->Add(this->button12);
			this->Controls->Add(this->button13);
			this->Controls->Add(this->button14);
			this->Controls->Add(this->button15);
			this->Controls->Add(this->button16);
			this->Controls->Add(this->button7);
			this->Controls->Add(this->button8);
			this->Controls->Add(this->button9);
			this->Controls->Add(this->button10);
			this->Controls->Add(this->button11);
			this->Controls->Add(this->button6);
			this->Controls->Add(this->button5);
			this->Controls->Add(this->button4);
			this->Controls->Add(this->button3);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->button1);
			this->Name = L"MyForm1";
			this->Text = L"CLIENT";
			this->Load += gcnew System::EventHandler(this, &MyForm1::MyForm1_Load);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void MyForm1_Load(System::Object^ sender, System::EventArgs^ e) {
		textBox1->Enabled = false;
		textBox1->Visible = false;
		button1->Enabled = false;
		button1->Visible = false;
		button2->Enabled = false;
		button2->Visible = false;
		button3->Enabled = false;
		button3->Visible = false;
		button4->Enabled = false;
		button4->Visible = false;
		button5->Enabled = false;
		button5->Visible = false;
		button6->Enabled = false;
		button6->Visible = false;
		button7->Enabled = false;
		button7->Visible = false;
		button8->Enabled = false;
		button8->Visible = false;
		button9->Enabled = false;
		button9->Visible = false;
		button10->Enabled = false;
		button10->Visible = false;
		button11->Enabled = false;
		button11->Visible = false;
		button12->Visible = false;
		button12->Enabled = false;
		button13->Visible = false;
		button13->Enabled = false;
		button14->Visible = false;
		button14->Enabled = false;
		button15->Visible = false;
		button15->Enabled = false;
		button16->Visible = false;
		button16->Enabled = false;
		button17->Visible = false;
		button17->Enabled = false;
		button18->Visible = false;
		button18->Enabled = false;
		button19->Visible = false;
		button19->Enabled = false;
		button20->Visible = false;
		button20->Enabled = false;
		button21->Visible = false;
		button21->Enabled = false;
		button22->Visible = false;
		button22->Enabled = false;
		button23->Visible = false;
		button23->Enabled = false;
		button24->Visible = false;
		button24->Enabled = false;
		button25->Visible = false;
		button25->Enabled = false;
		button26->Visible = false;
		button26->Enabled = false;
		button27->Enabled = false;
		button27->Visible = false;
	}
			 //start
	private: System::Void button27_Click(System::Object^ sender, System::EventArgs^ e) {
		WaitForSingleObject(hSem, INFINITE);
		textBox1->Enabled = !false;
		textBox1->Visible = !false;
		button1->Enabled = !false;
		button1->Visible = !false;
		button2->Enabled = !false;
		button2->Visible = !false;
		button3->Enabled = !false;
		button3->Visible = !false;
		button4->Enabled = !false;
		button4->Visible = 1;
		button5->Enabled = !false;
		button5->Visible = !false;
		button6->Enabled = !false;
		button6->Visible = !false;
		button7->Enabled = !false;
		button7->Visible = !false;
		button8->Enabled = !false;
		button8->Visible = !false;
		button9->Enabled = !false;
		button9->Visible = !false;
		button10->Enabled = !false;
		button10->Visible = !false;
		button11->Enabled = !false;
		button11->Visible = !false;
		button12->Visible = !false;
		button12->Enabled = !false;
		button13->Visible = !false;
		button13->Enabled = !false;
		button14->Visible = !false;
		button14->Enabled = !false;
		button15->Visible = !false;
		button15->Enabled = !false;
		button16->Visible = !false;
		button16->Enabled = !false;
		button17->Visible = !false;
		button17->Enabled = !false;
		button18->Visible = !false;
		button18->Enabled = !false;
		button19->Visible = !false;
		button19->Enabled = !false;
		button20->Visible = !false;
		button20->Enabled = !false;
		button21->Visible = !false;
		button21->Enabled = !false;
		button22->Visible = !false;
		button22->Enabled = !false;
		button23->Visible = !false;
		button23->Enabled = !false;
		button24->Visible = !false;
		button24->Enabled = !false;
		button25->Visible = !false;
		button25->Enabled = !false;
		button26->Visible = !false;
		button26->Enabled = !false;
		HANDLE hStart = OpenEvent(EVENT_ALL_ACCESS, TRUE, (LPWSTR)lpEventName6);
		HANDLE hPressG = CreateEvent(NULL, TRUE, FALSE, (LPWSTR)lpEventNameG);
		HANDLE hPressO = CreateEvent(NULL, TRUE, FALSE, (LPWSTR)lpEventNameO);
		HANDLE hPressN = CreateEvent(NULL, TRUE, FALSE, (LPWSTR)lpEventNameN);
		HANDLE hPressE = CreateEvent(NULL, TRUE, FALSE, (LPWSTR)lpEventNameE);
		HANDLE hPressZ = CreateEvent(NULL, TRUE, FALSE, (LPWSTR)lpEventNameZ);

		HANDLE hShow = OpenEvent(EVENT_ALL_ACCESS, TRUE, (LPWSTR)lpEventName7);
		HANDLE hWork = CreateEvent(NULL, TRUE, TRUE, (LPWSTR)lpEventName8);
		SetEvent(hStart);
		CloseHandle(hStart);
		BYTE ch = 0;
		bool password = 1;
		wchar_t dw;
		int num = 0;
		//HANDLE hAccept = OpenEvent(EVENT_ALL_ACCESS, TRUE, (LPWSTR)lpEventName10);
		HANDLE hPlus = CreateEvent(NULL, TRUE, FALSE, (LPWSTR)"PLUS");
		textBox1->Visible = 1;
		textBox1->Enabled = 1;
		HANDLE hPressA = OpenEvent(EVENT_ALL_ACCESS, TRUE, (LPWSTR)lpEventNameA);
		HANDLE hPressB = OpenEvent(EVENT_ALL_ACCESS, TRUE, (LPWSTR)lpEventNameB);
		HANDLE hPressC = OpenEvent(EVENT_ALL_ACCESS, TRUE, (LPWSTR)lpEventNameC);
		HANDLE hPressD = OpenEvent(EVENT_ALL_ACCESS, TRUE, (LPWSTR)lpEventNameD);
		HANDLE hPressF = OpenEvent(EVENT_ALL_ACCESS, TRUE, (LPWSTR)lpEventNameF);
		HANDLE hPressH = OpenEvent(EVENT_ALL_ACCESS, TRUE, (LPWSTR)lpEventNameH);
		HANDLE hPressI = OpenEvent(EVENT_ALL_ACCESS, TRUE, (LPWSTR)lpEventNameI);
		HANDLE hPressJ = OpenEvent(EVENT_ALL_ACCESS, TRUE, (LPWSTR)lpEventNameJ);
		HANDLE hPressK = OpenEvent(EVENT_ALL_ACCESS, TRUE, (LPWSTR)lpEventNameK);
		HANDLE hPressL = OpenEvent(EVENT_ALL_ACCESS, TRUE, (LPWSTR)lpEventNameL);
		HANDLE hPressM = OpenEvent(EVENT_ALL_ACCESS, TRUE, (LPWSTR)lpEventNameM);
		HANDLE hPressP = OpenEvent(EVENT_ALL_ACCESS, TRUE, (LPWSTR)lpEventNameP);
		HANDLE hPressQ = OpenEvent(EVENT_ALL_ACCESS, TRUE, (LPWSTR)lpEventNameQ);
		HANDLE hPressR = OpenEvent(EVENT_ALL_ACCESS, TRUE, (LPWSTR)lpEventNameR);
		HANDLE hPressS = OpenEvent(EVENT_ALL_ACCESS, TRUE, (LPWSTR)lpEventNameS);
		HANDLE hPressT = OpenEvent(EVENT_ALL_ACCESS, TRUE, (LPWSTR)lpEventNameT);
		HANDLE hPressU = OpenEvent(EVENT_ALL_ACCESS, TRUE, (LPWSTR)lpEventNameU);
		HANDLE hPressW = OpenEvent(EVENT_ALL_ACCESS, TRUE, (LPWSTR)lpEventNameW);
		HANDLE hPressV = OpenEvent(EVENT_ALL_ACCESS, TRUE, (LPWSTR)lpEventNameV);
		HANDLE hPressX = OpenEvent(EVENT_ALL_ACCESS, TRUE, (LPWSTR)lpEventNameX);
		HANDLE hPressY = OpenEvent(EVENT_ALL_ACCESS, TRUE, (LPWSTR)lpEventNameY);

		hAllEvents[0] = hPressA;	hAllEvents[1] = hPressB;	hAllEvents[2] = hPressC;
		hAllEvents[3] = hPressD;	hAllEvents[4] = hPressE;	hAllEvents[5] = hPressF;
		hAllEvents[6] = hPressG;	hAllEvents[7] = hPressH;	hAllEvents[8] = hPressI;
		hAllEvents[9] = hPressJ;	hAllEvents[10] = hPressK;	hAllEvents[11] = hPressL;
		hAllEvents[12] = hPressM;	hAllEvents[13] = hPressN;	hAllEvents[14] = hPressO;
		hAllEvents[15] = hPressP;	hAllEvents[16] = hPressQ;	hAllEvents[17] = hPressR;
		hAllEvents[18] = hPressS;	hAllEvents[19] = hPressT;	hAllEvents[20] = hPressU;
		hAllEvents[21] = hPressW;	hAllEvents[22] = hPressV;	hAllEvents[23] = hPressX;
		hAllEvents[24] = hPressY;	hAllEvents[25] = hPressZ;	hAllEvents[26] = hStart;
		hAllEvents[27] = hShow;		hAllEvents[28] = hWork;
	}
			 //A
	private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {


		hAllEvents[0] = OpenEvent(EVENT_MODIFY_STATE, FALSE, (LPWSTR)lpEventNameA);
		SetEvent((LPWSTR)hAllEvents[0]);
		a = TRUE;
		textBox1->Text += " A";
	}
	private: System::Void textBox1_TextChanged(System::Object^ sender, System::EventArgs^ e) {
	}
			 //B
	private: System::Void button2_Click(System::Object^ sender, System::EventArgs^ e) {
		hAllEvents[1] = OpenEvent(EVENT_MODIFY_STATE, FALSE, (LPWSTR)lpEventNameB);
		SetEvent((LPWSTR)hAllEvents[1]);
		b = 1;
		textBox1->Text += " B";
	}
			 //C
	private: System::Void button3_Click(System::Object^ sender, System::EventArgs^ e) {
		hAllEvents[2] = OpenEvent(EVENT_MODIFY_STATE, FALSE, (LPWSTR)lpEventNameC);
		SetEvent((LPWSTR)hAllEvents[2]);
		textBox1->Text += " C";
	}
			 //D
	private: System::Void button4_Click(System::Object^ sender, System::EventArgs^ e) {
		hAllEvents[3] = OpenEvent(EVENT_MODIFY_STATE, FALSE, (LPWSTR)lpEventNameD);
		SetEvent((LPWSTR)hAllEvents[3]);
		textBox1->Text += " D";
	}
			 //E
	private: System::Void button5_Click(System::Object^ sender, System::EventArgs^ e) {
		hAllEvents[4] = OpenEvent(EVENT_MODIFY_STATE, FALSE, (LPWSTR)lpEventNameE);
		SetEvent((LPWSTR)hAllEvents[4]);
		textBox1->Text += " E";
	}
			 //F
	private: System::Void button16_Click(System::Object^ sender, System::EventArgs^ e) {
		hAllEvents[5] = OpenEvent(EVENT_MODIFY_STATE, FALSE, (LPWSTR)lpEventNameF);
		SetEvent((LPWSTR)hAllEvents[5]);
		textBox1->Text += " F";
	}
			 //G
	private: System::Void button15_Click(System::Object^ sender, System::EventArgs^ e) {
		hAllEvents[6] = OpenEvent(EVENT_MODIFY_STATE, FALSE, (LPWSTR)lpEventNameG);
		SetEvent((LPWSTR)hAllEvents[6]);
		g = TRUE;
		textBox1->Text += " G";
	}
			 //H
	private: System::Void button14_Click(System::Object^ sender, System::EventArgs^ e) {
		hAllEvents[7] = OpenEvent(EVENT_MODIFY_STATE, FALSE, (LPWSTR)lpEventNameH);
		h = 1;
		SetEvent((LPWSTR)hAllEvents[7]);
		textBox1->Text += " H";
	}
			 //I
	private: System::Void button13_Click(System::Object^ sender, System::EventArgs^ e) {
		hAllEvents[8] = OpenEvent(EVENT_MODIFY_STATE, FALSE, (LPWSTR)lpEventNameI);
		SetEvent((LPWSTR)hAllEvents[8]);
		i = 1;
		textBox1->Text += " I";
	}
			 //J
	private: System::Void button12_Click(System::Object^ sender, System::EventArgs^ e) {
		hAllEvents[9] = OpenEvent(EVENT_MODIFY_STATE, FALSE, (LPWSTR)lpEventNameJ);
		SetEvent((LPWSTR)hAllEvents[9]);
		j = 1;
		textBox1->Text += " J";
	}
			 //K
	private: System::Void button11_Click(System::Object^ sender, System::EventArgs^ e) {
		hAllEvents[10] = OpenEvent(EVENT_MODIFY_STATE, FALSE, (LPWSTR)lpEventNameK);
		SetEvent((LPWSTR)hAllEvents[10]);
		k = 1;
		textBox1->Text += " K";
	}
			 //L
	private: System::Void button10_Click(System::Object^ sender, System::EventArgs^ e) {
		hAllEvents[11] = OpenEvent(EVENT_MODIFY_STATE, FALSE, (LPWSTR)lpEventNameL);
		SetEvent((LPWSTR)hAllEvents[11]);
		l = 1;
		textBox1->Text += " L";
	}
			 //M
	private: System::Void button9_Click(System::Object^ sender, System::EventArgs^ e) {
		hAllEvents[12] = OpenEvent(EVENT_MODIFY_STATE, FALSE, (LPWSTR)lpEventNameM);
		SetEvent((LPWSTR)hAllEvents[12]);
		m = 1;
		textBox1->Text += " M";
	}
			 //N
	private: System::Void button22_Click(System::Object^ sender, System::EventArgs^ e) {
		hAllEvents[13] = OpenEvent(EVENT_MODIFY_STATE, FALSE, (LPWSTR)lpEventNameN);
		SetEvent((LPWSTR)hAllEvents[13]);
		n = 1;
		textBox1->Text += " N";
	}
			 //O
	private: System::Void button8_Click(System::Object^ sender, System::EventArgs^ e) {
		hAllEvents[14] = OpenEvent(EVENT_MODIFY_STATE, FALSE, (LPWSTR)lpEventNameO);
		SetEvent((LPWSTR)hAllEvents[14]);
		o = 1;
		textBox1->Text += " O";
	}
			 //P
	private: System::Void button7_Click(System::Object^ sender, System::EventArgs^ e) {
		hAllEvents[15] = OpenEvent(EVENT_MODIFY_STATE, FALSE, (LPWSTR)lpEventNameP);
		SetEvent((LPWSTR)hAllEvents[15]);
		p = 1;
		textBox1->Text += " P";
	}
			 //Q
	private: System::Void button21_Click(System::Object^ sender, System::EventArgs^ e) {
		hAllEvents[16] = OpenEvent(EVENT_MODIFY_STATE, FALSE, (LPWSTR)lpEventNameQ);
		SetEvent((LPWSTR)hAllEvents[16]);
		q = 1;
		textBox1->Text += " Q";
	}
			 //R
	private: System::Void button20_Click(System::Object^ sender, System::EventArgs^ e) {
		hAllEvents[17] = OpenEvent(EVENT_MODIFY_STATE, FALSE, (LPWSTR)lpEventNameR);
		SetEvent((LPWSTR)hAllEvents[17]);
		r = 1;
		textBox1->Text += " R";
	}
			 //S
	private: System::Void button19_Click(System::Object^ sender, System::EventArgs^ e) {
		hAllEvents[18] = OpenEvent(EVENT_MODIFY_STATE, FALSE, (LPWSTR)lpEventNameS);
		SetEvent((LPWSTR)hAllEvents[18]);
		s = 1;
		textBox1->Text += " S";
	}
			 //T
	private: System::Void button18_Click(System::Object^ sender, System::EventArgs^ e) {
		hAllEvents[19] = OpenEvent(EVENT_MODIFY_STATE, FALSE, (LPWSTR)lpEventNameT);
		SetEvent((LPWSTR)hAllEvents[19]);
		t = 1;
		textBox1->Text += " T";
	}
			 //U
	private: System::Void button17_Click(System::Object^ sender, System::EventArgs^ e) {
		hAllEvents[20] = OpenEvent(EVENT_MODIFY_STATE, FALSE, (LPWSTR)lpEventNameU);
		SetEvent((LPWSTR)hAllEvents[20]);
		u = 1;
		textBox1->Text += " U";
	}
			 //W
	private: System::Void button26_Click(System::Object^ sender, System::EventArgs^ e) {
		hAllEvents[21] = OpenEvent(EVENT_MODIFY_STATE, FALSE, (LPWSTR)lpEventNameW);
		SetEvent((LPWSTR)hAllEvents[21]);
		w = 1;
		textBox1->Text += " W";
	}
			 //V
	private: System::Void button25_Click(System::Object^ sender, System::EventArgs^ e) {
		hAllEvents[22] = OpenEvent(EVENT_MODIFY_STATE, FALSE, (LPWSTR)lpEventNameV);
		SetEvent((LPWSTR)hAllEvents[22]);
		v = 1;
		textBox1->Text += " V";
	}
			 //X
	private: System::Void button24_Click(System::Object^ sender, System::EventArgs^ e) {
		hAllEvents[23] = OpenEvent(EVENT_MODIFY_STATE, FALSE, (LPWSTR)lpEventNameX);
		SetEvent((LPWSTR)hAllEvents[23]);
		x = 1;
		textBox1->Text += " X";
	}
			 //Y
	private: System::Void button23_Click(System::Object^ sender, System::EventArgs^ e) {
		hAllEvents[24] = OpenEvent(EVENT_MODIFY_STATE, FALSE, (LPWSTR)lpEventNameY);
		SetEvent((LPWSTR)hAllEvents[24]);
		y = 1;
		textBox1->Text += " Y";
	}
			 //Z
	private: System::Void button6_Click(System::Object^ sender, System::EventArgs^ e) {
		hAllEvents[25] = OpenEvent(EVENT_MODIFY_STATE, FALSE, (LPWSTR)lpEventNameZ);
		SetEvent((LPWSTR)hAllEvents[25]);
		z = 1;
		ReleaseSemaphore(hSem, 1, NULL);
		textBox1->Text += " Z";
		exit(0);
	}

	private: System::Void button28_Click(System::Object^ sender, System::EventArgs^ e) {
		string pass = "GONE";
		string s = "";

		System::String^ txt = textBox2->Text;
		s = msclr::interop::marshal_as<std::string>(txt);
		if (s == pass) {
			SetEvent(hPassWord);
			button27->Visible = !false;
			button27->Enabled = !false;
		}
		else
			textBox2->Text = "";
	}
	private: System::Void textBox2_TextChanged(System::Object^ sender, System::EventArgs^ e) {
	}
	};
}