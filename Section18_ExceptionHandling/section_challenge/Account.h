#ifndef _ACCOUNT_H_
#define _ACCOUNT_H_
#include "I_Printable.h"
#include "IllegalBalanceException.h"
#include <iostream>
#include <string>

class Account: public I_Printable {
private:
    static constexpr const char* defName = "Unnamed Account";
    static constexpr double defBalance = 0.0;

protected:
    std::string name;
    double balance;

public:
    Account(std::string name = defName, double balance = defBalance);
    virtual bool deposit(double amount) = 0;
    virtual bool withdraw(double amount) = 0;
    
    virtual void print(std::ostream& os) const override;

    virtual ~Account() = default;
};

#endif // _ACCOUNT_H_