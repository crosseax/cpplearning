#include <iostream>
#include "Account.h"
#include "Savings_Account.h"

using namespace std;

int main (void) 
{
    cout << "\n======Account======" << endl;
    Account a1 {1000.0};
    cout << a1 << endl;

    a1.deposit(500);
    cout << a1 << endl;

    a1.withdraw(1000.0);
    cout << a1 << endl;

    a1.withdraw(5000);
    cout << a1 << endl;

    cout << "\n======Savings Account======" << endl;
    Savings_Account s1 {1000, 5.0};
    cout << s1 << endl;

    s1.deposit(1000);
    cout << s1 << endl;

    s1.withdraw(800);
    cout << s1 << endl;

    s1.withdraw(7500);
    cout << s1 << endl;

    return 0;
}