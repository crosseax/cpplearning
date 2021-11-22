#include <iostream>
#include <fstream>

int main (void) 
{
    std::ifstream ifile;
    ifile.open("poem.txt");
    std::ofstream ofile;
    ofile.open("poem_copy.txt");

    if (!ifile) {
        std::cerr << "Problem opening file" << std::endl;
        return 1;
    }

    if (!ofile) {
        std::cerr << "Problem creating file" << std::endl;
        return 1;
    }

    char c;

    while (ifile.get(c)) {
        ofile.put(c);
    }

    std::cout << "Copy successfully made" << std::endl;

    ifile.close();
    ofile.close();

    return 0;
}