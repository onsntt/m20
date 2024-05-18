#include<iostream>
#include<fstream>
#include<ctime>
#include <string>

void draw(int width, int height, char black = '1', char white = '0')
{
  std::ofstream file("picture.txt", std::ios::app);
for (int i = 0; i < height; i++)
  {
    for (int j = 0; j < width; j++)
      {
        int n = std::rand() % 2;
        if (n == 0) 
          {
            file << white;
          } 
          else
          {
            file << black;
          }
      }
      file << "\n";
  }
  file << "\n";
  file.close();
}

int main(){

std::srand(std::time(nullptr));
int width = 0;
while (width < 10 || width > 140)
{
  std::cout << "Enter width: (10 - 140)";
  std::cin >> width;
}

int height = 0;
while (height < 10 || height > 140)
{
  std::cout << "Enter height: (10 - 140)";
  std::cin >> height;
}
std::cout << width << " " << height <<"\n";

draw(width, height);

}