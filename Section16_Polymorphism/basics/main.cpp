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

#include <iostream>