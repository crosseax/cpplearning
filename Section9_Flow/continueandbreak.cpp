#include <iostream>
#include <vector>

using namespace std;

int main() {

    vector <int> values {1,2,-1,3,-1,'A',-9,7,-99,8,9,1}; // int the val, then 'A' is transfered to 65 by using ASCII
    for (auto val : values){
        if (val == -99){
            break; // exit the loop
        }
        else if (val == -1){
            continue; // going back to the beginning of the loop starting from the next element in the loop
        }
        else{
            cout << val << endl;
        }
    }

    vector <char> chars {1,2,-1,3,-1,'A',-9,7,-99,8,9,1}; // ASCII transfer all ints into chars
    for (auto c : chars){
        if (c == -99){
            break; 
        }
        else if (c == -1){
            continue; 
        }
        else{
            cout << c << endl;
        }
    }

    return 0;
}