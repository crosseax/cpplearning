#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Player{
private:
    string name;
    int health;
    int xp;
public:
    Player();
    Player(string nameval);
    Player(string nameval, int healthval, int xpval);
};

// constructor initialization list done like below

Player::Player()
    : name {"None"}, health {0}, xp {0} {
}

Player::Player(string nameval)
    : name {nameval} , health {0}, xp {0} {
}

Player::Player(string nameval, int healthval, int xpval)
    : name {nameval}, health {healthval}, xp {xpval} {
}

// the order in after : does not matter
// the order is matter in the declaration of the class attributes, so from line 9 - 11
// the best practice is just to keep them the same


Player::Player():
    name {"None"}, health {0}, xp {0} {};


int main (void)
{
    Player empty;
    Player frank {"Frank"};
    Player slayer {"Slayer", 1000, 100};
    return 0;
}