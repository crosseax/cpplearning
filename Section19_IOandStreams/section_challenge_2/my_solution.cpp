// In responses.txt
// the first line is the correct answer
// they it's all student and answer pairs

// show everyone's score
// show the class average
// assume the file is properly formatted

/* sample output
Name    score
---
frank   5
moe     3
---
average 4
*/

#include <iostream>
#include <fstream>
#include <iomanip>

int main (void)
{
    std::ifstream ifile;
    ifile.open("responses.txt");
    if (!ifile) {
        std::cerr << "Problem opening file" << std::endl;
        return 1;
    }
    std::cout << "responses.txt is ready to go" << std::endl;
    
    std::string answers;
    std::getline(ifile, answers);

    std::string name;
    std::string response;
    double score {0};
    double total {0};
    int students {0};

    std::cout << std::setw(10) << std::left  << "Student" 
              << std::setw(5)  << std::right << "Score"
              << std::endl;

    std::cout << "===============" << std::endl;

    for (int i = 0; i < answers.length(); i++) {
        ifile >> name >> response;
        students++;
        score = 0;
        for (int j = 0; j < answers.length(); j++) {
            if (response.at(j) == answers.at(j)) {
                score++;
                total++;
            }
        }
        std::cout << std::setw(10) << std::left  << name 
                  << std::setw(5)  << std::right << score 
                  << std::endl;
    }
    
    std::cout << "===============" << std::endl;
    std::cout << std::setw(10) << std::left  << "Average" 
              << std::setw(5)  << std::right << std::setprecision(1) << std::fixed << (total / students)
              << std::endl;

    return 0;
}