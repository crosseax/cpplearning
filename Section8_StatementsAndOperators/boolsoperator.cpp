#include <iostream>
#include <vector>


using namespace std;

int main()
{
    bool result {false};

    result = (100 == 100);

    cout << result << endl; // return 1, which stands for true
    cout << boolalpha;
    cout << result << endl; // now return true
    cout << noboolalpha;
    cout << result << endl; // now return 1 or 0 again

    double num1 {12.0};
    double num2 {11.9999999999999999999999};

    bool isEqual {false};
    isEqual = (num1 == num2);

    cout << isEqual << endl; // they are equal, because how double store numbers

    int num3 {12};
    isEqual = (num1 == num3);

    cout << isEqual << endl; // the int is promoted to double, then compare, which is true


    return 0;
}