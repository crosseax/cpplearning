// Smart pointers, shared pointers
// smart pointers #include <memory>

// Shared pointers
// shared_ptr<T>, points to type T object on the heap
// Not unique - there can many shared_ptr s pointing to the same object
// establishes shared ownership relationship
// CAN be assigned or copied
// CAN be moved
// NOT support managing arrays by default
// when use count is zero (no more pointers points to the T), 
// the T it points to is automatically destroyed

#include <iostream>
#include <memory>
#include <vector>


int main (void) 
{
    {
        std::shared_ptr<int> p1 {new int {100}} ;
        std::cout << *p1 << std::endl;
        *p1 = 200;
        std::cout << *p1 << std::endl;
    } // automatically destroyed when out of scope

    std::cout << std::endl;

    { 
        // use_count() - returns the number of shared_ptr objects managing the heap obj    
        std::shared_ptr<int> p1 {new int {100}};
        std::cout << p1.use_count() << std::endl; // 1

        std::shared_ptr<int> p2 {p1};
        std::cout << p1.use_count() << std::endl; // 2
        std::cout << p2.use_count() << std::endl; // 2

        p1.reset(); // decrement the use_count; p1 is now nullptr
        std::cout << p1.use_count() << std::endl; // 0
        p1 = p2;
        std::cout << p1.use_count() << std::endl; // 2

        std::cout << *p1 << std::endl; // 100
        p1.reset(); 
        std::cout << p1 << std::endl; // 0x0
        std::cout << sizeof(p1) << "bytes" << std::endl; // 16 bytes
        // std::cout << *p1 << std::endl;   // segmentation fault
        // *p1 = 200;                       // segmentation fault
        p1 = p2; 
        *p1 = 200;
        std::cout << *p1 << std::endl; // 200

        std::cout << p2.use_count() << std::endl; // 1
    } // automatically detroyed

    std::cout << std::endl;

    {
        std::vector<std::shared_ptr<int>> vec;
        std::shared_ptr<int> ptr {new int {300}};
        vec.push_back(ptr); // OK - copy is allowed
        std::cout << ptr.use_count() << std::endl; // 2
        // because the int 300 on the heap is being referenced 
        // by the ptr and the ptr in the vec (copied)
        std::shared_ptr<int> ptr2 {new int {500}};
        vec.push_back(std::move(ptr2));
        std::cout << ptr2.use_count() << std::endl; // 0
        std::cout << vec[0].use_count() << std::endl; // 2, ptr
        std::cout << vec[1].use_count() << std::endl; // 1, ptr2
    } // automatically destroyed

    std::cout << std::endl;

    { // a better way to initialize shared_ptr
        std::shared_ptr<int> p1 = std::make_shared<int>(100); // make_shared is since c++11
        // also make_shared method generates less code by compiler (faster in general)
        std::cout << p1.use_count() << std::endl; // 1
        std::shared_ptr<int> p2 {p1};
        std::cout << p1.use_count() << std::endl; // 2
        std::shared_ptr<int> p3;
        p3 = p1;
        std::cout << p1.use_count() << std::endl; // 3
    } // the last one who references it will be responsible for cleaning up the heap storage (in this case, p1)


    return 0;
}


