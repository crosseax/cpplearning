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
    cout << c2 << endl;
    c2.display();

    c2 = c2 + c1;
    c2.display();

    c1 += "++++";
    c1.display();

    Mystring c4 {"abc"};
    c4 = c4 * 5;
    c4.display();

    return 0;
}