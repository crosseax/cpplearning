#include <iostream>

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

    ~Derived() {
        cout << "Derived destructor" << endl;
    }
};


int main (void) 
{
    cout << "\n===Base constructor===" << endl;
    {
        Base base;
    }
    
    cout << "\n===Base{x} constructor===" << endl;
    {
        Base base{100};
    }

    cout << "\n===Base constructor===" << endl;
    {
        Derived derived;
    }

    cout << "\n===Base constructor===" << endl;
    {
        Derived derived{500};
    }
}