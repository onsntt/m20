#include <iostream>
#include <fstream>

int main() {
std::cout << "In this river you can catch sunfish, shad, carp, bass, bullhead, walleye, catfish and, of course, deerfish!\n";    
std::cout << "What kind of fish you want to catch?\n";
std::string wantedFish;
std::cin >> wantedFish;
std::ifstream in;
in.open("river.txt") ;
if (in.is_open())
{    
std::string anyFish;
int count = 0;
std::ofstream out("basket.txt", std::ios::app);
out << "Let's begin fishing!\n";
while (!in.eof())
{
    in >> anyFish;
    if (anyFish == wantedFish) 
    {
        count++;
        
        out << wantedFish << "\n";
        

    }    

}
out << "You caught " << count << " " << wantedFish << "s this time.\n"<< "\n";

in.close();
out.close();
std::cout << "You caught " << count << " " << wantedFish << "s this time.\n";
}
}