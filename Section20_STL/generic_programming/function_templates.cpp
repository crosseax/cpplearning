// Generic programming with function templates

// What is a C++ template
    // Blueprint
    // Function and class templates
    // Allow plugging-in any data type
    // Compiler generates the appropriate function/class from the blueprint
    // Generic programming / Meta-programming


// ep.

    // template <typename T> // same as template <class T>
    // // type T will be replaced by whatever the user need
    // T max(T a, T b) {
    //     return (a > b) ? a : b;
    // }
    // // This will compile, but will NOT generate any code

    // // how to use it
    // max<int>(a, b);
    // max<double>(c, d)
    // // this part generates the code


    // // multiple typename - OK
    // template<typename T1, typename T2>
    // void func(T1 a, T2 b) {
    //     std::cout << a << " " << b;
    // }

    // func<int, double>(a, b); // int a, double b


#include <iostream>
#include <string>

template<typename T>
T min(T a, T b) {
    return (a < b) ? a : b;
}

template<typename T1, typename T2>
void func(T1 a, T2 b) {
    std::cout << a << " " <<  b << std::endl;
}

template<class T> // same as template<typename T>
void my_swap(T& a, T& b) {
    T temp = a;
    a = b;
    b = temp;
}

struct Person {
    std::string name;
    int age;
    bool operator<(const Person& rhs) const {
        return this->age < rhs.age;
    }
};

std::ostream& operator<< (std::ostream& os, const Person& p) {
        os << p.name;
        return os;
    }


int main (void)
{
    std::cout << min<int>(2, 3) << std::endl;   // 2
    std::cout << min(2, 3) << std::endl;        // 2
    std::cout << min('A', 'B') << std::endl;    // A
    std::cout << min(12.5, 14.9) << std::endl;  // 12.5
    std::cout << min(5+2*2, 7+40) << std::endl; // 2

    std::cout << "==========" << std::endl;

    Person p1 {"Curly", 50};
    Person p2 {"Moe", 30};

    Person p3 = min(p1, p2); // needs overload < operator, otherwise it wont compile
    std::cout << p3.name << " " << p3.age << std::endl;

    std::cout << "==========" << std::endl;

    func<int,int>(10, 20);
    func(10, 20);
    func<char, double>('A', 14.5);
    func(1000, "Testing");
    func(2000, std::string("Frank"));

    std::cout << "==========" << std::endl;

    func(p1, p2); // needs to overload the << operator

    std::cout << "==========" << std::endl;

    int x {100};
    int y {200};
    std::cout << x << " " << y << std::endl;
    my_swap(x, y);
    std::cout << x << " " << y << std::endl;

    char a {'a'};
    char b {'b'};
    std::cout << a << " " << b << std::endl;
    my_swap(a, b);
    std::cout << a << " " << b << std::endl;

    return 0;
}
