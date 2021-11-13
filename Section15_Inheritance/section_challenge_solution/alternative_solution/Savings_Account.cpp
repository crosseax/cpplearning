#include "Savings_Account.h"

std::ostream& operator<<(std::ostream& os, const Savings_Account& account) {
    os << "[Savings account: " << account.name << ", Bal: $" << account.balance << ", IR:" << account.intRate << "%]";
    return os;
}

Savings_Account::Savings_Account(std::string name, double balance, double intRate)
    : Account {name, balance}, intRate {intRate} { // create constructor
}

bool Savings_Account::deposit(double amount) { // override deposit methods
    amount += (amount * intRate/100);
    return Account::deposit(amount); // delegating to the parent method
}
// the withdraw method is inherited