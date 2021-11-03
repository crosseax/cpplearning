#include <iostream>
#include <vector>
#include <climits>
#include <iomanip>

using namespace std;

int main()
{
    // (conditional_expression) ? true_return : false_return
    // int a, b {};
    // cout << "Enter 2 integers seperated by space: ";
    // cin >> a >> b;
    // int result {};
    // result = (a >= b) ? a : b;

    // cout << result << " is bigger" << endl;
    // cout << result << ((result % 2 == 0) ? " is even" : " is odd") << endl;

    // for (init ; condition ; increment){statments}

    for (int i = 1; i <= 5; i++){
        cout << i << endl;
    }



    int scores [] {100, 95, 87, 84, 32, 77, 65};
    for (int i = 0; i < sizeof(scores) / 4; i++){ // because size of int is 4 bytes, array size = int size * array ele
        cout << scores[i] << endl;
    }



    for (int i = 1, j = 5; i <= 5; i++, j++){
        cout << i << " * " << j << " = " << (i*j) << endl;
    }



    for (int i = 1; i < 101; i++){
        cout << i;

        if (i % 10 == 0){
            cout << endl;
        } 
        else {
            cout << " ";
        }
    }



    vector <int> nums {10, 20, 30, 40, 50};
    for (unsigned i = 0; i < nums.size(); i++){
        cout << nums[i] << endl;
    }

    cout << endl;
    cout << sizeof(scores) << endl;
    cout << scores << endl;




    // range-based for loop
    //      for (var_type var_name: sequence){
    //          statements
    //      }

    for (int score : scores){
        cout << score << " ";
    }
    cout << endl;

    for (auto score : scores){
        cout << score << " ";
    }
    cout << endl;

    for (auto c : "CrosSea"){
        cout << c << " ";
    }
    cout << endl;


    // cout << fixed << setprecision(4); // <iomanip>
    vector <double> temps {87.9, 99.2, 70.5, 65.0, 81.8};
    double aveTemp {};
    double total {};

    for (auto temp : temps){
        total += temp;
    }
    aveTemp = total / temps.size();

    cout << "Ave temp: " << aveTemp << endl;
    cout << "Total temp: " << total << endl;




    int i {1};

    while (i < 11)
    {
        cout << i << " ";
        i++;
    }

    cout << endl;
    i = 5;
    
    do
    {
        cout << i << " ";
        i++;
    } while (i < 11);
    


    return 0;
}