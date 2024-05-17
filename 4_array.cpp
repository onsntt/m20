#include <iostream>
#include <fstream>
#include <cstdlib> // в ней rnd

int main(){
int checksum = 0;
int buildings[1000]; 
for (int i = 0; i < 1000; i++)
  {
     buildings[i] = std::rand() % 51; // выдает целое число от нуля до randMax. Это овердохера, поэтому возьмем только остатки от деления на 51 (это будут от 0 до 50)
     checksum += buildings[i];
  }

std::cout << "Checksum = " << checksum << "\n";
std::ofstream file ("buildings.txt");

for (int i = 0; i < 1000; i++)
{
    file << buildings[i] << "\n";
    
}
file.close();

std::ifstream file1 ("buildings.txt");
int in_buildings[1000];
for (int i = 0; i < 1000; i++)
  {
    file1 >> in_buildings[i]; //считали все числа из файла и положили их в новый массив Бля, из текстового файла спокойно читаются и кладутся в массив int'ы!!!!!

  }
  int new_sum = 0;
  for (int i = 0; i < 1000; i++)
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