#include <windows.h>
#include <iostream>
#include <fstream>
#include <io.h>
#include <fcntl.h>
#include <codecvt>
#include <string>
using namespace std;

void error(int err, HANDLE& hNamedPipe) {
	switch (err) {
		case 1: {
			cerr << "������ ��� �������� ������" << endl
				<< "��� ������: " << GetLastError() << endl;
			exit(1);
		}
		case 2: {
			cerr << "�� ������� ��������� �������" << endl
				<< "��� ������: " << GetLastError() << endl;
			CloseHandle(hNamedPipe);
			exit(2);
		}
		case 3: {
			cerr << "�� ������� ��������� ������ �� ������" << endl
				<< "��� ������: " << GetLastError() << endl;
			CloseHandle(hNamedPipe);
			exit(3);
		}
		case 4: {
			cerr << "� ���� ������ �� ������� ������� ������ �� �������.\n";
			CloseHandle(hNamedPipe);
			exit(4);
		}
	}
}

int main() {
	setlocale(LC_ALL, "rus");
	ifstream base("DO_NOT_TOUCH.txt");
	HANDLE hNamedPipe;
	hNamedPipe = CreateNamedPipe(
		"\\\\.\\pipe\\DataBase",  // ��� ������
		PIPE_ACCESS_DUPLEX, // ������ �� ������
		PIPE_TYPE_MESSAGE | PIPE_WAIT, // ���������� �������� ���������
		1, // ������������ ���������� ����������� ������
		0, // ������ ��������� ������ �� ���������
		0, // ������ �������� ������ �� ���������
		INFINITE, // ������ ���� ����� ���������� �����
		(LPSECURITY_ATTRIBUTES)NULL // ������ �� ���������
	);
	// ��������� �� �������� ��������
	if (hNamedPipe == INVALID_HANDLE_VALUE) {
		error(1, hNamedPipe);
	}
	// ���� ���� ������ �������� � �������
	cout << "������� ����������� �������" << endl;
	if (!ConnectNamedPipe(
		hNamedPipe, // ���������� ������
		(LPOVERLAPPED)NULL // ����� ����������
	))
	{
		error(2, hNamedPipe);
	}
	char request[50];
	// ������ ������ �� ������
	DWORD dwBytesRead;
	if (!ReadFile(
		hNamedPipe, // ���������� ������
		request, // ����� ������ ��� ����� ������
		50, // ���������� �������� ������
		&dwBytesRead, // ���������� ����������� ������
		(LPOVERLAPPED)NULL // �������� ������ ����������
	))
	{
		error(3, hNamedPipe);
	}
	
	string answer;
	int index;
	try {
		index = atoi(request);
	}
	catch (...) {
		error(4, hNamedPipe);
	}
	for (int i = 0; i < index; ++i) {
		getline(base, answer);
	}

	cout << "��������� �������:\n" << answer << endl;
	base.close();
	CloseHandle(hNamedPipe);
	return 0;
}