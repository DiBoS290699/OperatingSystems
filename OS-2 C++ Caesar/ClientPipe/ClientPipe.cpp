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
    setlocale(LC_ALL, "rus");
    HANDLE hNamedPipe;
    hNamedPipe = CreateFile(
            "\\\\.\\pipe\\CaesarPipe",
            GENERIC_WRITE | GENERIC_READ, // записываем в канал
            FILE_SHARE_READ, // разрешаем только запись в канал
            (LPSECURITY_ATTRIBUTES) NULL, // защита по умолчанию
            OPEN_EXISTING, // открываем существующий канал
            0, // атрибуты по умолчанию
            (HANDLE) NULL // дополнительных атрибутов нет
    );
    // проверяем связь с каналом
    if (hNamedPipe == INVALID_HANDLE_VALUE)
    {
        cerr << "Ошибка при подключении к серверу" << endl
        << "Код ошибки: " << GetLastError() << endl;
        return 0;
    }

    cout << "Введите текст для шифровки: ";
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
            hNamedPipe, // дескриптор канала
            buff, // данные
            static_cast<DWORD>(strlen(buff) + 1), // размер данных
            &dwBytesWritten, // количество записанных байтов
            (LPOVERLAPPED) NULL // синхронная запись
            ))
    {
        // ошибка записи
        cerr << "Ошибка при записи в канал: " << endl
        << "Код ошибки: " << GetLastError() << endl;
        CloseHandle(hNamedPipe);
        return 0;
    }
    // закрываем дескриптор канала
    CloseHandle(hNamedPipe);
    // завершаем процесс
    cout << "Данные успешно отосланы на сервер" << endl;
    return 0;
}