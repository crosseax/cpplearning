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
#include <typeinfo>

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

template <typename T>
void display_vector(std::vector<T> vec) {
    std::cout << "vec { ";
    for (T v : vec) {
        std::cout << v << " ";
    }
    std::cout << "}" << std::endl;
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
    // <bool(int)>
        // this is a predicate lambda
        // it expects one or more parameters and returns a boolean
    // std::function<bool(int)> func: 
        // a function object 
        // that expects int parameter 
        // returns a boolean value
        // named func
// void filter_vector(const std::vector<int>& vec, auto func), C++20 syntax
    std::cout << "[";
    for (int i : vec) {
        if (func(i)) { 
            // if the elem in vec meet the func() requirement
            // you don't need to know what func does
            // all you need too know is that it expects an int and returns a bool
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

// used for test 5
auto make_lambda() { 
    return []() { std::cout << "This lambda was make using the make_lambda function" << std::endl; };
}

void test5() {
    std::cout << "\n===test 5===" << std::endl;

    auto l1 = make_lambda(); // calling a function, returns a lambda, but not executing it

    l1(); // executing/calling it
}

// using auto in the lambda parameter list
void test6() {
    std::cout << "\n===test 6===" << std::endl;

    auto l1 = [](auto x, auto y) {
        // always overload the operator<< for x and y that's passed in
        std::cout << "x: (" << x << ") is a ("<< typeid(x).name() << ") type" << std::endl;
        std::cout << "y: (" << y << ") is a ("<< typeid(y).name() << ") type" << std::endl << std::endl;
                                            // if wanna see details about typeid()
                                            // when run, use comand:
                                            // ./main | c++filt -t
                                            // this is a gcc compiler stuff, read more
    }; 

    l1 (10, 20.5);
    l1 ("Frank", 9.99);
    
    std::string s {"Crossea"};
    long long i {500};
    l1 (s, i);

    l1 (Person("Larry", 20), 't');
}

void test7() {
    std::cout << "\n===test 7===" << std::endl;

    std::vector<Person> stooges {
        {"Larry", 18},
        {"Moe", 30},
        {"Curly", 25}
    };

    /***
     * The algorithm used by sort() is IntroSort. 
     * Introsort being a hybrid sorting algorithm 
     * uses three sorting algorithm to minimize the running time, 
     * Quicksort, Heapsort and Insertion Sort. 
     * Simply putting, it is the best sorting algorithm around. 
     * It is a hybrid sorting algorithm, 
     * which means that it uses more than one sorting algorithms as a routine. 
    ***/
   
    std::sort(stooges.begin(), stooges.end(), 
        [](const Person& p1, const Person& p2) {
            return p1.get_name() < p2.get_name(); 
            // if p1 name is less than p2 name, p1 will be placed in the first element
            // also a predicate lambda, pass in some val, return a bool
        });
    
    std::for_each(stooges.begin(), stooges.end(), [] (const Person& p) {
        std::cout << p << std::endl;
    });
    std::cout << std::endl;


    std::sort(stooges.begin(), stooges.end(), 
        [](const Person& p1, const Person& p2) {
            return p1.get_age() < p2.get_age(); 
            // if p1 age is less than p2 age, p1 will be placed in the first element
            // also a predicate lambda, pass in some val, return a bool
        });

    std::for_each(stooges.begin(), stooges.end(), [] (const Person& p) {
        std::cout << p << std::endl;
    });

    std::cout << std::endl;
    
    std::vector<int> nums {1, 2, 3, 4, 5, 6, 7};

    std::sort(nums.begin(), nums.end(), [] (const int& x, const int& y) {
        return x > y; // if x is greater than y, x will be ordered before y
    });
    display_vector(nums);

    std::sort(nums.begin(), nums.end(), [] (const int& x, const int& y) {
        return x < y; // if x is greater than y, y will be ordered before x
    });
    display_vector(nums);
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

    return 0;
}