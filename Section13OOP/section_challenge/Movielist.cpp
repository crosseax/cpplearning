#include <iostream>
#include "Movielist.h"

Movielist::Movielist () {

}


Movielist::~Movielist() {

}

// This is where the work of yourself come in
// to implement those methods

bool Movielist::add_movie(std::string name, std::string rating, int watched) {
    for (const Movie movie : movielist) {
        if (movie.get_name() == name) {
            return false;
        } 
    }
    Movie temp {name, rating, watched};
    movielist.push_back(temp);
    return true;
}


bool Movielist::increment_watched(std::string name) {
    for (Movie &movie : movielist) {
        if (movie.get_name() == name) {
            movie.increment_watched();
            return true;
        }
    }
    return false;
}


void Movielist::display() const {
    if (movielist.size() == 0) {
        std::cout << "No movies in the list. \n" << std::endl;
    } else {
        std::cout << "=====================" << std::endl;
        for (auto movie : movielist) {
            movie.display();
        }
        std::cout << "=====================" << std::endl;
    }
}