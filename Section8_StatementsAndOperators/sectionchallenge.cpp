#include <iostream>
#include <vector>

using namespace std;

int main ()
{
    int cents {0};
    cout << "Enter the cents amount here: ";
    cin >> cents;

    int remains {0};

    int dollars {0};
    int quarters {0};
    int dimes {0};
    int nickels {0};
    int pennies {0};

    if (cents >= 0) {
        dollars = cents / 100;
        remains = cents % 100;

        quarters = remains / 25;
        remains = remains % 25;

        dimes = remains / 10;
        remains = remains % 10;

        nickels = remains / 5;
        remains = remains % 5;

        pennies = remains / 1;
        remains = remains % 1;
    }; 

    cout << "You can provide this change as follows: " << endl;
    cout << "dollars: " << dollars << endl;
    cout << "quarters: " << quarters << endl;
    cout << "dimes: " << dimes << endl;
    cout << "nickels: " << nickels << endl;
    cout << "pennies: " << pennies << endl;

    

    return 0;
}