#include <iostream>
#include "Account.h"
#include "Savings_Account.h"
#include "Account_Util.h"
#include "Checking_Account.h"
#include "Trust_Account.h"

using namespace std;

int main (void) 
{
    cout.precision(2);
    cout << fixed;

    // // Accounts
    // vector<Account> accounts;
    // accounts.push_back(Account{});
    // accounts.push_back(Account{"Larry"});
    // accounts.push_back(Account{"Moe", 2000});
    // accounts.push_back(Account{"Curly", 5000});

    // display(accounts);
    // deposit(accounts, 1000);
    // withdraw(accounts, 2000);

    // // Savings

    // vector<Savings_Account> savAccounts;
    // savAccounts.push_back(Savings_Account{});
    // savAccounts.push_back(Savings_Account{"Garry"});
    // savAccounts.push_back(Savings_Account{"Tiger", 2000});
    // savAccounts.push_back(Savings_Account{"KC", 15000, 5});

    // display(savAccounts);
    // deposit(savAccounts, 1000);
    // withdraw(savAccounts, 2000);

    // vector<Checking_Account> cheAccounts;
    // cheAccounts.push_back(Checking_Account{});
    // cheAccounts.push_back(Checking_Account{"Garry"});
    // cheAccounts.push_back(Checking_Account{"Tiger", 2000});
    // cheAccounts.push_back(Checking_Account{"KC", 15000});

    // display(cheAccounts);
    // deposit(cheAccounts, 1000);
    // withdraw(cheAccounts, 2000);

    vector<Trust_Account> truAccounts;
    truAccounts.push_back(Trust_Account{});
    truAccounts.push_back(Trust_Account{"Garry", 2000});
    truAccounts.push_back(Trust_Account{"Tiger", 3000});
    truAccounts.push_back(Trust_Account{"KC", 15000});

    display(truAccounts);
    deposit(truAccounts, 1000);
    withdraw(truAccounts, 499);
    withdraw(truAccounts, 499);
    withdraw(truAccounts, 499);
    withdraw(truAccounts, 499);
    withdraw(truAccounts, 499);

    cout << endl;

    return 0;
}