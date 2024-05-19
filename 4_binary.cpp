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
std::ifstream file1("d:\\1\\dev\\4.bin", std::ios::binary);

int bu;
file1.read((char*)&bu, sizeof(int));

//char rrr[5];
//int r;
//file1.read(, sizeof(int));
//rrr[4] = 0;
std::cout << bu;

}