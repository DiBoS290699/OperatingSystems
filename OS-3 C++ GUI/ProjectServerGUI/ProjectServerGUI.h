#pragma once
#include "windows.h"
#include <iostream>
#include <fstream>
#include <conio.h>
#include "process.h" 
using namespace std;

HANDLE hAllEvents[28];
HANDLE hAllEvents1[28];

//---------------------------------
HANDLE hSem;		// semaphor
HANDLE hStart;		// client getting started
ofstream _log_;		// file where the log is saved
unsigned __stdcall Life(void* params);
void toLog(System::String^ msg);
void setButtonEnabled(bool b);
int number = 0;
//----------------------------------

void AddTimeToLog(string msg)
{
	SYSTEMTIME st;
	GetLocalTime(&st);
	_log_ << st.wYear << '-';
	_log_ << st.wMonth << '-';
	_log_ << st.wDay << ' ';
	_log_ << st.wHour << ':';
	_log_ << st.wMinute << ':';
	_log_ << st.wSecond << '.';
	_log_ << st.wMilliseconds << ' ';
	_log_ << msg;
}

namespace ProjectServerGUI {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;


	/// <summary>
	/// Summary for MyForm
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:
		MyForm(void)
		{
			InitializeComponent();

			hSem = CreateSemaphore(NULL, 3, 3, (LPWSTR)"SEM");
		}

	protected:
		/// <summary>
		/// Free all used resources.
		/// </summary>
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}
	public: static System::Windows::Forms::Button^ button1;
	public: static System::Windows::Forms::TextBox^ textBox2;



	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::NumericUpDown^ numProc;

	protected:


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
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->textBox2 = (gcnew System::Windows::Forms::TextBox());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->numProc = (gcnew System::Windows::Forms::NumericUpDown());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numProc))->BeginInit();
			this->SuspendLayout();
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(12, 138);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(75, 23);
			this->button1->TabIndex = 0;
			this->button1->Text = L"START";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &MyForm::button1_Click);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(9, 27);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(107, 13);
			this->label1->TabIndex = 2;
			this->label1->Text = L"Number of processes";
			// 
			// textBox2
			// 
			this->textBox2->Location = System::Drawing::Point(125, 97);
			this->textBox2->Multiline = true;
			this->textBox2->Name = L"textBox2";
			this->textBox2->ReadOnly = true;
			this->textBox2->ScrollBars = System::Windows::Forms::ScrollBars::Both;
			this->textBox2->Size = System::Drawing::Size(147, 64);
			this->textBox2->TabIndex = 3;
			this->textBox2->TextChanged += gcnew System::EventHandler(this, &MyForm::textBox2_TextChanged);
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(9, 100);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(50, 13);
			this->label2->TabIndex = 4;
			this->label2->Text = L"Message";
			this->label2->Click += gcnew System::EventHandler(this, &MyForm::Label2_Click);
			// 
			// numProc
			// 
			this->numProc->Location = System::Drawing::Point(125, 25);
			this->numProc->Minimum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 1, 0, 0, 0 });
			this->numProc->Name = L"numProc";
			this->numProc->Size = System::Drawing::Size(147, 20);
			this->numProc->TabIndex = 6;
			this->numProc->Value = System::Decimal(gcnew cli::array< System::Int32 >(4) { 1, 0, 0, 0 });
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->AutoValidate = System::Windows::Forms::AutoValidate::Disable;
			this->ClientSize = System::Drawing::Size(288, 188);
			this->Controls->Add(this->numProc);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->textBox2);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->button1);
			this->KeyPreview = true;
			this->Name = L"MyForm";
			this->Text = L"SERVER";
			this->Load += gcnew System::EventHandler(this, &MyForm::MyForm_Load);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numProc))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void MyForm_Load(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void MyForm_FormClosing(System::Object^ sender, FormClosingEventArgs e) {
		for (int i = 0; i < 28; i++)
			CloseHandle(hAllEvents[i]);
	}
	private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {
		setButtonEnabled(false);

		textBox2->Text = "";
		/*int*/ number = (int)(numProc->Value);
		/*HANDLE*/ hStart = CreateEvent(NULL, TRUE, FALSE, (LPWSTR)"START");

		/*ofstream*/ _log_ = ofstream("Log.txt");

		STARTUPINFO si;
		PROCESS_INFORMATION pi;
		ZeroMemory(&si, sizeof(STARTUPINFO));
		si.cb = sizeof(STARTUPINFO);
		for (int i = 0; i < number; i++)
		{
			string msg = "*Open the ";
			msg += i + 1;
			msg += " client  \n";
			AddTimeToLog(msg);
			CreateProcess(L"C:\\Users\\DiBoS\\Desktop\\Labs\\OperatingSystems\\OS-3 C++ GUI\\ProjectClientGUI\\Debug\\ProjectClientGUI.exe",
				NULL, NULL, NULL, FALSE, CREATE_NEW_CONSOLE, NULL, NULL, &si, &pi);
		}
		
		_beginthreadex(NULL, 0, Life, &number, 0, NULL);
	}
	private: System::Void textBox2_TextChanged(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void Label2_Click(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void numProc_SelectedItemChanged(System::Object^ sender, System::EventArgs^ e) {
	}
};
}

unsigned __stdcall Life(void* params) {


	WaitForSingleObject(hStart, INFINITE);		// waiting for when the client will start the event START

	AddTimeToLog ("*The start of work \n");
	/*HANDLE hPressO = OpenEvent(EVENT_ALL_ACCESS, TRUE, (LPWSTR)"O");
	HANDLE hPressP = OpenEvent(EVENT_ALL_ACCESS, TRUE, (LPWSTR)"P");
	HANDLE hPressE = OpenEvent(EVENT_ALL_ACCESS, TRUE, (LPWSTR)"E");
	HANDLE hPressN = OpenEvent(EVENT_ALL_ACCESS, TRUE, (LPWSTR)"N");*/
	HANDLE hPressExit = OpenEvent(EVENT_ALL_ACCESS, TRUE, (LPWSTR)"EXIT");

	HANDLE hPressA = CreateEvent(NULL, TRUE, FALSE, (LPWSTR)"A");
	HANDLE hPressB = CreateEvent(NULL, TRUE, FALSE, (LPWSTR)"B");
	HANDLE hPressC = CreateEvent(NULL, TRUE, FALSE, (LPWSTR)"C");
	HANDLE hPressD = CreateEvent(NULL, TRUE, FALSE, (LPWSTR)"D");
	HANDLE hPressE = CreateEvent(NULL, TRUE, FALSE, (LPWSTR)"E");
	HANDLE hPressF = CreateEvent(NULL, TRUE, FALSE, (LPWSTR)"F");
	HANDLE hPressG = CreateEvent(NULL, TRUE, FALSE, (LPWSTR)"G");
	HANDLE hPressH = CreateEvent(NULL, TRUE, FALSE, (LPWSTR)"H");
	HANDLE hPressI = CreateEvent(NULL, TRUE, FALSE, (LPWSTR)"I");
	HANDLE hPressJ = CreateEvent(NULL, TRUE, FALSE, (LPWSTR)"J");
	HANDLE hPressK = CreateEvent(NULL, TRUE, FALSE, (LPWSTR)"K");
	HANDLE hPressL = CreateEvent(NULL, TRUE, FALSE, (LPWSTR)"L");
	HANDLE hPressM = CreateEvent(NULL, TRUE, FALSE, (LPWSTR)"M");
	HANDLE hPressN = CreateEvent(NULL, TRUE, FALSE, (LPWSTR)"N");
	HANDLE hPressO = CreateEvent(NULL, TRUE, FALSE, (LPWSTR)"O");
	HANDLE hPressP = CreateEvent(NULL, TRUE, FALSE, (LPWSTR)"P");
	HANDLE hPressQ = CreateEvent(NULL, TRUE, FALSE, (LPWSTR)"Q");
	HANDLE hPressR = CreateEvent(NULL, TRUE, FALSE, (LPWSTR)"R");
	HANDLE hPressS = CreateEvent(NULL, TRUE, FALSE, (LPWSTR)"S");
	HANDLE hPressT = CreateEvent(NULL, TRUE, FALSE, (LPWSTR)"T");
	HANDLE hPressU = CreateEvent(NULL, TRUE, FALSE, (LPWSTR)"U");
	HANDLE hPressW = CreateEvent(NULL, TRUE, FALSE, (LPWSTR)"W");
	HANDLE hPressV = CreateEvent(NULL, TRUE, FALSE, (LPWSTR)"V");
	HANDLE hPressX = CreateEvent(NULL, TRUE, FALSE, (LPWSTR)"X");
	HANDLE hPressY = CreateEvent(NULL, TRUE, FALSE, (LPWSTR)"Y");
	HANDLE hPressZ = CreateEvent(NULL, TRUE, FALSE, (LPWSTR)"Z");

	hAllEvents[0] = hPressA;	hAllEvents[1] = hPressB;	hAllEvents[2] = hPressC;
	hAllEvents[3] = hPressD;	hAllEvents[4] = hPressE;	hAllEvents[5] = hPressF;
	hAllEvents[6] = hPressG;	hAllEvents[7] = hPressH;	hAllEvents[8] = hPressI;
	hAllEvents[9] = hPressJ;	hAllEvents[10] = hPressK;	hAllEvents[11] = hPressL;
	hAllEvents[12] = hPressM;	hAllEvents[13] = hPressN;	hAllEvents[14] = hPressO;
	hAllEvents[15] = hPressP;	hAllEvents[16] = hPressQ;	hAllEvents[17] = hPressR;
	hAllEvents[18] = hPressS;	hAllEvents[19] = hPressT;	hAllEvents[20] = hPressU;
	hAllEvents[21] = hPressW;	hAllEvents[22] = hPressV;	hAllEvents[23] = hPressX;
	hAllEvents[24] = hPressY;	hAllEvents[25] = hPressZ;	hAllEvents[26] = hPressExit;
	hAllEvents[27] = hSem;

	bool escape = 0;

	int numClients = number;


	while (1)
	{
		switch (WaitForMultipleObjects(27, hAllEvents, FALSE, INFINITE))
		{
		case 0:
			toLog(" A");
			AddTimeToLog("*The client introduced the symbol -> A \n");
			hAllEvents1[0] = OpenEvent(EVENT_MODIFY_STATE, FALSE, (LPWSTR)"A");
			ResetEvent(hAllEvents1[0]);
			break;
		case 1:
			toLog(" B");
			AddTimeToLog("*The client introduced the symbol -> B \n");
			hAllEvents1[1] = OpenEvent(EVENT_MODIFY_STATE, FALSE, (LPWSTR)"B");
			ResetEvent(hAllEvents1[1]);
			break;
		case 2:
			toLog(" C");
			AddTimeToLog("*The client introduced the symbol -> C \n");
			hAllEvents1[2] = OpenEvent(EVENT_MODIFY_STATE, FALSE, (LPWSTR)"C");
			ResetEvent(hAllEvents1[2]);
			break;
		case 3:
			toLog(" D");
			AddTimeToLog("*The client introduced the symbol -> D \n");
			hAllEvents1[3] = OpenEvent(EVENT_MODIFY_STATE, FALSE, (LPWSTR)"D");
			ResetEvent(hAllEvents1[3]);
			break;
		case 4:
			toLog(" E");
			AddTimeToLog("*The client introduced the symbol -> E \n");
			hAllEvents1[4] = OpenEvent(EVENT_MODIFY_STATE, FALSE, (LPWSTR)"E");
			ResetEvent(hAllEvents1[4]);
			break;
		case 5:
			toLog(" F");
			AddTimeToLog("*The client introduced the symbol -> F \n");
			hAllEvents1[5] = OpenEvent(EVENT_MODIFY_STATE, FALSE, (LPWSTR)"F");
			ResetEvent(hAllEvents1[5]);
			break;
		case 6:
			toLog(" G");
			AddTimeToLog("*The client introduced the symbol -> G \n");
			hAllEvents1[6] = OpenEvent(EVENT_MODIFY_STATE, FALSE, (LPWSTR)"G");
			ResetEvent(hAllEvents1[6]);
			break;
		case 7:
			toLog(" H");
			AddTimeToLog("*The client introduced the symbol -> H \n");
			hAllEvents1[7] = OpenEvent(EVENT_MODIFY_STATE, FALSE, (LPWSTR)"H");
			ResetEvent(hAllEvents1[7]);
			break;
		case 8:
			toLog(" I");
			AddTimeToLog("*The client introduced the symbol -> I \n");
			hAllEvents1[8] = OpenEvent(EVENT_MODIFY_STATE, FALSE, (LPWSTR)"I");
			ResetEvent(hAllEvents1[8]);
			break;
		case 9:
			toLog(" J");
			AddTimeToLog("*The client introduced the symbol -> J \n");
			hAllEvents1[9] = OpenEvent(EVENT_MODIFY_STATE, FALSE, (LPWSTR)"J");
			ResetEvent(hAllEvents1[9]);
			break;
		case 10:
			toLog(" K");
			AddTimeToLog("*The client introduced the symbol -> K \n");
			hAllEvents1[10] = OpenEvent(EVENT_MODIFY_STATE, FALSE, (LPWSTR)"K");
			ResetEvent(hAllEvents1[10]);
			break;
		case 11:
			toLog(" L");
			AddTimeToLog("*The client introduced the symbol -> L \n");
			hAllEvents1[11] = OpenEvent(EVENT_MODIFY_STATE, FALSE, (LPWSTR)"L");
			ResetEvent(hAllEvents1[11]);
			break;
		case 12:
			toLog(" M");
			AddTimeToLog("*The client introduced the symbol -> M \n");
			hAllEvents1[12] = OpenEvent(EVENT_MODIFY_STATE, FALSE, (LPWSTR)"M");
			ResetEvent(hAllEvents1[12]);
			break;
		case 13:
			toLog(" N");
			AddTimeToLog("*The client introduced the symbol -> N \n");
			hAllEvents1[13] = OpenEvent(EVENT_MODIFY_STATE, FALSE, (LPWSTR)"N");
			ResetEvent(hAllEvents1[13]);
			break;
		case 14:
			toLog(" O");
			AddTimeToLog("*The client introduced the symbol -> O \n");
			hAllEvents1[14] = OpenEvent(EVENT_MODIFY_STATE, FALSE, (LPWSTR)"O");
			ResetEvent(hAllEvents1[14]);
			break;
		case 15:
			toLog(" P");
			AddTimeToLog("*The client introduced the symbol -> P \n");
			hAllEvents1[15] = OpenEvent(EVENT_MODIFY_STATE, FALSE, (LPWSTR)"P");
			ResetEvent(hAllEvents1[15]);
			break;
		case 16:
			toLog(" Q");
			AddTimeToLog("*The client introduced the symbol -> Q \n");
			hAllEvents1[16] = OpenEvent(EVENT_MODIFY_STATE, FALSE, (LPWSTR)"Q");
			ResetEvent(hAllEvents1[16]);
			break;
		case 17:
			toLog(" R");
			AddTimeToLog("*The client introduced the symbol -> R \n");
			hAllEvents1[17] = OpenEvent(EVENT_MODIFY_STATE, FALSE, (LPWSTR)"R");
			ResetEvent(hAllEvents1[17]);
			break;
		case 18:
			toLog(" S");
			AddTimeToLog("*The client introduced the symbol -> S \n");
			hAllEvents1[18] = OpenEvent(EVENT_MODIFY_STATE, FALSE, (LPWSTR)"S");
			ResetEvent(hAllEvents1[18]);
			break;
		case 19:
			toLog(" T");
			AddTimeToLog("*The client introduced the symbol -> T \n");
			hAllEvents1[19] = OpenEvent(EVENT_MODIFY_STATE, FALSE, (LPWSTR)"T");
			ResetEvent(hAllEvents1[19]);
			break;
		case 20:
			toLog(" U");
			AddTimeToLog("*The client introduced the symbol -> U \n");
			hAllEvents1[20] = OpenEvent(EVENT_MODIFY_STATE, FALSE, (LPWSTR)"U");
			ResetEvent(hAllEvents1[20]);
			break;
		case 21:
			toLog(" W");
			AddTimeToLog("*The client introduced the symbol -> W \n");
			hAllEvents1[21] = OpenEvent(EVENT_MODIFY_STATE, FALSE, (LPWSTR)"W");

			ResetEvent(hAllEvents1[21]);
			break;
		case 22:
			toLog(" V");
			AddTimeToLog("*The client introduced the symbol -> V \n");
			hAllEvents1[22] = OpenEvent(EVENT_MODIFY_STATE, FALSE, (LPWSTR)"V");

			ResetEvent(hAllEvents1[22]);
			break;
		case 23:
			toLog(" X");
			AddTimeToLog("*The client introduced the symbol -> X \n");
			hAllEvents1[23] = OpenEvent(EVENT_MODIFY_STATE, FALSE, (LPWSTR)"X");

			ResetEvent(hAllEvents1[23]);
			break;
		case 24:
			toLog(" Y");
			AddTimeToLog("*The client introduced the symbol -> Y \n");
			hAllEvents1[24] = OpenEvent(EVENT_MODIFY_STATE, FALSE, (LPWSTR)"Y");

			ResetEvent(hAllEvents1[24]);
			break;
		case 25:
			toLog(" Z");
			AddTimeToLog("*The client introduced the symbol -> Z \n");
			hAllEvents1[25] = OpenEvent(EVENT_MODIFY_STATE, FALSE, (LPWSTR)"Z");
			ResetEvent(hAllEvents1[25]);
			break;
		case 26:
			AddTimeToLog("*The client disconnected from the server \n \n");
			hAllEvents1[26] = OpenEvent(EVENT_MODIFY_STATE, FALSE, (LPWSTR)"EXIT");
			ResetEvent(hAllEvents1[26]);
			numClients--;
			escape = 1;
			break;
		}
		if (escape) {
			if (numClients == 0) {
				AddTimeToLog("*All clients disconnected \n");
				setButtonEnabled(true);
				break;
			}
		}
	}
	_log_.close();

	return 0;
}

delegate void AddMessageDelegate(System::String^ msg);

void LogAdd(System::String^ msg) {
	ProjectServerGUI::MyForm::textBox2->Text += msg;
}

void toLog(System::String^ msg) {
	ProjectServerGUI::MyForm::textBox2->Invoke(gcnew AddMessageDelegate(LogAdd), { msg });
}

delegate void SetEnabledDelegate(bool b);

void SetEnabled(bool b) {
	ProjectServerGUI::MyForm::button1->Enabled = b;
}

void setButtonEnabled(bool b) {
	ProjectServerGUI::MyForm::button1->Invoke(gcnew SetEnabledDelegate(SetEnabled), { b });
}