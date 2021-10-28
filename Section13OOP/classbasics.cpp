#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Player {
public:
    string name{};
    int health {};
    int xp {};

    void talk(string text){cout << name << " says " << text << endl;}
};


int main (void)
{
    Player frank;
    frank.name = "Frank";
    frank.health = 100;

    Player* enemyPtr {nullptr};
    enemyPtr = new Player;
    (*enemyPtr).name = "Enemy";
    enemyPtr->health = 100;
    enemyPtr->talk("Go commit death");
    delete enemyPtr;

    return 0;
}