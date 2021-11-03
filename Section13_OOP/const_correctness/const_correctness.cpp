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
    string get_name() const; // this const grants compiler that you wont change anything so simple return could work
    void set_name(string nameval){name = nameval;}

    // overloaded constructors
    Player();
    Player(string nameval);
    Player(string nameval, int healthval, int xpval);
};

string Player::get_name() const { // heres the implementation of the const-correctness method in the class
    return name;
}


Player::Player()
    : Player {"None", 0, 0}{
}

Player::Player(string nameval)
    : Player {nameval, 0, 0}{
}

Player::Player(string nameval, int healthval, int xpval)
    : name {nameval}, health{healthval},xp{xpval}{
}

void display_player_name (const Player &p){
    cout << p.get_name() << endl;
}


int main (void)
{
    Player villain {"Villain", 100, 55};
    const Player hero {"Hero", 200, 50}; // since this is a const obj

    cout << villain.get_name() << endl;
    cout << hero.get_name() << endl; // require const above in the function to work

    display_player_name(villain);
    display_player_name(hero); // same reason as above
    

    return 0;
}

