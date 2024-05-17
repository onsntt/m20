#include <iostream>
#include <fstream>

int main(){
std::ofstream file("3.txt");
file.setf(std::ios::showpos);

file.setf(std::ios::showpoint);
file.setf(std::ios::fixed);
file.precision(1);

if (!file.is_open())
  {
    std::cout << "Can't open file!\n";
    return 0;
  }
    else
     {
       double temps[] = {12.8, 2.2, 0, -1.2, -3.8};
       std::string conds[] = {"sunny", "cloudy", "windy", "snowy", "stormy"};

       for (int i = 0; i < 5; i++)
         {
            file.width(5);
            file << temps[i];
            file.width(10);
            file << conds[i] << "\n";
         }
         file.close();
     }
}