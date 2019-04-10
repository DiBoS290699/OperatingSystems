//
// Created by DiBoS on 26.03.2019.
//
#include <windows.h>
#include <iostream>
#include <io.h>
#include <fcntl.h>
#include <codecvt>
#include <string>
#include "EncryptCaesar.h"

using namespace std;

int main() {
    HANDLE hNamedPipe;
    hNamedPipe = CreateFile(
            "\\\\.\\pipe\\CaesarPipe",
            GENERIC_WRITE | GENERIC_READ, // written to the pipe
            FILE_SHARE_READ, // only allow entry to the pipe
            (LPSECURITY_ATTRIBUTES) NULL, // default protection
            OPEN_EXISTING, // open an existing pipe
            0, // default attributes
            (HANDLE) NULL // no additional attributes
    );
    // check communication with the pipe
    if (hNamedPipe == INVALID_HANDLE_VALUE)
    {
        cerr << "Error connecting to server" << endl
        << "Error code: " << GetLastError() << endl;
        return 0;
    }

    cout << "Enter text to encrypt: ";
    string text;
    getline(cin, text);
    encryption(text);
    char buff[text.length()];
    for (int i = 0; i < text.length(); ++i) {
        buff[i] = text[i];
    }
    cout << buff << endl;
    DWORD dwBytesWritten;
    if(!WriteFile(
            hNamedPipe, // descriptor of the pipe
            buff, // data
            static_cast<DWORD>(strlen(buff) + 1), // data size
            &dwBytesWritten, // number of bytes written
            (LPOVERLAPPED) NULL // synchronous recording
            ))
    {
        // write error
        cerr << "Error writing to channel: " << endl
        << "Error code: " << GetLastError() << endl;
        CloseHandle(hNamedPipe);
        return 0;
    }
    // close the channel descriptor
    CloseHandle(hNamedPipe);
    // complete the process
    cout << "Data successfully sent to the server" << endl;
    return 0;
}