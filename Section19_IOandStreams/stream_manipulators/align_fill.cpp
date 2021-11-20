// Align and fill and field width

// Default when displaying floating point values is:
    // setw - not set by default
    // left - when no field width; right - when using field width
    // fill - not set by default - blank space is used

// Some of the manipulators affect only the next data element put on the stream (field width and justification)
// "again, cpp, why you have to be like this"

#include <iostream>
#include <iomanip>
#include <string>

int main (void)
{
    double num {1234.5678};
    std::string hello {"Hello"};

    std::cout << num << hello << std::endl;

    std::cout << std::endl;

    std::cout << num << std::endl;
    std::cout << hello << std::endl;

    std::cout << std::endl;

    std::cout << std::setw(10) 
    // set field width, 
    // the right most side of the info will be showing on the 10th width
    // in this case it's num
              << num << hello << std::endl;

    // so regular vs setw(10) output:
    // 123456789012345 (for reference)
    // 1234.57Hello
    //    1234.57Hello
    // the '7' is at the 10th field width. 

    std::cout << num << hello << std::endl;


    return 0;
}





