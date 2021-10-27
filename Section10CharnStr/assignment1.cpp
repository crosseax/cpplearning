#include <iostream>
#include <string>

using namespace std;    

int main()
{
    string str1 {};
    cout << "Enter your string here: ";
    getline(cin, str1);

    for (size_t i = 0; i < str1.length(); i++){

        string lineLeft {};
        lineLeft = str1.substr(0, i+1);

        string lineRight {lineLeft.rbegin(), lineLeft.rend()};
        lineRight.erase(0,1);

        string thisLine {};
        thisLine = lineLeft + lineRight;

        int x = str1.length() - i - 1;
        string spaces (x, ' ');

        cout << spaces << thisLine << endl;
    }

    return 0;
}

