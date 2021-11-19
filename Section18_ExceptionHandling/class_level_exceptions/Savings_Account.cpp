#include "Savings_Account.h"

void Savings_Account::print(std::ostream& os) const {
    os.precision(2);
    os << std::fixed;
    os << "[Savings account: " << name << ", Bal: $" << balance << ", IR:" << intRate << "%]";
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

