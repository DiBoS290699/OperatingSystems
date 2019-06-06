
#include "windows.h"
#include "string"
#include <iostream>
#include <conio.h>
#include "process.h" 
using namespace std;

HANDLE hAllEvents[30];
HANDLE hAllEventsNew[30];

void errOpenEvent() {
	cout << "Event opening is failed.";
	exit(GetLastError());
}

int main()
{
	int numProc = 0;
	cout << "Please, enter a number of processes: ";
	cin >> numProc;
	if (numProc <= 0 || !cin.good())
	{
		cout << "Error!" << endl;
		return 1;
	}

	HANDLE hStart = CreateEvent(NULL, TRUE, FALSE, (LPCSTR)"START");
	if (hStart == NULL) return GetLastError();
	HANDLE hShow = CreateEvent(NULL, TRUE, FALSE, (LPCSTR)"SHOW");
	if (hShow == NULL) return GetLastError();
	HANDLE hAccept = CreateEvent(NULL, TRUE, TRUE, (LPCSTR)"ACCEPT");
	if (hAccept == NULL) return GetLastError();


	STARTUPINFO si;
	PROCESS_INFORMATION pi;
	ZeroMemory(&si, sizeof(STARTUPINFO));
	si.cb = sizeof(STARTUPINFO);
	for (int i = 0; i < numProc; i++)
	{
		CreateProcess ("C:\\Users\\DiBoS\\Desktop\\Labs\\OperatingSystems\\OS-3 C++\\Client\\Debug\\Client.exe",
			NULL, NULL, NULL, FALSE, CREATE_NEW_CONSOLE, NULL, NULL, &si, &pi);
	}

	WaitForSingleObject(hStart, INFINITE);		
	HANDLE hPressO = OpenEvent(EVENT_ALL_ACCESS, TRUE, (LPCSTR)"O");		
	HANDLE hPressP = OpenEvent(EVENT_ALL_ACCESS, TRUE, (LPCSTR)"P");
	HANDLE hPressE = OpenEvent(EVENT_ALL_ACCESS, TRUE, (LPCSTR)"E");
	HANDLE hPressN = OpenEvent(EVENT_ALL_ACCESS, TRUE, (LPCSTR)"N");
	HANDLE hWork = OpenEvent(EVENT_ALL_ACCESS, TRUE, (LPCSTR)"WORK");
	HANDLE hPressExit = OpenEvent(EVENT_ALL_ACCESS, TRUE, (LPCSTR)"EXIT");

	HANDLE hPressA = CreateEvent(NULL, TRUE, FALSE, (LPCSTR)"A"); if (hPressA == NULL) return GetLastError();
	HANDLE hPressB = CreateEvent(NULL, TRUE, FALSE, (LPCSTR)"B"); if (hPressB == NULL) return GetLastError();
	HANDLE hPressC = CreateEvent(NULL, TRUE, FALSE, (LPCSTR)"C"); if (hPressC == NULL) return GetLastError();
	HANDLE hPressD = CreateEvent(NULL, TRUE, FALSE, (LPCSTR)"D"); if (hPressD == NULL) return GetLastError();
	HANDLE hPressF = CreateEvent(NULL, TRUE, FALSE, (LPCSTR)"F"); if (hPressF == NULL) return GetLastError();
	HANDLE hPressG = CreateEvent(NULL, TRUE, FALSE, (LPCSTR)"G"); if (hPressG == NULL) return GetLastError();
	HANDLE hPressH = CreateEvent(NULL, TRUE, FALSE, (LPCSTR)"H"); if (hPressH == NULL) return GetLastError();
	HANDLE hPressI = CreateEvent(NULL, TRUE, FALSE, (LPCSTR)"I"); if (hPressI == NULL) return GetLastError();
	HANDLE hPressJ = CreateEvent(NULL, TRUE, FALSE, (LPCSTR)"J"); if (hPressJ == NULL) return GetLastError();
	HANDLE hPressK = CreateEvent(NULL, TRUE, FALSE, (LPCSTR)"K"); if (hPressK == NULL) return GetLastError();
	HANDLE hPressL = CreateEvent(NULL, TRUE, FALSE, (LPCSTR)"L"); if (hPressL == NULL) return GetLastError();
	HANDLE hPressM = CreateEvent(NULL, TRUE, FALSE, (LPCSTR)"M"); if (hPressM == NULL) return GetLastError();
	HANDLE hPressQ = CreateEvent(NULL, TRUE, FALSE, (LPCSTR)"Q"); if (hPressQ == NULL) return GetLastError();
	HANDLE hPressR = CreateEvent(NULL, TRUE, FALSE, (LPCSTR)"R"); if (hPressR == NULL) return GetLastError();
	HANDLE hPressS = CreateEvent(NULL, TRUE, FALSE, (LPCSTR)"S"); if (hPressS == NULL) return GetLastError();
	HANDLE hPressT = CreateEvent(NULL, TRUE, FALSE, (LPCSTR)"T"); if (hPressT == NULL) return GetLastError();
	HANDLE hPressU = CreateEvent(NULL, TRUE, FALSE, (LPCSTR)"U"); if (hPressU == NULL) return GetLastError();
	HANDLE hPressW = CreateEvent(NULL, TRUE, FALSE, (LPCSTR)"W"); if (hPressW == NULL) return GetLastError();
	HANDLE hPressV = CreateEvent(NULL, TRUE, FALSE, (LPCSTR)"V"); if (hPressV == NULL) return GetLastError();
	HANDLE hPressX = CreateEvent(NULL, TRUE, FALSE, (LPCSTR)"X"); if (hPressX == NULL) return GetLastError();
	HANDLE hPressY = CreateEvent(NULL, TRUE, FALSE, (LPCSTR)"Y"); if (hPressY == NULL) return GetLastError();
	HANDLE hPressZ = CreateEvent(NULL, TRUE, FALSE, (LPCSTR)"Z"); if (hPressZ == NULL) return GetLastError();
	

	hAllEvents[0] = hPressA;	hAllEvents[1] = hPressB;	hAllEvents[2] = hPressC;
	hAllEvents[3] = hPressD;	hAllEvents[4] = hPressE;	hAllEvents[5] = hPressF;
	hAllEvents[6] = hPressG;	hAllEvents[7] = hPressH;	hAllEvents[8] = hPressI;
	hAllEvents[9] = hPressJ;	hAllEvents[10] = hPressK;	hAllEvents[11] = hPressL;
	hAllEvents[12] = hPressM;	hAllEvents[13] = hPressN;	hAllEvents[14] = hPressO;
	hAllEvents[15] = hPressP;	hAllEvents[16] = hPressQ;	hAllEvents[17] = hPressR;
	hAllEvents[18] = hPressS;	hAllEvents[19] = hPressT;	hAllEvents[20] = hPressU;
	hAllEvents[21] = hPressW;	hAllEvents[22] = hPressV;	hAllEvents[23] = hPressX;
	hAllEvents[24] = hPressY;	hAllEvents[25] = hPressZ;	hAllEvents[26] = hPressExit;
	hAllEvents[27] = hShow;		hAllEvents[28] = hWork; 	hAllEvents[29] = hAccept;
	bool exit = false;
	int numActivProc = 0;
	while (true)
	{
		HANDLE hPassWord = OpenEvent(EVENT_ALL_ACCESS, TRUE, (LPCSTR)"PASSWORD");
		switch (WaitForMultipleObjects(27, hAllEvents, FALSE, INFINITE))
		{
		case 0:
			cout << "A ";
			hAllEventsNew[0] = OpenEvent(EVENT_MODIFY_STATE, FALSE, (LPCSTR)"A");
			if (hAllEventsNew[0] == NULL)
			{
				errOpenEvent();
			}
			SetEvent(hAllEventsNew[0]);
			break;
		case 1:
			cout <<"B ";
			hAllEventsNew[1] = OpenEvent(EVENT_MODIFY_STATE, FALSE, (LPCSTR)"B");
			if (hAllEventsNew[1] == NULL)
			{
				errOpenEvent();
			}
			SetEvent(hAllEventsNew[1]);
			break;
		case 2:
			cout <<"C ";
			hAllEventsNew[2] = OpenEvent(EVENT_MODIFY_STATE, FALSE, (LPCSTR)"C");
			if (hAllEventsNew[2] == NULL)
			{
				errOpenEvent();
			}
			SetEvent(hAllEventsNew[2]);
			break;
		case 3:
			cout << "D ";
			hAllEventsNew[3] = OpenEvent(EVENT_MODIFY_STATE, FALSE, (LPCSTR)"D");
			if (hAllEventsNew[3] == NULL)
			{
				errOpenEvent();
			}
			SetEvent(hAllEventsNew[3]);
			break;
		case 4: 
			cout << "E ";
			hAllEventsNew[4] = OpenEvent(EVENT_MODIFY_STATE, FALSE, (LPCSTR)"E");
			if (hAllEventsNew[4] == NULL)
			{
				errOpenEvent();
			}
			SetEvent(hAllEventsNew[4]);
			break;
		case 5:
			cout << "F ";
			hAllEventsNew[5] = OpenEvent(EVENT_MODIFY_STATE, FALSE, (LPCSTR)"F");
			if (hAllEventsNew[5] == NULL)
			{
				errOpenEvent();
			}
			SetEvent(hAllEventsNew[5]);
			break;
		case 6:
			cout << "G ";
			hAllEventsNew[6] = OpenEvent(EVENT_MODIFY_STATE, FALSE, (LPCSTR)"G");
			if (hAllEventsNew[6] == NULL)
			{
				errOpenEvent();
			}
			SetEvent(hAllEventsNew[6]);
			break;
		case 7: 
			cout << "H ";
			hAllEventsNew[7] = OpenEvent(EVENT_MODIFY_STATE, FALSE, (LPCSTR)"H");
			if (hAllEventsNew[7] == NULL)
			{
				errOpenEvent();
			}
			SetEvent(hAllEventsNew[7]);
			break;
		case 8:
			cout << "I ";
			hAllEventsNew[8] = OpenEvent(EVENT_MODIFY_STATE, FALSE, (LPCSTR)"I");
			if (hAllEventsNew[8] == NULL)
			{
				errOpenEvent();
			}
			SetEvent(hAllEventsNew[8]);
			break;
		case 9:
			cout << "J ";
			hAllEventsNew[9] = OpenEvent(EVENT_MODIFY_STATE, FALSE, (LPCSTR)"J");
			if (hAllEventsNew[9] == NULL)
			{
				errOpenEvent();
			}
			SetEvent(hAllEventsNew[9]);
			break;
		case 10: 
			cout << "K ";
			hAllEventsNew[10] = OpenEvent(EVENT_MODIFY_STATE, FALSE, (LPCSTR)"K");
			if (hAllEventsNew[10] == NULL)
			{
				errOpenEvent();
			}
			SetEvent(hAllEventsNew[10]);
			break;
		case 11:
			cout << "L ";
			hAllEventsNew[11] = OpenEvent(EVENT_MODIFY_STATE, FALSE, (LPCSTR)"L");
			if (hAllEventsNew[11] == NULL)
			{
				errOpenEvent();
			}
			SetEvent(hAllEventsNew[11]);
			break;
		case 12:
			cout << "M ";
			hAllEventsNew[12] = OpenEvent(EVENT_MODIFY_STATE, FALSE, (LPCSTR)"M");
			if (hAllEventsNew[12] == NULL)
			{
				errOpenEvent();
			}
			SetEvent(hAllEventsNew[12]);
			break;
		case 13: 
			cout << "N ";
			hAllEventsNew[13] = OpenEvent(EVENT_MODIFY_STATE, FALSE, (LPCSTR)"N");
			if (hAllEventsNew[13] == NULL)
			{
				errOpenEvent();
			}
			SetEvent(hAllEventsNew[13]);
			break;
		case 14:
			cout << "O ";
			hAllEventsNew[14] = OpenEvent(EVENT_MODIFY_STATE, FALSE, (LPCSTR)"O");
			if (hAllEventsNew[14] == NULL)
			{
				errOpenEvent();
			}
			SetEvent(hAllEventsNew[14]);
			break;
		case 15:
			cout << "P ";
			hAllEventsNew[15] = OpenEvent(EVENT_MODIFY_STATE, FALSE, (LPCSTR)"P");
			if (hAllEventsNew[15] == NULL)
			{
				errOpenEvent();
			}
			SetEvent(hAllEventsNew[15]);
			break;
		case 16: 
			cout << "Q ";
			hAllEventsNew[16] = OpenEvent(EVENT_MODIFY_STATE, FALSE, (LPCSTR)"Q");
			if (hAllEventsNew[16] == NULL)
			{
				errOpenEvent();
			}
			SetEvent(hAllEventsNew[16]);
			break;
		case 17:
			cout << "R ";
			hAllEventsNew[17] = OpenEvent(EVENT_MODIFY_STATE, FALSE, (LPCSTR)"R");
			if (hAllEventsNew[17] == NULL)
			{
				errOpenEvent();
			}
			SetEvent(hAllEventsNew[17]);
			break;
		case 18:
			cout << "S ";
			hAllEventsNew[18] = OpenEvent(EVENT_MODIFY_STATE, FALSE, (LPCSTR)"S");
			if (hAllEventsNew[18] == NULL)
			{
				errOpenEvent();
			}
			SetEvent(hAllEventsNew[18]);
			break;
		case 19:
			cout << "T ";
			hAllEventsNew[19] = OpenEvent(EVENT_MODIFY_STATE, FALSE, (LPCSTR)"T");
			if (hAllEventsNew[19] == NULL)
			{
				errOpenEvent();
			}
			SetEvent(hAllEventsNew[19]);
			break;
		case 20:
			cout << "U ";
			hAllEventsNew[20] = OpenEvent(EVENT_MODIFY_STATE, FALSE, (LPCSTR)"U");
			if (hAllEventsNew[20] == NULL)
			{
				errOpenEvent();
			}
			SetEvent(hAllEventsNew[20]);
			break;
		case 21:
			cout << "W ";
			hAllEventsNew[21] = OpenEvent(EVENT_MODIFY_STATE, FALSE, (LPCSTR)"W");
			if (hAllEventsNew[21] == NULL)
			{
				errOpenEvent();
			}
			SetEvent(hAllEventsNew[21]);
			break;
		case 22:
			cout << "V ";
			hAllEventsNew[22] = OpenEvent(EVENT_MODIFY_STATE, FALSE, (LPCSTR)"V");
			if (hAllEventsNew[22] == NULL)
			{
				errOpenEvent();
			}
			SetEvent(hAllEventsNew[22]);
			break;
		case 23:
			cout << "X ";
			hAllEventsNew[23] = OpenEvent(EVENT_MODIFY_STATE, FALSE, (LPCSTR)"X");
			if (hAllEventsNew[23] == NULL)
			{
				errOpenEvent();
			}
			SetEvent(hAllEventsNew[23]);
			break;
		case 24:
			cout << "Y ";
			hAllEventsNew[24] = OpenEvent(EVENT_MODIFY_STATE, FALSE, (LPCSTR)"Y");
			if (hAllEventsNew[24] == NULL)
			{
				errOpenEvent();
			}
			SetEvent(hAllEventsNew[24]);
			break;
		case 25:
			cout << "Z ";
			hAllEventsNew[25] = OpenEvent(EVENT_MODIFY_STATE, FALSE, (LPCSTR)"Z");
			if (hAllEventsNew[25] == NULL)
			{
				errOpenEvent();
			}
			SetEvent(hAllEventsNew[25]);
			break;
		case 26:
			cout << "\nExit proccess.\n";
			hAllEventsNew[26] = OpenEvent(EVENT_MODIFY_STATE, FALSE, (LPCSTR)"EXIT");
			if (hAllEventsNew[26] == NULL)
			{
				errOpenEvent();
			}
			SetEvent(hAllEventsNew[26]);
			numProc--;
			exit = true;
			break;
		}
		if (hPassWord) {
			if (WaitForSingleObject(hPassWord, 0) == WAIT_OBJECT_0)
				numActivProc++;
			if (numActivProc > 3)
				ResetEvent(hAccept);
			if (exit) {
				if (numProc == 0) {
					cout << "\nEnd of communication!\n";
					break;
				}
				SetEvent(hAccept);
			}
		}
		for (int i = 0; i < 27; ++i) {
			ResetEvent(hAllEventsNew[i]);
		}
	}

	for (int i = 0; i < 30; i++)
		CloseHandle(hAllEvents[i]);
	system("pause");
	return 0;
}