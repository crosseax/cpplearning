#include <iostream>
#include <vector>
#include <string>

using namespace std;

void static_local();

int number {1000}; // global

int main (void)
{
    cout << "bonjour earth" << endl;

    cout << "global number: " << number << endl; // calls global 
    int number {100}; // local to main
    cout << "local number: " << number << endl; // calls the closest, which is local

    static_local(); // 5000 6000
    static_local(); // 6000 7000
    static_local(); // 7000 8000

    return 0;
}

void static_local(){
    static int num {5000}; // static variable only init once
    static string st {"hello"}; // same here
    // it behaves like a global variable but its local
    cout << num << endl;
    num += 1000;
    cout << num << endl;
    st += "1";
    cout << st << endl;
}