#include "Trust_Account.h"

int Trust_Account::limit {3};
int Trust_Account::withdrawTimes {0};

std::ostream& operator<<(std::ostream& os, const Trust_Account& account) {
    os << "[Trust account: " << account.name << ", $" << account.balance << ", " << account.intRate << "%]";
    return os;
}

Trust_Account::Trust_Account(std::string name, double balance, double intRate, double bonus)
    : Savings_Account{name, balance, intRate}, bonus {bonus} { // create constructor
}


bool Trust_Account::deposit(double amount) { // override deposit methods
    if (amount <= balance * 0.2 && withdrawTimes < limit) {
        if (amount >= bonusEntry) {
            amount += bonus;
        }
        return Savings_Account::deposit(amount);
        withdrawTimes++;
    } else {
        return false;
    }
}
// the withdraw method is inherited