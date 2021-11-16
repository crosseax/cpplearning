#include "Trust_Account.h"



std::ostream& operator<<(std::ostream& os, const Trust_Account& account) {
    os << "[Trust account: " << account.name << ", Bal: $" << account.balance 
       << ", withdraws: " << account.withdrawTimes << "]";
    return os;
}

void Trust_Account::print(std::ostream& os) const {
    
}



Trust_Account::Trust_Account(std::string name, double balance, double intRate)
    : Savings_Account{name, balance, intRate}, withdrawTimes {0} { 
}


bool Trust_Account::deposit(double amount) { 
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