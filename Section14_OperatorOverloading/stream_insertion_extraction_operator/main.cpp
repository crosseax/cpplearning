#include <iostream>
#include "Mystring.h"

using namespace std;


int main (void)
{
    Mystring larry {"Larry"};
    Mystring moe {"Moe"};
    Mystring curly;

    cout << "Enter the third stooge's first name: ";
    cin >> curly;

    cout << "The three stooges are " << larry << ", " << moe << ", " << curly << endl;
    
    cout << endl;
    
    // cout << "Enter the three stooges names separated by a space: ";
    // cin >> larry >> moe >> curly;

    // cout << "The three stooges are " << larry << ", " << moe << ", " << curly << endl;

    return 0;
}