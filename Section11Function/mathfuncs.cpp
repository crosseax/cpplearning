#include <iostream>
#include <cmath>

using namespace std;

int main (void)
{
    double num {};

    cout << "Enter a number (double): ";
    cin >> num;

    cout << endl;

    cout << "The square root of " << num << " is " << sqrt(num) << endl;
    cout << "The cube root of " << num << " is " << cbrt(num) << endl;
    cout << "The sine (rad) of " << num << " is " << sin(num) << endl;
    cout << "The cosine (rad) of " << num << " is " << cos(num) << endl;
    cout << "The ceil of " << num << " is " << ceil(num) << endl;
    cout << "The floor of " << num << " is " << floor(num) << endl;
    cout << "The round of " << num << " is " << round(num) << endl;


    return 0;
}