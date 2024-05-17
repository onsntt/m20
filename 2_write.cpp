#include <iostream>
#include <fstream>

int main(){
std::ofstream file("2.txt", std::ios::app);
file.setf(std::ios::showpos);
/*
к потоку file применили флаг setf (set formating) и в параметрах указали std::ios::showpos
теперь температура будет отображаться со знаком +
*/

file.setf(std::ios::boolalpha);
/*
применили к потоку еще один флаг - вывод булевых значений буквами

оба флага работают одновременно
*/

file.setf(std::ios::showpoint);
//добавили вывод точки для вещественных чисел

file.precision(3);
//добавили точность вывода чисел - 3
if (!file.is_open())
  {
    std::cout << "Can't open file!\n";
    return 0;
  }
    else
     {
       double temperature = 20; 
       file << temperature << "\n";
       bool tumbler = 1;
       file << tumbler << "\n";
       file.close();
     }
}