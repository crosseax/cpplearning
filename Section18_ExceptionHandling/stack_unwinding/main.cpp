// Stack unwinding

// if an exception is thrown but not caught in the current scope
// C++ tries to find a handler for the exception by unwinding the stack

// Function in which the exception was not caught terminates and is removed from the call stack
// If a try block was used to then catch blocks are checked for a match
// If no try block was used or the catch handler doesn't match stack unwinding occurs again
// If the stack is unwound back to main and no catch handler handles the exception, the program terminates


#include <iostream>

void funcA ();
void funcB ();
void funcC ();

void funcA () {
    std::cout << "A Start" << std::endl;
    funcB();
    std::cout << "- A Ends" << std::endl;
}

void funcB () {
    std::cout << "B Start" << std::endl;
    try {
        funcC();
    }

    catch (int& ex) {
        std::cerr << "Caught error in B" << std::endl;        
    }
    std::cout << "- B Ends" << std::endl;
}

void funcC () {
    std::cout << "C Start" << std::endl;
    throw 100;
    std::cout << "- C Ends" << std::endl;
}



int main (void)
{
    std::cout << "Main goes" << std::endl;

    try {
        funcA();
    }

    catch (int& ex) {
        std::cerr << "Caught error in main" << std::endl;
    }
    
    std::cout << "Main done" << std::endl;

    return 0;
}






