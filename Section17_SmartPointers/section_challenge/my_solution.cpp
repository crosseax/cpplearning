#include <iostream>
#include <memory>
#include <vector>

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

    friend std::ostream& operator<< (std::ostream& os, const Test& obj) {
        os << obj.get_data();
        return os;
    }

};

// Function prototypes for you to implement
std::unique_ptr<std::vector<std::shared_ptr<Test>>> make();
void fill (std::vector<std::shared_ptr<Test>>& vec, int num);
void display(const std::vector<std::shared_ptr<Test>>& vec);
// DO NOT use new and delete
// in another word, use only make_unique or make_shared


int main (void) 
{
    std::unique_ptr<std::vector<std::shared_ptr<Test>>> vecPtr;
    vecPtr = make();
    
    std::cout << "How many data points do you want to enter: ";
    int dataNum;
    std::cin >> dataNum;

    fill(*vecPtr, dataNum);
    display(*vecPtr);

    return 0;
}

std::unique_ptr<std::vector<std::shared_ptr<Test>>> make() {
    
    std::vector<std::shared_ptr<Test>> vec;
    std::unique_ptr<std::vector<std::shared_ptr<Test>>> ptr; 
    ptr = std::make_unique<std::vector<std::shared_ptr<Test>>> (vec);
    
    std::cout << "Unique_ptr that points to the vector which contains the shared_ptr that points to the Test obj is made" << std::endl;

    return ptr;
}



void fill (std::vector<std::shared_ptr<Test>>& vec, int num) {
    std::cout << "============" << std::endl;
    for (int i = 0; i < num; i++) {
        std::cout << "Enter data [" << i+1 << "]: ";
        int data;
        std::cin >> data;
        vec.push_back(std::make_shared<Test> (data));
    }
    std::cout << "============" << std::endl;
}


void display(const std::vector<std::shared_ptr<Test>>& vec) {
    std::cout << "===Displaying the data===" << std::endl;
    for (const auto& sharedPtr : vec) {
        std::cout << "Data: " << *sharedPtr << std::endl;
    }
}

// overloaded the << operator for display
std::ostream& operator<< (std::ostream& os, const Test& obj) {
    os << obj.get_data();
    return os;
}