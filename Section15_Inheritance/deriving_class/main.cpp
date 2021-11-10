#include <iostream>
#include "Account.h"
#include "Savings_Account.h"

using namespace std;

int main (void) 
{
    cout << "\n======Account=====" << endl;
    Account acc {};
    acc.deposit(2000.0);
    acc.withdraw(500.0);

    cout << endl;

    Account* pAcc {nullptr};
    pAcc = new Account();
    pAcc->deposit(1000.0);
    pAcc->withdraw(500.0);
    delete pAcc;

    cout << "\n======Savings Account=====" << endl;

    Savings_Account savAcc {};
    savAcc.deposit(4000.0);
    savAcc.withdraw(750.0);

    cout << endl;

    Savings_Account* pSavAcc {nullptr};
    pSavAcc->deposit(1000.0);
    pSavAcc->withdraw(500.0);
    delete pSavAcc;

    cout << endl;

    return 0;
}