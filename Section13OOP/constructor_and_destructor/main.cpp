#include <iostream>
#include <string>

using namespace std;

class Player {
private:
    string name;
    int health;
    int xp;

public:
    void set_name(string nameval){
        name = nameval;
    }

    // overload constructors
    Player(){
        cout << "No args constructor called" << endl;
    }
    Player(string name){
        cout << "String arg constructor called" << endl;
    }
    Player(string name, int health, int xp){
        cout << "Three args constructor called" << endl;
    }

    // destructor
    ~Player(){
        cout << "Destructor called for " << name << endl;
    }
};

int main (void)
{
    {
        Player slayer;
        slayer.set_name("Slayer");
    }
    // to put above into the block is because 
    // when the block end, or when going out of the scope
    // the destructor will automatically be called 

    {
        Player frank;
        frank.set_name("Frank");
        Player hero("Hero");
        hero.set_name("Hero");
        Player villain("Villain", 100, 12);
        villain.set_name("Villain");
    }
    // when the objects going out of scope
    // the destructor is called in the REVERSE order

    Player* enemyPtr {nullptr};
    enemyPtr = new Player;
    enemyPtr->set_name("Enemy");

    Player* bossPtr {nullptr};
    bossPtr = new Player("Boss", 1000, 3000);
    bossPtr->set_name("Level Boss");

    delete enemyPtr;
    delete bossPtr;

    return 0;
}