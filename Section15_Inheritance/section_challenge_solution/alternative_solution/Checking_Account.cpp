#include "Checking_Account.h"

std::ostream& operator<<(std::ostream& os, const Checking_Account& account) {
    os << "[Checking account: " << account.name << ", Bal: $" << account.balance << "]";
    return os;
}

Checking_Account::Checking_Account(std::string name, double balance) 
    : Account {name, balance} {
}

bool Checking_Account::withdraw(double amount) {
    amount += chargeFee;
    return Account::withdraw(amount);
}