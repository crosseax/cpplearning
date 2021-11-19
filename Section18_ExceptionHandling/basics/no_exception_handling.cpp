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
    
    // NOT exception handling, just regular if-else logic
    if (gallons != 0) {
        mpg = static_cast<double>(miles) / gallons;
    } else {
        std::cerr << "Sorry, can't divide by zero" << std::endl; // std::cerr is like std::cout for error specifically
    }
    std::cout << "Result mpg: " << mpg << std::endl;

    std::cout << "Bye" << std::endl;

    return 0;
}


