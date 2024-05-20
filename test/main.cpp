#include<iostream>
#include <fstream>
#include <vector>

//функция добавляет в элементы массива, равные нулю, случайные значения и возвращает true, если добавила больше нуля
bool add(int kucha[], int &currentSum)
{
  currentSum = 0;  
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
                 std::cout << added << " added\n";
                 return false;
              }

}
//функция перепроверяет сумму доступных средств, сравнивая значения из памяти и из файла
void recheck (int &currentSum )
 {
    int checksum = 0;
    std::ifstream readFile1("state.bin",  std::ios::binary); 
    if(readFile1.is_open())
      {
        int buf = 0;
        for (int i = 0; i < 1000; i++)
           {
             readFile1.read((char*)&buf, sizeof(int)); 
               if (buf > 0)
                 {
                   checksum += buf;
           
                 }
           }
      readFile1.close();
      }
      
      else std::cout << "Can not recheck!\n";
      if (checksum == currentSum) 
        {
          std::cout << "Data integrity checked.\n";
        }
       else
         {
           std::cout << "*   *   *\n" << "Somebody stole money from datafile!\n" << currentSum << " in RAM, but only " << checksum << " in datafile.\n" << "* * *   D E R Z H I     V O R A !   * * *\n";
            
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

 bool iCan(std::vector<int> &money, std::vector<int> &result, int request)

{
  int ostatok;
  ostatok = request;
  
  for (int i = 0; i < 1000; i++)
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
int nal[1000] = {0};    
std::vector<int> buffer(1000);
bool more = true;

int currentSum = 0;
std::ifstream readFile("state.bin", std::ios::binary); 
if(!readFile.is_open())
  {
    std::cout << "No cash!\n";
    std::ofstream writeFile("state.bin", std::ios::binary);
    writeFile.write((char*)&nal, sizeof(nal));
    writeFile.close(); 
    std::cout << "New datafile added!\n";
  }
  else
  {
    
     int bu;
    for (int i = 0; i < 1000; i++)
      {
        
       readFile.read((char*)&bu, sizeof(int)); 
       //std::cout << bu << "\n";
       if (bu > 0)
         {
           currentSum += bu;
           
         }
         nal[i] = bu;
       


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
 
      //recheck(currentSum);      
      
      if (!add(nal, currentSum))
        {
           std::cout << "Adding not performed!\n" << currentSum << " is availabel.\n" ;
        }
         else
        {
          std::ofstream writeFile("state.bin", std::ios::binary);
          writeFile.write((char*)&nal, sizeof(nal));
          writeFile.close();
          std::cout  << currentSum << " available\n";
          for(int i = 0; i < 1000; i++)
          {
            buffer[i] = nal[i];
          }
          sort(buffer);
          for (int z = 0; z < 1000; z++) std::cout << buffer[z];
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
std::cout << "Yabuchie roga!\n";
for(int i = 0; i < 1000; i++)
          {
            buffer[i] = nal[i];
          }
          sort(buffer);
int zapros;    
std::vector<int> vec;

std::cin >> zapros;
if (iCan(buffer, vec, zapros))
   
        {
            for(int i = 0; i < 1000; i++)
          {
             nal[i] = buffer[i] ;
          }
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
for (int i = 0; i < 1000; i++)
  {
    std::cout << buffer[i] << " ";
  }

   }  

 } 
 

}