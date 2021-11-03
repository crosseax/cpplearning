#include <iostream>

using namespace std;

inline int add_numbers (int a, int b);

/*
avoid function call overhead
generate inline assembly code
faster generally
but if use too much, could cause code bloat since youre copying code multiple times

compliers nowadays are pretty good so if you dont specify inline keywords
the complier are likely to inline even without your suggestions
*/

int main (void) 
{
    int result {};
    result = add_numbers(100, 200); // call
    cout << result << endl;

    return 0;
}

inline int add_numbers (int a, int b){ // definiton
    return a + b;
}
