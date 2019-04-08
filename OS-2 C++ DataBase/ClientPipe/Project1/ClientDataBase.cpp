#include <windows.h>
#include <stdlib.h>
#include <iostream>
#include <io.h>
#include <fcntl.h>
#include <codecvt>
#include <string>

using namespace std;

const string INFO = "������� ����� ������������ ��� ����������: ";

void error(int err, HANDLE& hNamedPipe) {
	switch (err) 
	{
		case 1: {
			cerr << "������ ��� ����������� � �������" << endl
				<< "��� ������: " << GetLastError() << endl;
			exit(1);
		}
		case 2: {
			cerr << "������ ��� ������ � �����: " << endl
				<< "��� ������: " << GetLastError() << endl;
			CloseHandle(hNamedPipe);
			exit(2);
		}
	}
}

int main() {
	setlocale(LC_ALL, "rus");
	HANDLE hNamedPipe;
	hNamedPipe = CreateFile(
		"\\\\.\\pipe\\DataBase",
		GENERIC_WRITE | GENERIC_READ, // ���������� � �����
		FILE_SHARE_READ, // ��������� ������ ������ � �����
		(LPSECURITY_ATTRIBUTES)NULL, // ������ �� ���������
		OPEN_EXISTING, // ��������� ������������ �����
		0, // �������� �� ���������
		(HANDLE)NULL // �������������� ��������� ���
	);
	// ��������� ����� � �������
	if (hNamedPipe == INVALID_HANDLE_VALUE)
	{
		error(1, hNamedPipe);
	}

	cout << INFO;
	string request;
	getline(cin, request);
	int request_size = request.length();
	while (!request_size) {
		cout << "�� ������ �� �����. ���������� ��� ���." << endl;
		cout << INFO;
		getline(cin, request);
		request_size = request.length();
	}

	char* buff = (char*) malloc(request_size);
	for (int i = 0; i < request_size; ++i) {
		*(buff+i) = request[i];
	}
	
	DWORD dwBytesWritten;
	if (!WriteFile(
		hNamedPipe, // ���������� ������
		buff, // ������
		static_cast<DWORD>(strlen(buff) + 1), // ������ ������
		&dwBytesWritten, // ���������� ���������� ������
		(LPOVERLAPPED)NULL // ���������� ������
	))
	{
		// ������ ������
		error(2, hNamedPipe);
	}

	// ��������� ���������� ������
	CloseHandle(hNamedPipe);
	// ��������� �������
	cout << "������ ������� �������� �� ������" << endl;

	free(buff); 
	return 0;
}