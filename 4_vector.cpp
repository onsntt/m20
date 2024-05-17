#include <iostream>
#include <fstream>
#include <vector>
#include <cstdlib> // в ней rnd

int main()
{
    int checksum = 0;
    std::vector<int> buildings;
    int count = std::rand() % 901 + 100; // количество домов будет случайным числом от 100 до 1000
    for (int i = 0; i < count; i++)
    {
         
        buildings.push_back(std::rand() % 51); // выдает целое число от нуля до randMax. Это овердохера, поэтому возьмем только остатки от деления на 51 (это будут от 0 до 50)
        checksum += buildings[i];
    }

    std::cout << "Checksum = " << checksum << "\n";
    std::ofstream file("buildings.txt");

    // первой строкой запишем в файл количество домов
    file << count << "\n";

    for (int i = 0; i < 1000; i++)
    {
        file << buildings[i] << "\n";
    }

     file << "Last text string, not number\n";  //при считывании чисел из файла эту строку нельзя брать в подсчет, это не число жителей в доме

    file.close();

    std::ifstream file1("buildings.txt");
    std::vector <int> in_buildings;
    int in_count; // объявили переменную, в которую поместим чексум из первой строки файла
    file1 >> in_count; //считали. Считывающий курсор перешел на следующую строку
    for (int i = 0; i < in_count; i++)
    {
        int in_people; // заведем переменную, в которую из файла будем читать кол-во людей в доме. Затем считанное значение припушбэчим к вектору in_buildings

        file1 >> in_people; // считали очередное число из файла в переменную. Бля, из текстового файла спокойно читаются и кладутся в массив int'ы!!!!!
        in_buildings.push_back(in_people);
    }
    
     std::string lastString;
     file1 >> lastString;

    int new_sum = 0;
    for (int i = 0; i < count; i++)
    {
        new_sum += in_buildings[i];
    }

    if (new_sum == checksum)
    {
        std::cout << "Population is " << new_sum << "\n";
    }
    else
    {
        std::cout << "Checksum error\n";
    }
}