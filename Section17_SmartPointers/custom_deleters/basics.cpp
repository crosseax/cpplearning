// Smart pointers, custom deleters

// sometimes when we destroy a smart pointer 
// we need more than to just destroy the object on the heap
// These are special use-cases
// lots of way to achieve this
// functions, lambdas, others

// when use custom deleters, CANNOT use make_unique or make_shared

#include <iostream>
#include <memory>

class Test {
private:
    int data;
public:
    Test() 
        : data{0} {
            std::cout << "Test constructor (" << data << ")" << std::endl;
        }
    
    Test(int data)
        : data{data} {
            std::cout << "Test constructor (" << data << ")" << std::endl;
        }
    
    int get_data() const {
        return data;
    }

    ~Test() {
        std::cout << "Test destructor (" << data << ")" << std::endl;
    }

};


void my_test_deleter (Test* ptr) {
    // this is a raw ptr being wrapped by shared_ptr
    // in this case the ptr points to the Test obj is the pointer that shared_ptr (unique_ptr) is managing
    std::cout << "\tIn my custom Test deleter for " << ptr->get_data() << std::endl;
    delete ptr;
}


int main (void)
{
    {
        std::shared_ptr<Test> ptr1 {new Test{100}, my_test_deleter};

        // code below wont work, 
        // error says no matching constructor for initialization of std::unique_ptr<Test>
        // std::unique_ptr<Test> ptr2 {new Test{500}, my_test_deleter};
    }

    std::cout << std::endl;

    {
        std::cout << "How this works using a lambda expression (will go into detail in later section)" << std::endl;

        std::shared_ptr<Test> ptr (new Test{200}, 
            [] (Test* ptr) {
                std::cout << "\tUsing my lambda custom deleter for " << ptr->get_data() << std::endl;
                delete ptr;
        });
    }



    return 0;
}