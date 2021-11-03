#ifndef _PLAYER_H_
#define _PLAYER_H_
#include <string>



class Player {
private:

    static int numPlayers; // since its static, it does not belong to he object, it belongs to the class

    std::string name;
    int health;
    int xp;
    

public:

    static int get_num_players(); // static functions only have access to the static variable

    std::string get_name();
    int get_health();
    int get_xp();
    // constructor
    Player(std::string nameval = "None", int healthval = 0, int xpval = 0);
    // copy constructor
    Player(const Player &source);
    // destructor
    ~Player();


};


#endif