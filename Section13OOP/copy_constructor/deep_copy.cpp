// Deep copy
// deep copy create a copy of pointed-to data
// each copy will have a pointer to unique storage in the heap
// deep copy when you have a raw pointer as a class data member


#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Deep {
private:
    int* dataPtr;
public:
    void set_data_value(int d) {*dataPtr = d;}
    int get_data_value() {return *dataPtr;}

    // constructor (prototype)
    Deep (int d);
    // copy constructor (prototype)
    Deep (const Deep &source);
    // destructor
    ~Deep();
};

// Deep constructor implementation
Deep::Deep (int d){
    dataPtr = new int;
    *dataPtr = d;
}

// Deep copy constructor implementation
// where difference comparing to shallow copy
Deep::Deep(const Deep &source){
    
    dataPtr = new int; // allocating new storage, so new pointer to new mem location on heap
    *dataPtr = *source.dataPtr;

    // or do : Deep{*source.dataPtr}; 

    cout << "Copy constructor - deep copy" << endl;
}

// Deep copy destructor implementation
Deep::~Deep(){
    delete dataPtr;
    cout << "Destructor freeing data" << endl;
}

void display_deep (Deep s){
    cout << s.get_data_value() << endl;
}


int main (void)
{
    Deep obj1 {100};
    display_deep(obj1);

    Deep obj2 {obj1};
    obj2.set_data_value(1000);
    display_deep(obj2);

    return 0;
}