#include <iostream>
#include <vector>

int main() {
int ostatok;
int zapros;    

std::cin >> zapros;
ostatok = zapros;
int arr[]= {5000, 5000, 2000, 2000, 1000, 1000, 500, 500, 500, 200, 200, 200, 0, 0, 0, 0};
std::vector<int> vec;

for (int i = 0; i < 16; i++)
  {
    if (arr[i] <= ostatok && arr[i] != 0)
      {
        vec.push_back(arr[i]);
        ostatok -= arr[i];
        arr[i] = 0;

      }

      if (ostatok == 0) break;
  }
if (ostatok == 0)
        {
            for (int i = 0; i < vec.size(); i++)
             std::cout << vec[i] << " ";
        }
        else
        {
            std::cout << "NE MOGU\n";
        }


}