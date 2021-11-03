#include <iostream>

using namespace std;

int main() 
{
    /***
     * char, one single character
    ***/

    char nameInitial {'Y'}; // using single quotes for char
    cout << nameInitial << endl;


    /***
     * integer types 
     * signed vs unsigned: unsigned can never be negetive
     * short int 16 bits, int 16 bits, long int 32 bits, long long 64 bits
    ***/

    unsigned short int score {55}; 
    cout << score << endl;

    int countryCode {886}; 
    cout << countryCode << endl; 

    long chinaPopulation {1'400'000'000};
    cout << chinaPopulation << endl;
    
    // long earthPopulation = 7'600'000'000; // compiler warning
    // cout << earthPopulation << endl;

    long long earthPopulation2 = {7'600'000'000}; // this catch problem like above
    cout << earthPopulation2 << endl;

    long long distanceAlphaCentauri {9'461'000'000'000};
    cout << distanceAlphaCentauri << endl;


    /***
     * float types
    ***/

    float payment {401.231552};
    cout << payment << endl;

    double num1 {3.1234567};
    cout << num1 << endl;

    long double num2 {2.1234567e100};
    cout << num2 << endl;


    /***
     * boolean value
    ***/

    bool gameStart {true};
    cout << gameStart << endl; // 1

    bool gameOver {false};
    cout << gameOver << endl; // 0


    /***
     * overflow example
    ***/

    short val1 {30000};
    short val2 {10000};
    // short prod {val1 * val2}; // this overflows
    int prod {val1 * val2};

    cout << val1 * val2 << endl;
    cout << prod << endl;


    return 0;
}