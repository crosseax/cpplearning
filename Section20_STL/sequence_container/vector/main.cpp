#include <iostream>
#include <vector>
#include <algorithm>


class Person {
private:
    friend std::ostream& operator<< (std::ostream& os, const Person& p);
    std::string name;
    int age;
public:
    Person() = default;
    Person(std::string name, int age)
        : name {name}, age {age} {
            std::cout << "Person constructor" << std::endl;
        }

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

// Use for_each and a lambda expression to display vector elements
void display_int(const std::vector<int>& vec) {
    std::cout << "[ ";
    std::for_each(vec.begin(), vec.end(), 
        [] (int x) { std::cout << x << " ";});
    std::cout << "]" << std::endl;
}


// template function to display any vector
template<typename T>
void display(const std::vector<T>& vec) {
    std::cout << "[ ";
    for (const auto& elem : vec) {
        std::cout << elem << " ";
    }
    std::cout << "]" << std::endl;
}


void test1 () {
    std::cout << "\n===test 1===" << std::endl;

    std::vector<int> vec {1, 2, 3, 4, 5};
    display_int(vec);

    std::vector<int> vec2 {10, 100}; // ten 100s 
    display(vec2);
}

void test2 () {
    std::cout << "\n===test 2===" << std::endl;
    
    std::vector<int> vec {1, 2, 3, 4, 5};
    display(vec);
    std::cout << "vec size: "<< vec.size() << std::endl;
    std::cout << "vec max size: "<< vec.max_size() << std::endl; // depends on your memory and the element type
    std::cout << "vec vec capacity: "<< vec.capacity() << std::endl;
    std::cout << std::endl;

    vec.push_back(6);
    display(vec);
    std::cout << "vec size: "<< vec.size() << std::endl;
    std::cout << "vec max size: "<< vec.max_size() << std::endl;
    std::cout << "vec capacity: "<< vec.capacity() << std::endl; // usually double the original size
    std::cout << std::endl;

    vec.shrink_to_fit(); // C++11, capacity to size
    display(vec);
    std::cout << "vec size: "<< vec.size() << std::endl;
    std::cout << "vec max size: "<< vec.max_size() << std::endl;
    std::cout << "vec capacity: "<< vec.capacity() << std::endl;
    std::cout << std::endl;

    vec.reserve(100); // reserve size
    display(vec);
    std::cout << "vec size: "<< vec.size() << std::endl;
    std::cout << "vec max size: "<< vec.max_size() << std::endl;
    std::cout << "vec capacity: "<< vec.capacity() << std::endl;

}

void test3 () {
    std::cout << "\n===test 3===" << std::endl;

    std::vector<int> vec {1, 2, 3, 4, 5};
    display(vec);

    vec[0] = 100;
    vec.at(1) = 200;

    display(vec);
}

void test4 () {
    std::cout << "\n===test 4===" << std::endl;
    
    std::vector<Person> stooges;
    display(stooges);

    Person p1 {"Larry", 18};
    stooges.push_back(p1);
    display(stooges);

    stooges.push_back(Person{"Moe", 25}); // move sementics
    display(stooges);

    stooges.emplace_back("Curly", 30);
    display(stooges);
}

void test5 () {
    std::cout << "\n===test 5===" << std::endl;

    std::vector<Person> stooges {
        {"Larry", 18},
        {"Moe", 25},
        {"Curly", 30}
    };

    display(stooges);

    std::cout << "Front: " << stooges.front() << std::endl;
    std::cout << "Back: " << stooges.back() << std::endl;
    std::cout << "*stooges.begin(): " << *stooges.begin() << std::endl;
    std::cout << "*(stooges.end() - 1): " << *(stooges.end() - 1) << std::endl;

    stooges.pop_back();
    display(stooges);
}

void test6 () {
    std::cout << "\n===test 6===" << std::endl;

    std::vector<int> vec {1, 2, 3, 4, 5};
    display(vec);
    std::cout << "vec capacity now: "<< vec.capacity() << std::endl;

    vec.clear(); // remove all the elements
    display(vec);
    std::cout << "vec capacity now: "<< vec.capacity() << std::endl;

    vec = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    display(vec);
    std::cout << "vec capacity now: "<< vec.capacity() << std::endl;
    
    std::vector<int>::iterator it = vec.begin();
    // auto it = vec.begin();
    // remove all even numbers
    while (it != vec.end()) {
        if (*it % 2 == 0) {
            vec.erase(it); // it acts like pointer
        } else {
            it++;
        }
    }
    display(vec);
    std::cout << "vec capacity now: "<< vec.capacity() << std::endl;
}

void test7 () {
    std::cout << "\n===test 7===" << std::endl;

    std::vector<int> vec1 {1, 2, 3, 4, 5};
    std::vector<int> vec2 {10, 20, 30, 40, 50, 60};

    int* ptr1;
    int* ptr2;
    ptr1 = vec1.data();
    ptr2 = vec2.data();

    display(vec1);
    // std::cout << "vec1 capacity now: " << vec1.capacity() << std::endl;
    std::cout << vec1.data() << " [ vec1.data() ]" << std::endl;
    std::cout << ptr1 << " [ ptr1 ]" << std::endl;
    display(vec2);
    // std::cout << "vec2 capacity now: " << vec2.capacity() << std::endl;
    std::cout << vec2.data() << " [ vec2.data() ]" << std::endl;
    std::cout << ptr2 << " [ ptr2 ]" << std::endl;
    
    std::cout << "\nswap\n" << std::endl;

    vec1.swap(vec2); // so this swaps the pointer that points to the vector

    display(vec1);
    // std::cout << "vec1 capacity now: " << vec1.capacity() << std::endl;
    std::cout << vec1.data() << " [ vec1.data() ]" << std::endl;
    std::cout << ptr1 << " [ ptr1 ]" << std::endl;
    display(vec2);
    // std::cout << "vec2 capacity now: " << vec2.capacity() << std::endl;
    std::cout << vec2.data() << " [ vec2.data() ]" << std::endl;
    std::cout << ptr2 << " [ ptr2 ]" << std::endl;
}

void test8 () {
    std::cout << "\n===test 8===" << std::endl;

    std::vector<int> vec {1, 21, 3, 40, 12};
    display(vec);

    std::sort(vec.begin(), vec.end());
    display(vec);
}

void test9 () {
    std::cout << "\n===test 9===" << std::endl;

    std::vector<int> vec1 {1, 2, 3, 4, 5};
    std::vector<int> vec2 {10, 20};

    display(vec1);
    display(vec2);

    std::cout << std::endl;

    std::copy(vec1.begin(), vec1.end(), std::back_inserter(vec2));

    display(vec1);
    display(vec2);

    std::cout << std::endl;

    // copy if the element is even
    vec1 = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    vec2 = {10, 20};

    display(vec1);
    display(vec2);

    std::cout << std::endl;

    std::copy_if(vec1.begin(), vec1.end(), std::back_inserter(vec2), 
        [] (int x) { return x % 2 == 0; });

    display(vec1);
    display(vec2);
}

void test10 () {
    std::cout << "\n===test 10===" << std::endl;

    // transform over 2 ranges
    std::vector<int> vec1 {1, 2, 3, 4, 5};
    std::vector<int> vec2 {10, 20, 30, 40, 50};
    std::vector<int> vec3;

    std::transform(vec1.begin(), vec1.end(), vec2.begin(), std::back_inserter(vec3), 
        [] (int x, int y) { return x * y; });

    display(vec1);
    display(vec2);
    display(vec3);
}

void test11 () {
    std::cout << "\n===test 11===" << std::endl;

    std::vector<int> vec1 {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    std::vector<int> vec2 {100, 200, 300, 400};

    display(vec1);
    display(vec2);

    std::cout << std::endl;


    std::vector<int>::iterator it; 
    // put it before where you want to insert
    // in this case, before 5
    it = std::find(vec1.begin(), vec1.end(), 5); 
    if (it != vec1.end()) {
        std::cout << "Inserting\n" << std::endl;
        vec1.insert(it, vec2.begin(), vec2.end());
    } else {
        std::cout << "Sorry, 5 not found " << std::endl;
    }
    display(vec1);
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
    test8();
    test9();
    test10();
    test11();

    return 0;
}