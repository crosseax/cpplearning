#include <iostream>
#include <vector>

using namespace std;

int main(){

    // switch (integer_control_expr)
    // {
    // case expression1:
    //     statement1
    //     break;

    // case expression2:
    //     statement2
    //     break;
    
    // default:
    //     break;
    // }

    char letterGrade {};
    cout << "Enter the letter grade you expect on the exam: ";
    cin >> letterGrade;

    switch (letterGrade)
    {
        case 'a':
        case 'A':
            cout << "You need 90 or above" << endl;
            break;

        case 'b':
        case 'B':
            cout << "You need 80-89" << endl;
            break;

        case 'c':
        case 'C':
            cout << "You need 70-79" << endl;
            break;

        case 'd':
        case 'D':
            cout << "You need 60-69" << endl;
            break;

        case 'f':
        case 'F':
        {
            char confirm {}; // once declared a variable, we need to put things below in the blue block{}
            cout << "Are you sure? (Y/N)";
            cin >> confirm;

            if (confirm == 'y' || confirm == 'Y'){
                cout << "Ok, be you" << endl;
            } else if (confirm == 'n' || confirm == 'N'){
                cout << "Good, think again" << endl;
            } else {
                cout << "Get your mind straight" << endl;
            }
            break;
        }
            

        default:
            cout << "Please enter a valid letter grade" << endl;
            break;
    }

    return 0;
}