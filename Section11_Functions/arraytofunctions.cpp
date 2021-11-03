#include <iostream>
#include <vector>

using namespace std;

void print_array (const int arr [], size_t size); // const made the value you print readonly
void set_array (int arr[], size_t size, int value);
void zero_array (int numbers[], size_t size);


int main (void)
{
    int my_numbers[] {1,2,3,4,5};
    print_array(my_numbers, 5); // 1 2 3 4 5


    // zero_array(my_numbers, 5);
    print_array(my_numbers, 5); // 0 0 0 0 0


    int my_scores[] {100, 98, 87, 89, 91};
    print_array(my_scores, 5); // my_scores give the memory location
    set_array(my_scores, 5, 100);
    print_array(my_scores, 5);


    return 0;
}






void print_array (const int arr [], size_t size){
    for (size_t i = 0; i < size; i++){
        cout << arr[i] << " ";
        // numbers [i] = 0; // when using const, this modification cannot be done because it is read only value
        // pass by reference is now passing the location of the array instead of the value of the array
    }
    cout << endl;
}


void set_array (int arr[], size_t size, int value){
    for (size_t i = 0; i < size; i++){
        arr[i] = value;
    }
}


void zero_array (int numbers[], size_t size){
    for (size_t i = 0; i < size; i++){
        numbers[i] = 0;
    }
}
