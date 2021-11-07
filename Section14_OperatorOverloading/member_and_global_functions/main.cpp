#include <iostream>
#include <cstring>
#include <string>
#include <vector>
#include "Mystring.h"

using namespace std;


int main (void)
{
    Mystring larry {"Larry"};
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

    Mystring stooges = larry + "Moe";
    Mystring twoStooges = moe + " " + "Larry";
    twoStooges.display();

    Mystring threeStooges = moe + " " + larry + " " + "Curly";
    threeStooges.display();

    return 0;
}