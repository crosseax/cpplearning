// a solution to << operator behaving the different in c++20 standard
// also a question that is in the Section14

#include <iostream>
#include <cstring>

class Example 
{
private:
    char* str;
public: 
    // no args constructor
    Example ()
        : str {nullptr} {
            str = new char[1];
            *str = '\0';
    }

    // Overloaded constructor
    Example (const char* s)
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
    Example (const Example& source)
        : str {nullptr} {
            str = new char[std::strlen(source.str) + 1];
            std::strcpy(str, source.str);
    }

    // Copy assignment
    Example& operator = (const Example& rhs) {
        std::cout << "Using Copy assignment for " << rhs.str << std::endl;
        if (this == &rhs) {
            return *this;
        }
        delete [] this->str;                        // clear the pointer
        str = new char[std::strlen(rhs.str) + 1];   // allocate the memory on heap thats the same length as rhs string
        std::strcpy (this->str, rhs.str);           // doing copy assignment
        return *this;                               // return the obj by reference
    }

    // Destructor
    ~Example(){
        if (str == nullptr){
            // std::cout << "Destructor for nullptr" << std::endl;
        } else {
            // std::cout << "Destructor for " << str << std::endl;
        }
        delete [] str;
    }



    friend std::ostream& operator<<(std::ostream& os, const Example& rhs){
        os << rhs.str;
        return os;
    }

    friend std::istream& operator>>(std::istream& is, Example& rhs){
        char buff [100]; 
        is >> buff;      
        rhs = Example {buff};         
        return is;
    }

    
};

int main (void)
{
    using namespace std;
    Example strep;

    cout << "Enter the third stooge's first name: ";
    cin >> strep;

    cout << "You entered: " << strep << endl;
    
    return 0;
}