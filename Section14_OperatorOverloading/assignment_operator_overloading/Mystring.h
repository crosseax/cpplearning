#ifndef _MYSTRING_H_
#define _MYSTRING_H_

class Mystring {
private:
    char* str;
public:
    Mystring();                         // no args constructor
    Mystring(const char* s);            // overloaded constructor
    Mystring(const Mystring &source);   // copy constructor
    Mystring (Mystring &&source);       // move constructor
    ~Mystring();                        // destructor

    // Copy assignment
    Mystring &operator = (const Mystring &rhs); 
    // in this case, we are overloading the "=" equal sign operator

    // Move assignment
    Mystring &operator = (Mystring &&rhs);
    // in this case, its a R-value

    void display() const;
    int get_length() const;
    const char* get_str() const;
};



#endif // _MYSTRING_H