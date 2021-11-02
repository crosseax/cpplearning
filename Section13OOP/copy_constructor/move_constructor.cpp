#include <iostream>
#include <string>
#include <vector>

// a rule of thumb:
// when you can refer to an object by name
// or you can follow a pointer to get to an object, and that is addressable
// that object is a L-value
// everything else is a R-value

// R-value is the value that move semantic addresses
// R-value reference operator &&


using namespace std;

class Move {
private:
    int* dataPtr;
public:
    void set_data_value(int d) {*dataPtr = d;}
    int get_data_value() {return *dataPtr;}
    // Construcot
    Move (int d);
    // Copy Constructor
    Move (const Move &source);
    // Move Constructor
    Move (Move &&source) noexcept;
    // Destructor
    ~Move();
};

Move::Move(int d){
    dataPtr = new int;
    *dataPtr = d;
    cout << "Constructor for: " << d << endl;
}

// Copy constructor
Move::Move(const Move &source)
    : Move {*source.dataPtr}{
        cout << "Copy constructor - deep copy - for: " << *dataPtr << endl;
}

// Move constructor
Move::Move(Move &&source) noexcept
    : dataPtr (source.dataPtr) {
        source.dataPtr = nullptr;
        cout << "Move constructor - moving resource: " << *dataPtr << endl;
}

Move::~Move(){
    if (dataPtr != nullptr){
        cout << "Destructor freeing data for: " << *dataPtr << endl;
    } else {
        cout << "Destructor freeing data for nullptr" << endl;
    }
    delete dataPtr;
}

int main (void)
{
    int x = 5;
    int &l_ref = x; // l-value reference
    l_ref = 10; // change x to 10
    cout << x << endl;

    int &&r_ref = 200; // r-value ref
    r_ref = 300; // change r_ref to 300
    
    // int &&x_ref = x; compiler error, CANNOT assign l-value to r-value reference

    vector<Move> vec;

    // because Move{10} is a R-value, using move constructor will now be more efficient

    vec.push_back(Move{10});

    cout << &vec << endl;

    vec.push_back(Move{10});

    vec.push_back(Move{20});
    vec.push_back(Move{30});
    vec.push_back(Move{40});
    vec.push_back(Move{50});
    vec.push_back(Move{60});
    vec.push_back(Move{70});
    vec.push_back(Move{80});


    return 0;
}