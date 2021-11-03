// global variables are automatically initialized to 0

#include <iostream>

using namespace std;

int age {18}; // global variable

int main()
{
    cout << age << endl;

    int age {25};

    cout << age << endl;

    return 0;
}