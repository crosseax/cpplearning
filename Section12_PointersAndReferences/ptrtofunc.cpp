#include <iostream>
#include <string>
#include <vector>

using namespace std;

void double_data (int* intPtr);
void swap(int* aPtr, int* bPtr);
void display(const vector<string>* const vPtr);
void display(const int* arrPtr, int const sentinel);

int main (void)
{
    int num {10};
    cout << num << endl;
    double_data(&num);
    cout << num << endl;

    cout << "----------------" << endl;

    int value {10};
    int* intPtr {nullptr};
    cout << "value: " << value << endl;
    double_data(&value);
    cout << "value: " << value << endl;

    cout << "----------------" << endl;

    intPtr = &value;
    double_data(intPtr);
    cout << "value: " << value << endl;

    cout << "----------------" << endl;

    int x {100}, y {200};
    cout << "x: " << x << endl;
    cout << "y: " << y << endl;

    swap(&x, &y);

    cout << "x: " << x << endl;
    cout << "y: " << y << endl;

    cout << "----------------" << endl;

    vector<string> stooges {"Larry", "Moe", "Curly"};
    display(&stooges);

    cout << "----------------" << endl;

    int scores[] {100, 98, 93, 87, 81, 75, -1};
    display(scores, -1);


    return 0;
}

void double_data (int* intPtr){
    *intPtr *= 2;
}

void swap(int* aPtr, int* bPtr){
    int temp = *aPtr;
    *aPtr = *bPtr;
    *bPtr = temp;
}

void display(const vector<string>* const vPtr){
    for (auto str : *vPtr){
        cout << str << " ";
    }
    cout << endl;
}

void display(const int* arrPtr, int const sentinel){
    while (*arrPtr != sentinel){
        cout << *arrPtr++ << endl;
    }
    cout << endl;
}
