// Interface class (way to achieve in C++):
// A class that has only pure virtual functions
// and those pure virtual functions must be declared as public
// when derive a concrete class all virtual method(function) must be implemented
// and C++ strictly enfore type information
// so the prototype must match exactly

// Interface class usually named like: I_class

#include <iostream>

class Account {
    friend std::ostream& operator<< (std::ostream& os, const Account& acc); 
    // the reason there's lots of friend functions prototype and implementation for classes below
    // is because friend functions are not inherited
public:
    virtual void withdraw(double amount) {
        std::cout << "In Account::withdraw" << std::endl;
    }
    virtual ~Account() {}
};

std::ostream& operator<< (std::ostream& os, const Account& acc) {
    os << "Account operator<< overload display";
    return os;
}



class Checking: public Account {
    friend std::ostream& operator<< (std::ostream& os, const Checking& acc);
public:
    virtual void withdraw(double amount) {
        std::cout << "Int Checking::withdraw" << std::endl;
    }
    virtual ~Checking() {}
};

std::ostream& operator<< (std::ostream& os, const Checking& acc) {
    os << "Checking operator<< overload display";
    return os;
}



class Savings: public Account {
    friend std::ostream& operator<< (std::ostream& os, const Savings& acc);
public:
    virtual void withdraw(double amount) {
        std::cout << "Int Savings::withdraw" << std::endl;
    }
    virtual ~Savings() {}
};

std::ostream& operator<< (std::ostream& os, const Savings& acc) {
    os << "Savings operator<< overload display";
    return os;
}



class Trust: public Account {
    friend std::ostream& operator<< (std::ostream& os, const Trust& acc);
public:
    virtual void withdraw(double amount) {
        std::cout << "Int Trust::withdraw" << std::endl;
    }
    virtual ~Trust() {}
};

std::ostream& operator<< (std::ostream& os, const Trust& acc) {
    os << "Trust operator<< overload display";
    return os;
}


int main (void)
{
    Account a;
    Checking c;
    Savings s;
    Trust t;

    std::cout << a << std::endl;
    std::cout << c << std::endl;
    std::cout << s << std::endl;
    std::cout << t << std::endl;

    Account* p1 = new Account();
    Account* p2 = new Checking();

    // why behavior below
    std::cout << *p1 << std::endl; // Account operator<< overload display
    std::cout << *p2 << std::endl; // Account operator<< overload display
    // because we got no virtual function for <<
    // the only virtual function we have is withdraw() and it is not called here

    return 0;
}








