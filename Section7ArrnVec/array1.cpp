#include <iostream>

using namespace std;

int main()
{
    // int testScores [5] {0}; // the remain will be 0
    
    // cout << "Enter the first score: " << endl;
    // cin >> testScores[0];
    // cout << testScores[0] << endl;

    char vowels[] {'a','e','i','o','u'};
    cout << "The first vowel is " << vowels[0] << endl;
    cout << "The last vowel is " << vowels[4] << endl;

    double temps[] {90.1, 83.5, 77.3};
    cout << "The first hightemp is " << temps[0] << endl;
    temps[0] = 100.7;
    cout << "The first hightemp is " << temps[0] << endl;

    int junkVal [5];
    cout << "Junk value 1: " << junkVal[0] << endl;
    cout << "Junk value 2: " << junkVal[1] << endl;
    cout << "Junk value 3: " << junkVal[2] << endl;
    cout << "Junk value 4: " << junkVal[3] << endl;
    cout << "Junk value 5: " << junkVal[4] << endl;

    int initVal [5] {}; // {} initialized the value to 0
    cout << "Initialized value 1: " << initVal[0] << endl;
    cout << "Initialized value 2: " << initVal[1] << endl;
    cout << "Initialized value 3: " << initVal[2] << endl;
    cout << "Initialized value 4: " << initVal[3] << endl;
    cout << "Initialized value 5: " << initVal[4] << endl;

    cout << "the name or the memory address of the array is " << initVal << " in hexdecimal" << endl;

    return 0;
}