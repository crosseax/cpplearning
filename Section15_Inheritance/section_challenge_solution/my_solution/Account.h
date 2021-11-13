#ifndef _ACCOUNT_H_
#define _ACCOUNT_H_
#include <iostream>
#include <string>

class Account {
    friend std::ostream& operator<<(std::ostream& os, const Account& account);

private:
    static constexpr const char* defName = "Unnamed Account";
    static constexpr double defBalance = 0.0;
    // think of two constexpr above available only to this class

protected:
    std::string name;
    double balance;

public:
    Account(std::string name = defName, double balance = defBalance);
    // Account(std::string name = "Unnamed Account", double balance = 0.0); // another way to do it
    bool deposit(double amount);
    bool withdraw(double amount);
    double get_balance() const;
};

#endif // _ACCOUNT_H_