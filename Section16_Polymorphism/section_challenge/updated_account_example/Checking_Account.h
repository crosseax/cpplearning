#ifndef _CHECKING_ACCOUNT_H_
#define _CHECKING_ACCOUNT_H_
#include "Account.h"
#include <iostream>
#include <string>

class Checking_Account: public Account {
    friend std::ostream& operator<<(std::ostream& os, const Checking_Account& account);

private:
    static constexpr const char* defName = "Unnamed Checking Account";
    static constexpr double defBalance = 0.0;
    
    static constexpr double chargeFee = 1.5;

public:
    Checking_Account(std::string name = defName, double balance = defBalance);
    bool withdraw(double amount);
};

#endif // _CHECKING_ACCOUNT_H_