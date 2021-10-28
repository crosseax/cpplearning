// method2
// do things in a more organized way
// which is put different things in different files

#include <iostream>
#include "Account.h"

using namespace std;


int main (void)
{
    Account frankAcc;
    frankAcc.set_name("Frank's account");
    frankAcc.set_balance(1000.00);

    if (frankAcc.deposit(200.00)){
        cout << "Deposit OK" << endl;
    } else {
        cout << "Deposit NOT allowed" << endl;
    }

    if (frankAcc.withdraw(500.00)){
        cout << "Withdrawal OK" << endl;
    } else {
        cout << "NOT sufficient funds" << endl;
    }

    if (frankAcc.withdraw(1500.00)){
        cout << "Withdrawal OK" << endl;
    } else {
        cout << "NOT sufficient funds" << endl;
    }

    return 0;
}
