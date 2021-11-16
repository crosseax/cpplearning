#include "Savings_Account.h"

std::ostream& operator<<(std::ostream& os, const Savings_Account& account) {
    os << "[Savings account: " << account.name << ", Bal: $" << account.balance << ", IR:" << account.intRate << "%]";
    return os;
}

void Savings_Account::print(std::ostream& os) const {
    
}

Savings_Account::Savings_Account(std::string name, double balance, double intRate)
    : Account {name, balance}, intRate {intRate} { 
}

bool Savings_Account::deposit(double amount) { 
    amount += (amount * intRate/100);
    return Account::deposit(amount); 
}

bool Savings_Account::withdraw(double amount) {
    return Account::withdraw(amount);
}

