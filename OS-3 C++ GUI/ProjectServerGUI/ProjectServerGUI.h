#pragma once
#include "windows.h"
#include <iostream>
#include <cmath>
#include <conio.h>
#include <ctime>
#include <limits.h>
#include "process.h" 
#undef max
using namespace std;

HANDLE hAllEvents[30];
HANDLE hAllEvents1[30];

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
LONG cMax = 3;

namespace ProjectServerGUI {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;


	/// <summary>
	/// ������ ��� MyForm
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:
		MyForm(void)
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
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^ button1;
	private: System::Windows::Forms::TextBox^ numProc;


	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::TextBox^ textBox2;
	protected:


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
			this->numProc = (gcnew System::Windows::Forms::TextBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->textBox2 = (gcnew System::Windows::Forms::TextBox());
			this->SuspendLayout();
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(100, 227);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(75, 23);
			this->button1->TabIndex = 0;
			this->button1->Text = L"START";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &MyForm::button1_Click);
			// 
			// numProc
			// 
			this->numProc->Location = System::Drawing::Point(172, 31);
			this->numProc->Name = L"numProc";
			this->numProc->Size = System::Drawing::Size(100, 20);
			this->numProc->TabIndex = 1;
			this->numProc->TextChanged += gcnew System::EventHandler(this, &MyForm::numProc_TextChanged);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(12, 38);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(98, 13);
			this->label1->TabIndex = 2;
			this->label1->Text = L"Number of processes";
			// 
			// textBox2
			// 
			this->textBox2->Location = System::Drawing::Point(15, 148);
			this->textBox2->Name = L"textBox2";
			this->textBox2->Size = System::Drawing::Size(260, 20);
			this->textBox2->TabIndex = 3;
			this->textBox2->TextChanged += gcnew System::EventHandler(this, &MyForm::textBox2_TextChanged);
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(284, 262);
			this->Controls->Add(this->textBox2);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->numProc);
			this->Controls->Add(this->button1);
			this->Name = L"MyForm";
			this->Text = L"SERVER";
			this->Load += gcnew System::EventHandler(this, &MyForm::MyForm_Load);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void MyForm_Load(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {
		textBox2->Text = "";
		int number = System::Convert::ToDouble(numProc->Text);
		HANDLE hStart = CreateEvent(NULL, TRUE, FALSE, (LPWSTR)lpEventName6);
		HANDLE hShow = CreateEvent(NULL, TRUE, FALSE, (LPWSTR)lpEventName7);
		HANDLE hAccept = CreateEvent(NULL, TRUE, TRUE, (LPWSTR)lpEventName10);

		if (this->numProc->Text != "") {
			STARTUPINFO si;
			PROCESS_INFORMATION pi;
			ZeroMemory(&si, sizeof(STARTUPINFO));
			si.cb = sizeof(STARTUPINFO);
			for (int i = 0; i < number; i++)
			{
				CreateProcess(L"C:\\Users\\DiBoS\\Desktop\\Labs\\OperatingSystems\\OS-3 C++ GUI\\ProjectClientGUI\\Debug\\ProjectClientGUI.exe",
					NULL, NULL, NULL, FALSE, CREATE_NEW_CONSOLE, NULL, NULL, &si, &pi);
			}
			WaitForSingleObject(hStart, INFINITE);//���� ����� ������ �������� ����� �����
			HANDLE hPressG = OpenEvent(EVENT_ALL_ACCESS, TRUE, (LPWSTR)lpEventNameG);//��������� ������� ��������� ��������
			HANDLE hPressO = OpenEvent(EVENT_ALL_ACCESS, TRUE, (LPWSTR)lpEventNameO);
			HANDLE hPressN = OpenEvent(EVENT_ALL_ACCESS, TRUE, (LPWSTR)lpEventNameN);
			HANDLE hPressE = OpenEvent(EVENT_ALL_ACCESS, TRUE, (LPWSTR)lpEventNameE);
			HANDLE hWork = OpenEvent(EVENT_ALL_ACCESS, TRUE, (LPWSTR)lpEventName8);
			HANDLE hPressA = CreateEvent(NULL, TRUE, FALSE, (LPWSTR)lpEventNameA);
			HANDLE hPressB = CreateEvent(NULL, TRUE, FALSE, (LPWSTR)lpEventNameB);
			HANDLE hPressC = CreateEvent(NULL, TRUE, FALSE, (LPWSTR)lpEventNameC);
			HANDLE hPressD = CreateEvent(NULL, TRUE, FALSE, (LPWSTR)lpEventNameD);
			HANDLE hPressF = CreateEvent(NULL, TRUE, FALSE, (LPWSTR)lpEventNameF);
			HANDLE hPressH = CreateEvent(NULL, TRUE, FALSE, (LPWSTR)lpEventNameH);
			HANDLE hPressI = CreateEvent(NULL, TRUE, FALSE, (LPWSTR)lpEventNameI);
			HANDLE hPressJ = CreateEvent(NULL, TRUE, FALSE, (LPWSTR)lpEventNameJ);
			HANDLE hPressK = CreateEvent(NULL, TRUE, FALSE, (LPWSTR)lpEventNameK);
			HANDLE hPressL = CreateEvent(NULL, TRUE, FALSE, (LPWSTR)lpEventNameL);
			HANDLE hPressM = CreateEvent(NULL, TRUE, FALSE, (LPWSTR)lpEventNameM);
			HANDLE hPressZ = CreateEvent(NULL, TRUE, FALSE, (LPWSTR)lpEventNameZ);
			HANDLE hPressU = CreateEvent(NULL, TRUE, FALSE, (LPWSTR)lpEventNameU);
			HANDLE hPressP = CreateEvent(NULL, TRUE, FALSE, (LPWSTR)lpEventNameP);
			HANDLE hPressQ = CreateEvent(NULL, TRUE, FALSE, (LPWSTR)lpEventNameQ);
			HANDLE hPressR = CreateEvent(NULL, TRUE, FALSE, (LPWSTR)lpEventNameR);
			HANDLE hPressS = CreateEvent(NULL, TRUE, FALSE, (LPWSTR)lpEventNameS);
			HANDLE hPressT = CreateEvent(NULL, TRUE, FALSE, (LPWSTR)lpEventNameT);
			HANDLE hPressW = CreateEvent(NULL, TRUE, FALSE, (LPWSTR)lpEventNameW);
			HANDLE hPressV = CreateEvent(NULL, TRUE, FALSE, (LPWSTR)lpEventNameV);
			HANDLE hPressX = CreateEvent(NULL, TRUE, FALSE, (LPWSTR)lpEventNameX);
			HANDLE hPressY = CreateEvent(NULL, TRUE, FALSE, (LPWSTR)lpEventNameY);
			HANDLE hSem = OpenSemaphore(SEMAPHORE_ALL_ACCESS, FALSE, (LPWSTR)"SEM");
			HANDLE CL1 = CreateEvent(NULL, TRUE, FALSE, (LPWSTR)"CL1");
			HANDLE CL2 = CreateEvent(NULL, TRUE, FALSE, (LPWSTR)"CL2");
			HANDLE CL3 = CreateEvent(NULL, TRUE, FALSE, (LPWSTR)"CL3");
			hAllEvents[0] = hPressA;	hAllEvents[1] = hPressB;	hAllEvents[2] = hPressC;
			hAllEvents[3] = hPressD;	hAllEvents[4] = hPressE;	hAllEvents[5] = hPressF;
			hAllEvents[6] = hPressG;	hAllEvents[7] = hPressH;	hAllEvents[8] = hPressI;
			hAllEvents[9] = hPressJ;	hAllEvents[10] = hPressK;	hAllEvents[11] = hPressL;
			hAllEvents[12] = hPressM;	hAllEvents[13] = hPressN;	hAllEvents[14] = hPressO;
			hAllEvents[15] = hPressP;	hAllEvents[16] = hPressQ;	hAllEvents[17] = hPressR;
			hAllEvents[18] = hPressS;	hAllEvents[19] = hPressT;	hAllEvents[20] = hPressU;
			hAllEvents[21] = hPressW;	hAllEvents[22] = hPressV;	hAllEvents[23] = hPressX;
			hAllEvents[24] = hPressY;	hAllEvents[25] = hPressZ;	hAllEvents[26] = hStart;
			hAllEvents[27] = hShow;		hAllEvents[28] = hWork; hAllEvents[29] = hAccept;
			SYSTEMTIME st;
			GetSystemTime(&st);


			int a = 0;
			st.wHour += 4;
			bool escape = 0;

			int numCl = 0;
			int NumCl2 = number;


			while (1)
			{
				switch (WaitForMultipleObjects(26, hAllEvents, FALSE, INFINITE))
				{
				case 0:
					textBox2->Text += " A";
					hAllEvents1[0] = OpenEvent(EVENT_MODIFY_STATE, FALSE, (LPWSTR)lpEventNameA);
					SetEvent(hAllEvents1[0]);
					break;
				case 1:
					textBox2->Text += " B";
					hAllEvents1[1] = OpenEvent(EVENT_MODIFY_STATE, FALSE, (LPWSTR)lpEventNameB);

					SetEvent(hAllEvents1[1]);
					break;
				case 2:
					textBox2->Text += " C";
					hAllEvents1[2] = OpenEvent(EVENT_MODIFY_STATE, FALSE, (LPWSTR)lpEventNameC);

					SetEvent(hAllEvents1[2]);
					break;
				case 3:
					textBox2->Text += " D";
					hAllEvents1[3] = OpenEvent(EVENT_MODIFY_STATE, FALSE, (LPWSTR)lpEventNameD);

					SetEvent(hAllEvents1[3]);
					break;
				case 4:
					textBox2->Text += " E";
					hAllEvents1[4] = OpenEvent(EVENT_MODIFY_STATE, FALSE, (LPWSTR)lpEventNameE);

					SetEvent(hAllEvents1[4]);
					break;
				case 5:
					textBox2->Text += " F";
					hAllEvents1[5] = OpenEvent(EVENT_MODIFY_STATE, FALSE, (LPWSTR)lpEventNameF);

					SetEvent(hAllEvents1[5]);
					break;
				case 6:
					textBox2->Text += " G";
					hAllEvents1[6] = OpenEvent(EVENT_MODIFY_STATE, FALSE, (LPWSTR)lpEventNameG);
					SetEvent(hAllEvents1[6]);
					break;
				case 7:
					textBox2->Text += " H";
					hAllEvents1[7] = OpenEvent(EVENT_MODIFY_STATE, FALSE, (LPWSTR)lpEventNameH);

					SetEvent(hAllEvents1[7]);
					break;
				case 8:
					textBox2->Text += " I";
					hAllEvents1[8] = OpenEvent(EVENT_MODIFY_STATE, FALSE, (LPWSTR)lpEventNameI);

					SetEvent(hAllEvents1[8]);
					break;
				case 9:
					textBox2->Text += " J";
					hAllEvents1[9] = OpenEvent(EVENT_MODIFY_STATE, FALSE, (LPWSTR)lpEventNameJ);

					SetEvent(hAllEvents1[9]);
					break;
				case 10:
					textBox2->Text += " K";
					hAllEvents1[10] = OpenEvent(EVENT_MODIFY_STATE, FALSE, (LPWSTR)lpEventNameK);

					SetEvent(hAllEvents1[10]);
					break;
				case 11:
					textBox2->Text += " L";
					hAllEvents1[11] = OpenEvent(EVENT_MODIFY_STATE, FALSE, (LPWSTR)lpEventNameL);

					SetEvent(hAllEvents1[11]);
					break;
				case 12:
					textBox2->Text += " M";
					hAllEvents1[12] = OpenEvent(EVENT_MODIFY_STATE, FALSE, (LPWSTR)lpEventNameM);

					SetEvent(hAllEvents1[12]);
					break;
				case 13:
					textBox2->Text += " N";
					hAllEvents1[13] = OpenEvent(EVENT_MODIFY_STATE, FALSE, (LPWSTR)lpEventNameN);

					SetEvent(hAllEvents1[13]);
					break;
				case 14:
					textBox2->Text += " O";
					hAllEvents1[14] = OpenEvent(EVENT_MODIFY_STATE, FALSE, (LPWSTR)lpEventNameO);

					SetEvent(hAllEvents1[14]);
					break;
				case 15:
					textBox2->Text += " P";
					hAllEvents1[15] = OpenEvent(EVENT_MODIFY_STATE, FALSE, (LPWSTR)lpEventNameP);

					SetEvent(hAllEvents1[15]);
					break;
				case 16:
					textBox2->Text += " Q";
					hAllEvents1[16] = OpenEvent(EVENT_MODIFY_STATE, FALSE, (LPWSTR)lpEventNameQ);

					SetEvent(hAllEvents1[16]);
					break;
				case 17:
					textBox2->Text += " R";
					hAllEvents1[17] = OpenEvent(EVENT_MODIFY_STATE, FALSE, (LPWSTR)lpEventNameR);

					SetEvent(hAllEvents1[17]);
					break;
				case 18:
					textBox2->Text += " S";
					hAllEvents1[18] = OpenEvent(EVENT_MODIFY_STATE, FALSE, (LPWSTR)lpEventNameS);

					SetEvent(hAllEvents1[18]);
					break;
				case 19:
					textBox2->Text += " T";
					hAllEvents1[19] = OpenEvent(EVENT_MODIFY_STATE, FALSE, (LPWSTR)lpEventNameT);

					SetEvent(hAllEvents1[19]);
					break;
				case 20:
					textBox2->Text += " U";
					hAllEvents1[20] = OpenEvent(EVENT_MODIFY_STATE, FALSE, (LPWSTR)lpEventNameU);

					SetEvent(hAllEvents1[20]);
					break;
				case 21:
					textBox2->Text += " W";
					hAllEvents1[21] = OpenEvent(EVENT_MODIFY_STATE, FALSE, (LPWSTR)lpEventNameW);

					SetEvent(hAllEvents1[21]);
					break;
				case 22:
					textBox2->Text += " V";
					hAllEvents1[22] = OpenEvent(EVENT_MODIFY_STATE, FALSE, (LPWSTR)lpEventNameV);

					SetEvent(hAllEvents1[22]);
					break;
				case 23:
					textBox2->Text += " X";
					hAllEvents1[23] = OpenEvent(EVENT_MODIFY_STATE, FALSE, (LPWSTR)lpEventNameX);

					SetEvent(hAllEvents1[23]);
					break;
				case 24:
					textBox2->Text += " Y";
					hAllEvents1[24] = OpenEvent(EVENT_MODIFY_STATE, FALSE, (LPWSTR)lpEventNameY);

					SetEvent(hAllEvents1[24]);
					break;
				case 25:
					textBox2->Text += " Z";
					hAllEvents1[25] = OpenEvent(EVENT_MODIFY_STATE, FALSE, (LPWSTR)lpEventNameZ);
					SetEvent(hAllEvents1[25]);
					NumCl2--;
					numCl--;
					ReleaseSemaphore(hSem, 1, NULL);
					escape = 1;
					break;
				}

				if (escape) {
					if (NumCl2 == 0) {
						break;
					}
				}

				ResetEvent(hAllEvents1[0]);
				ResetEvent(hAllEvents1[1]);
				ResetEvent(hAllEvents1[2]);
				ResetEvent(hAllEvents1[3]);
				ResetEvent(hAllEvents1[4]);
				ResetEvent(hAllEvents1[5]);
				ResetEvent(hAllEvents1[6]);
				ResetEvent(hAllEvents1[7]);
				ResetEvent(hAllEvents1[8]);
				ResetEvent(hAllEvents1[9]);
				ResetEvent(hAllEvents1[10]);
				ResetEvent(hAllEvents1[11]);
				ResetEvent(hAllEvents1[12]);
				ResetEvent(hAllEvents1[13]);
				ResetEvent(hAllEvents1[14]);
				ResetEvent(hAllEvents1[15]);
				ResetEvent(hAllEvents1[16]);
				ResetEvent(hAllEvents1[17]);
				ResetEvent(hAllEvents1[18]);
				ResetEvent(hAllEvents1[19]);
				ResetEvent(hAllEvents1[20]);
				ResetEvent(hAllEvents1[21]);
				ResetEvent(hAllEvents1[22]);
				ResetEvent(hAllEvents1[23]);
				ResetEvent(hAllEvents1[24]);
				ResetEvent(hAllEvents1[25]);
			}

		}
	}
	private: System::Void textBox2_TextChanged(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void numProc_TextChanged(System::Object^ sender, System::EventArgs^ e) {
	}
	};
}