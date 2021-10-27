#include <iostream>
#include <vector>
#include <string>

using namespace std;

int func1 (int a, int b);
void func2(int &x, int y, int z);


int main (void)
{
    // stack overflow: too many stack memory used then comes error

    int x{10};
    int y{20};
    int z{};
    z = func1(x,y);
    cout << z << endl;


    return 0;
}

int func1 (int a, int b){
    int result {};
    result = a + b;
    func2 (result, a, b);
    return result;
}


void func2(int &x, int y, int z){
    x += y + z;
}





/***
 * what typically happens when main calls func1 (or any function calls another)?
 * there are other ways to achieve the smae results:
 * 
 * main:
 *      push space on the stack for the return value
 *      push space for the parameters
 *      push the return address
 *      transfer contrl to func1 (jmp)
 * 
 * func1:
 *      push the address of the previous activation/record
 *      push any register values that will need to be restored before returning to the caller
 *      perform the code in func1
 *      restore the register values
 *      store any function result
 *      transfer control to the return address (jmp)
 * 
 * main:
 *      pop the parameters
 *      pop the return value
***/