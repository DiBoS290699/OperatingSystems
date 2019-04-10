#include <windows.h>
#include <stdlib.h>
#include <iostream>
#include <io.h>
#include <fcntl.h>
#include <codecvt>
#include <string>

using namespace std;

const string INFO = "Enter the number of information you are interested in: ";

void error(int err, HANDLE& hNamedPipe) {
	switch (err) 
	{
		case 1: {
			cerr << "Error connecting to server" << endl
				<< "Error code: " << GetLastError() << endl;
			exit(1);
		}
		case 2: {
			cerr << "Error writing to pipe: " << endl
				<< "Error code: " << GetLastError() << endl;
			CloseHandle(hNamedPipe);
			exit(2);
		}
	}
}

int main() {
	HANDLE hNamedPipe;
	hNamedPipe = CreateFile(
		"\\\\.\\pipe\\DataBase",
		GENERIC_WRITE | GENERIC_READ, // written to the pipe
		FILE_SHARE_READ, // only allow entry to the pipe
		(LPSECURITY_ATTRIBUTES)NULL, // default protection
		OPEN_EXISTING, // open an existing pipe
		0, // default attributes
		(HANDLE)NULL // no additional attributes
	);
	// check communication with the pipe
	if (hNamedPipe == INVALID_HANDLE_VALUE)
	{
		error(1, hNamedPipe);
	}

	cout << INFO;
	string request;
	getline(cin, request);
	int request_size = request.length();
	while (!request_size) {
		cout << "You entered nothing. Try again." << endl;
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
		hNamedPipe, // descriptor of the pipe
		buff, // data
		static_cast<DWORD>(strlen(buff) + 1), // data size
		&dwBytesWritten, // number of bytes written
		(LPOVERLAPPED)NULL // synchronous recording
	))
	{
		// write error
		error(2, hNamedPipe);
	}

	// close the channel descriptor
	CloseHandle(hNamedPipe);
	// complete the process
	cout << "Data successfully sent to the server" << endl;

	free(buff); 
	return 0;
}