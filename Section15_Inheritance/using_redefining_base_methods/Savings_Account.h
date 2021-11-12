#ifndef _SAVINGS_ACOUNT_H_
#define _SAVINGS_ACOUNT_H_
#include "Account.h"

// Savings Acount class
// Deposit method increments amount to be deposited by amount * int_rate percentage!!
// So a 1000 deposit at 5% interest rate will deposit 1000 + 50

// withdraw method doesn't specialize,
// so the idea is that we can use our parent class (Account class) withdraw method as is

class Savings_Account: public Account {
    friend std::ostream& operator<<(std::ostream& os, const Savings_Account& rhs);

protected:
    double intRate;

public:
    Savings_Account();
    Savings_Account(double balance, double intRate);
    
    void deposit(double amount);
    // withdraw() is inherited
};


#endif // _SAVINGS_ACOUNT_H_
