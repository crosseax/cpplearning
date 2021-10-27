#include <iostream>
#include <cmath>
#include <cstdlib>
#include <ctime>

using namespace std;

int main (void)
{
    int randNum {};
    size_t count {10};
    int min {1};
    int max {6};

    cout << "RAND_MAX on my system is: " << RAND_MAX << endl;
    srand(time(nullptr)); // without this line, the number will be random, but the sequence wont
    // also, srand means seed rand

    for (size_t i = 0; i < count; i++){
        randNum = rand() % max + min;
        cout << randNum << ' ';
    }
        cout << endl;



    return 0;
}






