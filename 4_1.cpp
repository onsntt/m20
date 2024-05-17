#include <iostream>

#include <fstream>
int main() {

int number;
std::cin >> number;

std::ofstream file("41.bin", std::ios::binary);

/*
write принимает два аргумента - указатель на данные и размер данных
написать  file.write(&number, sizeof(number)) не получится, т.к. долбаный write принимает только указатели на данные типа char
придется переводить
*/
file.write((char*)&number, sizeof(number));
file.close();

/*
если для чтения попытаться использовать тот же идент file - получим ошибку
на чтение придется открывать другую переменную для работы с файлом. Назову ее file1
похоже, что-то должно разрушать или иначе удалять объяаленные переменные
олень про это ничё не сказал

пишу 255 - в файле - FF 00 00 00
256 - 00 01 00 00
значит, читаем байты справа налево
олень молчал

*/

std::ifstream file1("41.bin", std::ios::binary);

file1.read((char*)&number, sizeof(number));

std::cout << number;

}