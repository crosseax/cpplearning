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

int calculate_scores (const std::string& response, const std::string answers) {
    int score {0};
    for (int i = 0; i < answers.length(); i++) {
        if (response.at(i) == answers.at(i)) {
            score++;
        }
    }
    return score;
}

void display_scores (const std::string name, int score) {
    std::cout << std::setw(10) << std::left  << name 
              << std::setw(5)  << std::right << score 
              << std::endl;
}

void show_title() {
    std::cout << std::setw(10) << std::left  << "Student" 
              << std::setw(5)  << std::right << "Score"
              << std::endl;    
}

void show_line() {
    // those two lines below == std::cout << "===============" << std::endl;
    std::cout << std::setw(15) << std::setfill('=') << "" << std::endl;
    std::cout << std::setfill(' ');
}

void display_average(int total, int students) {
    std::cout << std::setw(10) << std::left  
              << "Average" 
              << std::setw(5)  << std::right << std::setprecision(1) << std::fixed 
              << (static_cast<double>(total) / students)
              << std::endl;
}

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
    int score {0};
    int total {0};
    int students {0};

    show_title();
    show_line();

    for (int i = 0; i < answers.length(); i++) {
        ifile >> name >> response;
        students++;
        score = calculate_scores(response, answers);
        total += score;
        display_scores(name, score);
    }
    
    show_line();
    display_average(total, students);

    ifile.close();
    return 0;
}