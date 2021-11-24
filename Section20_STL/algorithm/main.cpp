#include <iostream>
#include <vector>
#include <list>
#include <algorithm>
#include <cctype> // toupper()

class Person {
private:
    std::string name;
    int age;
public:
    Person() = default;
    Person(std::string name, int age)
        : name {name}, age {age} {}
    bool operator< (const Person& rhs) const {
        return this->age < rhs.age;
    }
    bool operator== (const Person& rhs) const {
        return (this->name == rhs.name && this->age == rhs.age); 
    }
};

// find an element in a container
void find_test() {
    std::cout << "\n===find_test===" << std::endl;

    std::vector<int> vec {1, 2, 3, 4, 5};
    std::vector<int>::iterator loc = std::find(vec.begin(), vec.end(), 1);
    // auto loc = std::find(std::begin(vec), std::end(vec), 1);

    // Side note:
        // std::begin(vec) is more generic than vec.begin()

    if (loc != vec.end()) { // found it
    // if using like auto above, write condition like below
    // if (loc != std::end(vec)) {
        std::cout << "Found the number: " << *loc << std::endl;
    } else {
        std::cout << "Number not found" << std::endl;
    }


    std::list<Person> players {
        {"Larry", 18},
        {"Moe", 20},
        {"Curly", 21}
    };

    auto loc1 = std::find(players.begin(), players.end(), Person{"Moe", 20}); // this requires operator== overload
    if (loc1 != players.end()) {
        std::cout << "Found Moe" << std::endl;
    } else {
        std::cout << "Moe not found" << std::endl;
    }
}

// Count the number of elements in a container
void count_test() {
    std::cout << "\n===count_test===" << std::endl;

    std::vector<int> vec {1, 2, 3, 4, 5, 1, 2, 1};

    int num = std::count(vec.begin(), vec.end(), 1);
    std::cout << "Count: " << num << std::endl;
}

// Count the number of occurences of an element in a container
// based on a predicate using a lambda expression
void count_if_test() {
    std::cout << "\n===count_if_test===" << std::endl;

    std::vector<int> vec {1, 2, 3, 4, 5, 1, 2, 1, 100};

    int even = std::count_if(vec.begin(), vec.end(), 
        [] (int x) { return x % 2 == 0; }); // that match condition is called a predicate
    std::cout << "Even number counts: " << even << std::endl;

    int odd = std::count_if(vec.begin(), vec.end(), 
        [] (int x) { return x % 2 != 0; }); // that match condition is called a predicate
    std::cout << "Odd number counts: " << odd << std::endl;

    int num = std::count_if(vec.begin(), vec.end(), 
        [] (int x) { return x >= 5; });
    std::cout << "Numbers >= 5: " << num << std::endl;
}

// Replace occurrences of elements in a container
void replace_test() {
    std::cout << "\n===replace_test===" << std::endl;

    std::vector<int> vec {1, 2, 3, 4, 5, 1, 2, 1};
    for (auto i : vec) {
        std::cout << i << " ";
    }
    std::cout << std::endl;

    std::replace(vec.begin(), vec.end(), 1, 100);
    for (auto i : vec) {
        std::cout << i << " ";
    }
    std::cout << std::endl;
}

void all_of_test() { // also another algorithm call std::any_of
    std::cout << "\n===all_of_test===" << std::endl;

    std::vector<int> vec {1, 3, 5, 7, 9, 1, 3, 13, 19, 5};
    if (std::all_of(vec.begin(), vec.end(), [] (int x) { return x > 10; })) {
        std::cout << "All of the elements are > 10" << std::endl;
    } else {
        std::cout << "Not all of the elements are > 10" << std::endl;
    }
    
    if (std::all_of(vec.begin(), vec.end(), [] (int x) { return x < 20; })) {
        std::cout << "All of the elements are < 20" << std::endl;
    } else {
        std::cout << "Not all of the elements are < 20" << std::endl;
    }
}

// Transform occurrences of elements in a container
void string_transform_test() {
    std::cout << "\n===string_transform_test===" << std::endl;

    std::string str {"This is a test"};
    std::cout << "Before transform: " << str << std::endl;
    std::transform(str.begin(), str.end(), str.begin(), ::toupper); // ::toupper - global scope
    std::cout << "After transform: " << str << std::endl;
}

int main (void)
{
    find_test();
    count_test();
    count_if_test();
    replace_test();
    all_of_test();
    string_transform_test();

    return 0;
}