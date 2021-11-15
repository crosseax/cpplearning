#include <iostream>
#include <vector>

class Account {
public:
    virtual void withdraw(double amount){ 
    // since its virtual, it will be dynamically-bond
    // so its bond at runtime, not compile time
        std::cout << "Account::withdraw()" << std::endl;
    }
};

class Checking: public Account {
public:
    virtual void withdraw(double amount){
        std::cout << "Checking::withdraw()" << std::endl;
    }
};

class Savings: public Account {
public:
    virtual void withdraw(double amount){
        std::cout << "Savings::withdraw()" << std::endl;
    }
};

class Trust: public Savings {
public:
    virtual void withdraw(double amount){
        std::cout << "Trust::withdraw()" << std::endl;
    }
};




int main (void)
{
    std::cout << "\n===Pointers===" << std::endl;
    Account* p1 = new Account();
    Account* p2 = new Checking();
    Account* p3 = new Savings();
    Account* p4 = new Trust();

    p1->withdraw(1000);
    p2->withdraw(1000);
    p3->withdraw(1000);
    p4->withdraw(1000);
    
    std::cout << "\n===Array===" << std::endl;
    Account* accArray[] = {p1, p2, p3, p4};
    for (auto i = 0; i < 4; i++) {
        accArray[i]->withdraw(1000);
    }

    std::cout << "\n===Vector===" << std::endl;
    std::vector<Account*> accVectors {p1, p2, p3, p4};
    for (auto acc : accVectors) {
        acc->withdraw(1000);
    }


    std::cout << "\n===Another Vector===" << std::endl;

    Account* p5 = new Checking();
    Account* p6 = new Trust();

    accVectors.push_back(p5);
    accVectors.push_back(p6);

    for (auto acc : accVectors) {
        acc->withdraw(1000);
    }

    delete p1;
    delete p2;
    delete p3;
    delete p4;
    delete p5;
    delete p6;
    
    return 0;
}