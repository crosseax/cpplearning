#include <iostream>

using namespace std;

class Base {
    // Note friends of Base have access to all public, protected and private information
public:
    int a{0};
    void display() { // member method has access to all
        cout << "public a: " << a << endl;
        cout << "protected b: " << b << endl;
        cout << "private c: " << c << endl;
    }

protected:
    int b{0};

private:
    int c{0};
};

class Derived: public Base {
    // Note friends of Derived class have access to only what Derived class have access to

    // a will be public
    // b will be protected 
    // c will not be accessible, even thought it is indeed inherited
public:
    void access_base_member () {
        a = 300; // OK
        b = 300; // OK, it is protected member function have access to it
        // c = 300; // Compiler error cuz it is private of the Base class
        // if wanna access c
        // you need getter or setter function provided by the Base class
    }
};




int main (void)
{
    cout << "\n=== Base member access from base objects ===" << endl;
    Base base;
    base.a = 100; // OK
    // base.b = 100; // Compiler error cuz protected
    // base.c = 100; // Compiler error cuz private
    base.display();

    cout << "\n=== Base member access from derived objects ===" << endl;
    Derived derived;
    // Derived class also has a,b,c though some of them is not accessible
    // Not Accessible != Not Inherited

    derived.a = 200; // OK
    // derived.b = 200; // Compiler error cuz protected 
    // derived.c = 200; // Compiler error cuz private
    derived.display();

    cout << "\n=== Base member access using member function in derived objects ===" << endl;
    derived.access_base_member();
    derived.display();

    return 0;
}