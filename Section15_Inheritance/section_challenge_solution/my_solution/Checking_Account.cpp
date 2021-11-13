#include "Checking_Account.h"

std::ostream& operator<<(std::ostream& os, const Checking_Account& account) {
    os << "[Checking account: " << account.name << ", $" << account.balance << ", Charge fee:" << account.chargeFee << "]";
    return os;
}

Checking_Account::Checking_Account(std::string name, double balance, double chargeFee) 
    : Account {name, balance}, chargeFee {chargeFee} {
}

bool Checking_Account::withdraw(double amount) {
    amount += chargeFee;
    return Account::withdraw(amount);
}