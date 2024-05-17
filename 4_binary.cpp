#include <iostream>
#include <fstream>

int main(){
std::ofstream file("d:\\1\\dev\\4.bin", std::ios::binary);


if (!file.is_open())
  {
    std::cout << "Can't open file!\n";
    return 0;
  }
    else
     {
       int number;
       std::cin >> number;
       file.write((char*)&number, sizeof(number));
       file.close(); 
     }
}