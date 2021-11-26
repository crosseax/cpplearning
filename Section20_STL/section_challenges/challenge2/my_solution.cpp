// Section 20
// Challenge 2
// Lists

#include <iostream>
#include <list>
#include <string>
#include <cctype>
#include <iomanip>
#include <limits>

class Song {
    friend std::ostream& operator<<(std::ostream& os, const Song& s);
    std::string name;
    std::string artist;
    int rating;
public:
    Song() = default;
    Song(std::string name, std::string artist, int rating)
            : name{name}, artist{artist}, rating{rating} {}
    std::string get_name() const {
        return name;
    }
    std::string get_artist() const {
        return artist;
    }
    int get_rating() const {
        return rating;
    }
    
    bool operator<(const Song& rhs) const  {
        return this->name < rhs.name;
    }
    
    bool operator==(const Song& rhs) const  {
        return this->name == rhs.name;
    }
};

std::ostream& operator<<(std::ostream& os, const Song& s) {
    os << std::setw(20) << std::left << s.name
       << std::setw(30) << std::left << s.artist
       << std::setw(2) << std::left << s.rating;
       return os;
}

void display_menu() {
    std::cout << "\n===============================================" << std::endl;
    std::cout << "F - Play First Song" << std::endl;
    std::cout << "N - Play Next song" << std::endl;
    std::cout << "P - Play Previous song" << std::endl;
    std::cout << "A - Add and play a new Song at current location" << std::endl;
    std::cout << "L - List the current playlist" << std::endl;
    std::cout << "===============================================" << std::endl;
    std::cout << "Enter a selection (Q to quit): ";
}

void enter_choice() {
    std::cout << "Enter a selection (D to show menu, Q to quit): ";
}

void play_current_song(const Song& song) {
    std::cout << "\nPlaying:\n" << song << "\n" << std::endl;
}

void display_playlist(const std::list<Song>& playlist, const Song& current_song) {
    std::cout << "\n===Playlist===" << std::endl;
    for (const Song& song : playlist) {
        std::cout << song << std::endl;
    }
    std::cout << "==============" << std::endl;
}

void add_song(std::list<Song>& playlist, std::list<Song>::iterator& current_song) {
    std::string name;
    std::string artist;
    int rating {0};
    Song newSong;

    std::cout << "Enter the name of the song to add: ";
    std::cin.get();
    std::getline(std::cin, name);

    std::cout << "Enter the artist of the song to add: ";
    std::getline(std::cin, artist);

    do {
        std::cout << "Enter the rating of the song to add (1 - 5): ";
        std::cin >> rating;
    } while (rating < 1|| (rating > 5));

    newSong = {name, artist, rating};

    if (current_song != playlist.end()){
        playlist.insert(current_song, newSong);
    }

    std::cout << "\nYou added song [" << newSong.get_name() << "] by artist ["
              << newSong.get_artist() << "] \n" << std::endl;
}


int main() {

    std::list<Song> playlist{
            {"God's Plan",        "Drake",                     5},
            {"Never Be The Same", "Camila Cabello",            5},
            {"Pray For Me",       "The Weekend and K. Lamar",  4},
            {"The Middle",        "Zedd, Maren Morris & Grey", 5},
            {"Wait",              "Maroone 5",                 4},
            {"Whatever It Takes", "Imagine Dragons",           3}          
    };
    
    std::list<Song>::iterator current_song = playlist.begin();

    bool done = false;
    display_menu();

    do {
        char choice {};
        std::cin >> choice;

        switch (std::tolower(choice)) {
            case 'd':
                display_menu();
                break;

            case 'q': // quit done
                done = true;
                break;
            
            case 'f': // first song done
                current_song = playlist.begin();
                play_current_song(*current_song);
                enter_choice();
                break;

            case 'n': // next sone done
                if (*current_song == playlist.back()){
                    current_song = playlist.begin();
                } else {
                    current_song++;
                }
                play_current_song(*current_song);
                enter_choice();
                break;

            case 'p': // previous song done
            if (*current_song == playlist.front()){
                    current_song = playlist.end();
                    current_song--;
                } else {
                    current_song--;
                }
                play_current_song(*current_song);
                enter_choice();
                break;

            case 'l': // list playlist done
                display_playlist(playlist, *current_song);
                play_current_song(*current_song);
                enter_choice();
                break;

            case 'a': // add song before playing song
                add_song(playlist, current_song);
                enter_choice();
                break;

            default:
                display_menu();
                break;
        }
        
    } while (!done);

    std::cout << "Thanks for listening!" << std::endl;
    return 0;
}