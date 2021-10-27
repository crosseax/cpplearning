#include <iostream>
#include <string>
#include <vector>

using namespace std;

unsigned long long factorial (unsigned long long n);
unsigned long long fibonacci (unsigned long long n);

int main (void)
{
    unsigned long long factRes {};
    factRes = factorial (10); 
    cout << factRes << endl; // 3628800

    unsigned long long fibRes {};
    fibRes = fibonacci(30); 
    cout << fibRes << endl; // 832040

    int res {};
    for (int i = 0; i < 20; i++){
        res = fibonacci (i);
        cout << res << " ";
    }
    cout << endl;

    return 0;
}

unsigned long long factorial (unsigned long long n){
    if (n == 0){
        return 1;
    }
    return n * factorial (n-1);    
}

unsigned long long fibonacci (unsigned long long n){
    if (n <= 1){
        return n;
    }
    return fibonacci(n-1) + fibonacci(n-2);
}
