#include <iostream>
#include <string>
#include <vector>

using namespace std;

int* apply_all(const int* const arr1, size_t size1, const int* const arr2, size_t size2);
void print (const int* const arrPtr, size_t size);


int main (void)
{
    const size_t array1Size {5};
    const size_t array2Size {3};

    int array1 [] {1,2,3,4,5};
    int array2 [] {10,20,30};

    cout << "Array 1: ";
    print(array1, array1Size);

    cout << "Array 2: ";
    print(array2, array2Size);

    int* resultPtr {nullptr};
    resultPtr = apply_all(array1, array1Size, array2, array2Size);
    constexpr size_t resultSize {array1Size * array2Size};

    cout << "Result: ";
    print(resultPtr, resultSize);

    delete [] resultPtr;
    cout << endl;

    return 0;
}


int* apply_all(const int* const arr1, size_t size1, const int* const arr2, size_t size2){
    int* newArrPtr {nullptr};
    newArrPtr = new int [size1 * size2];

    const int* outerArrPtr {nullptr};
    const int* innerArrPtr {nullptr};
    int outerloop {};
    int innerloop {};

    // if (size1 < size2){
    //     outerArrPtr = arr1;
    //     outerloop = size1;
    //     innerArrPtr = arr2;
    //     innerloop = size2;
    // } else if (size2 < size1){
    //     outerArrPtr = arr2;
    //     outerloop = size2;
    //     innerArrPtr = arr1;
    //     innerloop = size1;
    // } else {
    //     outerArrPtr = arr1;
    //     outerloop = size1;
    //     innerArrPtr = arr2;
    //     innerloop = size2;
    // } 

    outerArrPtr = (size1 <= size2) ? arr1 : arr2;
    innerArrPtr = (size1 <= size2) ? arr2 : arr1;
    outerloop = (size1 <= size2) ? size1 : size2;
    innerloop = (size1 <= size2) ? size2 : size1;
    // reason for doing this, is that you wanna use shorter array for outer array, to potentially save heap memory during the loop

    int position {0};
    for (size_t i = 0; i < outerloop; i++){
        for (size_t j = 0; j < innerloop; j++){
            newArrPtr [position] = outerArrPtr[i] * innerArrPtr[j];
            position++;
        }
    }
    return newArrPtr;
}

void print (const int* const arrPtr, size_t size){
    cout << "[ ";
    for (size_t i = 0; i < size; i++){
        cout << arrPtr[i] << " "; 
        // or: cout << *(arrPtr + i) << " ";
    }
    cout << "]" << endl;
}