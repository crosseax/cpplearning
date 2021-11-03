// sec 5
// basic I/O using cin and cout

#include <iostream>

using namespace std;

int main()
{
    cout << "Hello world!!" << endl;

    cout << "Hello";
    cout << "WORLD" << endl;
    cout << "HELLO WORLD!!!\n"; // this does not flush the buffer
    cout << "Hello\nOut\nThere";


    int num1;
    int num2;

    cout << "Enter an interger: ";
    cin >> num1; // cin by default takes input from the keyboard
    cout << "You entered " << num1 << endl;

    cout << "Enter another interger: ";
    cin >> num2;
    cout << "You entered " << num2 << " this time" << endl;

    cout << "So you entered " << num1 << " and " << num2 << endl;





    return 0;
}