// Smart pointers, Unique pointers
// smart pointers #include <memory>

// Unique pointers
// unique_ptr<T>, points to type T object on the heap
// owns waht it points to (Strong Ownership)
// CANNOT be assigned or copied
// CAN be moved
// when pointer is destroyed, the T it points to is automatically destroyed

#include <iostream>
#include <memory>
#include <vector>

int main (void) 
{
    {
        std::unique_ptr<int> p1 {new int {100}};
        std::cout << *p1 << std::endl;
        *p1 = 200;
        std::cout << *p1 << std::endl;

        std::cout << p1.get() << std::endl; // returns a pointer to the managed obj
        p1.reset(); // p1 is now nullptr, and the memory it points to will be released

        if (p1) {
            std::cout << "will execute if not nullptr" << std::endl; // won't execute, cuz it's nullptr
        }

    } // when out of scope, both unique_ptr and data it points to (int 200) is deleted

    {
        std::vector<std::unique_ptr<int>> vec;
        std::unique_ptr<int> ptr {new int {100}};
        // vec.push_back<ptr>; // Error - copy not allowed
        vec.push_back(std::move(ptr)); // OK - move allowed
        
        // code below won't work because it's doing copy
        // for (auto v : vec) {
        //     std::cout << *v << std::endl;
        // }

        // this works
        for (const auto& v : vec) {
            std::cout << *v << std::endl;
        }
    }

    { // a better way to initialize unique_pointers
        std::unique_ptr<int> p1 = std::make_unique<int> (100); // since c++14
        // make_unique returns a unique pointer of the specified type,
        // and it allows to pass initialization values into the constructor for the manage object
        // in another words, initializing pointer and creating the managed object is done in one step
        auto p2 = std::make_unique<int> (1000); // since c++14: std::make_unique

        std::cout << *p1 << " " << *p2 << std::endl;
    }

    return 0;
}


