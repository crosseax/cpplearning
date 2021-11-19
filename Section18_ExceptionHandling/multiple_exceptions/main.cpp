#include <iostream>
#include <string>

double calc_mpg(int miles, int gallons) {
    if (gallons == 0) {
        throw 0;
    }
    if (miles < 0 || gallons < 0) {
        throw std::string {"Negative value error"};
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

    catch (int& ex) {
        std::cerr << "Gallons is zero, no logical result provided" << std::endl; 
    }

    catch (std::string& ex) {
        std::cerr << ex << std::endl;
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