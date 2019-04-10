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
			cerr << "Error when creating a pipe" << endl
				<< "Error code: " << GetLastError() << endl;
			exit(1);
		}
		case 2: {
			cerr << "Could not wait for client" << endl
				<< "Error code: " << GetLastError() << endl;
			CloseHandle(hNamedPipe);
			exit(2);
		}
		case 3: {
			cerr << "Could not read data from pipe" << endl
				<< "Error code: " << GetLastError() << endl;
			CloseHandle(hNamedPipe);
			exit(3);
		}
		case 4: {
			cerr << "Nothing was found in the database for this query.\n";
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
		"\\\\.\\pipe\\DataBase",  // pipe name
		PIPE_ACCESS_DUPLEX, // read from pipe
		PIPE_TYPE_MESSAGE | PIPE_WAIT, // synchronous message transmission
		1, // maximum number of channel instances
		0, // the size of the output buffer by default
		0, // the size of the input buffer by default
		INFINITE, // the client is waiting for an infinitely long connection
		(LPSECURITY_ATTRIBUTES)NULL // default protection
	);
	// check for successful creation
	if (hNamedPipe == INVALID_HANDLE_VALUE) {
		error(1, hNamedPipe);
	}
	// waiting for the client to contact the pipe
	cout << "Waiting for client connection" << endl;
	if (!ConnectNamedPipe(
		hNamedPipe, // descriptor of the pipe
		(LPOVERLAPPED)NULL // synchronous communication
	))
	{
		error(2, hNamedPipe);
	}
	char request[50];
	// read data from the pipe
	DWORD dwBytesRead;
	if (!ReadFile(
		hNamedPipe, // descriptor of the pipe
		request, // buffer address for data entry
		50, // number of bytes read
		&dwBytesRead, // number of bytes read
		(LPOVERLAPPED)NULL // data transmission synchronous
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

	cout << "Query result:\n" << answer << endl;
	base.close();
	CloseHandle(hNamedPipe);
	return 0;
}