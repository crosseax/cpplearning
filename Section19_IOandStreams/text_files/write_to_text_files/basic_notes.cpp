// fstream and oftream are commonly used for output files

// #include <fstream>
// Declare an fstream or ofstream object
// Connect it to a file on your file system (opens it for writing)
// Write data to the file via the stream
// Close the stream IMPORTANT

// by default, cpp will create a new file if it doesn't exist
// if it exist, it will be truncated or moved if not stated otherwise


// Output fules will be created if they don't exist
// Output files will be overwritten (truncated) by default
// Can be opened so that new writes append
// Can be open in text or binary modes

// ********
// This file is meant to be notes, not to be compiled
// ********

#include <iostream>
#include <fstream>

int main (void)
{
    std::fstream out_file {"file.txt", std::ios::out};
    // output mode, only write, not read
    // by default is text mode

    std::fstream out_file {"file.txt", std::ios::out | std::ios::binary}; // write in binary mode

    std::ofstream out_file {"file.txt", std::ios::out}; 
    // in std::ofstream, std::ios::out is default
    // commonly used for write-only file


    // different modes

    // by default
    // truncate (discard contents) when opening
    std::ofstream out_file {"file.txt", std::ios::trunc};  
    
    // append on each write
    std::ofstream out_file {"file.txt", std::ios::app}; 
    
    // seek to end of stream when opening
    // but we're free to move around using random access
    std::ofstream out_file {"file.txt", std::ios::ate}; 
    
    

    std::ofstream out_file;
    std::string filename;
    std::cin >> filename;
    out_file.open(filename);
    // or any flags
    out_file.open(filename, std::ios::binary);

    if (out_file.is_open()) {
        // read from it
    } else {
        // std::cerr
    }

    // or 

    if (out_file) { // just check the object
        // read from it
    } else {
        // std::cerr
    }

// Writing to files using (<<)
    // we can use the insertion operator for formatted write
    // same way we used it with std::cout

    int num {100};
    double total {255.67};
    std::string name {"Dude"};

    out_file << num     << "\n"
             << total   << "\n"
             << name    
             << std::endl; // flushes out any unwritten buffer


    // copy file
    std::ifstream in_file {"file.txt"}; // open file
    std::ofstream out_file {"copy.txt"};


    if (!in_file) { // check if file is open
        std::cerr << "File open error" << std::endl;
        return 1; // exit the program (main)
    }

    if (!out_file) { // check if file is open
        std::cerr << "File create error" << std::endl;
        return 1; // exit the program (main)
    }

    // formatted read and write
    std::string line{};
    while (std::getline(in_file, line)) { // read a line
        out_file << line << std::endl; // write a line
    } 

    // unformatted read and write
    char c;
    while (in_file.get(c)) { // read a character
        out_file.put(c); // write a character
    } 


    in_file.close();
    out_file.close();
    // once again, close the damn file, especially for output


    out_file.close(); // VERY IMPORTANT

    return 0;
}