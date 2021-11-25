#include <iostream>
#include <string>
#include <list>
#include <algorithm>
#include <iterator> // for std::advance


class Person {
private:
    friend std::ostream& operator<< (std::ostream& os, const Person& p);
    std::string name;
    int age;
public:
    Person()
        : name {"Unknown"}, age {0} {};
    Person(std::string name, int age)
        : name {name}, age {age} {}

    // when using our own class to STL
    // always overload < and == operator
    bool operator< (const Person& p) const {
        return this->age < p.age;
    }
    bool operator== (const Person& p) const {
        return (this->name == p.name && this->age == p.age); 
    }
};

std::ostream& operator<< (std::ostream& os, const Person& p) {
    os << p.name << ": " << p.age;
    return os;
}

// template function to display any list
template<typename T>
void display(const std::list<T>& vec) {
    std::cout << "[ ";
    for (const auto& elem : vec) {
        std::cout << elem << " ";
    }
    std::cout << "]" << std::endl;
}

void test1 () {
    std::cout << "\n===test 1===" << std::endl;

    std::list<int> l1 {1, 2, 3, 4, 5};
    display(l1);

    l1 = {5, 6, 7, 8, 9, 10};
    display(l1);

    std::list<int> l2 (10, 100); // ten 100s
    display(l2);

    std::list<std::string> l3;
    l3.push_back("Back");
    l3.push_front("Front");
    display(l3);
}

void test2 () {
    std::cout << "\n===test 2===" << std::endl;

    std::list<int> l {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    display(l);

    std::cout << "Size: " << l.size() << std::endl;
    std::cout << "Front: " << l.front() << std::endl;
    std::cout << "Back: " << l.back() << std::endl;

    l.clear();
    display(l);
    std::cout << "Size: " << l.size() << std::endl;
}

void test3 () {
    std::cout << "\n===test 3===" << std::endl;

    std::list<int> l {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    display(l);

    l.resize(5);
    display(l);

    l.resize(10); // when resize expand the size, push_back, not front
    display(l);

    std::list<Person> p;
    p.resize(5); // use overloaded default constructors
    // if did not overload the default constructor, then this will provide error
    display(p);
}


void test4 () {
    std::cout << "\n===test 4===" << std::endl;

    std::list<int> l1 {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    display(l1);

    std::list<int>::iterator it = std::find(l1.begin(), l1.end(), 5);
    // auto it = std::find(l1.begin(), l1.end(), 5);
    if (it != l1.end()){
        l1.insert(it, 100); // insert 100 before *it, in this case, 100 before 5
    }
    display(l1); 

    std::list<int> l2 {1000, 2000, 3000};
    l1.insert(it, l2.begin(), l2.end()); // you can also insert a range of things in
    display(l1);

    std::advance(it, -4); // iterator move backwards 4 unit, so points to 100
    std::cout << *it << std::endl;

    l1.erase(it); // this also invalidate the iterator
    display(l1);
}

void test5 () {
    std::cout << "\n===test 5===" << std::endl;

    std::list<Person> stooges {
        {"Larry", 18},
        {"Moe", 25},
        {"Curly", 22}
    };
    display(stooges);

    // std::string name;
    // int age{};
    // std::cout << "Enter the name of the next stooge: ";
    // std::getline(std::cin, name);
    // std::cout << "Enter the age of that stooge: ";
    // std::cin >> age;

    // stooges.emplace_back(name, age); // let the list create the object for me
    display(stooges);

    // Insert Frank before Moe
    std::list<Person>::iterator it = std::find(stooges.begin(), stooges.end(), Person{"Moe", 25}); // must overload the operator== to complete this step
    // auto it = std::find(stooges.begin(), stooges.end(), Person{"Moe", 25});
    if (it != stooges.end()) {
        stooges.emplace(it, "Frank", 30);
    }
    display(stooges);

}

void test6() {
    std::cout << "\n===test 6===" << std::endl;

    std::list<Person> stooges {
        {"Larry", 18},
        {"Moe", 25},
        {"Curly", 22}
    };
    display(stooges);

    stooges.sort(); // must overload the operator< for this to happen
    display(stooges);
}

int main (void)
{
    test1();
    test2();
    test3();
    test4();
    test5();
    test6();

    return 0;
}