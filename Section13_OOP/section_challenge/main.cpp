#include <iostream>
#include <vector>
#include <string>
#include "Movielist.h"

using namespace std;


// helper functions
void increment_watched (Movielist &movielist, string name);
void add_movie (Movielist &movielist, string name, string rating, int watched);



int main (void)
{
    Movielist myMovies;
    myMovies.display();

    add_movie(myMovies, "Big", "PG-13", 2);
    add_movie(myMovies, "Star Wars", "PG", 5);
    add_movie(myMovies, "Cinderella", "PG", 7);

    myMovies.display();

    add_movie(myMovies, "Cinderella", "PG", 7);
    add_movie(myMovies, "Ice Age", "PG", 12);

    myMovies.display();

    increment_watched(myMovies, "Big");
    increment_watched(myMovies, "Ice Age");

    myMovies.display();

    increment_watched(myMovies, "XXX");

    return 0;
}



void increment_watched (Movielist &movielist, string name){
    if (movielist.increment_watched(name)) {
        cout << name << " watch incremented" << endl;
    } else {
        cout << name << " not found" << endl;
    }
}

void add_movie (Movielist &movielist, string name, string rating, int watched){
    if (movielist.add_movie(name ,rating, watched)){
        cout << name << " added" << endl;
    } else {
        cout << name << " already exists" << endl;
    }
}
