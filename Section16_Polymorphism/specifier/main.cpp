#include <iostream>

// override keyword is like a notes to tell compiler if you forgot

class Base {
public:
    virtual void say_hello() const {
        std::cout << "Hello - I'm a Base class object" << std::endl;
    }
    virtual ~Base(){}
};

class Derived: public Base {
public:
    virtual void say_hello() const override { // if forgot const, compiler will notify you, and wont compile
    // if forgot const, 
    // then this is redifine not override, 
    // then this is static binding rather than dynamically binding 
        std::cout << "Hello - I'm a Derived class object" << std::endl;
    }
    virtual ~Derived(){}
};

int main (void)
{
    Base* p1 = new Base();
    p1->say_hello();

    Derived* p2 = new Derived();
    p2->say_hello();

    Base* p3 = new Derived();
    p3->say_hello();

    return 0;
}