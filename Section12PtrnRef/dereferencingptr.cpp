#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main (void)
{
    int score {100};
    int* scorePtr {&score};

    cout << *scorePtr << endl; // 100, this is dereferencing a ptr

    *scorePtr = 200;

    cout << *scorePtr << endl; // 200
    cout << score << endl; // 200

    cout << endl;

    double highTemp {100.8};
    double lowTemp {37.4};

    double* tempPtr {&highTemp};
    cout << *tempPtr << endl; // 100.8

    tempPtr = &lowTemp;
    cout << *tempPtr << endl; // 37.4
    
    cout << endl;

    string name {"Frank"};
    string* strPtr {&name};
    cout << &name << endl; // address
    cout << strPtr << endl; // address
    cout << *strPtr << endl; // Frank

    name = "James";

    cout << *strPtr << endl; // James

    cout << endl;

    vector<int> nums {};
    for (int i = 0; i < 5 ; i++){
        int num = i + 1;
        nums.push_back(num);
    }

    int* numPtr {&nums[0]};

    cout << numPtr << endl;

    for (auto num : nums){
        numPtr = &num;
        cout << num << " " << *numPtr << " " << numPtr << endl;
    }

    cout << endl;

    vector<string> stooges {"Larry", "Moe", "Curly"};
    vector<string>* stooPtr {nullptr};

    stooPtr = &stooges;

    cout << stooPtr << endl;
    cout << "First stooges: " << (*stooPtr).at(0) << endl;

    cout << "Stooges: ";
    for (auto stooge : *stooPtr){
        cout << stooge << " ";
    }

    cout << endl;

    return 0;
}