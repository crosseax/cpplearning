#include <iostream>
#include "Movie.h"

// constructor implementation
Movie::Movie(std::string name, std::string rating, int watched)
    : name(name), rating(rating), watched(watched) {
}

// copy constructor implementation
Movie::Movie(const Movie &source)
    : Movie {source.name, source.rating, source.watched} {
}

// destructor implementation
Movie::~Movie(){
}

// display method implementation
void Movie::display() const {
    std::cout << name << ", " << rating << ", " << watched << std::endl;
}

