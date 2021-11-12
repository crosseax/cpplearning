#include "Savings_Account.h"

std::ostream& operator<<(std::ostream& os, const Savings_Account& account) {
    os << "Savings account balance: $" << account.balance << "\nInterest rate: " << account.intRate << "% ";
    return os;
}

Savings_Account::Savings_Account(double balance, double intRate)
    : Account {balance}, intRate {intRate} { // create constructor
}

Savings_Account::Savings_Account () // delegating this to the overloaded constructor
    : Savings_Account(0.0, 0.0) {
}

void Savings_Account::deposit(double amount) { // override deposit methods
    amount = amount + (amount * intRate/100);
    // balance += amount;
    // std::cout << "Savings Account deposit called with " << amount << std::endl; 
    Account::deposit(amount); // delegating to the parent method
}

// the withdraw method is inherited