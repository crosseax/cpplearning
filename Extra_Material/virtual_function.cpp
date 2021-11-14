// An advanced atemptation to understand virtual functions

#include <iostream>

class Base 
{
public:
    void print() {
        std::cout << "Base print" << std::endl;
    }
    virtual void print1 () {

    }
};

class Derived: public Base 
{
public:
    void print() {
        std::cout << "Derived print" << std::endl;
    }
    void print1() {
        std::cout << "Virtual print" << std::endl;
    }
};

int main (void) 
{
    Derived der {};
    der.print();

    Base* bas {nullptr};
    bas = &der;
    bas->print();
    bas->print1();

    return 0;
}