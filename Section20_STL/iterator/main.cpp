#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <list>

// display any vector of integers using rage-based for loop
void display(const std::vector<int>& vec) {
    std::cout << "[ ";
    for (auto const& v : vec) {
        std::cout << v << " ";
    }
    std::cout << "]" << std::endl;
}

void test1() {
    std::cout << "\n===test1===" << std::endl;
    std::vector<int> nums1 {1, 2, 3, 4, 5};

    // std::vector<int>::iterator it = nums1.begin();
    auto it = nums1.begin(); // points to 1
    // remember, it is not a pointer, it's an object,
    // its just the syntax design makes it act like an pointer
    // which is for the sake of ease to use
    std::cout << *it << std::endl;

    it++; // points to 2
    std::cout << *it << std::endl;

    it += 2; // points to 4
    std::cout << *it << std::endl;
    
    it -= 2; // points to 2
    std::cout << *it << std::endl;

    it = nums1.end() - 1; // points to 5 (IMPORTANT)
    std::cout << *it << std::endl;
}


void test2() {
    std::cout << "\n===test2===" << std::endl;
    
    // display all vector elements using an iterator
    std::vector<int> nums1 {1, 2, 3, 4, 5};
    std::vector<int>::iterator it = nums1.begin();
    while (it != nums1.end()) {
        std::cout << *it << " ";
        it++;
    }
    std::cout << std::endl;

    // change all vector elements to 0
    it = nums1.begin();
    while (it != nums1.end()) {
        *it = 0;
        it++;
    }

    display(nums1);
}


void test3() {
    std::cout << "\n===test3===" << std::endl;
    // using a const_iterator (read-only iterator)
    std::vector<int> nums1 {1, 2, 3, 4, 5};

    std::vector<int>::const_iterator cit = nums1.begin();
    // auto cit = nums1.cbegin(); 
    // use cbegin() otherwise the auto will provide a regular iterator

    while (cit != nums1.end()) {
        std::cout << *cit << " ";
        cit++;
    }
    std::cout << std::endl;

    // change all vector elements to 0
    cit = nums1.begin();
    while (cit != nums1.end()) {
        // *cit = 0; // compiler error, read only
        cit++;
    }

    display(nums1);
}


void test4() {
    std::cout << "\n===test4===" << std::endl;
    // more iterators

    // using a reverse iterator
    std::vector<int> vec {1, 2, 3, 4, 5};
    std::vector<int>::reverse_iterator rit = vec.rbegin();
    // auto rit = vec.rbegin(); // use rbegin()

    while (rit != vec.rend()) {
        std::cout << *rit << " ";
        rit++; 
        // for reverse_iterator, rit++ is moving backwards
    }
    std::cout << std::endl;
    rit--; // points to 1
    std::cout << *rit << std::endl;

    rit -= 2; // points to 3
    std::cout << *rit << std::endl;

    std::cout << std::endl;

    // const reverse iterator over a list
    std::list<std::string> namelist {"Larry", "Moe", "Curly"};
    // a list is basically a doubly linked list
    // so vector is contiguous memory
    // but the list is not necessarily
    std::list<std::string>::const_reverse_iterator crit = namelist.crbegin(); // points to Curly
    // auto crit = namelist.crbegin(); // use crbegin()
    while (crit != namelist.crend()) {
        std::cout << *crit << " ";
        crit++; 
    }

    std::cout << std::endl;

    crit--; // points to Larry
    std::cout << *crit << std::endl;
    // crit -= 2; // CANNOT, because this is a list
    // to use += or -= etc with list, you need to overload them
    std::cout << *crit << std::endl;

    std::cout << std::endl;

    // iterator over a map
    std::map<std::string, std::string> favorites {
        {"Frank", "C++"},
        {"Bill", "Java"},
        {"James", "Haskell"}
    };

    // map is key-value pairs
    std::map<std::string, std::string>::iterator it = favorites.begin();
    // auto it = favorites.begin();
    while (it != favorites.end()) {
        std::cout << it->first << ": " << it->second << std::endl;
        it++;
    }
    // IMPORTANT: notice the output order is not necessarily the initializing order above
}


void test5() {
    std::cout << "\n===test5===" << std::endl;

    // iterate over a subset of a container
    std::vector<int> vec {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    std::vector<int>::iterator start = vec.begin() + 2; // points to 3
    // auto start = vec.begin();
    std::vector<int>::iterator finish = vec.end() - 3; // points to 8
    // auto finish = vec.end();

    while (start != finish) {
        std::cout << *start << std::endl;
        start++;
    }
    
    std::cout << std::endl;

    start = vec.begin();
    finish = vec.end() - 1; // important if you want to show *finish

    while (start < finish) {
        std::cout << *start << " " << *finish << std::endl;
        start++;
        finish--;
    }
}


int main (void) 
{
    test1();
    test2();
    test3();
    test4();
    test5();

    return 0;
}