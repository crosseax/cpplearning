#include <iostream>
#include <deque>
#include <vector>
#include <algorithm>

// the idea of using a deque
// is usually when you only need to add new element to the front or the back
// if you want to insert element in the middle
// using a list is probably more efficient

//template function to display any deque
template<typename T>
void display(const std::deque<T>& d) {
    std::cout << "[ ";
    for (const auto& elem : d) {
        std::cout << elem << " ";
    }
    std::cout << "]" << std::endl;
}


void test1() {
    std::cout << "\n===test 1===" << std::endl;
    
    std::deque<int> d1 {1, 2, 3, 4, 5};
    display(d1);

    d1 = {2, 4, 5, 6};
    display(d1);

    d1[0] = 100;
    d1.at(1) = 200;
    display(d1);

    std::deque<int> d2 (10, 100); // ten 100s
    display(d2);
}

// this is how you would typically use a deque
void test2() {
    std::cout << "\n===test 2===" << std::endl;

    std::deque<int> d {0, 0, 0};
    display(d);

    d.push_back(10);
    d.push_back(20);
    display(d);

    d.push_front(100);
    d.push_front(200);
    display(d);

    std::cout << "Front: " << d.front() << std::endl;
    std::cout << "Back: " << d.back() << std::endl;
    std::cout << "Size: " << d.size() << std::endl;

    d.pop_back();
    d.pop_front();
    display(d);
}

void test3() {
    std::cout << "\n===test 3===" << std::endl;

    std::vector<int> vec {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    std::deque<int> d;

    // push all the even numbers to the back of the deque
    // and odd numbers to the front

    for (const auto& v : vec) {
        if (v % 2 == 0) {
            d.push_back(v);
        } else {
            d.push_front(v);
        }
    }
    display(d);
}

void test4() {
    std::cout << "\n===test 4===" << std::endl;

    std::vector<int> vec {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    std::deque<int> d;

    for (const auto& v : vec) {
        d.push_front(v);
    }
    display(d);

    d.clear();

    for (const auto& v : vec) {
        d.push_back(v);
    }
    display(d);
}

void test5() {
    std::cout << "\n===test 5===" << std::endl;

    std::vector<int> vec {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    std::deque<int> d;

    std::copy(vec.begin(), vec.end(), std::front_inserter(d));
    display(d);

    d.clear();
    std::copy(vec.begin(), vec.end(), std::back_inserter(d));
    display(d);
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