#include <iostream>
#include <memory>
#include "Account.h"
#include "Savings_Account.h"
#include "Account_Util.h"
#include "Checking_Account.h"
#include "Trust_Account.h"
#include "I_Printable.h"
#include "IllegalBalanceException.h"

using namespace std;

int main (void) 
{
    std::string name {"Garry"};
    int balance;

    std::cout << "How much money you have: ";
    std::cin >> balance;

    try {
        std::unique_ptr<Account> garry = std::make_unique<Checking_Account> (name, balance); 
        std::cout << "Checking Account created\n"; 
        std::cout << *garry << std::endl; 
    }

    catch (const IllegalBalanceException& ex) {
        std::cerr << "Couldn't create account - negative balance" << std::endl;
    }

    std::cout << "Program complete successfully" << std::endl;
    
    return 0;
}