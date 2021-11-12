#include <iostream>

// if need to copy a derived obj
// then need to make sure the base part of that derived obj is also copied

using namespace std;

class Base {
private:
    int value;
public:
    Base() : value {0} {
        cout << "Base no-args constructor" << endl;
    }

    Base(int x) : value {x} {
        cout << "(int) Base overloaded constructor" << endl;
    }

    // copy constructor
    Base (const Base& other) : value {other.value} {
        cout << "Base copy constructor" << endl;
    }

    // overload copy assignment operator =
    Base& operator=(const Base& rhs) {
        if (this != &rhs) {
            value = rhs.value; // assign
        }
        cout << "Base operator= overloaded copy assignment" << endl;
        return *this;
    }

    ~Base() {
        cout << "Base destructor" << endl;
    }    
};

class Derived: public Base {
private:
    int doubled_value;
public:
    Derived() 
        : Base {}, doubled_value {0} {
            cout << "Derived no-args constructor" << endl;
    }

    Derived(int x) 
        : Base {x}, doubled_value {x * 2} {
            cout << "(int) Derived overloaded constructor" << endl;
    }

    // copy constructor
    Derived(const Derived& other) 
        : Base(other), doubled_value {other.doubled_value} {
            // explicitly copying the Base part of other by invoking the Base class copy constructor in the derived copy constructor's initialization list
            cout << "Derived copy constructr" << endl;
    }

    // overload copy assignment operator =
    Derived& operator=(const Derived& rhs) {
        if (this != &rhs) {
            Base::operator=(rhs); // Assign Base part, slicing out the Base value part of the other, so this line leads to Base copy constructor
            doubled_value = rhs.doubled_value; // Assign Derived part
        }
        cout << "Derived operator= overloaded copy assignment" << endl;
        return *this;
    }

    ~Derived() {
        cout << "Derived destructor" << endl;
    }
};


int main (void) 
{
    cout << "\n===Base part===" << endl;
    Base b {100};       // Overloaded constructor
    Base b1 {b};        // Copy constructor
    b = b1;             // Copy assignment

    cout << "\n===Derived part===" << endl;
    Derived d {500};    // Overloaded constructor
    Derived d1 {d};     // Copy constructor
    d = d1;             // Copy assignment

    cout << "\n===Destructor part===" << endl;


    return 0;
}