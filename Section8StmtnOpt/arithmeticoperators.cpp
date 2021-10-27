#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int num1 {200};
    int num2 {100};

    cout << num1 << " + " << num2 << " = " << num1 + num2 << endl;

    int addRes {0};
    addRes = num1 + num2;
    cout << num1 << " + " << num2 << " = " << addRes << endl;

    int subRes {0};
    subRes = num1 - num2;
    cout << num1 << " - " << num2 << " = " << subRes << endl;

    int mulRes {0};
    mulRes = num1 * num2;
    cout << num1 << " * " << num2 << " = " << mulRes << endl;

    int divRes {0}; 
    divRes = num1 / num2;
    cout << num1 << " / " << num2 << " = " << divRes << endl;

    int intdivRes {0}; // div int means only take int part of the result
    intdivRes = num2 / num1;
    cout << num2 << " / " << num1 << " = " << intdivRes << endl;

    int num3 {10};
    int num4 {3};

    int modRes {0};
    modRes = num3 % num4; // this is for mod calculation, so remainder
    cout << num3 << " % " << num4 << " = " << modRes << endl;


    cout << 5/10 << endl;
    cout << 5.0/10.0 << endl;



    // EUR and USD

    const double usd_per_eur {1.19};

    double euros {0.0};
    double dollars {0.0};

    cout << "Enter the value in Euros: ";
    cin >> euros;

    dollars = euros * usd_per_eur;

    cout << euros << " Eur is " << dollars << " dollars" << endl;

    return 0;
}