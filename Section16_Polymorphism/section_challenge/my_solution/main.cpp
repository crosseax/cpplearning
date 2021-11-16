#include <iostream>
#include "Account.h"
#include "Savings_Account.h"
#include "Account_Util.h"
#include "Checking_Account.h"
#include "Trust_Account.h"
#include "I_Printable.h"

using namespace std;

int main (void) 
{
    Checking_Account c;
    cout << c << endl;

    Savings_Account s {"Frank", 5000, 2.6};
    cout << s << endl;
    s.deposit(10000);
    cout << s << endl;
    s.withdraw(10000);
    cout << s << endl;


    Account* ptr = new Trust_Account("Leo", 10000, 3.4);
    cout << *ptr << endl;
    

    cout << endl;

    return 0;
}