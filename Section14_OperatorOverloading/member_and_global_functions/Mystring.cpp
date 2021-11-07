#include <cstring>
#include <iostream>
#include "Mystring.h"


// no args constructor
Mystring::Mystring ()
    : str {nullptr} {
        str = new char[1];
        *str = '\0';
}

// Overloaded constructor
Mystring::Mystring (const char* s)
    : str {nullptr} {
        if (s == nullptr) {
            str = new char[1];
            *str = '\0';
        } else {
            str = new char[std::strlen(s) + 1];
            std::strcpy(str, s);
        }
}

// Copy constructor
Mystring::Mystring (const Mystring &source)
    : str {nullptr} {
        str = new char[std::strlen(source.str) + 1];
        std::strcpy(str, source.str);
        // std::cout << "Copy constructor" << std::endl;
}

// Move constructor
Mystring::Mystring (Mystring &&source)
    : str(source.str) {              // stealing the pointer
        source.str = nullptr;        // nullout the original pointer to avoid memory leak
        // std::cout << "Move constructor" << std::endl;
    }


// Make lowercase
Mystring Mystring::operator-() const {
    char* buff = new char[std::strlen(str) + 1];    // alloc heap memory
    std::strcpy(buff, str);                         // copy targeted str into buff
    for (size_t i = 0; i < std::strlen(buff); i++){ // loop and change to lower
        buff[i] = std::tolower(buff[i]);
    }
    Mystring temp {buff};   // create new obj containing the lowered str
    delete [] buff;         // free the heap memory
    return temp;            // return that obj
}

// Concatenate operator 
Mystring Mystring::operator+(const Mystring &rhs) const {
    char* buff = new char[std::strlen(str) + std::strlen(rhs.str) + 1]; // alloc heap memory that fits both original and concatenated str
    std::strcpy (buff, str);        // copy that original into that heap memory
    std::strcat (buff, rhs.str);    // concatenate the rhs one to this
    Mystring temp {buff};           // create new obj containing the result
    delete [] buff;                 // free heap memory
    return temp;                    // return the result obj
}

// Equality operator
bool Mystring::operator==(const Mystring &rhs) const {
    return (std::strcmp(str, rhs.str) == 0);
}




// Destructor
Mystring::~Mystring(){
    if (str == nullptr){
        // std::cout << "Destructor for nullptr" << std::endl;
    } else {
        // std::cout << "Destructor for " << str << std::endl;
    }
    delete [] str;
}



// Copy assignment
Mystring &Mystring::operator = (const Mystring &rhs) {
    std::cout << "Using Copy assignment for " << rhs.str << std::endl;
    if (this == &rhs) {
        return *this;
    }
    delete [] this->str;                        // clear the pointer
    str = new char[std::strlen(rhs.str) + 1];   // allocate the memory on heap thats the same length as rhs string
    std::strcpy (this->str, rhs.str);           // doing copy assignment
    return *this;                               // return the obj by reference
}


// Move assignment
Mystring &Mystring::operator = (Mystring &&rhs) {
    std::cout << "Using Move assignment for " << rhs.str << std::endl;
    if (this == &rhs) {     // self assignment
        return *this;       // return current object
    }
    delete [] this->str;    // deallocate current storage
    str = rhs.str;          // steal the pointer
    rhs.str = nullptr;      // null out the rhs object
    return *this;           // return the obj by reference
}



// Methods implementation
void Mystring::display() const {
    std::cout << "string: " << str << ", length: " << get_length() << std::endl;
}

int Mystring::get_length() const {
    return std::strlen(str);
}

const char* Mystring::get_str() const {
    return str;
}
