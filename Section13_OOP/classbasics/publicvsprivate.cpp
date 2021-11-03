#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Player{
private:
    // when trying to access private things, compiler error
    // even just cout << privatestuff << endl;
    string name {"Player"};
    int health;
    int xp;

public:
    void talk(string text){cout << name << " says " << text << endl;}
    bool isdead();
};

int main (void)
{
    Player frank;
    frank.talk("hello");
    return 0;
}