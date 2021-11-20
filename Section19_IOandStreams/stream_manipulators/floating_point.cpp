// Formatting floating point types

// Default:
    // setprecision - number of digits displayed (6)
    // fixed - not fixed to a specific number of digits after the decimal point
    // noshowpoint - trailing zeroes are not displayed (3.40000)
    // nouppercase - when displaying in scientific notation
    // noshowpos - no '+' is displayed for positive numbers

// These manipulators affect all further output to the stream

// ======NOTICE======
// some of the method below are different
// refer to cppreference would be the best way to find out
// ==================


#include <iostream>
#include <iomanip>

int main (void) 
{
    double num1 {1234.5678};
    double num2 {123456789.987654321};

    std::cout << num1 << " " << num2 << std::endl;

    std::cout << std::setprecision(9);
    std::cout << num1 << " " << num2 << std::endl;

    std::cout << std::setprecision(6) << std::fixed; // will display that much from the decimal point 
    std::cout << num1 << " " << num2 << std::endl; // notice trailing 0s

    // reset fixed
    std::cout << std::defaultfloat;
    std::cout << std::resetiosflags(std::ios::floatfield); 



    std::cout << std::setprecision(3);
    std::cout << num1 << " " << num2 << std::endl;

    std::cout << std::endl;

    double num3 {1.2};

    std::cout << num3 << std::endl; 
    std::cout << std::showpoint; // show trailing zeroes
    std::cout << num3 << std::endl; 

    std::cout << std::setprecision(3) << std::scientific << std::uppercase;
    std::cout << num1 << " " << num2 << " " << num3 << std::endl;


    // reset std::fixed and std::scientific
    // unsetf
    std::cout.unsetf(std::ios::scientific | std::ios::fixed | std::ios::uppercase);
    

    std::cout << std::noshowpoint; // no trailing zeroes
    std::cout << std::setprecision(6); // precision
    std::cout << std::defaultfloat; // unset scientific and fixed
    std::cout << std::nouppercase; // no uppercase
    
    std::cout << num1 << " " << num2 << " " << num3 << std::endl;

    
    // - Seriously bro, just go look cppreference
    // - this shit varies with C++ standards too (c++98 c++11 c++17 etc)
    // - why do cpp has to be like this

    return 0;
}
