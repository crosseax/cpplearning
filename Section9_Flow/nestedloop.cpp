#include <iostream>
#include <vector>

using namespace std;

int main () 
{
    int start {1};
    for (int num1 = 1; num1 < 10; num1 ++){
        for (int num2 = start; num2 < 10; num2 ++){
            cout << num1 << " * " << num2 << " = " << num1*num2 << "; " ;
        }
        start++;
        cout << endl;
    }
    cout << endl;



    int itemAmount {};
    cout << "How many items you do you have: ";
    cin >> itemAmount;

    vector <int> datas {}; // init a dynamic vector of integer

    for (int i = 1; i <= itemAmount; i ++){
        int itemData {};
        cout << "Enter data item: " << i << ": ";
        cin >> itemData;
        datas.push_back(itemData);
    }

    cout << "Your items below: " << endl;
    for (auto val : datas) {
        cout << val << " ";
    }
    cout << endl << endl;

    cout << "Historgram below: " << endl << endl;
    for (auto val : datas){
        for (int k = 1; k <= val; k++){
            if (k % 5 == 0){
                cout << "\\";
            }
            else{
                cout << "=";
            }
        }
        cout << " " << val << endl;
    }
    cout << endl;



    return 0;
}