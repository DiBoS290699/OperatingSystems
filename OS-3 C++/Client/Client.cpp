#include <windows.h>
#include <conio.h>
#include <iostream>
#include <ctime>

using namespace std;

HANDLE hAllEvents[30];

void errOpenEvent() {
	cout << "Event opening is failed.";
	_getch();
	exit(GetLastError());
}

int main()
{
	HANDLE hStart = OpenEvent(EVENT_ALL_ACCESS, TRUE, (LPCSTR)"START");
	if (!hStart)
	{
		cout << "No connection...\n";
		return -1;
	}
	//HANDLE hPassWord = OpenEvent(EVENT_ALL_ACCESS, TRUE, (LPCSTR)"PASSWORD");
	HANDLE hPassWord = CreateEvent(NULL, TRUE, FALSE, (LPCSTR)"PASSWORD"); if (hPassWord == NULL) return GetLastError();
	HANDLE hPressO = CreateEvent(NULL, TRUE, FALSE, (LPCSTR)"O"); if (hPressO == NULL) return GetLastError();
	HANDLE hPressP = CreateEvent(NULL, TRUE, FALSE, (LPCSTR)"P"); if (hPressP == NULL) return GetLastError();
	HANDLE hPressE = CreateEvent(NULL, TRUE, FALSE, (LPCSTR)"E"); if (hPressE == NULL) return GetLastError();
	HANDLE hPressN = CreateEvent(NULL, TRUE, FALSE, (LPCSTR)"N"); if (hPressN == NULL) return GetLastError();
	HANDLE hShow = OpenEvent(EVENT_ALL_ACCESS, TRUE, (LPCSTR)"SHOW");
	HANDLE hWork = CreateEvent(NULL, TRUE, TRUE, (LPCSTR)"WORK"); if (hWork == NULL) return GetLastError();
	HANDLE hPressExit = CreateEvent(NULL, TRUE, FALSE, (LPCSTR)"EXIT"); if (hPressExit == NULL) return GetLastError();

	SetEvent(hStart);
	CloseHandle(hStart);
	cout << "Please, enter a password:\n";
	BYTE ch = 0;
	bool password = false;
	wchar_t dw;
	HANDLE hAccept = OpenEvent(EVENT_ALL_ACCESS, TRUE, (LPCSTR)"ACCEPT");
	while ((ch = LOBYTE(LOWORD(_getch()))) != 27)
	{
		HANDLE hPassWord = CreateEvent(NULL, TRUE, FALSE, (LPCSTR)"PASSWORD"); if (hPassWord == NULL) return GetLastError();
		ResetEvent(hPassWord);
		if (ch == 79)		//key code O
		{
			cout << "O ";
			SetEvent(hPressO);
			ch = _getch();
			password = true;
			if (ch == 80)		//key code P
			{
				cout << "P ";
				SetEvent(hPressP);
				ch = _getch();
				password = true;
				if (ch == 69)		//key code E
				{
					cout << "E ";
					SetEvent(hPressE);
					ch = _getch();
					password = true;
					if (ch == 78)		//key code N
					{
						cout << "N ";
						SetEvent(hPressN);
						SetEvent(hPassWord);
						password = true;
						break;
					}
					else
					{
						password = false;
						cout << "Your password is incorrect! Please enter a password again.\n";
						continue;
					}
				}
				else
				{
					password = false;
					cout << "Your password is incorrect! Please enter a password again.\n";
					continue;
				}
			}
			else
			{
				password = false;
				cout << "Your password is incorrect! Please enter a password again.\n";
				continue;
			}
		}
		else
		{
			password = false;
			cout << "Your password is incorrect! Please enter a password again.\n";

			continue;
		}
	}
	if (ch == 27)
	{
		ResetEvent(hWork);
		cout << "Disconnected from the server!\n";
		return 0;
	}
	cout << "The password is entered correctly. Please, you enter only Latin letters:\n";
	WaitForSingleObject(hAccept, INFINITE);
	FlushConsoleInputBuffer(GetStdHandle(STD_INPUT_HANDLE));
	while ((dw = LOBYTE(LOWORD(_getch()))) != 27)
	{
		ResetEvent(hPassWord);
		printf("You have entered a character code: %d \n", dw - '0');
		switch (dw - '0')
		{
		case 17:
			hAllEvents[0] = OpenEvent(EVENT_MODIFY_STATE, FALSE, (LPCSTR)"A");
			if (hAllEvents[0] == NULL)
			{
				errOpenEvent();
			}
			SetEvent(hAllEvents[0]);
			ResetEvent(hAllEvents[0]);
			break;
		case 18:
			hAllEvents[1] = OpenEvent(EVENT_MODIFY_STATE, FALSE, (LPCSTR)"B");
			if (hAllEvents[1] == NULL)
			{
				errOpenEvent();
			}
			SetEvent(hAllEvents[1]);
			ResetEvent(hAllEvents[1]);
			break;
		case 19:
			hAllEvents[2] = OpenEvent(EVENT_MODIFY_STATE, FALSE, (LPCSTR)"C");
			if (hAllEvents[2] == NULL)
			{
				errOpenEvent();
			}
			SetEvent(hAllEvents[2]);
			ResetEvent(hAllEvents[2]);
			break;
		case 20:
			hAllEvents[3] = OpenEvent(EVENT_MODIFY_STATE, FALSE, (LPCSTR)"D");
			if (hAllEvents[3] == NULL)
			{
				errOpenEvent();
			}
			SetEvent(hAllEvents[3]);
			ResetEvent(hAllEvents[3]);
			break;
		case 21:
			hAllEvents[4] = OpenEvent(EVENT_MODIFY_STATE, FALSE, (LPCSTR)"E");
			if (hAllEvents[4] == NULL)
			{
				errOpenEvent();
			}
			SetEvent(hAllEvents[4]);
			ResetEvent(hAllEvents[4]);
			break;
		case 22:
			hAllEvents[5] = OpenEvent(EVENT_MODIFY_STATE, FALSE, (LPCSTR)"F");
			if (hAllEvents[5] == NULL)
			{
				errOpenEvent();
			}
			SetEvent(hAllEvents[5]);
			ResetEvent(hAllEvents[5]);
			break;
		case 23:
			hAllEvents[6] = OpenEvent(EVENT_MODIFY_STATE, FALSE, (LPCSTR)"G");
			if (hAllEvents[6] == NULL)
			{
				errOpenEvent();
			}
			SetEvent(hAllEvents[6]);
			ResetEvent(hAllEvents[6]);
			break;
		case 24:
			hAllEvents[7] = OpenEvent(EVENT_MODIFY_STATE, FALSE, (LPCSTR)"H");
			if (hAllEvents[7] == NULL)
			{
				errOpenEvent();
			}
			SetEvent(hAllEvents[7]);
			ResetEvent(hAllEvents[7]);
			break;
		case 25:
			hAllEvents[8] = OpenEvent(EVENT_MODIFY_STATE, FALSE, (LPCSTR)"I");
			if (hAllEvents[8] == NULL)
			{
				errOpenEvent();
			}
			SetEvent(hAllEvents[8]);
			ResetEvent(hAllEvents[8]);
			break;
		case 26:
			hAllEvents[9] = OpenEvent(EVENT_MODIFY_STATE, FALSE, (LPCSTR)"J");
			if (hAllEvents[9] == NULL)
			{
				errOpenEvent();
			}
			SetEvent(hAllEvents[9]);
			ResetEvent(hAllEvents[9]);
			break;
		case 27:
			hAllEvents[10] = OpenEvent(EVENT_MODIFY_STATE, FALSE, (LPCSTR)"K");
			if (hAllEvents[10] == NULL)
			{
				errOpenEvent();
			}
			SetEvent(hAllEvents[10]);
			ResetEvent(hAllEvents[10]);
			break;
		case 28:
			hAllEvents[11] = OpenEvent(EVENT_MODIFY_STATE, FALSE, (LPCSTR)"L");
			if (hAllEvents[11] == NULL)
			{
				errOpenEvent();
			}
			SetEvent(hAllEvents[11]);
			ResetEvent(hAllEvents[11]);
			break;
		case 29:
			hAllEvents[12] = OpenEvent(EVENT_MODIFY_STATE, FALSE, (LPCSTR)"M");
			if (hAllEvents[12] == NULL)
			{
				errOpenEvent();
			}
			SetEvent(hAllEvents[12]);
			ResetEvent(hAllEvents[12]);
			break;
		case 30:
			hAllEvents[13] = OpenEvent(EVENT_MODIFY_STATE, FALSE, (LPCSTR)"N");
			if (hAllEvents[13] == NULL)
			{
				errOpenEvent();
			}
			SetEvent(hAllEvents[13]);
			ResetEvent(hAllEvents[13]);
			break;
		case 31:
			hAllEvents[14] = OpenEvent(EVENT_MODIFY_STATE, FALSE, (LPCSTR)"O");
			if (hAllEvents[14] == NULL)
			{
				errOpenEvent();
			}
			SetEvent(hAllEvents[14]);
			ResetEvent(hAllEvents[14]);
			break;
		case 32:
			hAllEvents[15] = OpenEvent(EVENT_MODIFY_STATE, FALSE, (LPCSTR)"P");
			if (hAllEvents[15] == NULL)
			{
				errOpenEvent();
			}
			SetEvent(hAllEvents[15]);
			ResetEvent(hAllEvents[15]);
			break;
		case 33:
			hAllEvents[16] = OpenEvent(EVENT_MODIFY_STATE, FALSE, (LPCSTR)"Q");
			if (hAllEvents[16] == NULL)
			{
				errOpenEvent();
			}
			SetEvent(hAllEvents[16]);
			ResetEvent(hAllEvents[16]);
			break;
		case 34:
			hAllEvents[17] = OpenEvent(EVENT_MODIFY_STATE, FALSE, (LPCSTR)"R");
			if (hAllEvents[17] == NULL)
			{
				errOpenEvent();
			}
			SetEvent(hAllEvents[17]);
			ResetEvent(hAllEvents[17]);
			break;
		case 35:
			hAllEvents[18] = OpenEvent(EVENT_MODIFY_STATE, FALSE, (LPCSTR)"S");
			if (hAllEvents[18] == NULL)
			{
				errOpenEvent();
			}
			SetEvent(hAllEvents[18]);
			ResetEvent(hAllEvents[18]);
			break;
		case 36:
			hAllEvents[19] = OpenEvent(EVENT_MODIFY_STATE, FALSE, (LPCSTR)"T");
			if (hAllEvents[19] == NULL)
			{
				errOpenEvent();
			}
			SetEvent(hAllEvents[19]);
			ResetEvent(hAllEvents[19]);
			break;
		case 37:
			hAllEvents[20] = OpenEvent(EVENT_MODIFY_STATE, FALSE, (LPCSTR)"U");
			if (hAllEvents[20] == NULL)
			{
				errOpenEvent();
			}
			SetEvent(hAllEvents[20]);
			ResetEvent(hAllEvents[20]);
			break;
		case 38:
			hAllEvents[21] = OpenEvent(EVENT_MODIFY_STATE, FALSE, (LPCSTR)"W");
			if (hAllEvents[21] == NULL)
			{
				errOpenEvent();
			}
			SetEvent(hAllEvents[21]);
			ResetEvent(hAllEvents[21]);
			break;
		case 39:
			hAllEvents[22] = OpenEvent(EVENT_MODIFY_STATE, FALSE, (LPCSTR)"V");
			if (hAllEvents[22] == NULL)
			{
				errOpenEvent();
			}
			SetEvent(hAllEvents[22]);
			ResetEvent(hAllEvents[22]);
			break;
		case 40:
			hAllEvents[23] = OpenEvent(EVENT_MODIFY_STATE, FALSE, (LPCSTR)"X");
			if (hAllEvents[23] == NULL)
			{
				errOpenEvent();
			}
			SetEvent(hAllEvents[23]);
			ResetEvent(hAllEvents[23]);
			break;
		case 41:
			hAllEvents[24] = OpenEvent(EVENT_MODIFY_STATE, FALSE, (LPCSTR)"Y");
			if (hAllEvents[24] == NULL)
			{
				errOpenEvent();
			}
			SetEvent(hAllEvents[24]);
			ResetEvent(hAllEvents[24]);
			break;
		case 42:
			hAllEvents[25] = OpenEvent(EVENT_MODIFY_STATE, FALSE, (LPCSTR)"Z");
			if (hAllEvents[25] == NULL)
			{
				errOpenEvent();
			}
			SetEvent(hAllEvents[25]);
			ResetEvent(hAllEvents[25]);
			break;
		default:
			cout << "Wrong key!\n";
			break;
		}
		ResetEvent(hPassWord);
		CloseHandle(hPassWord);
	}
	ResetEvent(hPressO);
	ResetEvent(hPressP);
	ResetEvent(hPressE);
	ResetEvent(hPressN);
	SetEvent(hPressExit);

	HANDLE hPressA = OpenEvent(EVENT_ALL_ACCESS, TRUE, (LPCSTR)"A");
	HANDLE hPressB = OpenEvent(EVENT_ALL_ACCESS, TRUE, (LPCSTR)"B");
	HANDLE hPressC = OpenEvent(EVENT_ALL_ACCESS, TRUE, (LPCSTR)"C");
	HANDLE hPressD = OpenEvent(EVENT_ALL_ACCESS, TRUE, (LPCSTR)"D");
	HANDLE hPressF = OpenEvent(EVENT_ALL_ACCESS, TRUE, (LPCSTR)"F");
	HANDLE hPressG = OpenEvent(EVENT_ALL_ACCESS, TRUE, (LPCSTR)"G");
	HANDLE hPressH = OpenEvent(EVENT_ALL_ACCESS, TRUE, (LPCSTR)"H");
	HANDLE hPressI = OpenEvent(EVENT_ALL_ACCESS, TRUE, (LPCSTR)"I");
	HANDLE hPressJ = OpenEvent(EVENT_ALL_ACCESS, TRUE, (LPCSTR)"J");
	HANDLE hPressK = OpenEvent(EVENT_ALL_ACCESS, TRUE, (LPCSTR)"K");
	HANDLE hPressL = OpenEvent(EVENT_ALL_ACCESS, TRUE, (LPCSTR)"L");
	HANDLE hPressM = OpenEvent(EVENT_ALL_ACCESS, TRUE, (LPCSTR)"M");
	HANDLE hPressQ = OpenEvent(EVENT_ALL_ACCESS, TRUE, (LPCSTR)"Q");
	HANDLE hPressR = OpenEvent(EVENT_ALL_ACCESS, TRUE, (LPCSTR)"R");
	HANDLE hPressS = OpenEvent(EVENT_ALL_ACCESS, TRUE, (LPCSTR)"S");
	HANDLE hPressT = OpenEvent(EVENT_ALL_ACCESS, TRUE, (LPCSTR)"T");
	HANDLE hPressU = OpenEvent(EVENT_ALL_ACCESS, TRUE, (LPCSTR)"U");
	HANDLE hPressW = OpenEvent(EVENT_ALL_ACCESS, TRUE, (LPCSTR)"W");
	HANDLE hPressV = OpenEvent(EVENT_ALL_ACCESS, TRUE, (LPCSTR)"V");
	HANDLE hPressX = OpenEvent(EVENT_ALL_ACCESS, TRUE, (LPCSTR)"X");
	HANDLE hPressY = OpenEvent(EVENT_ALL_ACCESS, TRUE, (LPCSTR)"Y");
	HANDLE hPressZ = OpenEvent(EVENT_ALL_ACCESS, TRUE, (LPCSTR)"Z");
	//HANDLE hPressExit = OpenEvent(EVENT_ALL_ACCESS, TRUE, (LPCSTR)"EXIT");
	

	hAllEvents[0] = hPressA;	hAllEvents[1] = hPressB;	hAllEvents[2] = hPressC;
	hAllEvents[3] = hPressD;	hAllEvents[4] = hPressE;	hAllEvents[5] = hPressF;
	hAllEvents[6] = hPressG;	hAllEvents[7] = hPressH;	hAllEvents[8] = hPressI;
	hAllEvents[9] = hPressJ;	hAllEvents[10] = hPressK;	hAllEvents[11] = hPressL;
	hAllEvents[12] = hPressM;	hAllEvents[13] = hPressN;	hAllEvents[14] = hPressO;
	hAllEvents[15] = hPressP;	hAllEvents[16] = hPressQ;	hAllEvents[17] = hPressR;
	hAllEvents[18] = hPressS;	hAllEvents[19] = hPressT;	hAllEvents[20] = hPressU;
	hAllEvents[21] = hPressW;	hAllEvents[22] = hPressV;	hAllEvents[23] = hPressX;
	hAllEvents[24] = hPressY;	hAllEvents[25] = hPressZ;	hAllEvents[26] = hPressExit;
	hAllEvents[27] = hShow;		hAllEvents[28] = hWork;		hAllEvents[29] = hAccept;

	CloseHandle(hPressO);
	CloseHandle(hPressP);
	CloseHandle(hPressE);
	CloseHandle(hPressN);
	CloseHandle(hShow);
	system("pause");
	return 0;
}