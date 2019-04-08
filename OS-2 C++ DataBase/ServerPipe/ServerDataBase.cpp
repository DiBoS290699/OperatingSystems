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
			cerr << "Ошибка при создании канала" << endl
				<< "Код ошибки: " << GetLastError() << endl;
			exit(1);
		}
		case 2: {
			cerr << "Не удалось дождаться клиента" << endl
				<< "Код ошибки: " << GetLastError() << endl;
			CloseHandle(hNamedPipe);
			exit(2);
		}
		case 3: {
			cerr << "Не удалось прочитать данные из канала" << endl
				<< "Код ошибки: " << GetLastError() << endl;
			CloseHandle(hNamedPipe);
			exit(3);
		}
		case 4: {
			cerr << "В базе данных по данному запросу ничего не найдено.\n";
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
		"\\\\.\\pipe\\DataBase",  // имя канала
		PIPE_ACCESS_DUPLEX, // читаем из канала
		PIPE_TYPE_MESSAGE | PIPE_WAIT, // синхронная передача сообщений
		1, // максимальное количество экземпляров канала
		0, // размер выходного буфера по умолчанию
		0, // размер входного буфера по умолчанию
		INFINITE, // клиент ждет связь бесконечно долго
		(LPSECURITY_ATTRIBUTES)NULL // защита по умолчанию
	);
	// проверяем на успешное создание
	if (hNamedPipe == INVALID_HANDLE_VALUE) {
		error(1, hNamedPipe);
	}
	// ждем пока клиент свяжется с каналом
	cout << "Ожидаем подключение клиента" << endl;
	if (!ConnectNamedPipe(
		hNamedPipe, // дескриптор канала
		(LPOVERLAPPED)NULL // связь синхронная
	))
	{
		error(2, hNamedPipe);
	}
	char request[50];
	// читаем данные из канала
	DWORD dwBytesRead;
	if (!ReadFile(
		hNamedPipe, // дескриптор канала
		request, // адрес буфера для ввода данных
		50, // количество читаемых байтов
		&dwBytesRead, // количество прочитанных байтов
		(LPOVERLAPPED)NULL // передача данных синхронная
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

	cout << "Результат запроса:\n" << answer << endl;
	base.close();
	CloseHandle(hNamedPipe);
	return 0;
}