#include <iostream>
#include <memory>
#include <vector>

#include "Account.h"
#include "Savings_Account.h"
#include "Account_Util.h"
#include "Checking_Account.h"
#include "Trust_Account.h"
#include "I_Printable.h"

class Test {
private:
    int data;
public:
    Test() 
        : data{0} {
            std::cout << "Test constructor (" << data << ")" << std::endl;
        }
    
    Test(int data)
        : data{data} {
            std::cout << "Test constructor (" << data << ")" << std::endl;
        }
    
    int get_data() const {
        return data;
    }

    ~Test() {
        std::cout << "Test destructor (" << data << ")" << std::endl;
    }

};

int main (void) 
{
    {
        std::cout << "===Test part===" << std::endl;
        Test t1 {100};
        Test *t2 = new Test {200};
        delete t2;

        std::unique_ptr<Test> t3 {new Test(300)};
        std::unique_ptr<Test> t4 = std::make_unique<Test> (500);

        std::unique_ptr<Test> t5;
        // t5 = t3; // ERROR - unique_ptr CANNOT be assigned
        t5 = std::move(t3); // t3 become nullptr
        if (!t3) {
            std::cout << "t3 is nullptr" << std::endl;
        }
        std::cout << "===Test destructors===" << std::endl;
    }


    std::cout << "===Account part===" << std::endl;
    std::unique_ptr<Account> a1 = std::make_unique<Checking_Account> ("Moe", 5000);
    std::cout << *a1 << std::endl;
    a1->deposit(5000);
    std::cout << *a1 << std::endl;


    std::cout << "===Vector part===" << std::endl;
    
    std::vector<std::unique_ptr<Account>> accounts;

    accounts.push_back(std::make_unique<Checking_Account> ("James", 1000));    
    accounts.push_back(std::make_unique<Savings_Account> ("Kai", 4000, 5.2));    
    accounts.push_back(std::make_unique<Trust_Account> ("Garry", 8000, 3.7));

    for (const auto& acc : accounts) {
        std::cout << *acc << std::endl;
    }    




    // Checking_Account frank {"Frank", 5000};

    // Account* trust = new Trust_Account("Leo", 10000, 3.4);
    // cout << *trust << endl;
    
    // Account* p1 = new Checking_Account("Larry", 10000);
    // Account* p2 = new Savings_Account("Moe", 10000);
    // Account* p3 = new Trust_Account("Curly");
    // Account* p4 = new Trust_Account("Garry", 100000);

    // std::vector<Account*> accounts {p1, p2, p3, p4};

    // display(accounts);
    // deposit(accounts, 1000);
    // withdraw(accounts, 2000);
    // withdraw(accounts, 2000);
    // withdraw(accounts, 2000);
    // withdraw(accounts, 2000);

    // display(accounts);

    // cout << endl;

    // delete p1;
    // delete p2; 
    // delete p3;

    return 0;
}