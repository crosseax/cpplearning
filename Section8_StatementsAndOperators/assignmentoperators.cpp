#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int num1 {10};
    int num2 {20};

    cout << "num1 is " << num1 << endl;
    cout << "num2 is " << num2 << endl;

    num1 = 100;
    num2 = num1 = 1000;

    cout << "num1 is " << num1 << endl;
    cout << "num2 is " << num2 << endl;

    return 0;
}