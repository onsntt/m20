#include <iostream>
#include <vector>
#include <fstream>
bool addMoney(std::vector<int>& kucha)
{
    int added = 0;
 for (int i = 0; i < 1000; i++)
 {
    if (kucha[i] == 0)
      {
        switch(rand() % 6)
         {
            case 0:
            kucha[i] = 100;
            break;
            case 1:
            kucha[i] = 200;
            break;
            case 2:
            kucha[i] = 500;
            break;
            case 3:
            kucha[i] = 1000;
            break;
            case 4:
            kucha[i] = 2000;
            break;
            case 5:
            kucha[i] = 5000;
            break;
         }
         added += kucha[i];
      }

 }
 if (added > 0)
 {
  std::cout << added << " added" << "\n";
  return true;
 } 
 else 
 {
    std::cout << added << "added\n";
    return false;
 }

}



int main(){
std::vector<int> kucha(1000, 0);
if (addMoney(kucha)== true)
  {
     for (int i = 0; i < 1000; i++)
        {
           std::cout << kucha[i] << " ";
        }

   std::ofstream vecFile("vecfile.bin", std::ios::binary); 
   for (int i= 0; i <1000; i++)
     {
       vecFile.write((char*)&kucha[i], sizeof(int));

     }

   

  }







}