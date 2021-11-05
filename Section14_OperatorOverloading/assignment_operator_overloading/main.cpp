#include <iostream>
#include <vector>
#include "Mystring.h"

using namespace std;


int main (void) 
{
    Mystring a {"Hello"};       // overloaded constructor
    Mystring b;                 // no args constructor
    b = a;                      // copy assignment, assignment operator is called
    b = "This is a test";       // b.operator= ("This is a test"), assignment operator is called

    Mystring c {"Nihao"};       // overloaded constructor
    c = Mystring{"Hola"};       // overloaded constructor then move assignment
    c = "Bonjour amigo";        // overloaded constructor then move assignment

    Mystring empty;             // no args constructor
    Mystring larry {"Larry"};   // overloaded constructor
    Mystring stooge {larry};    // copy constructor
    Mystring stooges;           // no args constructor

    empty = stooge;             // copy assignment operator
                                // stooge is an L-value
    empty = "Funny";            // move assignment
                                // "Funny" is an R-values


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
        s = c;      // copy assignment operator is called for that many times 
                    // because c is L-value
    }

    cout << "===loop 3===" << endl;
    for (const Mystring &s : stoogesVec) {
        s.display();
    }

    cout << "===loop 4===" << endl;
    for (Mystring &s : stoogesVec) {
        s = "Changed";      // copy assignment operator is called for that many times
                            // because "change" is R-value
    }

    cout << "===loop 5===" << endl;
    for (const Mystring &s : stoogesVec) {
        s.display();
    }

    cout << "============" << endl;

    return 0;
}