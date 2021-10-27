#include <iostream>

using namespace std;

int main()
{
    int roomWidth {0}; // its good to initialize variable even youre using it after the input
    int roomLenght {0};

    cout << "Enter the width of the room: ";
    cin >> roomWidth;

    cout << "Enter the length of the room: ";
    cin >> roomLenght;

    cout << "The area of the room is " << roomWidth * roomLenght << " square meter" << endl;

    return 0;
}