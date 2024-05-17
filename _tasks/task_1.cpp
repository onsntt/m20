#include <iostream>
#include <fstream>
#include <string>
#include <cstring>
#include <vector>
#include <cmath>

bool isName(std::string str)
{
    //char xx;
    if ((str[0]) < (char)65 || str[0] > (char)90) 
      {
        std::cout << "First letter must be big one!\n";
        return false;
      }

    for (int i = 0; i < str.length(); i++)
    {
        bool big = true;
        bool small = true;
        bool space = true;
        bool minus = true;
        //xx = str[i];
        if ((str[i] < (char)65 || str[i] > (char)90))    big = false;

        if ((str[i] < (char)97 || str[i] > (char)122))    small = false;

        if (str[i] != (char)32) space = false;

        if (str[i] != (char)45) minus = false;

        if (big == false && small == false && space == false && minus == false) return false; 
      }

return true;
}

bool correctSum(std::string str)
{
    int dotNumber = 0;
    for (int i = 0; i < str.length(); i++)
    {
        bool digit = true;
        bool dot = true;
        
         if ((str[i] < (char)48 || str[i] > (char)57)) digit = false;
         if (str[i] != (char)46) dot = false;
         if (str[i] == (char)46) dotNumber++;
         if((digit == false && dot == false) || dotNumber >1) return false;
    }

    return true;

}   

bool dateOk(std::string str)
{
    if (str.length() != 10 )
    {
        std::cout << "Incorrect date format!\n";
        return false;
    } 
    int dotNumber = 0;
    for (int i = 0; i < str.length(); i++)
    {
        bool digit = true;
        bool dot = true;

        if ((str[i] < (char)48 || str[i] > (char)57)) digit = false;
        if (str[i] != (char)46) dot = false;
        if (str[i] == (char)46) dotNumber++;
        if ((digit == false && dot == false))
        {
            std::cout << "Incorrect symbol in date!\n";
            return false;
        } 
        if (str[2] != (char)46 && str[5] != (char)46)
        {
            std::cout << "Incorrect date format! Where are the dots?\n";
            return false;
        } 

    }

    int day = std::stoi(str.substr(0, 2));
    if (day <= 0)
    {
        std::cout << "There no day less than 1 in mounth!\n";
        return false;
    } 
    int month = std::stoi(str.substr(3, 2));
    if (month < 1 || month > 12)
    {
        std::cout << "There are no month less than 1 in a year!\n";
        return false;
    } 
    int year = std::stoi(str.substr(6, 4));
    int months[12] = {31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    if (year % 4 != 0 || (year % 100 == 0 && year % 400 != 0)) months[1] = 28;
    if (day > months[month-1]) 
    {
        std::cout << "There are not so many days in this month!\n";
        return false;
    }    
    return true;
}



int main() {

while (true)
{
std::cout << "Enter name (A-Z, a-z, -, space): ";
std::string name;
std::getline(std::cin, name);
if (!isName(name))
{
    std::cout << "Incorrect input. Program will be closed!\n";
    return 0;
}
//std::cout << name << "\n";
std::cout << "Enter surname (A-Z, a-z, -, space): ";
std::string surname;
std::getline(std::cin, surname);
if (!isName(surname))
{
    std::cout << "Incorrect input. Program will be closed!\n";
    return 0;
}
//std::cout << surname << "\n";
std::cout << "Enter sum: ";
std::string sum;
std::getline(std::cin, sum);
if (!correctSum(sum))
{
    std::cout << "Incorrect input. Program will be closed!\n";
    return 0;
}
double realSum = stod(sum);
realSum = round(realSum * 100) / 100;

//std::cout << realSum << "\n";
std::cout << "Enter date: ";
std::string date;
std::getline(std::cin, date); 
//std::cout << date << "\n";

if (!dateOk(date))
{
    std::cout << "Date is not correct. Program will be closed!\n";
    return 0;
}
/*
int day = std::stoi(date.substr(0, 2));
std::cout << day << "\n";
int month = std::stoi(date.substr(3, 2));
std::cout << month << "\n";
int year = std::stoi(date.substr(6, 4));
std::cout << year << "\n";
*/
std::ofstream file ("vatakakayato.txt", std::ios::app);
file << name << " " << surname << " " << date << " " << realSum << " RUB\n";
file.close();
}

}