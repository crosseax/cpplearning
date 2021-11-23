// String streams

// allow to read or write from strings in memory 
// much similar to doing it to files
// useful for data validation


// #include <sstream>

// Decalre an stringstream, istringstream or ostringstream
// connect it to a std::string
// read/write data from/to the string stream using formatted I/O


#include <iostream>
#include <sstream>

int main (void)
{
    // how to read from stringstream
    int num1{};
    double total1{};
    std::string name1{};
    std::string info {"Moe 100 1234.5"};

    std::istringstream iss {info};
    iss >> name1 >> num1 >> total1;



    // how to write to stringstream
    int num2 {500};
    double total2 {4567.8};
    std::string name2 {"Larry"};

    std::ostringstream oss {};
    oss << name2 << " " << num2 << " " << total2;
    
    std::cout << oss.str() << std::endl;



    // data validation
    int value{};
    std::string input{};
    std::cout << "Enter an integer: ";
    std::cin >> input;

    std::stringstream ss {input};
    if (ss >> value) { // if the extraction from string to int is successful
        std::cout << "An integer (" << value << ") was entered" << std::endl;
    } else {
        std::cout << "No integer was entered" << std::endl;
    }



    return 0;
}

