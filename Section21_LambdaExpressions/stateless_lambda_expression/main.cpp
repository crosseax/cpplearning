// stateless lambda expression

// [] empty capture list means that the expression captures no information from its environment
// and only knows about the information passed to it via the function parameter list
// this means that the lambda expression has no idea about the information assigned out side of it

// a preidcate 
// is a C++ function that takes any number of arguments and returns a boolean value

#include <iostream>
#include <string>
#include <vector>
#include <functional> // for std::function
#include <algorithm>

class Person {
    friend std::ostream& operator<< (std::ostream& os, const Person& p);
private:
    std::string name;
    int age;
public:
    Person (std::string name, int age) : name {name}, age {age} {}
    Person (const Person& p) : name {p.name}, age {p.age} {}
    ~Person() = default;

    std::string get_name() const { return name; }
    void set_name(std::string name) {
        this->name = name;
    }

    int get_age() const { return age; };
    void set_age(int age) {
        this->age = age;
    }
};

std::ostream& operator<< (std::ostream& os, const Person& p) {
    os << "[Person: " << p.name << ": " << p.age << "]";
    return os;
}

// structure and the syntax of the lambda expressions
void test1() {
    std::cout << "\n===test 1===" << std::endl;

    [] () { std::cout << "Hi" << std::endl; } (); // the last () calls the lambda function
    [] (int x) { std::cout << x << std::endl; } (100);
    [] (int x, int y) { std::cout << x + y << std::endl; } (300, 400);
}

// using values and references as lambda parameters
void test2() {
    std::cout << "\n===test 2===" << std::endl;

    auto l1 = [] () { std::cout << "Hi" << std::endl; }; // define l1 as lambda function
    l1(); // calls l1

    int num1 {100};
    int num2 {100};

    auto l2 = [] (int x, int y) { std::cout << x + y << std::endl; };
    l2 (10, 20);
    l2 (num1, num2);

    auto l3 = [] (int& x, int y) { // notice only x is passed in by reference
        std::cout << "x: " << x << " y: " << y << std::endl;
        x = 1000; // reference, the actual parameter is changed,
        y = 2000; // the local is changed, so actual y that's passed in is not changed
    };
    l3 (num1, num2);
    std::cout << "num1: " << num1 << " num2: " << num2 << std::endl; // only num1 changed
}

// using values and reference objects as lambda parameters
void test3() {
    std::cout << "\n===test 3===" << std::endl;

    Person stooge {"Larry", 18};
    std::cout << stooge << std::endl;

    auto l1 = [] (Person p) { // copy constructor, so this function will not affect the original
        std::cout << p << std::endl;
    };
    l1(stooge); // stooge did not change

    auto l2 = [] (const Person& p) { // alias, no copy constructor
        std::cout << p << std::endl;
    };
    l2(stooge); // showing the actual stooge

    auto l3 = [] (Person& p) {
        p.set_name("Frank");
        p.set_age(25);
        std::cout << p << std::endl;
    };
    l3(stooge); // actually changed

    std::cout << stooge << std::endl; // you can see it's actually changed
}

// used for test 4
// using std::function as parameter in C++14 and greater
// or 
// auto as parameter type in C++20
void filter_vector(const std::vector<int>& vec, std::function<bool(int)> func) { 
    // std::function<bool(int)> func: 
        // a function object 
        // that expects int parameter 
        // returns a boolean value
        // named func
// void filter_vector(const std::vector<int>& vec, auto func)
    std::cout << "[";
    for (int i : vec) {
        if (func(i)) { // if the elem in vec meet the func() requirement
            std::cout << i << " ";
        }
    }
    std::cout << "]" << std::endl;
}

void test4() {
    std::cout << "\n===test 4===" << std::endl;

    std::vector<int> nums {10, 20, 30, 40, 50, 60, 70, 80, 90, 100};

    filter_vector(nums, [] (int x) { return x > 50; });
    filter_vector(nums, [] (int x) { return x <= 30; });
    filter_vector(nums, [] (int x) { return x >= 30 && x <= 60; });
}

void test5() {
    std::cout << "\n===test 5===" << std::endl;
}

void test6() {
    std::cout << "\n===test 6===" << std::endl;
}

void test7() {
    std::cout << "\n===test 7===" << std::endl;
}



int main (void)
{
    test1();
    test2();
    test3();
    test4();
    test5();
    test6();
    test7();

    std::cout << std::endl;
    return 0;
}