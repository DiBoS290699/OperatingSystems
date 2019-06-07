import os
from time import ctime

def cp(args):
    if not os.path.exists(args[0]):
        print('File is not found.')

    else:
        filename = args[0]      # Сохраняем имя файла
        destination = args[1]   # Сохраняем путь к копии

        file = open(filename, 'r')    # Открываем файл для чтения
        file.seek(0, os.SEEK_END)     # Переносим указатель в конец
        file_size = file.tell()     # Получаем номер позиции указателя
        file.seek(0, os.SEEK_SET)     # Возвращаем указатель на начало

        destination_file = open(destination, 'w')   # Открываем файл для записи
        while file.tell() < file_size:          # пока позиция указателя не дошла до конца
            block = file.read(30)                 # Заносим по 30 символов в копию
            destination_file.write(block)
        print('Copy completed')


def rights_info(file):
    result = []
    if os.access(file, os.W_OK):
        result.append('writable')      # Файл для записи
    if os.access(file, os.R_OK):
        result.append('readable')      # Файл для чтения
    if os.access(file, os.X_OK):
        result.append('executable')    # Файл можно изменять
    return result

def help():
    print('cp - <filename> <path where to copy to> - copy')
    print('chmod <filename> <encoded rights> - changing rights')
    print('info <filename> - info about filename')
    print('quit - quits the program')

def info(file):
    files = ''.join(file)   # Достаём строку
    inf = os.stat(files)    # Заносим информацию о файле
    inf_path = os.path.abspath(files)   # Путь до файла
    inf_acc = rights_info(files)       # Получение информации о правах доступа
    print('File name: ' + str(files))
    print('Rights: ' + str(inf_acc))
    print('Size: ' + str(inf.st_size) + ' bytes')
    print('Owner ID: ' + str(inf.st_uid))
    print('Path: ' + str(inf_path))
    print('Created: ' + str(ctime(inf.st_ctime)))

def chmod(args):
    rights = int(args[1], 8)    # Преобразовываем число в 8-ричную систему счисления
    path = args[0]
    os.chmod(path, rights)      # Команда по восьмиричному числу изменяет права файла
    print('chmod completed')

if __name__ == '__main__':
    while True:
        print('Enter commands: ')
        com = input()                   # Заносим команду
        com_list = com.split(' ')   # Разбиваем команду на составляющие
        com_key = com_list[0]       # Заносим ключ в переменную
        if com_key == '--help':         # Если ключ совпадает с --help,
            help()                          # то переходим в функцию help
        elif com_key == 'cp':           # Если ключ совпадает с cp,
            cp(com_list[1:])            # то передаём в функцию cp файл копирования и путь
        elif com_key == 'info':         # Если ключ совпадает с info,
            info(com_list[1:])          # то передаём в функцию info название файла
        elif com_key == 'chmod':        # Если ключ совпадает с chmod
            chmod(com_list[1:])         # то передаём в функцию chmod название файла и код права
        elif com_key == 'quit':
            exit(0)
        else:
            print('Unknown command.')
