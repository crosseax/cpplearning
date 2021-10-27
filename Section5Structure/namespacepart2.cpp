#include <iostream>

// using part of that namespace, to reduce future error possibilities
// using only what you need
using std::cout;
using std::cin;
using std::endl;


int main()
{
    int favNumber;

    cout << "Enter your favorite number between 1 and 100: ";

    cin >> favNumber;

    cout << "Amazing! That's my favorite number too!" << endl;

    cout << "No really!! " << favNumber << " is my favorite number!" << endl;

    return 0;
}