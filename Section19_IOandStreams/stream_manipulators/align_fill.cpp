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
    // the '7' is at the 10th field width. "like seriously wtf cpp why"

    // and that shit only affect the next item once "like seriously WTF"

    std::cout << num << hello << std::endl;

    std::cout << "1234567890123456789012345678901234567890" << std::endl;
    std::cout << std::setw(10) << num
              << std::setw(10) << hello
              << std::setw(10) << hello << std::endl;
    // output:
    // 123456789012345678901234567890 (for reference)
    //    1234.57     Hello     Hello
    
    // oh I guess now it makes sense
    
    std::cout << "12345678901234567890123456789012345678901234567890" << std::endl;
    std::cout << std::setw(10) << num
              << std::setw(10) << std::right << hello // std::right is the default
              << std::setw(15) << std::left << hello 
              << std::setw(15) << std::right << hello << std::endl;
    // output:
    // 12345678901234567890123456789012345678901234567890 (for reference)
    //    1234.57     HelloHello                    Hello
    

    // std::setfill() 
    // will only works if field width associated with it
    std::cout << "1234567890123456789012345678901234567890" << std::endl;
    std::cout << std::setfill('*');
    std::cout << std::setw(10) << num
              << std::setfill('-') << std::setw(15) << hello 
              << std::setw(10) << hello 
              << std::endl;
    // output:
    // 1234567890123456789012345678901234567890 (for reference)
    // ****1234.57---------Hello-----Hello
    

    return 0;
}





