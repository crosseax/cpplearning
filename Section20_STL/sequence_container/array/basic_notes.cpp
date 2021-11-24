// std::array (C++11) container

// #include <array>

// Fixed size array of any time
    // is a object type
    // size must be known at compile time
    // does not decay to a pointer to the first element of the array when we pass it into a function
// Direct element access
    // constant time to access any element
// Provides access to the underlying raw array
// Use instead of raw arrays when possible
// All iterators available and do not invalidate
    // because its a fixed size structure


// to initialize

// in C++11, double curly braces
// std::array <type, size> name { {ele1, ele2 ...} }; 

// since C++14
// std::array<int, 5> arr {1, 2, 3, 4, 5};

// common methods:
    // arr.size();      // 5
    // arr.at(0);       // 1, bounds check
    // arr[1];          // 2, no bounds check
    // arr.front();     // 1
    // arr.back();      // 5
    // arr.empty;       // 0, (false) - returns true if is empty
    // arr.max_size();  // 5
    // arr.fill();      // fill array with provided elements
    // arr.swap(arr1);  // swaps the 2 arrays
    // int* data = arr.data();  // get raw array address

// check en.cppreference.com for more info


