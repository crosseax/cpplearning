// Formatting boolean types

// default when diplaying boolean values is 1 or 0
// sometimes the strings true or false are more appropriate

#include <iostream>
#include <iomanip> // must include for manipulators

int main (void)
{
    std::cout << "Manipulators" << std::endl;

    std::cout << "noboolalpha - default (10 == 10): " << (10 == 10) << std::endl;
    std::cout << "noboolalpha - default (10 == 20): " << (10 == 20) << std::endl;

    std::cout << std::boolalpha; // if no further manipulator, will stay for all the rest
    
    std::cout << "boolalpha (10 == 10): " << (10 == 10) << std::endl; // true
    std::cout << "boolalpha (10 == 20): " <<(10 == 20) << std::endl; // false

    std::cout << std::noboolalpha;

    std::cout << "noboolalpha (10 == 10): " << (10 == 10) << std::endl; // 1
    std::cout << "noboolalpha (10 == 20): " << (10 == 20) << std::endl; // 0

    // std::boolalpha and std::noboolalpha affects all boolean values after

    std::cout << "Methods" << std::endl;

    // method version
    std::cout.setf(std::ios::boolalpha); // std - namespace, ios - class, boolalpha - flag
    std::cout << "boolalpha (10 == 10): " << (10 == 10) << std::endl; // true
    std::cout << "boolalpha (10 == 20): " <<(10 == 20) << std::endl; // false
    // all the flags have default value
    // reset to default
    std::cout << std::resetiosflags(std::ios::boolalpha);
    std::cout << "noboolalpha (10 == 10): " << (10 == 10) << std::endl; // 1
    std::cout << "noboolalpha (10 == 20): " << (10 == 20) << std::endl; // 0


    return 0;
}