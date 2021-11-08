#include <iostream>
#include <cstring>
#include "Mystring.h"


// No args constructor
Mystring::Mystring()
    : str {nullptr} {
        str = new char[1];
        *str = '\0';
}

// Overloaded constructor
Mystring::Mystring(const char* s)
    : str {nullptr} {
        if (s == nullptr) {
            str = new char[1];
            *str = '\0';
        } else {
            str = new char[strlen(s) + 1];
            strcpy(str, s);
        }
}

// Copy constructor
Mystring::Mystring(const Mystring& source)
    : str {nullptr} {
        str = new char[strlen(source.str) + 1];
        strcpy(str, source.str);
        // std::cout << "Copy constructor called" << std::endl;
}

// Move constructor
Mystring::Mystring(Mystring&& source)
    : str {source.str} {
        source.str = nullptr;
        // std::cout << "Move constructor called" << std::endl;
}

// Destructor
Mystring::~Mystring() {
    delete [] str;
}

// Copy assignment
Mystring& Mystring::operator=(const Mystring& rhs) {
    // std:: << "Using copy assignment" << std::endl;
    if (this == &rhs) {
        return *this;
    }
    delete [] str;
    str = new char[strlen(rhs.str) + 1];
    strcpy(str, rhs.str);
    return *this;
}

// Move assignment
Mystring& Mystring::operator=(Mystring&& rhs) {
    // std:: << "Using move assignment" << std::endl;
    if (this == &rhs) {
        return *this;
    }
    delete [] str;
    str = rhs.str;
    rhs.str = nullptr;
    return *this;
}


// Member methods
void Mystring::display() const {
    std::cout << "String: " << str << ". Length: " << get_length() << std::endl; 
}

int Mystring::get_length() const {
    return std::strlen(str);
}

const char* Mystring::get_str() const {
    return str;
}



// Now the fun part

// << Insertion operator overload
std::ostream& operator<<(std::ostream& os, const Mystring& rhsobj) {
    os << rhsobj.str;
    return os;
}

// >> Extraction operator overload
std::istream& operator>>(std::istream& is, Mystring& rhsobj) {
    char* buff = new char[1000];
    is >> buff;
    rhsobj = Mystring {buff};
    delete [] buff;
    return is;
}


// == Equal sign overload
bool operator==(const Mystring& lhsobj, const Mystring& rhsobj) {
    return (std::strcmp(lhsobj.str, rhsobj.str) == 0);
}

// != Unequal sign overload
bool operator!=(const Mystring& lhsobj, const Mystring& rhsobj) {
    return (std::strcmp(lhsobj.str, rhsobj.str) != 0);
}

// < Small sign overload
bool operator<(const Mystring& lhsobj, const Mystring& rhsobj) {
    return (std::strcmp(lhsobj.str, rhsobj.str) < 0);
}

// > Larger sign overload
bool operator>(const Mystring& lhsobj, const Mystring& rhsobj) {
    return (std::strcmp(lhsobj.str, rhsobj.str) > 0);
}

// -str Minus sign overload, tolower
Mystring operator-(const Mystring& obj) {
    char* buff = new char[std::strlen(obj.str) + 1];
    std::strcpy(buff, obj.str);
    for (size_t i = 0; i < std::strlen(buff); i++) {
        buff[i] = std::tolower(buff[i]);
    }
    Mystring tmp {buff};
    delete [] buff;
    return tmp;
}

// +str Plus sign overload, concatenate
Mystring operator+(const Mystring& lhsobj, const Mystring& rhsobj) {
    char* buff = new char[std::strlen(lhsobj.str) + std::strlen(rhsobj.str) + 1];
    std::strcpy(buff, lhsobj.str);
    std::strcat(buff, rhsobj.str);
    Mystring tmp {buff};
    delete [] buff;
    return tmp;
}


// +=str Plus-equal sign overload, concatenate then assign, based on + overload
Mystring& operator+=(Mystring& lhsobj, const Mystring& rhsobj) {
    lhsobj = lhsobj + rhsobj;
    return lhsobj;
}



// * Multiply sign overload, repeat for int times
Mystring operator*(const Mystring& obj, const int times) {
    char* buff = new char[std::strlen(obj.str) * times + 1];
    std::strcpy(buff, obj.str);
    for (int i = 0; i < times - 1; i++) {
        std::strcat(buff, obj.str);
    }
    Mystring tmp {buff};
    delete [] buff;
    return tmp;
}

// A cleaner code for * sign overload
// Mystring operator*(const Mystring& obj, const int times) {
//     Mystring tmp;
//     for (int i = 0; i < times; i++){
//         tmp = tmp + obj;
//     }
//     return tmp;
// }

// *= Multiply sign overload, repeat then assign, based on * overload
Mystring& operator*=(Mystring& obj, const int times) {
    obj = obj * times;
    return obj;
}

// ++ Plus-plus sign overload, post-increment, toupper, based on pre-increment
Mystring operator++(Mystring& obj, int) {
    Mystring tmp {obj};
    ++obj; // make sure to call pre-increment
    return tmp;
}

// ++ Plus-plus sign overload, pre-increment, toupper
Mystring& operator++(Mystring& obj) {
    for (size_t i = 0; i < std::strlen(obj.str); i++) {
        obj.str[i] = std::toupper(obj.str[i]);
    }
    return obj;
}

