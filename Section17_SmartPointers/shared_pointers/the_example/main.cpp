#include <iostream>
#include <memory>
#include <vector>

#include "Account.h"
#include "Savings_Account.h"
#include "Account_Util.h"
#include "Checking_Account.h"
#include "Trust_Account.h"
#include "I_Printable.h"

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

void func1(std::shared_ptr<Test> p) {
    std::cout << "Use count through func1: " << p.use_count() << std::endl;
}

void func2(std::shared_ptr<Test>& p) {
    std::cout << "Use count through func1: " << p.use_count() << std::endl;
}

int main (void) 
{
    // {
    //     std::cout << "===int part===" << std::endl;
    //     std::shared_ptr<int> p1 {new int {100}};
    //     std::cout << "Use count: " << p1.use_count() << std::endl; // 1

    //     std::shared_ptr<int> p2 {p1};
    //     std::cout << "Use count: " << p1.use_count() << std::endl; // 2
    //     p1.reset();
    //     std::cout << "Use count: " << p1.use_count() << std::endl; // 0, p1 is nullptr
    //     std::cout << "Use count: " << p2.use_count() << std::endl; // 1
    // }

    {
        std::cout << "\n===Test part===" << std::endl;
        std::shared_ptr<Test> ptr = std::make_shared<Test> (100);
        func1(ptr); // 2, because func1 makes a copy of ptr
        std::cout << "Use count: " << ptr.use_count() << std::endl; // 1, because when func1 ends, the copied ptr in func1 get destroyed
        func2(ptr); // 1, because func2 takes ref 
        std::cout << "Use count: " << ptr.use_count() << std::endl; // 1 
    
        {
            std::shared_ptr<Test> ptr1 = ptr;
            std::cout << "Use count: " << ptr.use_count() << std::endl; // 2
            {
                std::shared_ptr<Test> ptr2 = ptr;
                std::cout << "Use count: " << ptr.use_count() << std::endl; // 3
                ptr.reset();
            }
            std::cout << "Use count: " << ptr.use_count() << std::endl; // 0
        }
        std::cout << "Use count: " << ptr.use_count() << std::endl; // 0
    }

    {
        std::cout << "\n===Account part===" << std::endl;
        std::shared_ptr<Account> acc1 = std::make_shared<Trust_Account> ("Larry", 10000, 3.1); 
        std::shared_ptr<Account> acc2 = std::make_shared<Checking_Account> ("Moe", 5000); 
        std::shared_ptr<Account> acc3 = std::make_shared<Savings_Account> ("Curly", 6000); 
    
        std::vector<std::shared_ptr<Account>*> accPtrVec;
        accPtrVec.push_back(&acc1);
        accPtrVec.push_back(&acc2);
        accPtrVec.push_back(&acc3);

        std::cout << "\naccPtrVec" << std::endl;
        for (const auto& acc : accPtrVec) {
            std::cout << **acc << std::endl;
            std::cout << "Use count: " << (*acc).use_count() << std::endl; 
            // 1, because accPtrVec did not copy, it takes a pointer that points to a share_ptr which points to an Account obj
        }

        std::vector<std::shared_ptr<Account>> accVec;
        accVec.push_back(acc1);
        accVec.push_back(acc2);
        accVec.push_back(acc3);

        std::cout << "\naccVec" << std::endl;
        for (const auto& acc : accVec) {
            std::cout << *acc << std::endl;
            std::cout << "Use count: " << acc.use_count() << std::endl; 
            // 2, because copied
        }

        std::cout << "\naccPtrVec again" << std::endl;
        for (const auto& acc : accPtrVec) {
            std::cout << **acc << std::endl;
            std::cout << "Use count: " << (*acc).use_count() << std::endl; 
            // also 2 now, because accVec
        }
    }

    return 0;
}