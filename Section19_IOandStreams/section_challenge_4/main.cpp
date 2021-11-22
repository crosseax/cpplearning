#include <iostream>
#include <fstream>
#include <string>

void line_number(std::ifstream& ifile, std::ofstream& ofile) {
    std::string line;
    int num {1};
    while (std::getline(ifile, line)) {
            ofile << std::setw(10) << std::left << num
                << line << std::endl;
            num++; 
    }
}

void line_number_no_space(std::ifstream& ifile, std::ofstream& ofile) {

}

int main (void) 
{
    std::ifstream ifile;
    std::ofstream ofile;

    ifile.open("hamlet.txt");
    ofile.open("hamlet_line_number.txt");

    if (!ifile) {
        std::cerr << "Problem opening file" << std::endl;
        return 1;
    }

    if (!ofile) {
        std::cerr << "Problem creating file" << std::endl;
        return 1;
    }

    line_number(ifile, ofile);

    std::cout << "Line number added, copy created" << std::endl;

    ifile.close();
    ofile.close();

    return 0;
}