// increment and decrement works on
// int, float, double etc and pointers

#include <iostream>
#include <vector>

using namespace std;

int main ()
{
    int counter {0};
    float deci {0.5};
    int res {0};

    cout << counter << endl;
    cout << deci << endl;

    counter = counter + 1;
    counter += 1;
    counter++;
    ++counter;

    deci = deci + 1;
    deci += 1;
    deci++;
    ++deci;

    cout << counter << endl;
    cout << deci << endl;

    counter = counter - 1;
    counter -= 1;
    counter--;
    --counter;

    deci = deci - 1;
    deci -= 1;
    deci--;
    --deci;

    cout << counter << endl;
    cout << deci << endl;

    int num1 {0};
    int num2 {0};

    res = 0;
    res = ++num1 + 10; // num1++ before use to res
    cout << res << endl;

    res = 0;
    res = num2++ + 10; // num2++ after use to res
    cout << res << endl;

    cout << "End" << endl;

    return 0;
}