// vectors are dynamic in size
// elements are all same type
// elements automatically initialized to 0


#include <vector>

using namespace std;

int main ()
{
    // how to declare vectors
    vector <char> vowels (5);
    vector <int> scores (10); // unlike array, those 10 ints will be automatically set to 0

    vector <int> nums {10, 15, 31, 44, 23};

    vector <double> temps (365, 80.0); // (size, initial value)
    // so for above is like 365 ints that are all 80.0


    return 0;
}