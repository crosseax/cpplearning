#include <iostream>
#include <string>
#include <vector>

using namespace std;

// pointer arithmetic only make sense when using with raw arrays


int main(void)
{
    // pointers equal only when point at the same address and type
    

    int scores[] {100, 95, 91, 88, 73, -1};
    int* scorePtr {scores};

    while (*scorePtr != -1){
        cout << *scorePtr << endl;
        scorePtr++;
    } // -1 is called a sentinel value, or terminator

    cout << "--------------" << endl;
    //same thing can be achieved like below 
    scorePtr = scores;
    while (*scorePtr != -1){
        cout << *scorePtr++ << endl;
    }

    // careful for the difference below
    // * has higher priority than +

    cout << "===== careful fore this part =====" << endl;
    scorePtr = scores;
    while (*scorePtr != 105){
        cout << (*scorePtr)++ << endl;
    }
    cout << "===== careful fore this part =====" << endl;

    cout << "--------------" << endl;

    string s1 {"frank"};
    string s2 {"frank"};
    string s3 {"james"};

    string* sp1 {&s1};
    string* sp2 {&s2};
    string* sp3 {&s1};

    cout << boolalpha;
    cout << "sp1 == sp2: " << (sp1 == sp2) << endl; // false
    cout << "sp1 == sp3: " << (sp1 == sp3) << endl; // true

    // now for the value after dereferencing

    cout << "*sp1 == *sp2: " << (*sp1 == *sp2) << endl; // true
    cout << "*sp1 == *sp3: " << (*sp1 == *sp3) << endl; // true

    cout << "now we do sp3 = &s3, so sp3 points at s3" << endl;
    sp3 = &s3;

    cout << "now for sp1 == sp3: " << (sp1 == sp3) << endl; // false
    cout << "--------------" << endl;

    char name[] {"CrosSea"}; // C-style string

    char* charPtr1 {nullptr};
    char* charPtr2 {nullptr};

    charPtr1 = &name[0]; // C
    charPtr2 = &name[4]; // S

    cout << "In the string " << name << ", " << *charPtr2 << " is " << (charPtr2 - charPtr1) << " characters away from " << *charPtr1 << endl;
    cout << "(charPtr2 - charPtr1) is " << (charPtr2 - charPtr1) << endl;
    
    cout << endl;
    
    return 0;
}