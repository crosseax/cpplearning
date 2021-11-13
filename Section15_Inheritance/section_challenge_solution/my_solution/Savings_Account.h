#ifndef _SAVINGS_ACOUNT_H_
#define _SAVINGS_ACOUNT_H_
#include "Account.h"

// withdraw method doesn't specialize,
// so the idea is that we can use our parent class (Account class) withdraw method as is

class Savings_Account: public Account {
    friend std::ostream& operator<<(std::ostream& os, const Savings_Account& rhs);

private:
    static constexpr const char* defName = "Unnamed Savings Account";
    static constexpr double defBalance = 0.0;
    static constexpr double defIntRate = 0.0;

protected:
    double intRate;

public:
    Savings_Account(std::string name = defName, double balance = defBalance, double intRate = defIntRate);
    bool deposit(double amount);
    // withdraw() is inherited
};


#endif // _SAVINGS_ACOUNT_H_
