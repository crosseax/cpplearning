// Note: Since C++11 the STL has std::array which is a template-based array class
// Use std::array instead of raw arrays when possible,
// unless you know exactly what you are doing

// Note that we can have non-type template parameters
// That's N in this case

#include <iostream>
#include <string>

template <typename T, int N> // the user provide N at the compile time so the compiler can create that array
class Array {
private:
    int size {N}; // how to get the N??? 
    T values [N]; // the N needs to be known at compile-time

    friend std::ostream& operator<< (std::ostream& os, const Array<T, N>& arr) {
        os << "[ ";
        for (const auto& val : arr.values) {
            os << val << " ";
        }
        os << "]";
        return os;
    }

public:
    Array() = default;
    Array(T init_val) {
        for (auto& item : values) {
            item = init_val;
        }
    }

    void fill(T val) {
        for (auto& item : values) {
            item = val;
        }
    }

    int get_size() const {
        return size;
    }

    // overloaded subscript operator for easy use
    T& operator[] (int index) {
        return values[index];
    }
};

int main (void) 
{
    std::cout << "==========" << std::endl;

    Array<int, 5> nums; // happens on the stack
    std::cout << "The size of nums is: " << nums.get_size() << std::endl;
    std::cout << nums << std::endl; // yet garbage value but the array is created

    std::cout << "==========" << std::endl;

    nums.fill(0);
    std::cout << "The size of nums is: " << nums.get_size() << std::endl;
    std::cout << nums << std::endl;

    nums.fill(10);
    std::cout << nums << std::endl;

    nums[0] = 1000; // this is where the overloaded subscript operator comes in
    nums[3] = 2000; // nums.operator[](3), setting value
    std::cout << nums << std::endl;

    std::cout << "==========" << std::endl;

    Array<int, 100> nums2 {1}; // fixed allocation, happens on the stack
    std::cout << "The size of nums2 is: " << nums2.get_size() << std::endl;
    std::cout << nums2 << std::endl;

    std::cout << "==========" << std::endl;

    Array<std::string, 10> strings {std::string ("hello")};
    std::cout << "The size of strings is: " << strings.get_size() << std::endl;
    std::cout << strings << std::endl;


    return 0;
}