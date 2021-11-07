#include <iostream>
#include <cstring>
#include <string>
#include <vector>
#include "Mystring.h"

using namespace std;


int main (void)
{
    Mystring larry {"Larry"};
    Mystring larry2 {"Larry2"};
    Mystring moe {"Moe"};

    Mystring stooge = larry;
    larry.display();
    moe.display();

    cout << boolalpha; // now return true/false for true and false
    cout << (larry == moe) << endl;
    cout << (larry == stooge) << endl;
    cout << noboolalpha; // now return 1/0 for true and false

    larry.display();
    Mystring larrylower = -larry; // this is highly scenario-depended, whether the operator makes sense to do such job is leave to subjective decision
    larrylower.display();

    Mystring stooges1 = larry + "Moe";
    Mystring stooges2 = "Moe" + larry; // this is only possible in global operator overload since it has lhs, unlike the member functions
    stooges1.display();
    stooges2.display();
    
    Mystring twoStooges = moe + " " + "Larry";
    twoStooges.display();

    Mystring threeStooges = moe + " " + larry + " " + "Curly";
    threeStooges.display();

    return 0;
}