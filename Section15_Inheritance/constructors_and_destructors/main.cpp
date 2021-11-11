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
        cout << "Base (int) overloaded constructor" << endl;
    }

    ~Base() {
        cout << "Base destructor" << endl;
    }
    // Destructor happens in the reverse order of constructor
};

class Derived_with_constructor: public Base {
private:
    int doubled_value;
public:
    Derived_with_constructor() : doubled_value {0} {
        cout << "Derived_with_constructor no-args constructor" << endl;
    }

    Derived_with_constructor(int x) : doubled_value {x * 2} {
        cout << "Derived_with_constructor (int) overloaded constructor" << endl;
    }

    ~Derived_with_constructor() {
        cout << "Derived_with_constructor destructor" << endl;
    }
};

class Derived_with_NO_constructor: public Base {
    using Base::Base; // allow us to inherite the Non-special constructor in Base class
private:
    int another_value;
public:

};

int main (void) 
{
    cout << "\n===Base class===" << endl;
    {
        Base base;
    }

    cout << "\n===Derived_with_constructor class===" << endl;
    {
        Derived_with_constructor derived1;
    }

    cout << "\n===Derived_with_NO_constructor class===" << endl;
    {
        Derived_with_NO_constructor derived2;
    }
    {
        Derived_with_NO_constructor derived3{70};  
        // So now init Base-part value
        // But Derived-part doubled_value is still garbage value
        // so this is the problem using: using Base::Base constructor
    }

    cout << "\n===Put together===" << endl;
    {
        Base b{10};
        cout << endl;

        Derived_with_constructor d1{50}; // the derived int-arg constructor is called before the ***no-args constructor*** of the Base class is called
        Derived_with_NO_constructor d2; // the derived class object d2 here, the doubled_value of it, contains garbage value
        
        cout << endl;
        
        Derived_with_NO_constructor d3{70};  
        
        // Above CANNOT work since constructor is not inherited
        // Unless do using Base::Base
        // Then it's using Base (int) constructor

        cout << endl;

        // When creating derived class objects
        // The value of Base part of it must be constructed before it's constructed
    }

    return 0;
}