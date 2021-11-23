// it is possible to have non-type template parameters
//

#include <iostream>
#include <string>

template <int N> // the user provide N at the compile time so the compiler can create that array
class Array {
private:
    int size {N}; // how to get the N??? 
    int values [N]; // the N needs to be known at compile-time

    friend std::ostream& operator<< (std::ostream& os, const Array<N>& arr) {
        os << "[ ";
        for (const auto& val : arr.values) {
            os << val << " ";
        }
        os << "]";
        return os;
    }

public:
    Array() = default;
    Array(int init_val) {
        for (auto& item : values) {
            item = init_val;
        }
    }

    void fill(int val) {
        for (auto& item : values) {
            item = val;
        }
    }

    int get_size() const {
        return size;
    }

    // overloaded subscript operator for easy use
    int& operator[] (int index) {
        return values[index];
    }
};

int main (void) 
{
    Array<5> nums;
    std::cout << "The size of nums is: " << nums.get_size() << std::endl;
    std::cout << nums << std::endl; // yet garbage value but the array is created

    return 0;
}