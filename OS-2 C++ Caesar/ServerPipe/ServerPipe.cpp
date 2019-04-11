//
// Created by DiBoS on 26.03.2019.
//
#include <windows.h>
#include <iostream>
#include <io.h>
#include <fcntl.h>
#include <codecvt>
#include <string>
#include "DecryptCaesar.h"
using namespace std;

int main() {
    setlocale(LC_ALL, "rus");
    HANDLE hNamedPipe;
    hNamedPipe = CreateNamedPipe(
            "\\\\.\\pipe\\CaesarPipe",  // pipe name
            PIPE_ACCESS_DUPLEX, // read from pipe
            PIPE_TYPE_MESSAGE | PIPE_WAIT, // synchronous message transmission
            1, // maximum number of channel instances
            0, // the size of the output buffer by default
            0, // the size of the input buffer by default
            INFINITE, // the client is waiting for an infinitely long connection
            (LPSECURITY_ATTRIBUTES) NULL // default protection
            );
    // check for successful creation
    if (hNamedPipe == INVALID_HANDLE_VALUE) {
        cerr << "Error when creating a channel" << endl
        << "Error code: " << GetLastError() << endl;
        return 0;
    }
    // waiting for the client to contact the pipe
    cout << "Waiting for client connection" << endl;
    if (!ConnectNamedPipe(
            hNamedPipe, // descriptor of the pipe
            (LPOVERLAPPED) NULL // synchronous communication
            ))
    {
        cerr << "Could not wait for client" << endl
        << "Error code: " << GetLastError() << endl;
        CloseHandle(hNamedPipe);
        return 0;
    }
    char out[100];
    // read data from the pipe
    DWORD dwBytesRead;
    if (!ReadFile(
            hNamedPipe, // descriptor of the pipe
            out, // buffer address for data entry
            100, // number of bytes read
            &dwBytesRead, // number of bytes read
            (LPOVERLAPPED) NULL // data transmission synchronous
        ))
    {
        cerr << "Could not read data from pipe" << endl
        << "Error code: " << GetLastError() << endl;
        CloseHandle(hNamedPipe);
        return 0;
    }
    // decrypt the data
    string decryptOut = decription(out);
    // output the read data to the console
    cout << "The received message:  " << decryptOut  << endl;
    // close the pipe descriptor
    CloseHandle(hNamedPipe);
    // complete the process
    cout << "The data was successfully delivered" << endl;
    return 0;
}