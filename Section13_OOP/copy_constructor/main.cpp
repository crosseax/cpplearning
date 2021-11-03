// when copying constructors, the BEST PRACTICE is below
// provide a copy constructor when your class has raw pointer members
// provide the copy constrctor with a *const reference* parameter
// use STL classes as they already provide copy constructors
// avoid using raw pointer data members ii possible

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
    string get_name() {return name;}
    int get_health() {return health;}
    int get_xp() {return xp;}
    Player(string nameval = "None", int healthval = 0, int xpval = 0);

    // Copy constructor
    Player(const Player &source);
    // Destructor
    ~Player() {cout << "Destructor is called for " + name << endl;}
};

Player::Player(string nameval, int healthval, int xpval)
    : name {nameval}, health {healthval}, xp {xpval}{
        cout << "Three args constructor for " + name << endl;
}

Player::Player(const Player &source)
    // : name {source.name}, health {source.health}, xp {source.xp}{
    // or do the delegating way like below, so all copying objects will execute the code of both this block and the block above
    : Player {source.name, source.health, source.xp}{
        cout << "Copy constructor of " << source.name << endl;
}


void display_player(Player plyr);



int main (void)
{
    Player empty;
    display_player(empty); // display the copy because in the display function it is passed by value

    Player frank {"Frank"};
    Player hero {"Hero", 100};
    Player villain {"Villain", 200, 55};

    cout << endl;

    Player example {"XXXXXX", 50, 25};

    Player copyExample {example}; // first copy
    display_player(copyExample); // another copy that is copying the value of copyExample

    // destruction called for displayed copy
    // destruction called for copyExample
    // destruction called for everything


    return 0;
}


void display_player(Player plyr){
    cout << "Name: " << plyr.get_name() << endl;
    cout << "Health: " << plyr.get_health() << endl;
    cout << "XP: " << plyr.get_xp() << endl;
}