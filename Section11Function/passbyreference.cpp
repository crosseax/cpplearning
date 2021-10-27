#include <iostream>
#include <vector>

using namespace std;


void scale_number(int &num); 
void swap(int &a, int &b);
void print (const vector<int> &v); // use const to prevent accidental change of the original value


int main (void)
{

    int number {1000};
    cout << number << endl;
    scale_number(number); // behind the scene the location of the number is passed into the function using &
    cout << number << endl;

    int arrayNum[] {1,2,5,1000,520,88,91};

    for (int num:arrayNum){
        cout << num << " ";
        scale_number(num);
    }

    cout << endl; 

    for (int num:arrayNum){
        cout << num << " ";
    }

    cout << endl;

    for (int &num:arrayNum){ // now passing the location of the num in array
        scale_number(num);
    }

    for (int num:arrayNum){
        cout << num << " ";
    }

    cout << endl;


    int x{10}, y{20};
    cout << x << " " << y << endl; // 10 20
    swap(x,y);
    cout << x << " " << y << endl; // 20 10

    vector<int> data {1,2,3,4,5};
    print (data);

    int a {1};
    int*ptr = &a;
    cout << &a << endl;
    cout << ptr << endl;
    cout << *ptr << endl;





    return 0;
}



void scale_number(int &num){ // reference parameter
    if (num > 100){
        num = 100;
    }
}

void swap(int &a, int &b){
    int temp = a;
    a = b;
    b = temp;
}

void print (const vector<int> &v){
    for (auto num:v){
        cout << num << " ";
    }
    cout << endl;
}

