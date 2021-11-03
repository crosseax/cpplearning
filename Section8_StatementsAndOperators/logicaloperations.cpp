#include <iostream>
#include <vector> 

using namespace std;

int main()
{
    // not! has higher precedence than and&&
    // and&& has higher precedence than or||


    cout << boolalpha;
    bool examp {false}; 

    examp =  13 < 12 || 10 > 14 && 11 < 10;
    cout << examp << endl;

    examp =  13 < 12 || 10 > 14 && 11 < 15;
    cout << examp << endl;

    examp =  13 < 15 || 10 > 14 && 11 < 15;
    cout << examp << endl;

    examp =  !(13 < 15 || 10 > 14) && 11 < 15;
    cout << examp << endl;

    return 0;
}

