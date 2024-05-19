#include<iostream>
#include <fstream>


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

int main() {
int nal[1000] = {0};    
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
 
      recheck(currentSum);      
      
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

   }  

 } 
 

}