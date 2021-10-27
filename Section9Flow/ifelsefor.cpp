#include <iostream>
#include <vector>

using namespace std;

int main() 
{
    int num1 {0};

    cout << "Enter your number: ";
    cin >> num1;
    
    for (int i = 0; i < num1; i++) {
        if (i % 100 == 1 || i % 100 == 99){
            cout << i << endl; 
        } else {
            cout << "gay" << endl;
        }
    }
    return 0;
}