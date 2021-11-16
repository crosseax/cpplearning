#ifndef _SAVINGS_ACOUNT_H_
#define _SAVINGS_ACOUNT_H_
#include "Account.h"

class Savings_Account: public Account {
private:
    static constexpr const char* defName = "Unnamed Savings Account";
    static constexpr double defBalance = 0.0;
    static constexpr double defIntRate = 0.0;

protected:
    double intRate;

public:
    virtual void print(std::ostream& os) const override;

    Savings_Account(std::string name = defName, double balance = defBalance, double intRate = defIntRate);
    virtual bool deposit(double amount) override;
    virtual bool withdraw(double amount) override;
    virtual ~Savings_Account() = default;
};


#endif // _SAVINGS_ACOUNT_H_
