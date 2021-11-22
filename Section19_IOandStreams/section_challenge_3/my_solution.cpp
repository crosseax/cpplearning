#include <iostream>
#include <fstream>


// bool word_check(const std::string& word, const std::string& target) {
//     if (target.length() < word.length()) {
//         for (int i = 0; i < word.length(); i++) {
//             if (word.at(i) == target.at(0)) {
//                 for (int j = 0; j < target.length(); j++) {
//                     if (word.at(i + j) == target.at(j)) {

//                     }
//                 }
//             } else {
//                 return false;
//             }
//         }

//     } else {
//         return false;
//     }
// }

bool word_check(const std::string& wordToRead, const std::string& wordToFind) {
    std::size_t found = wordToRead.find(wordToFind); // string.find() returns a index
    if (found == std::string::npos) {
        return false;
    } else {
        return true;
    }
}

int main (void)
{
    std::ifstream ifile;
    ifile.open("hamlet.txt");
    if (!ifile) {
        std::cerr << "Problem opening the file" << std::endl;
        return 1;
    }

    int wordCount;
    std::string wordRead;
    int matchCount;
    std::string target;
    
    std::cout << "Enter the word you want to search: ";
    std::cin >> target;

    while (ifile >> wordRead) {
        wordCount++;
        if (word_check(wordRead, target)) {
            // std::cout << wordRead << " ";
            matchCount++;
        }
    }

    std::cout << "Total words read: " << wordCount << std::endl;
    std::cout << "Total (" << target << ") found: " << matchCount << std::endl; 


    



    return 0;
}