#include <iostream>

using namespace std;

int main()
{
    cout << "Enter the width of the room: ";
    int roomWidth {0}; // its good to initialize variable even youre using it after the input
    cin >> roomWidth;

    cout << "Enter the length of the room: ";
    int roomLenght {0};
    cin >> roomLenght;

    cout << "The area of the room is " << roomWidth * roomLenght << " square meter" << endl;

    return 0;
}