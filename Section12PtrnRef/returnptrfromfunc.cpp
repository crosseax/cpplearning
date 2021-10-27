#include <iostream> 
#include <vector>
#include <string>

using namespace std;

int* largest_of (int* intPtr1, int* intPtr2);
void display(const int* const array, size_t size);
int* create_array (size_t size, int initVal = 0);

int main(void)
{
    // type *function()
    int a {100};
    int b {200};

    int* largePtr {nullptr};
    cout << largePtr << endl;
    largePtr = largest_of(&a, &b);
    cout << largePtr << endl;
    cout << *largePtr << endl;

    cout << "--------------" << endl;

    int* myArrPtr {nullptr};
    size_t size;
    int initVal {};

    cout << "How many integers would you like to allocate: ";
    cin >> size;
    cout << "What value you want them to initialized to: ";
    cin >> initVal;

    myArrPtr = create_array(size, initVal);
    cout << myArrPtr << endl; // this address is in the heap
    display(myArrPtr, size);

    delete [] myArrPtr;

    return 0;
}

int* largest_of (int* intPtr1, int* intPtr2){
    if (*intPtr1 > *intPtr2){
        return intPtr1;
    } else {
        return intPtr2;
    }
}

void display(const int* const array, size_t size){
    for (size_t i = 0; i < size; i++){
        cout << array[i] << " ";
    }
    cout << endl;
}

// allocate memory dynamically inside a function 
// and return the address of that memory
int* create_array (size_t size, int initVal){
    int* newStoragePtr {nullptr};
    newStoragePtr = new int[size];
    for (size_t i = 0; i < size; i++){
        *(newStoragePtr + i) = initVal;
    }
    return newStoragePtr;
}
