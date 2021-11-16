#ifndef _TRUST_ACCOUNT_H_
#define _TRUST_ACCOUNT_H_
#include "Savings_Account.h"
#include <iostream>
#include <string>

class Trust_Account: public Savings_Account {
private:
    static constexpr const char* defName = "Unnamed Trust Account";
    static constexpr double defBalance = 0.0;
    static constexpr double defIntRate = 0.0;
    
    static constexpr double bonusEntry = 5000;
    static constexpr double bonus = 50;
    static constexpr double maxWithdrawPercent = 0.2;
    
    static constexpr int limit = 3;

protected:
    int withdrawTimes;

public:
    virtual void print(std::ostream& os) const override;

    Trust_Account(std::string name = defName, double balance = defBalance, double intRate = defIntRate);
    virtual bool deposit(double amount) override;
    virtual bool withdraw(double amount) override;
    virtual ~Trust_Account() = default;
};

#endif // _TRUST_ACCOUNT_H_