// fstream and ifstream are commonly used for input files

// #inlcude <fstream>
// Declare an fstream or ifstream object
// Connect it to a file on your file system (open for reading) (make sure the type are right)
// Read data from the file via the stream
// Close the stream

// this file is just a notes, not meant to be compiled

#include <fstream>
#include <iostream>

int main (void)
{
    // std::fstream 
    // the second parameter specifies the mode and any other properties
    std::fstream thefile {"file.txt",    // this syntax depends varies along with operating system and IDE
                            std::ios::in};  // open in input mode - able to read but not write to
                                            // by default its open in text mode

    std::fstream thefile {"file", 
                            std::ios::in | std::ios::binary};
                            // | bitwise operator
                            // sets both the input and the binary modes to true
    
    // the fstream class can open, read and write at the same time
    // if only have a file that you'll use only for input 
    // its more common to use the ifstream

    std::ifstream thefile {"file.txt",
                            std::ios::in}; 


    // opening a file for reading with open
    std::ifstream in_file;
    std::string filename;
    // std::cin >> filename; // if want to grab file name from the user during the run time
    filename = "file.txt"; // assume exist

    in_file.open(filename);
    // or
    in_file.open(filename, std::ios::binary); // or any other flags

    // how to make sure the file is open successfully
    // maybe the name or directory is wrong, maybe the file did not exist
    if (in_file.is_open()) { // or (in_file) // just check the stream object
        // read from it
    } else {
        // file could not be opened
        // does not exist
        // terminate the program if needed
        // totally application-dependent
    }

    // CLosing the file
    // once finishing reading from a file, we MUST close it
    // always close any open files to flush out any unwritten data
    in_file.close();



    // How to read from it

    // Reading from files using
    /// stream extraction >> operator



    /****** text file example
     * 100
     * 255.67
     * Larry
     ******/
    int num{};
    double total{};
    std::string name{};

    in_file >> num;
    in_file >> total >> name;



    /*** line file example
     * This is a line
     ***/ 

    std::string line{};
    std::getline(in_file, line);
    



    // lets see how to read all the lines in a txt file
    
    std::ifstream in_file{"myfile.txt"}; // open file
    std::string line{};

    if (!in_file) { // check if the file is open
        std::cerr << "File open error" << std::endl;
        return 1; // exit the program (main)
    }
                // eof -> end of file
    while (!in_file.eof()) {            // while not at the end
        std::getline(in_file, line);    // read a line
        std::cout << line << std::endl; // display the line
    }
    in_file.close(); // close the file

    // for the while loop above, you can also do
    while (std::getline(in_file, line)) {
        // since these statements return a reference to the stream object
        // they'll only return a true value when the read was successful 
        // so when the end of file or any other encounter,
        // they will not return true and the while loop will terminate
        std::cout << line << std::endl;
    }

    // one more way, unformatted manner
    char c;
    while (in_file.get(c)) { // read a character
        std::cout << c;
    }


    return 0;
}



