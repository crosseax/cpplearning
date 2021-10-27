// arrays are fixed sized
// once created, arrays cannot change size
// arrays are a chunk of continuous space allocated in memory
// emelent_type array_name [fixed array size] {init list}

#include <iostream>

using namespace std;

int main()
{
    int testScores [5] {2,3}; // the remain will be 0
    const int daysInYear {365};
    double tempOfDay [daysInYear] {0}; // all init to z
    int anotherArray [] {1,2,3,4,5}; // size automattically calculated

    cout << tempOfDay << endl; // output starting memory location

    return 0;
}