#include "Savings_Account.h"

std::ostream& operator<<(std::ostream& os, const Savings_Account& account) {
    os << "[Savings account: " << account.name << ", $" << account.balance << ", " << account.intRate << "%]";
    return os;
}

Savings_Account::Savings_Account(std::string name, double balance, double intRate)
    : Account {name, balance}, intRate {intRate} { // create constructor
}

bool Savings_Account::deposit(double amount) { // override deposit methods
    if (amount >= 0) {
        amount += (amount * intRate/100);
        return Account::deposit(amount); // delegating to the parent method
    } else {
        return false;
    }
}
// the withdraw method is inherited