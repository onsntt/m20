#include <iostream>
#include <vector>
#include <fstream>
//функция заполнения нулевых элементов случайными номиналами
bool addMoney(std::vector<int>& kucha, int &currentSum)
{
    int added = 0;
    currentSum = 0;
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
      else
         {
           currentSum += kucha[i];
         }

 }
 if (added > 0)
 {
    
  currentSum += added;  
  std::cout << added << " added" << "\n";
  return true;
 } 
 else 
 {
    std::cout << added << "added\n";
    return false;
 }

}

//функция сортирует вектор, из которого будут делаться наборы на выдачу. Вызывается при пополнениях 
 void sort(std::vector<int> &vec)
 {
  for (int i = vec.size() - 1; i >= 0; i--)
        {
            int minInd = 0;

            for (int j = 0; j <=i; j++)
                if (vec[j] < vec[minInd])
                {
                    minInd = j;
                }

                int temp = vec[i];
                vec[i] = vec[minInd];
                vec[minInd] = temp;

                
        }

 }
//функция построена на жадном алгоритме 
 bool iCan(std::vector<int> &money, std::vector<int> &result, int request)

{
  int tail;
  tail = request;
  
  for (int i = 0; i < 1000; i++)
  {
    if (money[i] <= tail && money[i] != 0)
      {
        result.push_back(money[i]);
        tail -= money[i];
        money[i] = 0;
      }
         if (tail == 0)
           {
            return true;            
           }
  } 
  return false;
}


int main(){

std::vector<int> kucha(1000, 0);
std::vector<int> sandbox(1000, 0);
bool more = true;
int currentSum = 0;

std::ifstream readFile("state.bin", std::ios::binary); 
if(!readFile.is_open())
  {
    std::cout << "No cash!\n";
    std::ofstream writeFile("state.bin", std::ios::binary);
    for (int i = 0; i < 1000; i++)
      {
        writeFile.write((char*)&kucha[i], sizeof(int));
      }
    
    writeFile.close(); 
    std::cout << "New datafile added!\n";
  }
  else
  {
    int bu;
    for (int i = 0; i < 1000; i++)
      {
         readFile.read((char*)&bu, sizeof(int)); 
         if (bu > 0)
           {
             currentSum += bu;
           }
         kucha[i] = bu;
      }
      readFile.close();
     std::cout << "Device status has been restored. " << currentSum << " available.\n";
  }

while (more == true)

 {
   char action = ' ';

 while ((action != '+') && (action != '-') && (action != '0')  )
 {
    std::cout << "Enter '+' for adding or '-' for getting cash. '0' - exit program\n";
    std::cin >> action;
 }
 if (action == '+')
   {
 
           
      
      if (!addMoney(kucha, currentSum))
        {
           std::cout << "Adding not performed!\n" << currentSum << " is availabel.\n" ;
        }
         else
        {
          sort(kucha);  
          std::ofstream writeFile("state.bin", std::ios::binary);
          for (int i = 0; i < 1000; i++)
            {
              writeFile.write((char*)&kucha[i], sizeof(int));
            }
          writeFile.close();
          std::cout  << currentSum << " available\n";

        }     
   }
 else if (action == '0')
   {
    std::cout << "Exit" << "\n";
    more = false;
    return 0;
   }
 else if (action == '-')
   {
std::cout << "Enter wanted sum\n";

int wantedSum = 0;    
std::cin >> wantedSum;

std::vector<int> set(0);
sandbox = kucha;
if (wantedSum <= currentSum && wantedSum >= 100 && iCan(sandbox, set, wantedSum))
  { 
    currentSum -= wantedSum;
    kucha = sandbox;
    std::ofstream writeFile("state.bin", std::ios::binary);
          for (int i = 0; i < 1000; i++)
            {
              writeFile.write((char*)&kucha[i], sizeof(int));
            }
          writeFile.close();

    
    for (int i = 0; i < set.size(); i++)
            {
              std::cout << set[i] << " ";
            }
             std::cout << "\n";
             std::cout << "Here's your money.\n" << currentSum << " availabel\n";
  }
    else
        {
            std::cout << "NE MOGU! NE DAM! NE PROSI!\n";
        }
   // for (int i = 0; i < 1000; i++)
      //  {
          // std::cout << kucha[i] << " ";
        //  }

   }  

 } 
 


}