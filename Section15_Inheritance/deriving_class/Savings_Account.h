#ifndef _SAVINGS_ACOUNT_H_
#define _SAVINGS_ACOUNT_H_
#include "Account.h"

class Savings_Account: public Account {
public:
    Savings_Account();
    ~Savings_Account();

    double intRate;

    void deposit (double amount);
    void withdraw (double amount);
};


#endif // _SAVINGS_ACOUNT_H_
