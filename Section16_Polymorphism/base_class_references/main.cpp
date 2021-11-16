#include <iostream>
#include <vector>

class Account {
public:
    virtual void withdraw(double amount){ 
        std::cout << "Account::withdraw(amount), $" << amount << std::endl;
    }

    virtual ~Account() {
        std::cout << "Account::destructor" << std::endl;
    }
};

class Checking: public Account {
public:
    virtual void withdraw(double amount){
        std::cout << "Checking::withdraw(amount), $" << amount << std::endl;
    }
    virtual ~Checking() {
        std::cout << "Checking::destructor, ";
    }
};

class Savings: public Account {
public:
    virtual void withdraw(double amount){
        std::cout << "Savings::withdraw(amount), $" << amount << std::endl;
    }
    virtual ~Savings() {
        std::cout << "Savings::destructor, ";
    }
};

class Trust: public Savings {
public:
    virtual void withdraw(double amount){
        std::cout << "Trust::withdraw(amount), $" << amount << std::endl;
    }
    virtual ~Trust() {
        std::cout << "Trust::destructor, ";
    }
};


// Use Base class reference here
// to think generally and abstratly

void do_withdraw(Account &account, double amount) {
    account.withdraw(amount);
}

int main (void)
{
    Account a;
    Account &ref1 = a;
    ref1.withdraw(1000);

    Trust t;
    Account &ref2 = t;
    ref2.withdraw(1000); 

    
    // Use Base class reference
    Account a1;
    Savings a2;
    Checking a3;
    Trust a4;

    do_withdraw(a1, 1000);
    do_withdraw(a2, 2000);
    do_withdraw(a3, 3000);
    do_withdraw(a4, 4000);

    std::cout << "\n===Pointers vector===" << std::endl;
    std::vector<Account*> accountsPtr;
    accountsPtr.push_back(&a1);
    accountsPtr.push_back(&a2);
    accountsPtr.push_back(&a3);
    accountsPtr.push_back(&a4);

    for (const auto acc : accountsPtr) {
        do_withdraw(*acc, 500);
    }

    // Destructor calls
    std::cout << "\n===Destructors===" << std::endl;


    return 0;
}