// section 6
// constants

/*****
 * Frank's cleaning service 
 * charges $30 per room
 * sales tax is 6%
 * estimates are valid for 30 days
 * 
*****/ 

#include <iostream>

using namespace std;

int main()
{
    cout << "Hello welcome to Frank's cleanning service." << endl;
    cout << endl;
    cout << "How many rooms would you like to be cleaned?" << endl;

    int numOfRooms {0};
    cin >> numOfRooms;

    const double price {30.00};
    const double taxRate {0.06};
    const int expiryDay {30};

    cout << "Estimate for cleaning service " << endl;
    cout << "Number of rooms: " << numOfRooms << endl;
    cout << "Price per room: $" << price << endl;
    cout << "Cleaning Cost: $" << numOfRooms * price << endl;
    cout << "Sale Tax: $" << price * numOfRooms * taxRate << endl;
    cout << "====================================" << endl;
    cout << "Total estimated cost: $" << numOfRooms * price + price * numOfRooms * taxRate << endl;
    cout << "This estimate is valid for " << expiryDay << " days" << endl;
    cout << endl;
    
    return 0;
}