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
    Checking_Account frank {"Frank", 5000};

    Account* trust = new Trust_Account("Leo", 10000, 3.4);
    cout << *trust << endl;
    
    Account* p1 = new Checking_Account("Larry", 10000);
    Account* p2 = new Savings_Account("Moe", 10000);
    Account* p3 = new Trust_Account("Curly");
    Account* p4 = new Trust_Account("Garry", 100000);

    std::vector<Account*> accounts {p1, p2, p3, p4};

    display(accounts);
    deposit(accounts, 1000);
    withdraw(accounts, 2000);
    withdraw(accounts, 2000);
    withdraw(accounts, 2000);
    withdraw(accounts, 2000);

    display(accounts);

    cout << endl;

    delete p1;
    delete p2; 
    delete p3;

    

    return 0;
}