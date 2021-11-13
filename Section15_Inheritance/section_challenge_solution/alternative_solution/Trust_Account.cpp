#include "Trust_Account.h"



std::ostream& operator<<(std::ostream& os, const Trust_Account& account) {
    os << "[Trust account: " << account.name << ", Bal: $" << account.balance 
       << ", withdraws: " << account.withdrawTimes << "]";
    return os;
}

Trust_Account::Trust_Account(std::string name, double balance, double intRate)
    : Savings_Account{name, balance, intRate}, withdrawTimes {0} { // create constructor
}


bool Trust_Account::deposit(double amount) { // override deposit methods
    if (amount >= bonusEntry) {
        amount += bonus;
    }
    return Savings_Account::deposit(amount);
}

bool Trust_Account::withdraw(double amount) {
    if (amount > balance * maxWithdrawPercent || (withdrawTimes >= limit)) {
        return false;
    } else {
        withdrawTimes++;
        return Savings_Account::withdraw(amount);
    }
}