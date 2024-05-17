#include <iostream>
#include <fstream>

int main(){
std::ofstream file("1.txt", std::ios::app);
/*
открываем файл одной строкой, передавая в виде параметров путь к файлу
и флаг std::ios::app (от app end - прилепить к концу)
Получаем такой режим записи в файл, когда следующая запись в него будет
добавлена сразу после последнего символа предыдущей записи 
*/
if (!file.is_open())
  {
    std::cout << "Can't open file!\n";
    return 0;
  }
    else
     {
       file << "Around the world\n";
       file << "Forever young\n";
       
        file.close();
     }
}