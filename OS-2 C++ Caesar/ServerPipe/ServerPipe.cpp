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
            "\\\\.\\pipe\\CaesarPipe",  // имя канала
            PIPE_ACCESS_DUPLEX, // читаем из канала
            PIPE_TYPE_MESSAGE | PIPE_WAIT, // синхронная передача сообщений
            1, // максимальное количество экземпляров канала
            0, // размер выходного буфера по умолчанию
            0, // размер входного буфера по умолчанию
            INFINITE, // клиент ждет связь бесконечно долго
            (LPSECURITY_ATTRIBUTES) NULL // защита по умолчанию
            );
    // проверяем на успешное создание
    if (hNamedPipe == INVALID_HANDLE_VALUE) {
        cerr << "Ошибка при создании канала" << endl
        << "Код ошибки: " << GetLastError() << endl;
        return 0;
    }
    // ждем пока клиент свяжется с каналом
    cout << "Ожидаем подключение клиента" << endl;
    if (!ConnectNamedPipe(
            hNamedPipe, // дескриптор канала
            (LPOVERLAPPED) NULL // связь синхронная
            ))
    {
        cerr << "Не удалось дождаться клиента" << endl
        << "Код ошибки: " << GetLastError() << endl;
        CloseHandle(hNamedPipe);
        return 0;
    }
    char out[100];
    // читаем данные из канала
    int nData;
    DWORD dwBytesRead;
    if (!ReadFile(
            hNamedPipe, // дескриптор канала
            out, // адрес буфера для ввода данных
            100, // количество читаемых байтов
            &dwBytesRead, // количество прочитанных байтов
            (LPOVERLAPPED) NULL // передача данных синхронная
        ))
    {
        cerr << "Не удалось прочитать данные из канала" << endl
        << "Код ошибки: " << GetLastError() << endl;
        CloseHandle(hNamedPipe);
        return 0;
    }
    // расшифровываем полученные данные
    string decryptOut = decription(out);
    // выводим прочитанные данные на консоль
    cout << "Получено сообщение:  " << decryptOut  << endl;
    // закрываем дескриптор канала
    CloseHandle(hNamedPipe);
    // завершаем процесс
    cout << "Данные успешно доставлены" << endl;
    return 0;
}