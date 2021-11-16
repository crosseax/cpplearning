#include <iostream>

class I_Printable {
    friend std::ostream& operator<< (std::ostream& os, const I_Printable& obj);
public:
    virtual void print(std::ostream& os) const = 0; // pure virtual function
    // this line must exist because 
    // all derived class of interface (abstract class) 
    // must implement all the virtual functions 
};

std::ostream& operator<< (std::ostream& os, const I_Printable& obj){
    obj.print(os);
    return os;
}

class Account: public I_Printable {
public:
    virtual void withdraw(double amount) {
        std::cout << "In Account::withdraw" << std::endl;
    }
    virtual void print(std::ostream& os) const override {
        os << "Account display";
    }
    virtual ~Account() {}
};

class Checking: public Account {
public:
    virtual void withdraw(double amount) override {
        std::cout << "Int Checking::withdraw" << std::endl;
    }
    virtual void print(std::ostream& os) const override {
        os << "Checking display";
    }
    virtual ~Checking() {}
};

class Savings: public Account {
public:
    virtual void withdraw(double amount) override {
        std::cout << "Int Savings::withdraw" << std::endl;
    }
    virtual void print(std::ostream& os) const override {
        os << "Savings display";
    }
    virtual ~Savings() {}
};

class Trust: public Account {
public:
    virtual void withdraw(double amount) override {
        std::cout << "Int Trust::withdraw" << std::endl;
    }
    virtual void print(std::ostream& os) const override {
        os << "Trust display";
    }
    virtual ~Trust() {}
};



// Say a new class
// even Dog has nothing to do with Account
// it can still print itself by doing below
class Dog: public I_Printable {
public:
    virtual void print(std::ostream& os) const override {
        os << "Woof I'm a dog";
    } 
};



// even better to use function to implement I_Printable
void print(const I_Printable& obj) {
    std::cout << obj << std::endl;
}




int main (void)
{
    // static binding 
    Account a;
    Checking c;
    Savings s;
    Trust t;

    std::cout << a << std::endl;
    std::cout << c << std::endl;
    std::cout << s << std::endl;
    std::cout << t << std::endl;


    // dynamic polymorphism
    Account* p1 = new Account();
    Account* p2 = new Checking();

    std::cout << *p1 << std::endl; 
    std::cout << *p2 << std::endl; 


    // class that has nothing to do with Account
    Dog d; 
    Dog* dp = new Dog();

    std::cout << d << std::endl; 
    std::cout << *dp << std::endl;

    std::cout << std::endl;


    // using function
    print(*p1);
    print(a);
    print(t);
    print(*dp);

    dp->print(std::cout << "hi ");

    return 0;
}








