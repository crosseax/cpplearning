#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main(void)
{
    int* intPtr {nullptr};
    intPtr = new int; // allocating an new integer on the heap

    cout << intPtr << endl; // address
    cout << *intPtr << endl; // garbage value

    *intPtr = 100;
    cout << *intPtr << endl;

    delete intPtr; // frees the allocated memory


    int* arrayPtr {nullptr};
    int size {};

    cout << "How big do you want the array: ";
    cin >> size;

    arrayPtr = new int[size];
    delete [] arrayPtr;

    cout << endl; 

    // see a example below

    int* intPtr2 {nullptr};
    intPtr2 = new int;
    cout << intPtr2 << endl; // address on heap
    delete intPtr2; // free the memo on heap

    // another one 

    size_t size2{0};
    double* tempPtr {nullptr};

    cout << "How many temps: ";
    cin >> size2;

    tempPtr = new double[size2];
    cout << tempPtr << endl;

    delete tempPtr; // free the memo on heap

    return 0;
}