#include <vector>
#include <iostream>
#include <string>

using namespace std;

int main(void)
{
    vector<string> stooges {"Larry", "Moe", "Curly"};
    
    for (auto str : stooges){
        str = "Funny"; // changes the copy
        cout << str << " ";
    }
    cout << endl;

    for (auto str : stooges){
        cout << str << " "; // still Larry, Moe, Curly
    }
    cout << endl;

    // now using references

    for (auto &str : stooges){ // for (auto const &str : stooges) -> compiler error
        str = "Funny"; // changes the original data
    }

    for (auto str : stooges){
        cout << str << " "; // all Funny
    }
    cout << endl;

    int num {100};
    int &ref {num};

    cout << num << endl;
    cout << ref << endl;

    num = 200;
    cout << num << endl;
    cout << ref << endl;

    ref = 300;
    cout << num << endl;
    cout << ref << endl;



    return 0;
}