#pragma once
#include "windows.h"
#include <iostream>
#include <conio.h>
#include "process.h" 
using namespace std;

HANDLE hAllEvents[31];
HANDLE hAllEvents1[31];

namespace ProjectServerGUI {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;


	/// <summary>
	/// Сводка для MyForm
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:
		MyForm(void)
		{
			InitializeComponent();
			//
			//TODO: добавьте код конструктора
			//
		}

	protected:
		/// <summary>
		/// Освободить все используемые ресурсы.
		/// </summary>
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^ button1;



	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::TextBox^ textBox2;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::NumericUpDown^ numProc;
	private: System::Windows::Forms::TextBox^ logTextBox;

	private: System::Windows::Forms::Label^ TheLogBox;



	protected:


	private:
		/// <summary>
		/// Требуется переменная конструктора.
		/// </summary>
		System::ComponentModel::Container^ components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Обязательный метод для поддержки конструктора - не изменяйте
		/// содержимое данного метода при помощи редактора кода.
		/// </summary>
		void InitializeComponent(void)
		{
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->textBox2 = (gcnew System::Windows::Forms::TextBox());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->numProc = (gcnew System::Windows::Forms::NumericUpDown());
			this->logTextBox = (gcnew System::Windows::Forms::TextBox());
			this->TheLogBox = (gcnew System::Windows::Forms::Label());
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
			// logTextBox
			// 
			this->logTextBox->Location = System::Drawing::Point(296, 43);
			this->logTextBox->Multiline = true;
			this->logTextBox->Name = L"logTextBox";
			this->logTextBox->ReadOnly = true;
			this->logTextBox->Size = System::Drawing::Size(189, 118);
			this->logTextBox->TabIndex = 7;
			// 
			// TheLogBox
			// 
			this->TheLogBox->AutoSize = true;
			this->TheLogBox->Location = System::Drawing::Point(357, 27);
			this->TheLogBox->Name = L"TheLogBox";
			this->TheLogBox->Size = System::Drawing::Size(68, 13);
			this->TheLogBox->TabIndex = 8;
			this->TheLogBox->Text = L"*The Log Box";
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(514, 202);
			this->Controls->Add(this->TheLogBox);
			this->Controls->Add(this->logTextBox);
			this->Controls->Add(this->numProc);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->textBox2);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->button1);
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
		for (int i = 0; i < 31; i++)
			CloseHandle(hAllEvents[i]);
	}
	private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {
		textBox2->Text = "";
		int number = System::Convert::ToDouble(numProc->Value);
		HANDLE hStart = CreateEvent(NULL, TRUE, FALSE, (LPWSTR)"START");
		HANDLE hShow = CreateEvent(NULL, TRUE, FALSE, (LPWSTR)"SHOW");
		HANDLE hAccept = CreateEvent(NULL, TRUE, TRUE, (LPWSTR)"ACCEPT");

		STARTUPINFO si;
		PROCESS_INFORMATION pi;
		ZeroMemory(&si, sizeof(STARTUPINFO));
		si.cb = sizeof(STARTUPINFO);
		for (int i = 0; i < number; i++)
		{
			logTextBox->Text += "*Open the " + i + " client\n";
			CreateProcess(L"C:\\Users\\DiBoS\\Desktop\\Labs\\OperatingSystems\\OS-3 C++ GUI\\ProjectClientGUI\\Debug\\ProjectClientGUI.exe",
				NULL, NULL, NULL, FALSE, CREATE_NEW_CONSOLE, NULL, NULL, &si, &pi);
		}
		WaitForSingleObject(hStart, INFINITE);		//ждем когда клиент запустит ивент СТАРТ

		logTextBox->Text += "*The start of work\n";
		HANDLE hPressO = OpenEvent(EVENT_ALL_ACCESS, TRUE, (LPWSTR)"O");
		HANDLE hPressP = OpenEvent(EVENT_ALL_ACCESS, TRUE, (LPWSTR)"P");
		HANDLE hPressE = OpenEvent(EVENT_ALL_ACCESS, TRUE, (LPWSTR)"E");
		HANDLE hPressN = OpenEvent(EVENT_ALL_ACCESS, TRUE, (LPWSTR)"N");
		HANDLE hWork = OpenEvent(EVENT_ALL_ACCESS, TRUE, (LPWSTR)"WORK");
		HANDLE hPressExit = OpenEvent(EVENT_ALL_ACCESS, TRUE, (LPWSTR)"EXIT");
		HANDLE hPressA = CreateEvent(NULL, TRUE, FALSE, (LPWSTR)"A");
		HANDLE hPressB = CreateEvent(NULL, TRUE, FALSE, (LPWSTR)"B");
		HANDLE hPressC = CreateEvent(NULL, TRUE, FALSE, (LPWSTR)"C");
		HANDLE hPressD = CreateEvent(NULL, TRUE, FALSE, (LPWSTR)"D");
		HANDLE hPressF = CreateEvent(NULL, TRUE, FALSE, (LPWSTR)"F");
		HANDLE hPressG = CreateEvent(NULL, TRUE, FALSE, (LPWSTR)"G");
		HANDLE hPressH = CreateEvent(NULL, TRUE, FALSE, (LPWSTR)"H");
		HANDLE hPressI = CreateEvent(NULL, TRUE, FALSE, (LPWSTR)"I");
		HANDLE hPressJ = CreateEvent(NULL, TRUE, FALSE, (LPWSTR)"J");
		HANDLE hPressK = CreateEvent(NULL, TRUE, FALSE, (LPWSTR)"K");
		HANDLE hPressL = CreateEvent(NULL, TRUE, FALSE, (LPWSTR)"L");
		HANDLE hPressM = CreateEvent(NULL, TRUE, FALSE, (LPWSTR)"M");
		HANDLE hPressZ = CreateEvent(NULL, TRUE, FALSE, (LPWSTR)"Z");
		HANDLE hPressU = CreateEvent(NULL, TRUE, FALSE, (LPWSTR)"U");
		HANDLE hPressQ = CreateEvent(NULL, TRUE, FALSE, (LPWSTR)"Q");
		HANDLE hPressR = CreateEvent(NULL, TRUE, FALSE, (LPWSTR)"R");
		HANDLE hPressS = CreateEvent(NULL, TRUE, FALSE, (LPWSTR)"S");
		HANDLE hPressT = CreateEvent(NULL, TRUE, FALSE, (LPWSTR)"T");
		HANDLE hPressW = CreateEvent(NULL, TRUE, FALSE, (LPWSTR)"W");
		HANDLE hPressV = CreateEvent(NULL, TRUE, FALSE, (LPWSTR)"V");
		HANDLE hPressX = CreateEvent(NULL, TRUE, FALSE, (LPWSTR)"X");
		HANDLE hPressY = CreateEvent(NULL, TRUE, FALSE, (LPWSTR)"Y");
		HANDLE hSem = OpenSemaphore(SEMAPHORE_ALL_ACCESS, FALSE, (LPWSTR)"SEM");

		hAllEvents[0] = hPressA;	hAllEvents[1] = hPressB;	hAllEvents[2] = hPressC;
		hAllEvents[3] = hPressD;	hAllEvents[4] = hPressE;	hAllEvents[5] = hPressF;
		hAllEvents[6] = hPressG;	hAllEvents[7] = hPressH;	hAllEvents[8] = hPressI;
		hAllEvents[9] = hPressJ;	hAllEvents[10] = hPressK;	hAllEvents[11] = hPressL;
		hAllEvents[12] = hPressM;	hAllEvents[13] = hPressN;	hAllEvents[14] = hPressO;
		hAllEvents[15] = hPressP;	hAllEvents[16] = hPressQ;	hAllEvents[17] = hPressR;
		hAllEvents[18] = hPressS;	hAllEvents[19] = hPressT;	hAllEvents[20] = hPressU;
		hAllEvents[21] = hPressW;	hAllEvents[22] = hPressV;	hAllEvents[23] = hPressX;
		hAllEvents[24] = hPressY;	hAllEvents[25] = hPressZ;	hAllEvents[26] = hPressExit;
		hAllEvents[27] = hShow;		hAllEvents[28] = hWork; hAllEvents[29] = hAccept;
		hAllEvents[30] = hSem;

		bool escape = 0;

		int numClients = number;


		while (1)
		{
			switch (WaitForMultipleObjects(27, hAllEvents, FALSE, INFINITE))
			{
			case 0:
				textBox2->Text += " A";
				logTextBox->Text += "*The client introduced the symbol -> A\n";
				hAllEvents1[0] = OpenEvent(EVENT_MODIFY_STATE, FALSE, (LPWSTR)"A");
				SetEvent(hAllEvents1[0]);
				ResetEvent(hAllEvents1[0]);
				break;
			case 1:
				textBox2->Text += " B";
				logTextBox->Text += "*The client introduced the symbol -> B\n";
				hAllEvents1[1] = OpenEvent(EVENT_MODIFY_STATE, FALSE, (LPWSTR)"B");

				SetEvent(hAllEvents1[1]);
				ResetEvent(hAllEvents1[1]);
				break;
			case 2:
				textBox2->Text += " C";
				logTextBox->Text += "*The client introduced the symbol -> C\n";
				hAllEvents1[2] = OpenEvent(EVENT_MODIFY_STATE, FALSE, (LPWSTR)"C");

				SetEvent(hAllEvents1[2]);
				ResetEvent(hAllEvents1[2]);
				break;
			case 3:
				textBox2->Text += " D";
				logTextBox->Text += "*The client introduced the symbol -> D\n";
				hAllEvents1[3] = OpenEvent(EVENT_MODIFY_STATE, FALSE, (LPWSTR)"D");

				SetEvent(hAllEvents1[3]);
				ResetEvent(hAllEvents1[3]);
				break;
			case 4:
				textBox2->Text += " E";
				logTextBox->Text += "*The client introduced the symbol -> E\n";
				hAllEvents1[4] = OpenEvent(EVENT_MODIFY_STATE, FALSE, (LPWSTR)"E");

				SetEvent(hAllEvents1[4]);
				ResetEvent(hAllEvents1[4]);
				break;
			case 5:
				textBox2->Text += " F";
				logTextBox->Text += "*The client introduced the symbol -> F\n";
				hAllEvents1[5] = OpenEvent(EVENT_MODIFY_STATE, FALSE, (LPWSTR)"F");

				SetEvent(hAllEvents1[5]);
				ResetEvent(hAllEvents1[5]);
				break;
			case 6:
				textBox2->Text += " G";
				logTextBox->Text += "*The client introduced the symbol -> G\n";
				hAllEvents1[6] = OpenEvent(EVENT_MODIFY_STATE, FALSE, (LPWSTR)"G");
				SetEvent(hAllEvents1[6]);
				ResetEvent(hAllEvents1[6]);
				break;
			case 7:
				textBox2->Text += " H";
				logTextBox->Text += "*The client introduced the symbol -> H\n";
				hAllEvents1[7] = OpenEvent(EVENT_MODIFY_STATE, FALSE, (LPWSTR)"H");

				SetEvent(hAllEvents1[7]);
				ResetEvent(hAllEvents1[7]);
				break;
			case 8:
				textBox2->Text += " I";
				logTextBox->Text += "*The client introduced the symbol -> I\n";
				hAllEvents1[8] = OpenEvent(EVENT_MODIFY_STATE, FALSE, (LPWSTR)"I");

				SetEvent(hAllEvents1[8]);
				ResetEvent(hAllEvents1[8]);
				break;
			case 9:
				textBox2->Text += " J";
				logTextBox->Text += "*The client introduced the symbol -> J\n";
				hAllEvents1[9] = OpenEvent(EVENT_MODIFY_STATE, FALSE, (LPWSTR)"J");

				SetEvent(hAllEvents1[9]);
				ResetEvent(hAllEvents1[9]);
				break;
			case 10:
				textBox2->Text += " K";
				logTextBox->Text += "*The client introduced the symbol -> K\n";
				hAllEvents1[10] = OpenEvent(EVENT_MODIFY_STATE, FALSE, (LPWSTR)"K");

				SetEvent(hAllEvents1[10]);
				ResetEvent(hAllEvents1[10]);
				break;
			case 11:
				textBox2->Text += " L";
				logTextBox->Text += "*The client introduced the symbol -> L\n";
				hAllEvents1[11] = OpenEvent(EVENT_MODIFY_STATE, FALSE, (LPWSTR)"L");

				SetEvent(hAllEvents1[11]);
				ResetEvent(hAllEvents1[11]);
				break;
			case 12:
				textBox2->Text += " M";
				logTextBox->Text += "*The client introduced the symbol -> M\n";
				hAllEvents1[12] = OpenEvent(EVENT_MODIFY_STATE, FALSE, (LPWSTR)"M");

				SetEvent(hAllEvents1[12]);
				ResetEvent(hAllEvents1[12]);
				break;
			case 13:
				textBox2->Text += " N";
				logTextBox->Text += "*The client introduced the symbol -> N\n";
				hAllEvents1[13] = OpenEvent(EVENT_MODIFY_STATE, FALSE, (LPWSTR)"N");

				SetEvent(hAllEvents1[13]);
				ResetEvent(hAllEvents1[13]);
				break;
			case 14:
				textBox2->Text += " O";
				logTextBox->Text += "*The client introduced the symbol -> O\n";
				hAllEvents1[14] = OpenEvent(EVENT_MODIFY_STATE, FALSE, (LPWSTR)"O");

				SetEvent(hAllEvents1[14]);
				ResetEvent(hAllEvents1[14]);
				break;
			case 15:
				textBox2->Text += " P";
				logTextBox->Text += "*The client introduced the symbol -> P\n";
				hAllEvents1[15] = OpenEvent(EVENT_MODIFY_STATE, FALSE, (LPWSTR)"P");

				SetEvent(hAllEvents1[15]);
				ResetEvent(hAllEvents1[15]);
				break;
			case 16:
				textBox2->Text += " Q";
				logTextBox->Text += "*The client introduced the symbol -> Q\n";
				hAllEvents1[16] = OpenEvent(EVENT_MODIFY_STATE, FALSE, (LPWSTR)"Q");

				SetEvent(hAllEvents1[16]);
				ResetEvent(hAllEvents1[16]);
				break;
			case 17:
				textBox2->Text += " R";
				logTextBox->Text += "*The client introduced the symbol -> R\n";
				hAllEvents1[17] = OpenEvent(EVENT_MODIFY_STATE, FALSE, (LPWSTR)"R");

				SetEvent(hAllEvents1[17]);
				ResetEvent(hAllEvents1[17]);
				break;
			case 18:
				textBox2->Text += " S";
				logTextBox->Text += "*The client introduced the symbol -> S\n";
				hAllEvents1[18] = OpenEvent(EVENT_MODIFY_STATE, FALSE, (LPWSTR)"S");

				SetEvent(hAllEvents1[18]);
				ResetEvent(hAllEvents1[18]);
				break;
			case 19:
				textBox2->Text += " T";
				logTextBox->Text += "*The client introduced the symbol -> T\n";
				hAllEvents1[19] = OpenEvent(EVENT_MODIFY_STATE, FALSE, (LPWSTR)"T");

				SetEvent(hAllEvents1[19]);
				ResetEvent(hAllEvents1[19]);
				break;
			case 20:
				textBox2->Text += " U";
				logTextBox->Text += "*The client introduced the symbol -> U\n";
				hAllEvents1[20] = OpenEvent(EVENT_MODIFY_STATE, FALSE, (LPWSTR)"U");

				SetEvent(hAllEvents1[20]);
				ResetEvent(hAllEvents1[20]);
				break;
			case 21:
				textBox2->Text += " W";
				logTextBox->Text += "*The client introduced the symbol -> W\n";
				hAllEvents1[21] = OpenEvent(EVENT_MODIFY_STATE, FALSE, (LPWSTR)"W");

				SetEvent(hAllEvents1[21]);
				ResetEvent(hAllEvents1[21]);
				break;
			case 22:
				textBox2->Text += " V";
				logTextBox->Text += "*The client introduced the symbol -> V\n";
				hAllEvents1[22] = OpenEvent(EVENT_MODIFY_STATE, FALSE, (LPWSTR)"V");

				SetEvent(hAllEvents1[22]);
				ResetEvent(hAllEvents1[22]);
				break;
			case 23:
				textBox2->Text += " X";
				logTextBox->Text += "*The client introduced the symbol -> X\n";
				hAllEvents1[23] = OpenEvent(EVENT_MODIFY_STATE, FALSE, (LPWSTR)"X");

				SetEvent(hAllEvents1[23]);
				ResetEvent(hAllEvents1[23]);
				break;
			case 24:
				textBox2->Text += " Y";
				logTextBox->Text += "*The client introduced the symbol -> Y\n";
				hAllEvents1[24] = OpenEvent(EVENT_MODIFY_STATE, FALSE, (LPWSTR)"Y");

				SetEvent(hAllEvents1[24]);
				ResetEvent(hAllEvents1[24]);
				break;
			case 25:
				textBox2->Text += " Z";
				logTextBox->Text += "*The client introduced the symbol -> Z\n";
				hAllEvents1[25] = OpenEvent(EVENT_MODIFY_STATE, FALSE, (LPWSTR)"Z");
				SetEvent(hAllEvents1[25]);
				ResetEvent(hAllEvents1[25]);
				break;
			case 26:
				logTextBox->Text += "*The client disconnected from the server\n\n";
				hAllEvents1[26] = OpenEvent(EVENT_MODIFY_STATE, FALSE, (LPWSTR)"EXIT");
				SetEvent(hAllEvents1[26]);
				ResetEvent(hAllEvents1[26]);
				numClients--;
				escape = 1;
				break;
			}
			if (escape) {
				if (numClients == 0) {
					logTextBox->Text += "*All clients disconnected\n";
					break;
				}
			}
		}
	}
	private: System::Void textBox2_TextChanged(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void Label2_Click(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void numProc_SelectedItemChanged(System::Object^ sender, System::EventArgs^ e) {
	}
};
}