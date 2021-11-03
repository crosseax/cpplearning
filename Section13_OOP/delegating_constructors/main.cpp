// one common error of coding is duplicated codes

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

// write this first, (or you can wrote this below delegating constructors but it is not the best practice)
Player::Player(string nameval, int healthval, int xpval)
    : name {nameval}, health {healthval}, xp {xpval} {
        cout << "The constructor, name: " << name << endl;
}

// this is the delegating constructor
// so they will call the constructor that has three args, which is the one above
Player::Player()
    : Player {"None", 0, 0}{
        cout << "No args constructors, name: " << name << endl;
}

Player::Player(string nameval)
    : Player {nameval, 0, 0}{
        cout << "String(name) only constructors, name: " << name << endl;
}
// things above only works in the initialization lists
// so you cannot call the other constructors from the body in the delegating constructors
// also you CANNOT delegate to another constructor and provide initialization values to the class


int main (void)
{
    Player empty; // this use delegating constructor which then refer to the original constructor, so two couts
    Player frank {"Frank"}; // this use delegating constructor which then refer to the original constructor, so two couts
    Player slayer {"Slayer", 1000, 100}; // this only calls the original constructor, so only one cout

    // so when creating new objects, if using delegating constructor, both the bodies are going to be executed

    return 0;
}