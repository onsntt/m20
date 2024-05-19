#include <iostream>

bool incass(int kucha[])
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
int kucha[1000]={0};
if (incass(kucha)== true)
for (int i = 0; i < 1000; i++)
  {
    std::cout << kucha[i] << "\n";
  }






}