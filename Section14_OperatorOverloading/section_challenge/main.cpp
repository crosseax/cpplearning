#include <iostream>
#include <cstring>
#include "Mystring.h"

using namespace std;

int main (void)
{
    cout << "Let the fun begin!" << endl;
    cout << boolalpha << endl;

    Mystring a {"crossea"};
    Mystring b {"crossea"};

    cout << (a == b) << endl;
    cout << (a != b) << endl;

    a = "frank";
    b = "george";
    cout << strcmp("frank", "george") << endl;
    cout << (a < b) << endl;
    cout << (a > b) << endl;

    Mystring c1 {"LOUD"};
    Mystring c2 = -c1;
    cout << c2 << endl; // loud
    c2.display(); // loud

    c2 = c2 + c1;
    c2.display(); // loudLOUD

    c1 += a;
    c1.display(); // LOUDfrank

    Mystring c4 {"abc"};
    c4 = c4 * 4;
    c4.display(); // abcabcabcabc

    Mystring c5 {"hello"};
    c5 *= 5;
    c5.display(); // hellohellohellohellohello

    Mystring c6 {"comeon"};
    ++c6;
    cout << c6 << endl; // COMEON

    Mystring c7 {"last test"};
    c7++;
    cout << c7 << endl; // LAST TEST

    return 0;
}