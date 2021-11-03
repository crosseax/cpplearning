#include <iostream>
#include "Player.h" // which contains <string>

using namespace std;

void display_active_players();

int main (void)
{
    display_active_players(); // 0
    Player hero {"Hero"};
    display_active_players(); // 1

    { // a local block
        Player frank {"Frank"}; // this will be destroyed once going out of the block
        display_active_players(); // 2
    }

    display_active_players(); // 1, because frank is destroyed when out of the local block
    Player enemy {"Enemy", 100, 100};
    display_active_players(); // 2

    return 0;
}

void display_active_players(){
    cout << "Active players: " << Player::get_num_players() << endl;
}