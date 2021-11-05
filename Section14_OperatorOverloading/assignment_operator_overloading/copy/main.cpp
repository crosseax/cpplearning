#include <iostream>
#include <vector>
#include "Mystring.h"

using namespace std;


int main (void) 
{
    Mystring a {"Hello"};   // overloaded constructor
    Mystring b;             // no args constructor
    b = a;                  // copy assignment, assignment operator is called
    b = "This is a test";   // b.operator= ("This is a test"), assignment operator is called

    Mystring empty;
    Mystring larry {"Larry"};
    Mystring stooge {larry};
    Mystring stooges;

    empty = stooge;         // assignment operator is called

    empty.display();
    larry.display();
    stooge.display();

    empty = "Hello darkness my old friend"; // assignment operator is called
    empty.display();
    
    vector<Mystring> stoogesVec;
    stoogesVec.push_back("Larry");
    stoogesVec.push_back("Moe");
    stoogesVec.push_back("Curly");

    cout << "===loop 1===" << endl;
    for (const Mystring &s : stoogesVec) {
        s.display();
    }

    cout << "===loop 2===" << endl;
    for (Mystring &s : stoogesVec) {
        s = "Changed";      // assignment operator is called for that many times
    }

    cout << "===loop 3===" << endl;
    for (const Mystring &s : stoogesVec) {
        s.display();
    }

    return 0;
}