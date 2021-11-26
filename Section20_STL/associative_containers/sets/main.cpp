#include <set>
#include <string>
#include <iostream>


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
void display(const std::set<T>& set) {
    std::cout << "[ ";
    for (const auto& elem : set) {
        std::cout << elem << " ";
    }
    std::cout << "]" << std::endl;
}

void test1 () {
    std::cout << "\n===test 1===" << std::endl;

    std::set<int> s {1, 4, 3, 5, 2};
    display(s); // notice the result is sorted

    s = {1, 1, 2, 2, 3, 3, 3, 4, 5, 1, 1, 2, 3, 5};
    display(s); // notice the result is sorted

    s.insert(10);
    s.insert(0);
    display(s); // still automatically sorted

    if (s.count(10)) { // return 0 or 1
        std::cout << "10 is in the set" << std::endl;
    } else {
        std::cout << "10 is NOT in the set" << std::endl;
    }

    std::set<int>::iterator it = s.find(5);
    if (it != s.end()) { // found
        std::cout << "Found: " << *it << std::endl;
    }

    s.clear();
    display(s);
}

void test2 () {
    std::cout << "\n===test 2===" << std::endl;

    std::set<Person> stooges {
        {"Larry", 1},
        {"Moe", 2},
        {"Curly", 3}
    };
    display(stooges); // ordered by age, because it's using < operator

    stooges.emplace("James", 50);
    display(stooges);

    stooges.emplace("Frank", 50); 
    // NO, because we overloaded < operator, 
    // and that is used to determine 
    // if an element is in the set or not
    display(stooges); // No Frank 50

    std::set<Person>::iterator it = stooges.find(Person{"Moe", 2});
    // auto it = stooges.find(Person{"Moe", 2});
    if (it != stooges.end()) { // found
        stooges.erase(it); // remove Moe from set
    }
    display(stooges);

    it = stooges.find(Person{"XXXX", 50}); // will find James, because again, the < operator
    if (it != stooges.end()) { // found
        stooges.erase(it); // remove Moe from set
    }

    display(stooges);
}

void test3 () {
    std::cout << "\n===test 3===" << std::endl;

    std::set<std::string> s {"A", "B", "C"};
    display(s);

    auto result = s.insert("D");
    // std::pair<std::set<std::string>::iterator, bool> result = s.insert("D");
    display(s);

    std::cout << std::boolalpha;

    // result is a std::pair
    std::cout << "first: " << *(result.first) << std::endl;
    std::cout << "first: " << *result.first << std::endl;
    std::cout << "second: " << result.second << std::endl;

    result = s.insert("A");
    display(s);

    std::cout << "first: " << *(result.first) << std::endl;
    std::cout << "first: " << *result.first << std::endl;
    std::cout << "second: " << result.second << std::endl; // because A is already in there
}


int main (void)
{
    test1();
    test2();
    test3();

    return 0;
}