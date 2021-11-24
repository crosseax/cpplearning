#include <iostream>
#include <array>
#include <vector>
#include <algorithm>
#include <numeric> // for more algorithms like accumulate


// display the array -- note the size MUST be included
// when passing a std::array to a function
void display_array_five_elements(const std::array<int, 5>& arr) {
    std::cout << "[ ";
    for (const auto& n : arr) {
        std::cout << n << " ";    
    }
    std::cout << "]" << std::endl;
}


void test1() {
    std::cout << "\n=== test 1 ===" << std::endl;
    std::array<int, 5> arr1 {1, 2, 3, 4, 5}; // double {{}} if C++11
    std::array<int, 5> arr2;

    display_array_five_elements(arr1);
    display_array_five_elements(arr2); // uninitialized, garbage value

    arr2 = {10, 20, 30, 40, 50};

    display_array_five_elements(arr1);
    display_array_five_elements(arr2);

    std::cout << "Size of arr1 is: " << arr1.size() << std::endl; // 5
    std::cout << "Size of arr1 is: " << arr2.size() << std::endl; // 5 

    arr1[0] = 1000;
    arr1.at(1) = 2000;
    display_array_five_elements(arr1);

    std::cout << "Front of arr2 is: " << arr2.front() << std::endl; // 10
    std::cout << "Back of arr2 is: " << arr2.back() << std::endl; // 50
    std::cout << "arr2.begin(): " << arr2.begin() << std::endl;
    std::cout << "*arr2.begin(): " << *arr2.begin() << std::endl;
    std::cout << "arr2.end(): " << arr2.end() << std::endl; // address of the first element
    std::cout << "*arr2.end(): " << *arr2.end() << std::endl; // garbage value
    std::cout << "*(arr2.end() - 1): " << *(arr2.end() - 1) << std::endl; 
}

void test2() {
    std::cout << "\n=== test 2 ===" << std::endl;
    std::array<int, 5> arr1 {1, 2, 3, 4, 5};
    std::array<int, 5> arr2 {10, 20, 30, 40, 50};
    display_array_five_elements(arr1);
    display_array_five_elements(arr2);

    arr1.fill(1);
    display_array_five_elements(arr1);
    display_array_five_elements(arr2);

    std::cout << "swap" << std::endl;
    arr1.swap(arr2);
    display_array_five_elements(arr1);
    display_array_five_elements(arr2);
}

void test3() {
    std::cout << "\n=== test 3 ===" << std::endl;
    std::array<int, 5> arr1 {1, 2, 3, 4, 5};

    display_array_five_elements(arr1);
    std::cout << "arr1.data(): " << arr1.data() << std::endl;
    std::cout << "arr1.begin(): " << arr1.begin() << std::endl;
    int* ptr = arr1.data();
    std::cout << ptr << std::endl;
    *ptr = 10000;
    display_array_five_elements(arr1);
}

void test4() {
    std::cout << "\n=== test 4 ===" << std::endl;
    std::array<int, 5> arr {2, 1, 4, 5, 3};
    display_array_five_elements(arr);

    std::sort(arr.begin(), arr.end());
    display_array_five_elements(arr);
    std::sort(arr.rbegin(), arr.rend());
    display_array_five_elements(arr);
}

void test5() {
    std::cout << "\n=== test 5 ===" << std::endl;
    std::array<int, 5> arr {2, 1, 4, 5, 3};

    // for two lines below, returns a iterator to that element, so like pointer
    std::array<int, 5>::iterator min_num = std::min_element(arr.begin(), arr.end()); 
    auto max_num = std::max_element(arr.begin(), arr.end()); 
    std::cout << "min: " << min_num << ", max: " << max_num << std::endl; 
    std::cout << "*min: " << *min_num << ", *max: " << *max_num << std::endl;
}

void test6() {
    std::cout << "\n=== test 6 ===" << std::endl;
    std::array<int, 5> arr {1, 2, 3, 3, 5};

    // returns the first occurrence of adjacent value
    // so it returns the address of the first 3 (arr[2]) in the case below
    std::array<int, 5>::iterator adjacent = std::adjacent_find(arr.begin(), arr.end());
    // auto adjacent = std::adjacent_find(arr.begin(), arr.end());
    if (adjacent != arr.end()) {
        std::cout << "Adjacent element found with value: " << *adjacent << std::endl;
    } else {
        std::cout << "No adjacent element fount" << std::endl;
    }
}

void test7() {
    std::cout << "\n=== test 7 ===" << std::endl;
    std::array<int, 5> arr {1, 2, 3, 4, 5};

    // std::accumulate is from <numeric>
    // make sure the type of element in arr, the type of sum, and the 0 matches (int)
    // if all double, use 0.0
    int sum = std::accumulate(arr.begin(), arr.end(), 0); // initial sum is 0
    std::cout << "Accumulate (Sum) of the elements in arr is: " << sum << std::endl;
}

void test8() {
    std::cout << "\n=== test 8 ===" << std::endl;
    std::array<int, 10> arr {1, 2, 3, 1, 2, 3, 3, 3, 3, 3};

    int count = std::count(arr.begin(), arr.end(), 3);
    std::cout << "Found 3, counts: " << count << std::endl;
}

void test9() {
    std::cout << "\n=== test 9 ===" << std::endl;
    std::array<int, 10> arr {1, 2, 3, 50, 60, 70, 80, 200, 300, 400};

    int count = std::count_if(arr.begin(), arr.end(), 
        [](int x){ return x > 10 && x < 200;});
    std::cout << "Found matches: " << count << std::endl;
}

int main (void)
{
    test1();
    test2();
    test3();
    test4();
    test5();
    test6();
    test7();
    test8();
    test9();

    return 0;
}