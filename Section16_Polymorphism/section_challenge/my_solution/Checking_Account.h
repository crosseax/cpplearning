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
    virtual void print(std::ostream& os) const override;

    Checking_Account(std::string name = defName, double balance = defBalance);
    virtual bool withdraw(double amount) override;
    virtual bool deposit(double amount) override;
    virtual ~Checking_Account() = default;
};

#endif // _CHECKING_ACCOUNT_H_