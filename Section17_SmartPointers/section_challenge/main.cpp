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
std::unique_ptr<std::vector<std::shared_ptr<Test>>> make();
void fill (std::vector<std::shared_ptr<Test>>& vec, int num);
void display(const std::vector<std::shared_ptr<Test>>& vec);

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