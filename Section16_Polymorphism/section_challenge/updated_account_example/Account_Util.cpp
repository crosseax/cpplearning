#include <iostream>
#include "Account_Util.h"


// Utility helper functions for Account class

void display(const std::vector<Account>& accounts) {
    std::cout << "\n===Accounts===" << std::endl;
    for (const auto& acc : accounts) {
        std::cout << acc << std::endl;
    }
}

void deposit(std::vector<Account>& accounts, double amount) {
    std::cout << "\n===Depositing to Accounts===" << std::endl;
    for (auto& acc : accounts) {
        if (acc.deposit(amount)){
            std::cout << "Deposited $" << amount << " to " << acc << std::endl;
        } else {
            std::cout << "Failed deposit of $" << amount << " to " << acc << std::endl;
        }
    }
}

void withdraw(std::vector<Account>& accounts, double amount) {
    std::cout << "\n===Withdrawing from Accounts===" << std::endl;
    for (auto& acc : accounts) {
        if (acc.withdraw(amount)){
            std::cout << "Withdrew $" << amount << " from " << acc << std::endl;
        } else {
            std::cout << "Failed withdrawal of $" << amount << " from " << acc << std::endl;
        }
    }
}


// Utility helper functions for Savings_Account class

void display(const std::vector<Savings_Account>& accounts) {
    std::cout << "\n===Savings Accounts===" << std::endl;
    for (const auto& acc : accounts) {
        std::cout << acc << std::endl;
    }
}

void deposit(std::vector<Savings_Account>& accounts, double amount) {
    std::cout << "\n===Depositing to Savings Accounts===" << std::endl;
    for (auto& acc : accounts) {
        if (acc.deposit(amount)){
            std::cout << "Deposited $" << amount << " to " << acc << std::endl;
        } else {
            std::cout << "Failed deposit of $" << amount << " to " << acc << std::endl;
        }
    }
}

void withdraw(std::vector<Savings_Account>& accounts, double amount) {
    std::cout << "\n===Withdrawing from Savings Accounts===" << std::endl;
    for (auto& acc : accounts) {
        if (acc.withdraw(amount)){
            std::cout << "Withdrew $" << amount << " from " << acc << std::endl;
        } else {
            std::cout << "Failed withdrawal of $" << amount << " from " << acc << std::endl;
        }
    }
}



// Utility helper functions for Checking_Account class


void display(const std::vector<Checking_Account>& accounts) {
    std::cout << "\n===Checking_Accounts===" << std::endl;
    for (const auto& acc : accounts) {
        std::cout << acc << std::endl;
    }
}

void deposit(std::vector<Checking_Account>& accounts, double amount) {
    std::cout << "\n===Depositing to Checking Accounts===" << std::endl;
    for (auto& acc : accounts) {
        if (acc.deposit(amount)){
            std::cout << "Deposited $" << amount << " to " << acc << std::endl;
        } else {
            std::cout << "Failed deposit of $" << amount << " to " << acc << std::endl;
        }
    }
}


void withdraw(std::vector<Checking_Account>& accounts, double amount) {
    std::cout << "\n===Withdrawing from Checking Accounts===" << std::endl;
    for (auto& acc : accounts) {
        if (acc.withdraw(amount)){
            std::cout << "Withdrew $" << amount << " from " << acc << std::endl;
        } else {
            std::cout << "Failed withdrawal of $" << amount << " from " << acc << std::endl;
        }
    }
}

// Utility helper functions for Checking_Account class

void display(const std::vector<Trust_Account>& accounts) {
    std::cout << "\n===Trust Accounts===" << std::endl;
    for (const auto& acc : accounts) {
        std::cout << acc << std::endl;
    }
}

void deposit(std::vector<Trust_Account>& accounts, double amount) {
    std::cout << "\n===Depositing to Trust Accounts===" << std::endl;
    for (auto& acc : accounts) {
        if (acc.deposit(amount)){
            std::cout << "Deposited $" << amount << " to " << acc << std::endl;
        } else {
            std::cout << "Failed deposit of $" << amount << " to " << acc << std::endl;
        }
    }
}

void withdraw(std::vector<Trust_Account>& accounts, double amount) {
    std::cout << "\n===Withdrawing from Trust Accounts===" << std::endl;
    for (auto& acc : accounts) {
        if (acc.withdraw(amount)){
            std::cout << "Withdrew $" << amount << " from " << acc << std::endl;
        } else {
            std::cout << "Failed withdrawal of $" << amount << " from " << acc << std::endl;
        }
    }
}
