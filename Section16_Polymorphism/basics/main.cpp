// Polymorphism 
// compile-time / early binding / static binding are the same
// run-time / late binding / dynamic binding are the same

// Two types of polymorphism: compile time / run time
// compile time: function overloading, operator overloading 
// run time: function overriding (this section focus)


// Example:

// Account a; a.withdraw() => Account::withdraw()
// Savings b: public a; b.withdraw() => Savings::withdraw()
// Account* p = new Savings(); p->withdraw => Account::withdraw(), while it should be Savings::withdraw()

// Cuz we're using static binding by default 
// so the compiler doesn't really know what type of account obj p is pointing to at runtime
// all it knows is that p is pointing to an account 
// so it calls the Account::withdraw()

// since all the compiler knows is that p is a pointer to an account
// so it will bind the withdraw method to the Account::withdraw() at compile time

// The virtual function:
// Tells compiler to not to bind the function call during compile time
// instead, wait to bind it during the run time

// Virtual function will always call the method/function depending on the object's type at Run-Time

#include <iostream>
#include <memory>

class Base {
public: 
    void say_hello() const {
        std::cout << "Hello - I'm a Base class object" << std::endl;
    }
};

class Derived: public Base {
public:
    void say_hello() const {
        std::cout << "Hello - I'm a Derived class object" << std::endl;
    }
};

void greetings(const Base& obj) {   
    // it expect a Base class by reference
    // since Derived is a Base, can also pass in Derived
    // so when use, all bind Base::say_hello()
    std::cout << "Greetings: ";
    obj.say_hello();
}

int main (void)
{
    Base b;
    b.say_hello(); // compile-time, compiler only knows its Base, and will call Base function

    Derived d;
    d.say_hello(); // same thing happens, compiler knows its Derived, and will call Derived function
    // everything above is static binding 

    // so some issue might goes like below
    greetings(b); // Base
    greetings(d); // Base

    Base* rawPtr = new Derived; // rawPtr can hold address of any Base obj (include "is-a" Base obj)
    rawPtr->say_hello(); // always bind to Base::say_hello()
    delete rawPtr;

    // same thing happens to smart ptr (will learn later)
    std::unique_ptr<Base> smartPtr = std::make_unique<Derived>(); // will create a smart ptr
    smartPtr->say_hello(); // same problem
    // smart pointers delete themselves

    return 0;
}