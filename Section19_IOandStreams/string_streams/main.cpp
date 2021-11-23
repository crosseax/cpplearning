#include <iostream>
#include <iomanip>
#include <sstream>
#include <string>
#include <limits> 

int main (void)
{
    // input
    int num {};
    double total {};
    std::string name {};

    std::string info {"Moe 100 1234.5"};
    std::istringstream iss {info};

    iss >> name >> num >> total;
    std::cout << std::setw(10) << std::left << name 
              << std::setw(5) << num
              << std::setw(10) << total
              << std::endl;

    std::cout << "======" << std::endl;


    // output
    std::ostringstream oss{};

    oss << std::setw(10) << std::left << name 
        << std::setw(5) << num
        << std::setw(10) << total
        << std::endl;

    std::cout << oss.str() << std::endl;



    // data validation
    int value{};
    std::string entry{};
    bool done = false;

    do {
        std::cout << "Please enter an integer: ";
        std::cin >> entry;
        std::istringstream validator {entry}; // code just use std::streamstring 
        if (validator >> value){
            done = true;
        } else {
            std::cout << "Sorry, that's not an integer." << std::endl;
        }
        
        // discards the input buffer
        
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n'); // <limits>
        
        // using std::numeric limits up to whatever the std::stream size is
        // then using the max of that size, getting rid all of it, clearing out that stream
        // ignore everything in the stream up to the new line
        
        // so basically, if the user input the 12.43
        // the int will read 12, and left over .43
        // which could be read by the next stream input (and lead to potential damage)
        // so the code above just drops the .43

        std::cout << "\n";

    } while (!done);

    std::cout << "You entered an integer: " << value << std::endl;

    return 0;
}