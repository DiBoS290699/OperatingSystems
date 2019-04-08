#include <windows.h>
#include <stdlib.h>
#include <iostream>
#include <io.h>
#include <fcntl.h>
#include <codecvt>
#include <string>

using namespace std;

const string INFO = "Введите номер интересующей вас информации: ";

void error(int err, HANDLE& hNamedPipe) {
	switch (err) 
	{
		case 1: {
			cerr << "Ошибка при подключении к серверу" << endl
				<< "Код ошибки: " << GetLastError() << endl;
			exit(1);
		}
		case 2: {
			cerr << "Ошибка при записи в канал: " << endl
				<< "Код ошибки: " << GetLastError() << endl;
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
		GENERIC_WRITE | GENERIC_READ, // записываем в канал
		FILE_SHARE_READ, // разрешаем только запись в канал
		(LPSECURITY_ATTRIBUTES)NULL, // защита по умолчанию
		OPEN_EXISTING, // открываем существующий канал
		0, // атрибуты по умолчанию
		(HANDLE)NULL // дополнительных атрибутов нет
	);
	// проверяем связь с каналом
	if (hNamedPipe == INVALID_HANDLE_VALUE)
	{
		error(1, hNamedPipe);
	}

	cout << INFO;
	string request;
	getline(cin, request);
	int request_size = request.length();
	while (!request_size) {
		cout << "Вы ничего не ввели. Попробуйте ещё раз." << endl;
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
		hNamedPipe, // дескриптор канала
		buff, // данные
		static_cast<DWORD>(strlen(buff) + 1), // размер данных
		&dwBytesWritten, // количество записанных байтов
		(LPOVERLAPPED)NULL // синхронная запись
	))
	{
		// ошибка записи
		error(2, hNamedPipe);
	}

	// закрываем дескриптор канала
	CloseHandle(hNamedPipe);
	// завершаем процесс
	cout << "Данные успешно отосланы на сервер" << endl;

	free(buff); 
	return 0;
}