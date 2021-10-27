#include <iostream> 
#include <vector> 
#include <string> 

using namespace std;

int main (void)
{
    int highScore {100};
    int lowScore {65};

    // Pointers to constants 
    // constants cannot be changed
    const int* scorePtr1 {&highScore};

    // *scorePtr1 = 86; // error
    scorePtr1 = &lowScore; // ok

    // Constant pointers
    // pointers cannot be change
    int* const scorePtr2 {&highScore};

    *scorePtr2 = 86; // error
    // scorePtr2 = &lowScore; // error

    // Constant pointers to constants
    // both cannot be changed
    const int* const scorePtr3 {&highScore};

    // *scorePtr3 = 86; // error
    // scorePtr3 = &lowScore; // error


    // pointer to constant NOT mean constant variable 
    // so below is still valid after pointer to constant like scorePtr1
    highScore = 90;

    // or below

    int num {10};

    const int* numPtr {&num};
    cout << *numPtr << endl;
    // *numPtr = 20; // no, you cannot change the value of num through pointer to constant
    num = 20; // yes
    cout << *numPtr << endl;

    

    return 0;
}