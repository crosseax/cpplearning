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
};

// Function prototypes for you to implement
// std::unique_ptr<std::vector<std::shared_ptr<Test>>> make();
auto make();
void fill (std::vector<std::shared_ptr<Test>>& vec, int num);
void display(const std::vector<std::shared_ptr<Test>>& vec);
// DO NOT use new and delete
// in another word, use only make_unique or make_shared

auto make() {
    return std::make_unique<std::vector<std::shared_ptr<Test>>>();
}

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

// std::unique_ptr<std::vector<std::shared_ptr<Test>>> make() {
//     return std::make_unique<std::vector<std::shared_ptr<Test>>>();
// }




void fill (std::vector<std::shared_ptr<Test>>& vec, int num) {
    int temp;
    for (int i = 0; i < num; i++) {
        std::cout << "Enter data point [" << i + 1 << "]: ";
        std::cin >> temp;
        // std::shared_ptr<Test> ptr = std::make_shared<Test> (temp);
        // vec.push_back(ptr);
        vec.push_back(std::make_shared<Test> (temp));
    }
}


void display(const std::vector<std::shared_ptr<Test>>& vec) {
    std::cout << "===Displaying the data===" << std::endl;
    for (const auto& ptr : vec) {
        std::cout << ptr->get_data() << std::endl;
    }
}
