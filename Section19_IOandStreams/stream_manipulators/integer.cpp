// Formatting integer types

// Default:
    // dec (base10)
    // noshowbase - prefix used to show hexadecimal or octal (0x0 hex, 0 octal)
    // nouppercase - when displaying a prefix and hex values it will be lower case
    // noshowpos - no '+' is displayed for positive numbers


#include <iostream>
#include <iomanip>

int main (void)
{
    int num {255};

    std::cout << std::dec << num << std::endl;
    std::cout << std::hex << num << std::endl;
    std::cout << std::oct << num << std::endl;

    // setting also will persist for the future cout 

    std::cout << "\nstd::showbase;";
    std::cout << std::showbase;
    std::cout << std::dec << num << std::endl;
    std::cout << std::hex << num << std::endl;
    std::cout << std::oct << num << std::endl;

    std::cout << "\nstd::showbase << std::uppercase;";
    std::cout << std::showbase << std::uppercase; // for all hex output
    std::cout << std::dec << num << std::endl;
    std::cout << std::hex << num << std::endl;
    std::cout << std::oct << num << std::endl;

    std::cout << std::dec << std::noshowbase << std::nouppercase; // reset

    std::cout << "\nstd::showpos;" << std::endl;
    int num1 {255};
    int num2 {-255};

    std::cout << num1 << std::endl;
    std::cout << num2 << std::endl;

    std::cout << std::showpos;
    
    std::cout << num1 << std::endl;
    std::cout << num2 << std::endl;

    std::cout << std::noshowpos;

    // set using setf
    std::cout.setf(std::ios::hex); // what in the parathethese is (format flag)
    std::cout.setf(std::ios::showbase);
    std::cout.setf(std::ios::uppercase);
    std::cout.setf(std::ios::showpoint);

    // reset to defaults
    std::cout << std::resetiosflags(std::ios::basefield);
    std::cout << std::resetiosflags(std::ios::showbase);
    std::cout << std::resetiosflags(std::ios::showpos);
    std::cout << std::resetiosflags(std::ios::uppercase);

    // no need to memorize, just look up in cppreference 


    return 0;
}



