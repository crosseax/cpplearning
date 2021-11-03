#include "Player.h"

// first to initialize the static variable
int Player::numPlayers {0}; 

// then implement the static functions
int Player::get_num_players() {
    return numPlayers;
}

std::string Player::get_name(){
    return name;
}

int Player::get_health(){
    return health;
}

int Player::get_xp(){
    return xp;
}

// constructor implementation
Player::Player(std::string nameval, int healthval, int xpval) 
    : name {nameval}, health {healthval}, xp {xpval} {
        numPlayers++; // increment numPlayers everytime creating new obj of this class
}

// copy constructor implementation
Player::Player(const Player &source)
    : Player {source.name, source.health, source.xp} {
}

// destructor implementation
Player::~Player(){
    --numPlayers; // decrement numPlayers everytime destroying the obj in this class
}