#include <iostream>
#include <vector>

bool iCan(std::vector<int> &money, std::vector<int> &result, int request)

{
  int ostatok;
  ostatok = request;
  
  for (int i = 0; i < 16; i++)
  {
    if (money[i] <= ostatok && money[i] != 0)
      {
        result.push_back(money[i]);
        ostatok -= money[i];
        money[i] = 0;
      }
         if (ostatok == 0)
           {
            return true;            
           }
  } 
  return false;
}


int main() {

int zapros;    

std::cin >> zapros;

std::vector<int> storage = {5000, 5000, 2000, 2000, 1000, 1000, 500, 500, 500, 200, 200, 200, 0, 0, 0, 0};
std::vector<int> test = storage;
std::vector<int> vec;
if (iCan(test, vec, zapros))
   
        {
            storage = test;
            for (int i = 0; i < vec.size(); i++)
            {
              std::cout << vec[i] << " ";
            }
             std::cout << "\n";
        }
        else
        {
            std::cout << "NE MOGU\n";
        }
for (int i = 0; i < 16; i++)
  {
    std::cout << storage[i] << " ";
  }

}