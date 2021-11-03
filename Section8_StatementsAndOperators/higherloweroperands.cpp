#include <vector>
#include <iostream>

using namespace std;

int main() 
{
    // int total {100};
    // int amount {8};

    // double average {0.0};

    // average = total / amount;
    // cout << average << endl; // 12, because int / int = int

    // average = static_cast<double>(total) / amount;
    // cout << average << endl; // 12.5, because total is now double, double / int = double



    // example 
    int sum {};
    int num1 {}, num2 {}, num3 {}; // all init to 0
    double mean {};
    const int count {3};

    cout << "Enter 3 integers seperated by spaces: ";
    cin >> num1 >> num2 >> num3;

    sum = num1 + num2 + num3;
    mean = static_cast<double>(sum) / count;

    cout << "The three numbers are: " << num1 << ", " << num2 << ", " << num3 << endl;
    cout << "Sum: " << sum << endl;
    cout << "Mean: " << mean << endl;

    return 0;
}