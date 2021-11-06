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
        std::cout << "Copy constructor" << std::endl;
}

// Move constructor
Mystring::Mystring(Mystring &&source)
    : str(source.str) {              // stealing the pointer
        source.str = nullptr;        // nullout the original pointer to avoid memory leak
        std::cout << "Move constructor" << std::endl;
    }


// Destructor
Mystring::~Mystring(){
    if (str == nullptr){
        std::cout << "Destructor for nullptr" << std::endl;
    } else {
        std::cout << "Destructor for " << str << std::endl;
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
