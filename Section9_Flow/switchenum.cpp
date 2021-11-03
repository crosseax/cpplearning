#include <iostream>
#include <climits>

using namespace std;

int main()
{
    enum directions{
        left, right, up, down
    };

    directions heading {left}; // heading is a enumeration, init to left

    switch (heading)
    {
        case left:
            cout << "Going left" << endl;
            break;
            
        case right:
            cout << "Going right" << endl;
            break;

        case up:
            cout << "Going up" << endl;
            break; 

        case down:
            cout << "Going down" << endl;
            break;

        default:
            break;
    };

    int num {2147483647};

    cout << INT_MAX << endl;
    cout << num << endl;
    cout << num + 1 << endl;

    return 0;
}