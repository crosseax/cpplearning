#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main (void)
{
    int num {10};
    cout << "Value of num is: " << num << endl;
    cout << "sizeof of num is: " << sizeof num << endl; // 4 bytes to store a int
    cout << "Address of num is: " << &num << endl;

    cout << endl;

    int* p;
    cout << "Value of pointer p before initialization is: " << p << endl;
    cout << "Address of pointer p is: " << &p << endl;
    cout << "sizeof of pointer p is: " << sizeof p << endl;
    p = nullptr;
    cout << "Value of pointer p after initialization is: " << p << endl;

    cout << endl; 

    int* p1 {nullptr};
    double* p2 {nullptr};
    unsigned long long* p3 {nullptr};
    vector<string>* p4 {nullptr};
    string* p5 {nullptr};

    cout << "sizeof of p1 is " << sizeof p1 << endl;
    cout << "sizeof of p2 is " << sizeof p2 << endl;
    cout << "sizeof of p3 is " << sizeof p3 << endl;
    cout << "sizeof of p4 is " << sizeof p4 << endl;
    cout << "sizeof of p5 is " << sizeof p5 << endl;
    cout << "The pointer itself is  simple and always use the same sizeof" << endl;
    cout << "What they point to could be simple or complex" << endl;

    cout << endl;

    int score {10};
    double temp {100.8};

    int* scorePtr {nullptr};

    scorePtr = &score;

    cout << "Value of score is: " << score << endl;
    cout << "Address of score is: " << &score << endl;
    cout << "Value of pointer scorePtr is " << scorePtr << endl;

    cout << endl;
    return 0;
}