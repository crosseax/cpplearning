#ifndef _MYSTRING_H_
#define _MYSTRING_H_

class Mystring
{
    friend std::ostream& operator<<(std::ostream& os, const Mystring& rhs);
    friend std::istream& operator>>(std::istream& is, Mystring& rhs);
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

friend std::ostream& operator<<(std::ostream& os, const Mystring& rhsobj); // << Insertion operator overload
friend std::istream& operator>>(std::istream& is, Mystring& rhsobj); // >> Extraction operator overload

friend bool operator==(const Mystring& lhsobj, const Mystring& rhsobj);   // == Equal sign overload
friend bool operator!=(const Mystring& lhsobj, const Mystring& rhsobj);   // != Unequal sign overload
friend bool operator<(const Mystring& lhsobj, const Mystring& rhsobj);    // < Smaller sign overload
friend bool operator>(const Mystring& lhsobj, const Mystring& rhsobj);    // > Larger sign overload
friend Mystring operator-(const Mystring& obj); // -str Minus sign overload, tolower
friend Mystring operator+(const Mystring& lhsobj, const Mystring& rhsobj); // +str Plus sign overload, concatenate
friend Mystring operator+=(const Mystring& lhsobj, const Mystring& rhspbj); // +=str Plus-equal sign overload, concatenate
friend Mystring operator*(const Mystring& obj, const int times);            // * Multiply sign overload, repeat for int times


};

#endif