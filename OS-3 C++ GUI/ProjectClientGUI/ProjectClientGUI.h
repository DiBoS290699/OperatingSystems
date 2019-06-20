#include <windows.h>
#include <stdio.h>
#include <conio.h>
#include <iostream>
#include <msclr\marshal_cppstd.h>
using namespace std;

HANDLE hAllEvents[27];
HANDLE hSem = OpenSemaphore(SEMAPHORE_ALL_ACCESS, FALSE, (LPWSTR)"SEM");
#pragma once
namespace ProjectClientGUI {
	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for MyForm1
	/// </summary>
	public ref class MyForm1 : public System::Windows::Forms::Form
	{
	public:
		MyForm1(void)
		{
			InitializeComponent();
		}

	protected:
		/// <summary>
		/// Free all used resources.
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
	private: System::Windows::Forms::Button^ button29;




	private:
		/// <summary>
		/// You want a variable to the constructor.
		/// </summary>
		System::ComponentModel::Container^ components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for designer support - do not modify 
		/// the contents of this method using the code editor.
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
			this->button29 = (gcnew System::Windows::Forms::Button());
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
			this->button6->Location = System::Drawing::Point(65, 200);
			this->button6->Name = L"button6";
			this->button6->Size = System::Drawing::Size(45, 29);
			this->button6->TabIndex = 5;
			this->button6->Text = L" Z";
			this->button6->UseVisualStyleBackColor = true;
			this->button6->Click += gcnew System::EventHandler(this, &MyForm1::button6_Click);
			// 
			// button7
			// 
			this->button7->Location = System::Drawing::Point(168, 130);
			this->button7->Name = L"button7";
			this->button7->Size = System::Drawing::Size(45, 29);
			this->button7->TabIndex = 10;
			this->button7->Text = L"P";
			this->button7->UseVisualStyleBackColor = true;
			this->button7->Click += gcnew System::EventHandler(this, &MyForm1::button7_Click);
			// 
			// button8
			// 
			this->button8->Location = System::Drawing::Point(116, 130);
			this->button8->Name = L"button8";
			this->button8->Size = System::Drawing::Size(45, 29);
			this->button8->TabIndex = 9;
			this->button8->Text = L"O";
			this->button8->UseVisualStyleBackColor = true;
			this->button8->Click += gcnew System::EventHandler(this, &MyForm1::button8_Click);
			// 
			// button9
			// 
			this->button9->Location = System::Drawing::Point(14, 130);
			this->button9->Name = L"button9";
			this->button9->Size = System::Drawing::Size(45, 29);
			this->button9->TabIndex = 8;
			this->button9->Text = L"M";
			this->button9->UseVisualStyleBackColor = true;
			this->button9->Click += gcnew System::EventHandler(this, &MyForm1::button9_Click);
			// 
			// button10
			// 
			this->button10->Location = System::Drawing::Point(269, 95);
			this->button10->Name = L"button10";
			this->button10->Size = System::Drawing::Size(45, 29);
			this->button10->TabIndex = 7;
			this->button10->Text = L"L";
			this->button10->UseVisualStyleBackColor = true;
			this->button10->Click += gcnew System::EventHandler(this, &MyForm1::button10_Click);
			// 
			// button11
			// 
			this->button11->Location = System::Drawing::Point(218, 95);
			this->button11->Name = L"button11";
			this->button11->Size = System::Drawing::Size(45, 29);
			this->button11->TabIndex = 6;
			this->button11->Text = L"K";
			this->button11->UseVisualStyleBackColor = true;
			this->button11->Click += gcnew System::EventHandler(this, &MyForm1::button11_Click);
			// 
			// button12
			// 
			this->button12->Location = System::Drawing::Point(167, 95);
			this->button12->Name = L"button12";
			this->button12->Size = System::Drawing::Size(45, 29);
			this->button12->TabIndex = 15;
			this->button12->Text = L"J";
			this->button12->UseVisualStyleBackColor = true;
			this->button12->Click += gcnew System::EventHandler(this, &MyForm1::button12_Click);
			// 
			// button13
			// 
			this->button13->Location = System::Drawing::Point(116, 95);
			this->button13->Name = L"button13";
			this->button13->Size = System::Drawing::Size(45, 29);
			this->button13->TabIndex = 14;
			this->button13->Text = L"I";
			this->button13->UseVisualStyleBackColor = true;
			this->button13->Click += gcnew System::EventHandler(this, &MyForm1::button13_Click);
			// 
			// button14
			// 
			this->button14->Location = System::Drawing::Point(65, 95);
			this->button14->Name = L"button14";
			this->button14->Size = System::Drawing::Size(45, 29);
			this->button14->TabIndex = 13;
			this->button14->Text = L"H";
			this->button14->UseVisualStyleBackColor = true;
			this->button14->Click += gcnew System::EventHandler(this, &MyForm1::button14_Click);
			// 
			// button15
			// 
			this->button15->Location = System::Drawing::Point(14, 95);
			this->button15->Name = L"button15";
			this->button15->Size = System::Drawing::Size(45, 29);
			this->button15->TabIndex = 12;
			this->button15->Text = L"G";
			this->button15->UseVisualStyleBackColor = true;
			this->button15->Click += gcnew System::EventHandler(this, &MyForm1::button15_Click);
			// 
			// button16
			// 
			this->button16->Location = System::Drawing::Point(269, 60);
			this->button16->Name = L"button16";
			this->button16->Size = System::Drawing::Size(45, 29);
			this->button16->TabIndex = 11;
			this->button16->Text = L"F";
			this->button16->UseVisualStyleBackColor = true;
			this->button16->Click += gcnew System::EventHandler(this, &MyForm1::button16_Click);
			// 
			// button17
			// 
			this->button17->Location = System::Drawing::Point(116, 165);
			this->button17->Name = L"button17";
			this->button17->Size = System::Drawing::Size(45, 29);
			this->button17->TabIndex = 20;
			this->button17->Text = L"U";
			this->button17->UseVisualStyleBackColor = true;
			this->button17->Click += gcnew System::EventHandler(this, &MyForm1::button17_Click);
			// 
			// button18
			// 
			this->button18->Location = System::Drawing::Point(65, 165);
			this->button18->Name = L"button18";
			this->button18->Size = System::Drawing::Size(45, 29);
			this->button18->TabIndex = 19;
			this->button18->Text = L"T";
			this->button18->UseVisualStyleBackColor = true;
			this->button18->Click += gcnew System::EventHandler(this, &MyForm1::button18_Click);
			// 
			// button19
			// 
			this->button19->Location = System::Drawing::Point(14, 165);
			this->button19->Name = L"button19";
			this->button19->Size = System::Drawing::Size(45, 29);
			this->button19->TabIndex = 18;
			this->button19->Text = L"S";
			this->button19->UseVisualStyleBackColor = true;
			this->button19->Click += gcnew System::EventHandler(this, &MyForm1::button19_Click);
			// 
			// button20
			// 
			this->button20->Location = System::Drawing::Point(269, 130);
			this->button20->Name = L"button20";
			this->button20->Size = System::Drawing::Size(45, 29);
			this->button20->TabIndex = 17;
			this->button20->Text = L"R";
			this->button20->UseVisualStyleBackColor = true;
			this->button20->Click += gcnew System::EventHandler(this, &MyForm1::button20_Click);
			// 
			// button21
			// 
			this->button21->Location = System::Drawing::Point(218, 130);
			this->button21->Name = L"button21";
			this->button21->Size = System::Drawing::Size(45, 29);
			this->button21->TabIndex = 16;
			this->button21->Text = L"Q";
			this->button21->UseVisualStyleBackColor = true;
			this->button21->Click += gcnew System::EventHandler(this, &MyForm1::button21_Click);
			// 
			// button22
			// 
			this->button22->Location = System::Drawing::Point(65, 130);
			this->button22->Name = L"button22";
			this->button22->Size = System::Drawing::Size(45, 29);
			this->button22->TabIndex = 25;
			this->button22->Text = L"N";
			this->button22->UseVisualStyleBackColor = true;
			this->button22->Click += gcnew System::EventHandler(this, &MyForm1::button22_Click);
			// 
			// button23
			// 
			this->button23->Location = System::Drawing::Point(14, 200);
			this->button23->Name = L"button23";
			this->button23->Size = System::Drawing::Size(45, 29);
			this->button23->TabIndex = 24;
			this->button23->Text = L"Y";
			this->button23->UseVisualStyleBackColor = true;
			this->button23->Click += gcnew System::EventHandler(this, &MyForm1::button23_Click);
			// 
			// button24
			// 
			this->button24->Location = System::Drawing::Point(269, 165);
			this->button24->Name = L"button24";
			this->button24->Size = System::Drawing::Size(45, 29);
			this->button24->TabIndex = 23;
			this->button24->Text = L"X";
			this->button24->UseVisualStyleBackColor = true;
			this->button24->Click += gcnew System::EventHandler(this, &MyForm1::button24_Click);
			// 
			// button25
			// 
			this->button25->Location = System::Drawing::Point(218, 165);
			this->button25->Name = L"button25";
			this->button25->Size = System::Drawing::Size(45, 29);
			this->button25->TabIndex = 22;
			this->button25->Text = L"V";
			this->button25->UseVisualStyleBackColor = true;
			this->button25->Click += gcnew System::EventHandler(this, &MyForm1::button25_Click);
			// 
			// button26
			// 
			this->button26->Location = System::Drawing::Point(167, 165);
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
			this->label1->Location = System::Drawing::Point(113, 44);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(100, 13);
			this->label1->TabIndex = 26;
			this->label1->Text = L"Enter your message";
			// 
			// textBox1
			// 
			this->textBox1->Location = System::Drawing::Point(83, 12);
			this->textBox1->Name = L"textBox1";
			this->textBox1->ReadOnly = true;
			this->textBox1->Size = System::Drawing::Size(231, 20);
			this->textBox1->TabIndex = 27;
			this->textBox1->TextChanged += gcnew System::EventHandler(this, &MyForm1::textBox1_TextChanged);
			// 
			// button27
			// 
			this->button27->Location = System::Drawing::Point(167, 260);
			this->button27->Name = L"button27";
			this->button27->Size = System::Drawing::Size(147, 29);
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
			this->label2->Size = System::Drawing::Size(50, 13);
			this->label2->TabIndex = 29;
			this->label2->Text = L"Message";
			this->label2->Click += gcnew System::EventHandler(this, &MyForm1::Label2_Click);
			// 
			// textBox2
			// 
			this->textBox2->Location = System::Drawing::Point(14, 311);
			this->textBox2->Name = L"textBox2";
			this->textBox2->PasswordChar = '*';
			this->textBox2->Size = System::Drawing::Size(146, 20);
			this->textBox2->TabIndex = 30;
			this->textBox2->TextChanged += gcnew System::EventHandler(this, &MyForm1::textBox2_TextChanged);
			// 
			// button28
			// 
			this->button28->Location = System::Drawing::Point(204, 304);
			this->button28->Name = L"button28";
			this->button28->Size = System::Drawing::Size(111, 32);
			this->button28->TabIndex = 31;
			this->button28->Text = L"Send password";
			this->button28->UseVisualStyleBackColor = true;
			this->button28->Click += gcnew System::EventHandler(this, &MyForm1::button28_Click);
			// 
			// button29
			// 
			this->button29->Location = System::Drawing::Point(14, 260);
			this->button29->Name = L"button29";
			this->button29->Size = System::Drawing::Size(147, 29);
			this->button29->TabIndex = 32;
			this->button29->Text = L"EXIT";
			this->button29->UseVisualStyleBackColor = true;
			this->button29->Click += gcnew System::EventHandler(this, &MyForm1::Button29_Click);
			// 
			// MyForm1
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(327, 343);
			this->ControlBox = false;
			this->Controls->Add(this->button29);
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
		textBox1->Enabled = true;
		textBox1->Visible = true;
		button1->Enabled = true;
		button1->Visible = true;
		button2->Enabled = true;
		button2->Visible = true;
		button3->Enabled = true;
		button3->Visible = true;
		button4->Enabled = true;
		button4->Visible = true;
		button5->Enabled = true;
		button5->Visible = true;
		button6->Enabled = true;
		button6->Visible = true;
		button7->Enabled = true;
		button7->Visible = true;
		button8->Enabled = true;
		button8->Visible = true;
		button9->Enabled = true;
		button9->Visible = true;
		button10->Enabled = true;
		button10->Visible = true;
		button11->Enabled = true;
		button11->Visible = true;
		button12->Visible = true;
		button12->Enabled = true;
		button13->Visible = true;
		button13->Enabled = true;
		button14->Visible = true;
		button14->Enabled = true;
		button15->Visible = true;
		button15->Enabled = true;
		button16->Visible = true;
		button16->Enabled = true;
		button17->Visible = true;
		button17->Enabled = true;
		button18->Visible = true;
		button18->Enabled = true;
		button19->Visible = true;
		button19->Enabled = true;
		button20->Visible = true;
		button20->Enabled = true;
		button21->Visible = true;
		button21->Enabled = true;
		button22->Visible = true;
		button22->Enabled = true;
		button23->Visible = true;
		button23->Enabled = true;
		button24->Visible = true;
		button24->Enabled = true;
		button25->Visible = true;
		button25->Enabled = true;
		button26->Visible = true;
		button26->Enabled = true;
		button27->Visible = false;
		button27->Enabled = false;
		textBox1->Visible = true;
		textBox1->Enabled = true;
		HANDLE hStart = OpenEvent(EVENT_ALL_ACCESS, TRUE, (LPWSTR)"START");
		/*HANDLE hPressO = CreateEvent(NULL, TRUE, FALSE, (LPWSTR)"O");
		HANDLE hPressP = CreateEvent(NULL, TRUE, FALSE, (LPWSTR)"P");
		HANDLE hPressE = CreateEvent(NULL, TRUE, FALSE, (LPWSTR)"E"); 
		HANDLE hPressN = CreateEvent(NULL, TRUE, FALSE, (LPWSTR)"N");*/
		HANDLE hPressExit = CreateEvent(NULL, TRUE, FALSE, (LPWSTR)"EXIT");

		SetEvent(hStart);
		CloseHandle(hStart);


		HANDLE hPressA = OpenEvent(EVENT_ALL_ACCESS, TRUE, (LPWSTR)"A");
		HANDLE hPressB = OpenEvent(EVENT_ALL_ACCESS, TRUE, (LPWSTR)"B");
		HANDLE hPressC = OpenEvent(EVENT_ALL_ACCESS, TRUE, (LPWSTR)"C");
		HANDLE hPressD = OpenEvent(EVENT_ALL_ACCESS, TRUE, (LPWSTR)"D");
		HANDLE hPressE = OpenEvent(EVENT_ALL_ACCESS, TRUE, (LPWSTR)"E");
		HANDLE hPressF = OpenEvent(EVENT_ALL_ACCESS, TRUE, (LPWSTR)"F");
		HANDLE hPressG = OpenEvent(EVENT_ALL_ACCESS, TRUE, (LPWSTR)"G");
		HANDLE hPressH = OpenEvent(EVENT_ALL_ACCESS, TRUE, (LPWSTR)"H");
		HANDLE hPressI = OpenEvent(EVENT_ALL_ACCESS, TRUE, (LPWSTR)"I");
		HANDLE hPressJ = OpenEvent(EVENT_ALL_ACCESS, TRUE, (LPWSTR)"J");
		HANDLE hPressK = OpenEvent(EVENT_ALL_ACCESS, TRUE, (LPWSTR)"K");
		HANDLE hPressL = OpenEvent(EVENT_ALL_ACCESS, TRUE, (LPWSTR)"L");
		HANDLE hPressM = OpenEvent(EVENT_ALL_ACCESS, TRUE, (LPWSTR)"M");
		HANDLE hPressN = OpenEvent(EVENT_ALL_ACCESS, TRUE, (LPWSTR)"N");
		HANDLE hPressO = OpenEvent(EVENT_ALL_ACCESS, TRUE, (LPWSTR)"O");
		HANDLE hPressP = OpenEvent(EVENT_ALL_ACCESS, TRUE, (LPWSTR)"P");
		HANDLE hPressQ = OpenEvent(EVENT_ALL_ACCESS, TRUE, (LPWSTR)"Q");
		HANDLE hPressR = OpenEvent(EVENT_ALL_ACCESS, TRUE, (LPWSTR)"R");
		HANDLE hPressS = OpenEvent(EVENT_ALL_ACCESS, TRUE, (LPWSTR)"S");
		HANDLE hPressT = OpenEvent(EVENT_ALL_ACCESS, TRUE, (LPWSTR)"T");
		HANDLE hPressU = OpenEvent(EVENT_ALL_ACCESS, TRUE, (LPWSTR)"U");
		HANDLE hPressW = OpenEvent(EVENT_ALL_ACCESS, TRUE, (LPWSTR)"W");
		HANDLE hPressV = OpenEvent(EVENT_ALL_ACCESS, TRUE, (LPWSTR)"V");
		HANDLE hPressX = OpenEvent(EVENT_ALL_ACCESS, TRUE, (LPWSTR)"X");
		HANDLE hPressY = OpenEvent(EVENT_ALL_ACCESS, TRUE, (LPWSTR)"Y");
		HANDLE hPressZ = OpenEvent(EVENT_ALL_ACCESS, TRUE, (LPWSTR)"Z");

		hAllEvents[0] = hPressA;	hAllEvents[1] = hPressB;	hAllEvents[2] = hPressC;
		hAllEvents[3] = hPressD;	hAllEvents[4] = hPressE;	hAllEvents[5] = hPressF;
		hAllEvents[6] = hPressG;	hAllEvents[7] = hPressH;	hAllEvents[8] = hPressI;
		hAllEvents[9] = hPressJ;	hAllEvents[10] = hPressK;	hAllEvents[11] = hPressL;
		hAllEvents[12] = hPressM;	hAllEvents[13] = hPressN;	hAllEvents[14] = hPressO;
		hAllEvents[15] = hPressP;	hAllEvents[16] = hPressQ;	hAllEvents[17] = hPressR;
		hAllEvents[18] = hPressS;	hAllEvents[19] = hPressT;	hAllEvents[20] = hPressU;
		hAllEvents[21] = hPressW;	hAllEvents[22] = hPressV;	hAllEvents[23] = hPressX;
		hAllEvents[24] = hPressY;	hAllEvents[25] = hPressZ;	hAllEvents[26] = hPressExit;
	}
			 //A
	private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {


		hAllEvents[0] = OpenEvent(EVENT_MODIFY_STATE, FALSE, (LPWSTR)"A");
		SetEvent((LPWSTR)hAllEvents[0]);
		textBox1->Text += " A";
	}
	private: System::Void textBox1_TextChanged(System::Object^ sender, System::EventArgs^ e) {
	}
			 //B
	private: System::Void button2_Click(System::Object^ sender, System::EventArgs^ e) {
		hAllEvents[1] = OpenEvent(EVENT_MODIFY_STATE, FALSE, (LPWSTR)"B");
		SetEvent((LPWSTR)hAllEvents[1]);

		textBox1->Text += " B";
	}
			 //C
	private: System::Void button3_Click(System::Object^ sender, System::EventArgs^ e) {
		hAllEvents[2] = OpenEvent(EVENT_MODIFY_STATE, FALSE, (LPWSTR)"C");
		SetEvent((LPWSTR)hAllEvents[2]);
		textBox1->Text += " C";
	}
			 //D
	private: System::Void button4_Click(System::Object^ sender, System::EventArgs^ e) {
		hAllEvents[3] = OpenEvent(EVENT_MODIFY_STATE, FALSE, (LPWSTR)"D");
		SetEvent((LPWSTR)hAllEvents[3]);
		textBox1->Text += " D";
	}
			 //E
	private: System::Void button5_Click(System::Object^ sender, System::EventArgs^ e) {
		hAllEvents[4] = OpenEvent(EVENT_MODIFY_STATE, FALSE, (LPWSTR)"E");
		SetEvent((LPWSTR)hAllEvents[4]);
		textBox1->Text += " E";
	}
			 //F
	private: System::Void button16_Click(System::Object^ sender, System::EventArgs^ e) {
		hAllEvents[5] = OpenEvent(EVENT_MODIFY_STATE, FALSE, (LPWSTR)"F");
		SetEvent((LPWSTR)hAllEvents[5]);
		textBox1->Text += " F";
	}
			 //G
	private: System::Void button15_Click(System::Object^ sender, System::EventArgs^ e) {
		hAllEvents[6] = OpenEvent(EVENT_MODIFY_STATE, FALSE, (LPWSTR)"G");
		SetEvent((LPWSTR)hAllEvents[6]);
		textBox1->Text += " G";
	}
			 //H
	private: System::Void button14_Click(System::Object^ sender, System::EventArgs^ e) {
		hAllEvents[7] = OpenEvent(EVENT_MODIFY_STATE, FALSE, (LPWSTR)"H");
		SetEvent((LPWSTR)hAllEvents[7]);
		textBox1->Text += " H";
	}
			 //I
	private: System::Void button13_Click(System::Object^ sender, System::EventArgs^ e) {
		hAllEvents[8] = OpenEvent(EVENT_MODIFY_STATE, FALSE, (LPWSTR)"I");
		SetEvent((LPWSTR)hAllEvents[8]);
		textBox1->Text += " I";
	}
			 //J
	private: System::Void button12_Click(System::Object^ sender, System::EventArgs^ e) {
		hAllEvents[9] = OpenEvent(EVENT_MODIFY_STATE, FALSE, (LPWSTR)"J");
		SetEvent((LPWSTR)hAllEvents[9]);
		textBox1->Text += " J";
	}
			 //K
	private: System::Void button11_Click(System::Object^ sender, System::EventArgs^ e) {
		hAllEvents[10] = OpenEvent(EVENT_MODIFY_STATE, FALSE, (LPWSTR)"K");
		SetEvent((LPWSTR)hAllEvents[10]);
		textBox1->Text += " K";
	}
			 //L
	private: System::Void button10_Click(System::Object^ sender, System::EventArgs^ e) {
		hAllEvents[11] = OpenEvent(EVENT_MODIFY_STATE, FALSE, (LPWSTR)"L");
		SetEvent((LPWSTR)hAllEvents[11]);
		textBox1->Text += " L";
	}
			 //M
	private: System::Void button9_Click(System::Object^ sender, System::EventArgs^ e) {
		hAllEvents[12] = OpenEvent(EVENT_MODIFY_STATE, FALSE, (LPWSTR)"M");
		SetEvent((LPWSTR)hAllEvents[12]);
		textBox1->Text += " M";
	}
			 //N
	private: System::Void button22_Click(System::Object^ sender, System::EventArgs^ e) {
		hAllEvents[13] = OpenEvent(EVENT_MODIFY_STATE, FALSE, (LPWSTR)"N");
		SetEvent((LPWSTR)hAllEvents[13]);
		textBox1->Text += " N";
	}
			 //O
	private: System::Void button8_Click(System::Object^ sender, System::EventArgs^ e) {
		hAllEvents[14] = OpenEvent(EVENT_MODIFY_STATE, FALSE, (LPWSTR)"O");
		SetEvent((LPWSTR)hAllEvents[14]);
		textBox1->Text += " O";
	}
			 //P
	private: System::Void button7_Click(System::Object^ sender, System::EventArgs^ e) {
		hAllEvents[15] = OpenEvent(EVENT_MODIFY_STATE, FALSE, (LPWSTR)"P");
		SetEvent((LPWSTR)hAllEvents[15]);
		textBox1->Text += " P";
	}
			 //Q
	private: System::Void button21_Click(System::Object^ sender, System::EventArgs^ e) {
		hAllEvents[16] = OpenEvent(EVENT_MODIFY_STATE, FALSE, (LPWSTR)"Q");
		SetEvent((LPWSTR)hAllEvents[16]);
		textBox1->Text += " Q";
	}
			 //R
	private: System::Void button20_Click(System::Object^ sender, System::EventArgs^ e) {
		hAllEvents[17] = OpenEvent(EVENT_MODIFY_STATE, FALSE, (LPWSTR)"R");
		SetEvent((LPWSTR)hAllEvents[17]);
		textBox1->Text += " R";
	}
			 //S
	private: System::Void button19_Click(System::Object^ sender, System::EventArgs^ e) {
		hAllEvents[18] = OpenEvent(EVENT_MODIFY_STATE, FALSE, (LPWSTR)"S");
		SetEvent((LPWSTR)hAllEvents[18]);
		textBox1->Text += " S";
	}
			 //T
	private: System::Void button18_Click(System::Object^ sender, System::EventArgs^ e) {
		hAllEvents[19] = OpenEvent(EVENT_MODIFY_STATE, FALSE, (LPWSTR)"T");
		SetEvent((LPWSTR)hAllEvents[19]);
		textBox1->Text += " T";
	}
			 //U
	private: System::Void button17_Click(System::Object^ sender, System::EventArgs^ e) {
		hAllEvents[20] = OpenEvent(EVENT_MODIFY_STATE, FALSE, (LPWSTR)"U");
		SetEvent((LPWSTR)hAllEvents[20]);
		textBox1->Text += " U";
	}
			 //W
	private: System::Void button26_Click(System::Object^ sender, System::EventArgs^ e) {
		hAllEvents[21] = OpenEvent(EVENT_MODIFY_STATE, FALSE, (LPWSTR)"W");
		SetEvent((LPWSTR)hAllEvents[21]);
		textBox1->Text += " W";
	}
			 //V
	private: System::Void button25_Click(System::Object^ sender, System::EventArgs^ e) {
		hAllEvents[22] = OpenEvent(EVENT_MODIFY_STATE, FALSE, (LPWSTR)"V");
		SetEvent((LPWSTR)hAllEvents[22]);
		textBox1->Text += " V";
	}
			 //X
	private: System::Void button24_Click(System::Object^ sender, System::EventArgs^ e) {
		hAllEvents[23] = OpenEvent(EVENT_MODIFY_STATE, FALSE, (LPWSTR)"X");
		SetEvent((LPWSTR)hAllEvents[23]);
		textBox1->Text += " X";
	}
			 //Y
	private: System::Void button23_Click(System::Object^ sender, System::EventArgs^ e) {
		hAllEvents[24] = OpenEvent(EVENT_MODIFY_STATE, FALSE, (LPWSTR)"Y");
		SetEvent((LPWSTR)hAllEvents[24]);
		textBox1->Text += " Y";
	}
			 //Z
	private: System::Void button6_Click(System::Object^ sender, System::EventArgs^ e) {
		hAllEvents[25] = OpenEvent(EVENT_MODIFY_STATE, FALSE, (LPWSTR)"Z");
		SetEvent((LPWSTR)hAllEvents[25]);
		textBox1->Text += " Z";
	}

	private: System::Void button28_Click(System::Object^ sender, System::EventArgs^ e) {
		string pass = "OPEN";
		string s = "";

		System::String^ txt = textBox2->Text;
		s = msclr::interop::marshal_as<std::string>(txt);
		if (s == pass) {
			button27->Visible = true;
			button27->Enabled = true;
			button28->Visible = false;
			button28->Enabled = false;
			textBox2->Visible = false;
			textBox2->Enabled = false;

		}
		else
			textBox2->Text = "";
	}
	private: System::Void Button29_Click(System::Object^ sender, System::EventArgs^ e) {
		hAllEvents[26] = OpenEvent(EVENT_MODIFY_STATE, FALSE, (LPWSTR)"EXIT");
		SetEvent((LPWSTR)hAllEvents[26]);
		ReleaseSemaphore(hSem, 1, NULL);
		exit(0);
	}
	private: System::Void textBox2_TextChanged(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void Label2_Click(System::Object^ sender, System::EventArgs^ e) {
	}
};
}