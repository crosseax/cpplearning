#include <iostream>
#include <vector>
#include <string>

using namespace std;

int square(int &n){
        return n*n;
}

int main (void)
{
    int x {100}; // x is a L-value, 100 is a R-value
    x = 1000;
    x = 1000 + 20;
    int &ref {x}; // ref is a reference to l-value
    // and reference can only ref l-value

    int num {10};
    square(num); // ok
    // square(5); // error

    // 100 = x; // 100 is NOT a L-value, but R-value, because they're not addressable
    // (1000 + 20) = x; //(1000 + 20) is NOT a L-value


    string name; // name is a L-value
    name = "CrosSea"; // "CrosSea" is a R-value
    // "CrosSea" = name; // "CrosSea" is NOT a L-value

    // anything that's not a L-value is a R-value

    int maxNum = max(20, 30); // max(20, 30) is a R-value



    return 0;
}