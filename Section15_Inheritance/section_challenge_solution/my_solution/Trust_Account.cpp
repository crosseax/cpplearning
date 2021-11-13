#include "Trust_Account.h"

int Trust_Account::limit {3};


std::ostream& operator<<(std::ostream& os, const Trust_Account& account) {
    os << "[Trust account: " << account.name << ", Bal: $" << account.balance << ", IR: " << account.intRate << "%]";
    return os;
}

Trust_Account::Trust_Account(std::string name, double balance, double intRate, double bonus)
    : Savings_Account{name, balance, intRate}, bonus {bonus} { // create constructor
    int withdrawTimes {0};
}


bool Trust_Account::deposit(double amount) { // override deposit methods
        if (amount >= bonusEntry) {
            amount += bonus;
        }
        return Savings_Account::deposit(amount);
    
}

bool Trust_Account::withdraw(double amount) {
    if (amount <= balance * 0.2 && withdrawTimes < limit) {
        withdrawTimes++;
        return Savings_Account::deposit(amount);
    } else {
        return false;
    }
}