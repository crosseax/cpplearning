#include <iostream>
#include <string>
#include <vector>

using namespace std;

int add_numbers (int a, int b);
double add_numbers (double a, double b);

void print(int);
void print(double);
void print(string);
void print(string,string);
void print(vector<string>);


int main (void)
{
    cout << add_numbers(10, 20) << endl;
    cout << add_numbers(10.0, 20.1) << endl;

    print(100);
    print('A'); // character is always promoted to int should print 65 ASCII 'A'

    print(123.5);
    print(123.33F); // float is promoted to double

    print("C-style string"); // C-style string is covereted to C++ string

    string s {"C++ string"};
    print(s);

    print("C-style string", s);

    vector<string> threeNames {"Larry", "Moe", "Curly"};
    print(threeNames);

    return 0;
}


int add_numbers (int a, int b){
    return a + b;
}

double add_numbers (double a, double b){
    return a + b;
}

void print (int num){
    cout << "Printing int: " << num << endl;
}

void print (double num){
    cout << "Printing double: " << num << endl;
}

void print (string s){
    cout << "Printing string: " << s << endl;
}

void print (string s, string t){
    cout << "Printing 2 strings: " << s << " and " << t << endl;
}

void print (vector<string> v){
    cout << "Printing vector of strings: ";
    for (auto s: v){
        cout << s + " ";
    }
    cout << endl;
}