#include <vector>
#include <iostream>
#include <string>

using namespace std;

class Player{
private:
    string name;
    int health;
    int xp;
public:
    // overloadrd constructors
    // Player();
    // Player(string nameval);
    Player(string nameval = "None", int healthval = 0, int xpval = 0);
};

// Player::Player()
//     : Player ("None", 0, 0){
//         cout << "No args constructor" << endl;
// }

// Player::Player(string nameval)
//     : Player (nameval, 0, 0){
//         cout << "String name arg constructor" << endl;
// }

Player::Player(string nameval, int healthval, int xpval)
    : Player (nameval, healthval, xpval){
        cout << "Three args constructor" << endl;
}

int main (void)
{
    Player empty;
    Player frank {"Frank"};
    Player hero {"Hero", 100};
    Player villain {"Villain", 100, 55};

    return 0;
}