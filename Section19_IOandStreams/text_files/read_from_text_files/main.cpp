#include <iostream>
#include <fstream>

int main (void)
{
    std::string line;
    int num;
    double total;

    std::ifstream in_file; // create an input file stream
    in_file.open("file.txt"); // this works for MacOS, or ./file.txt

    if (!in_file) {
        std::cerr << "Problem opening file" << std::endl;
        return 1; // anything other than 0 means the program runs successfully
        // std::exit(1); // sometimes the code looks like this
    }
    std::cout << "===The file.txt is good to go===" << std::endl;

    in_file >> line >> num >> total;
    // extraction operator >> would stop at while space " ", so space or \n would work
    std::cout << line << std::endl;
    std::cout << num << std::endl;
    std::cout << total << std::endl;
    in_file.close(); // VERY IMPORTANT

    std::cout << std::endl;

    in_file.open("test.txt");
    if (!in_file) {
        std::cerr << "Problem opening file" << std::endl;
        return 1;
    }
    std::cout << "===The test.txt is good to go===" << std::endl;

    std::string name;
    while (!in_file.eof()) {
        in_file >> name >> num >> total;
        std::cout << std::setw(10) << std::left << name
                  << std::setw(10) << num
                  << std::setw(10) << total
                  << std::endl;
    }
    // note in test.txt, the line in between is ok because how >> operator works
    // but if there're more empty lines below the data
    // the while loop wont terminate 
    // because it's not the end of file so in_file.eof() returns 0


    // since reached the end of the file, the eof and fail flags will be set
    // to re read, need to clear those flags and seek back to the beginning of the file
    in_file.clear();    // clear those flags
    in_file.seekg(0);   // seek go, so going back to the beginning of the file

    std::cout << std::endl;
    
    // you can also do as below
    while (in_file >> name >> num >> total) {
        std::cout << std::setw(10) << std::left << name
                  << std::setw(10) << num
                  << std::setw(10) << total
                  << std::endl;
    }

    in_file.close();

    return 0;
}