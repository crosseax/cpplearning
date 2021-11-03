#ifndef _MOVIELIST_H_
#define _MOVIELIST_H_
#include <string>
#include <vector>
#include "Movie.h"

class Movielist {
private:
    std::vector<Movie> movielist; 

public:
    Movielist();  // constructor
    ~Movielist(); // destructor

    bool add_movie(std::string name, std::string rating, int watched);
    bool increment_watched(std::string name);

    void display() const;
};



#endif