#include "Trust_Account.h"

void Trust_Account::print(std::ostream& os) const {
    os.precision(2);
    os << std::fixed;
    os << "[Trust account: " << name << ", Bal: $" << balance 
       << ", withdraws: " << withdrawTimes << "]";
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