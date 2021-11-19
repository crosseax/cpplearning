#include <iostream>

int main (void)
{
    int miles {};
    int gallons {};
    double mpg {};

    std::cout << "Enter the miles: ";
    std::cin >> miles;
    std::cout << "Enter the gallons: ";
    std::cin >> gallons;

    // mpg = miles / gallons; // int division, truncation
   
    // Exception handling
    try {
        if (gallons == 0) { // condition
            throw 0; // can be anything, best practice is to throw obj
        } // if condition is meet, code block below won't execute
        mpg = static_cast<double>(miles) / gallons;
        std::cout << "Result mpg: " << mpg << std::endl;
    }

    catch (int& ex) { // will catch error above and execute the block below
        std::cerr << "Sorry, can't divide by zero" << std::endl; // std::cerr is like std::cout for error specifically
    }

    // This is not the typical way to do exception handling,
    // This is just to show the syntax
    
    // Usually is done when function throws exception

    std::cout << "Bye" << std::endl;

    return 0;
}


