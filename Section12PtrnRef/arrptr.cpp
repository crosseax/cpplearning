#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main (void)
{
    int scores[] {100, 95, 89, 77};
    cout << scores << endl; // address
    cout << *scores << endl; // first element
    // since the arr address is the same as the first element in it
    // dereferencing an arr is the same as going to the address of its first element
    cout << endl;

    int* scorePtr {scores};
    cout << scorePtr << endl; // same address
    cout << *scorePtr << endl; // same first element
    cout << endl;

    cout << "Array subscript notation ---------" << endl;
    cout << scores[0] << endl;
    cout << scores[1] << endl;
    cout << scores[2] << endl;
    cout << scores[3] << endl;
    cout << endl;

    cout << "Pointer subscript notation ---------" << endl;
    cout << scorePtr[0] << endl;
    cout << scorePtr[1] << endl;
    cout << scorePtr[2] << endl;
    cout << scorePtr[3] << endl;
    // above is the same as showing arr.at()
    // arr in C++ is a lie
    cout << endl;

    cout << "Pointer arrithmetic ---------" << endl;
    cout << scorePtr << endl; // ptr address
    cout << (scorePtr + 1) << endl; // address increment by four
    cout << (scorePtr + 2) << endl; // cuz we adding one int size to ptr mem
    cout << (scorePtr + 3) << endl; // which is 4 bytes
    cout << endl;

    cout << "Pointer offset notation ---------" << endl;
    cout << *scorePtr << endl; // you can make sense of this now
    cout << *(scorePtr + 1) << endl; // just think of ptrs as arrows
    cout << *(scorePtr + 2) << endl; 
    cout << *(scorePtr + 3) << endl; 
    cout << endl;

    cout << "Array offset notation ---------" << endl;
    cout << *scores << endl; 
    cout << *(scores + 1) << endl; 
    cout << *(scores + 2) << endl; 
    cout << *(scores + 3) << endl; 


    return 0;
}