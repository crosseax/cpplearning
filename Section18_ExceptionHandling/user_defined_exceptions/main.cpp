// User defined exceptions

// We cancreate exception classes and throw instances of those classes

// Best practice:
// - throw an object, not a primitive type
// - throw an object by value
// - catch an object by reference (or const &)


#include <iostream>
#include <string>

class DevideZero {

};

class NegativeValue {

};


double calc_mpg(int miles, int gallons) {
    if (gallons == 0) {
        throw DevideZero();
    }
    if (miles < 0 || gallons < 0) {
        throw NegativeValue();
    }

    return static_cast<double> (miles) / gallons;
}


int main (void)
{
    int miles {};
    int gallons {};
    double mpg {};

    std::cout << "Enter the miles: ";
    std::cin >> miles;
    std::cout << "Enter the gallons: ";
    std::cin >> gallons;



    try { // write try block around the code that can potentially throw exception
        mpg = calc_mpg(miles, gallons);
        std::cout << "Result MPG: " << mpg << std::endl;
    }

    catch (const DevideZero& ex) {
        std::cerr << "Gallons is zero, no logical result" << std::endl; 
    }

    catch (const NegativeValue& ex) {
        std::cerr << "Negative value, no logical result" << std::endl;
    }

    catch (...) { 
        // catch all handler
        // catches whatever is thrown
        // usually used at the last catch
        std::cerr << "Unknown exception" << std::endl;
    }

    std::cout << "Done" << std::endl;

    return 0;
}





