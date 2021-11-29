// the most predominant use of lambdas 
// is in conjunction with the standard template algorithms library
// as either a predicate or operator

// once again, a predicate is just a function that takes bunch of args and return a boolean

// for more of the STL, see cppreference.com

// when hearing people use 
// unary, binary predicate or unary binary operations
// this simply referes to whether the lambda will 
// act as predicate or operator and how many parameters the lambda requires
// unary meaning one, binary meaning two

#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric> // for std::iota


// for test 5
class Person {
    friend std::ostream& operator<< (std::ostream& os, const Person& p);
private:
    std::string name;
    int age;
public:
    Person () = default;
    Person (std::string name, int age) : name {name}, age {age} {}
    // Person (const Person& p) : name {p.name}, age {p.age} {} // copy constructor
    Person (const Person& p) = default; // copy constructor
    ~Person() = default;

    std::string get_name() const { return name; }
    void set_name(std::string name) { this->name = name; }

    int get_age() const { return age; };
    void set_age(int age) { this->age = age; }
};

std::ostream& operator<< (std::ostream& os, const Person& p) {
    os << "[Person: " << p.name << ": " << p.age << "]";
    return os;
}

// for test 5
template <typename T>
void display_vector(std::vector<T> vec) {
    std::cout << "vec { ";
    for (T v : vec) {
        std::cout << v << " ";
    }
    std::cout << "}" << std::endl;
}

// for test 7
class Password_Validator1 {
private:
    char restricted_symbol {'$'};
public:
    bool is_valid(std::string password) {
        return std::all_of(password.begin(), password.end(), 
            [this] (char c) {
                return c != restricted_symbol;
            });
    };
};

class Password_Validator2 {
private:
    std::vector<char> restricted_symbols {'$', '!', '+'};
public:
    bool is_valid(std::string password) {
        // making sure that
        // all of the char in password
        // has none of the symbols in restricted_symbols
        return std::all_of(password.begin(), password.end(), 
            [this] (char c) {
                return std::none_of(restricted_symbols.begin(), restricted_symbols.end(), 
                    [&] (char symbol) {
                        return c == symbol;
                    });
            });
    };
};


// std::for_each - Non-modifying sequence operation
// Displays each element of nums
void test1() {
    std::cout << "\n===test 1===" << std::endl;

    std::vector<int> nums {10, 20, 30, 40, 50};

    std::for_each(nums.begin(), nums.end(), [] (int x) {
        std::cout << x << " ";
    });

    std::cout << std::endl;
}

// std::is_permutation - Non-modifying sequence operation
// loosely speaking, permutation is a set of mathematical ways of differently arrange a set of elements
// so this tests whether two triangles are equivalent
// triangles are defined by a vector of three points in any order
// regardless of the order of points 
// if two triangles contain the same three points then they are equivalent
// this is determined by testing 
// whether one sequence of points is a permutation of another 
// using a predicate lambda to compare points
void test2() {
    std::cout << "\n===test 2===" << std::endl;

    struct Point {
        int x;
        int y;
    };

    Point pt1 {1, 2};
    Point pt2 {4, 3};
    Point pt3 {3, 5};
    Point pt4 {3, 1};

    std::vector<Point> tri1 {pt1, pt2, pt3};
    std::vector<Point> tri2 {pt2, pt3, pt1};
    std::vector<Point> tri3 {pt1, pt2, pt4};

    if (std::is_permutation(tri1.begin(), tri1.end(), tri2.begin(), 
        [] (Point lhs, Point rhs) {
            return lhs.x == rhs.x && lhs.y == rhs.y;
        })) {
            std::cout << "Triangle1 and Triangle2 are equivalent!" << std::endl;
        } else {
            std::cout << "Triangle1 and Triangle2 are NOT equivalent!" << std::endl;
        }


    if (std::is_permutation(tri2.begin(), tri2.end(), tri3.begin(), 
        [] (Point lhs, Point rhs) {
            return lhs.x == rhs.x && lhs.y == rhs.y;
        })) {
            std::cout << "Triangle2 and Triangle3 are equivalent!" << std::endl;
        } else {
            std::cout << "Triangle2 and Triangle3 are NOT equivalent!" << std::endl;
        }
}

// std::transform - Modifying sequence operation
// the transform function applies 
// whatever operation is defined
// within the passed lambda to each element of the sequence
void test3() {
    std::cout << "\n===test 3===" << std::endl;

    std::vector<int> scores {93, 88, 75, 68, 65};
    int bonus {5};

    std::for_each(scores.begin(),scores.end(), 
        [] (int x) {
            std::cout << x << " ";
        });
    std::cout << std::endl;

    std::transform(scores.begin(), scores.end(), scores.begin(), 
        [bonus] (int x) {
            return x += bonus;
        });
    
    std::for_each(scores.begin(),scores.end(), 
        [] (int x) {
            std::cout << x << " ";
        });
    std::cout << std::endl;
}

// std::remove_if - Modifying sequence operation
// this example is what's known as an erase-remove idiom 
// and is one of the most common uses of lambdas with the STL
// the remove_if function removes all elements 
// for which the predicate lambda returns true
// the way in which it does this is by replacing each element 
// for which the predicate returned false
void test4() {
    std::cout << "\n===test 4===" << std::endl;

    std::vector<int> nums {1, 2, 3, 4, 5, 6, 7, 8};

    std::for_each(nums.begin(),nums.end(), 
        [] (int x) {
            std::cout << x << " ";
        });
    std::cout << std::endl;
    std::cout << nums.capacity() << std::endl;

    nums.erase(std::remove_if(nums.begin(), nums.end(), 
        // remove_if moves true element to the end of the vector
        [] (int x) {
            return x % 2 == 0;
        }),
        nums.end()); // use nums.end() as the new end of the vector

    std::for_each(nums.begin(),nums.end(), 
        [] (int x) {
            std::cout << x << " ";
        });
    std::cout << std::endl;
    std::cout << nums.capacity() << std::endl; 
    // notice the capacity is not changed, 
    // the memory is still reserved

    for (const auto& i : nums) {
        std::cout << i << " ";
    }
    std::cout << std::endl;
    nums.shrink_to_fit(); // mark those memory free
    std::cout << nums.capacity() << std::endl;
}

// std::sort - Modifying sequence operation - Sorting
// sorts elements in the sequence according to the predicate lambda
void test5() {
    std::cout << "\n===test 5===" << std::endl;

    std::vector<Person> stooges {
        {"Larry", 18},
        {"Moe", 30},
        {"Curly", 25}
    };

    std::for_each(stooges.begin(), stooges.end(), [] (const Person& p) {
        std::cout << p << std::endl;
    });
    std::cout << std::endl;


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


    // extra example
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

// for test 6
// std::all_of - Non modifying sequence operation
// tests whether all elements contained within the sequence
// satisfy the condition defined by the passed predicate lambda
bool in_between (const std::vector<int>& nums, int startVal, int endVal) {
    bool result {false};
    result = std::all_of(nums.begin(), nums.end(), 
        [&] (int val) {
            return val >= startVal && val <= endVal;
        });
    return result;
}

void test6() {
    std::cout << "\n===test 6===" << std::endl;

    std::cout << std::boolalpha;

    // not initializing, just setting element nums
    std::vector<int> nums(10); 
    // setting sequentially increasing value within that range starting from 1
    // so setting it to 1, 2, 3, ... , 10
    std::iota(nums.begin(), nums.end(), 1); 

    for (int x : nums) {
        std::cout << x << " ";
    }
    std::cout << std::endl;

    // using std::all_of from in_between() to check 
    // if all of vector's element is in between those startVal and endVal
    std::cout << "All vector numbers between 50 and 60 (include): " << in_between(nums, 50, 60) << std::endl;
    std::cout << "All vector numbers between 1 and 10 (include): " << in_between(nums, 1, 10) << std::endl;
    std::cout << "All vector numbers between 5 and 7 (include): " << in_between(nums, 5, 7) << std::endl;
}

void test7() {
    std::cout << "\n===test 7===" << std::endl;

    std::cout << "\t---password validator 1---" << std::endl;

    std::string password1 {"holywood1$"};
    std::string password2 {"hollywood1!"};
    Password_Validator1 pv1;

    if (pv1.is_valid(password1)) {
        std::cout << "The password (" << password1 << ") is valid!" << std::endl; 
    } else {
        std::cout << "The password (" << password1 << ") is NOT valid!" << std::endl; 
    }

    if (pv1.is_valid(password2)) {
        std::cout << "The password (" << password2 << ") is valid!" << std::endl; 
    } else {
        std::cout << "The password (" << password2 << ") is NOT valid!" << std::endl; 
    }

    std::cout << "\t---password validator 2---" << std::endl;

    std::string password3 {"C++Rocks!"};
    std::string password4 {"CplusplusRocks!"};
    std::string password5 {"CplusplusRocks"};
    Password_Validator2 pv2;

    if (pv2.is_valid(password3)) {
        std::cout << "The password (" << password3 << ") is valid!" << std::endl; 
    } else {
        std::cout << "The password (" << password3 << ") is NOT valid!" << std::endl;     
    }

    if (pv2.is_valid(password4)) {
        std::cout << "The password (" << password4 << ") is valid!" << std::endl; 
    } else {
        std::cout << "The password (" << password4 << ") is NOT valid!" << std::endl;     
    }

    if (pv2.is_valid(password5)) {
        std::cout << "The password (" << password5 << ") is valid!" << std::endl; 
    } else {
        std::cout << "The password (" << password5 << ") is NOT valid!" << std::endl;     
    }
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
