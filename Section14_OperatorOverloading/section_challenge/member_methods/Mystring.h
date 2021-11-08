#ifndef _MYSTRING_H_
#define _MYSTRING_H_

class Mystring
{
    friend std::ostream& operator<<(std::ostream& os, const Mystring& rhs); // << Insertion operator overload
    friend std::istream& operator>>(std::istream& is, Mystring& rhs);       // >> Extraction operator overload
private:
    char* str;
public:
    Mystring();                                 // No args constructor
    Mystring(const char* s);                    // Overloaded constructor
    Mystring(const Mystring& source);           // Copy constructor
    Mystring(Mystring&& source);                // Move constructor
    ~Mystring();                                // Destructor

    Mystring& operator=(const Mystring& rhs);   // Copy assignment
    Mystring& operator=(Mystring&& rhs);        // Move assignment


    // Member methods
    void display() const;
    int get_length() const;
    const char* get_str() const;

// Now the fun part
// as member methods

friend std::ostream& operator<<(std::ostream& os, Mystring& rhs);  // << Insertion operator overload
friend std::istream& operator>>(std::istream& is, Mystring& rhs);        // >> Extraction operator ovverload

Mystring operator-() const;   // -str Minus sign overload, tolower
Mystring operator+(const Mystring& rhs) const;  // +str Plus sign overload, concatenate
bool operator==(const Mystring& rhs) const;     // == Equal sign overload
bool operator!=(const Mystring& rhs) const;     // != Unequal sign overload
bool operator<(const Mystring& rhs) const;      // < Smaller sign overload
bool operator>(const Mystring& rhs) const;      // > Larger sign ovverload
Mystring& operator+=(const Mystring& rhs);      // +=str Plus-equal sign overload, concatenate then assign
Mystring operator*(int times) const;            // * Multiply sign overload, repeat for int times
Mystring& operator*=(int n);                // *= Multiply sign overload, repeat then assign
Mystring operator++(int);         // ++ Plus-plus sign overload, post-increment, toupper
Mystring& operator++();             // ++ Plus-plus sign overload, pre-increment, toupper

};

#endif