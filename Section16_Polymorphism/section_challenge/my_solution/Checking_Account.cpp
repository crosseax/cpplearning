#include "Checking_Account.h"

void Checking_Account::print(std::ostream& os) const {
    os.precision(2);
    os << std::fixed;
    os << "[Checking account: " << name << ", Bal: $" << balance << "]";
}

Checking_Account::Checking_Account(std::string name, double balance) 
    : Account {name, balance} {
}

bool Checking_Account::withdraw(double amount) {
    amount += chargeFee;
    return Account::withdraw(amount);
}

bool Checking_Account::deposit(double amount) {
    return Account::deposit(amount);
}