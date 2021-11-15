#include <iostream>

// override specifier is like a notes to tell compiler if you forgot

// final specifier:
// 1. when used at the class level: prevents a class from being derived from
// 2. when used at the method level: prevents the virtual method from being overriden in derived classes

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

class Final_Class final: public Derived { // final class specifier, cannot be derived from
public:
    virtual void say_hello() const final { // final method specifier, cannot be further overriding
        std::cout << "Hello - I'm a Final class so I cannot be derived from" << std::endl;
        std::cout << "Also My say_hello() method has final specifier so this method cannot be further overriden" << std::endl;
    }
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