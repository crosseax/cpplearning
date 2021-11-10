#include <iostream>
#include "Account.h"

Account::Account () {

}

Account::~Account () {

}

void Account::deposit (double amount) {
    std::cout << "Account deposit called with " << amount << std::endl; 
}

void Account::withdraw (double amount) {
    std::cout << "Account wihtdraw called with " << amount << std::endl; 
}