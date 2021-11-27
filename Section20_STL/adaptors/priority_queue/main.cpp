#include <iostream>
#include <queue>

class Person {
private:
    friend std::ostream& operator<< (std::ostream& os, const Person& p);
    std::string name;
    int age;
public:
    Person() : name {"Unknown"}, age {0} {};
    Person(std::string name, int age) 
        : name {name}, age {age} {}
    bool operator< (const Person& rhs) const {
        // return this->age < rhs.age; // order by age when comparing
        // return this->name < rhs.name; // order by name when comparing
        return this->name > rhs.name; // order by name, reversely
    }
    bool operator== (const Person& rhs) const {
        return (this->name == rhs.name && this->age == rhs.age);
    }
};


std::ostream& operator<< (std::ostream& os, const Person& p) {
    os << p.name << ": " << p.age;
    return os;
}


// This displays the priority queue by 
// repeatedly topping and popping the priority queue
// Note theat the priority queue is passed in value (a copy)
// so we don't affect the passed in queue
template <typename T>
void display(std::priority_queue<T> pq) { // passed in by value, created a copy
    std::cout << "top [ ";
    while (!pq.empty()) {
        T elem = pq.top();
        pq.pop();
        std::cout << elem << " ";
    }
    std::cout << "] back" << std::endl;
}


void test1 () {
    std::cout << "\n===test 1===" << std::endl;

    std::priority_queue<int> pq;

    for (int i : {3, 5, 6, 12, 23, 12, 4, 100, 0, 3, 5, 7}) {
        pq.push(i);
    }
    display(pq);

    std::cout << "size: " << pq.size() << std::endl;
    std::cout << "top: " << pq.top() << std::endl;

    pq.push(50);
    pq.push(17);
    pq.push(81);
    pq.push(8);
    display(pq);

    pq.pop();
    display(pq);

    pq.pop();
    pq.pop();
    pq.pop();
    display(pq);

    while (!pq.empty()) {
        pq.pop();
    }
    display(pq);

    pq.push(5);
    pq.push(3);
    pq.push(12);
    pq.push(1);
    display(pq);
}
void test2 () {
    std::cout << "\n===test 2===" << std::endl;

    std::priority_queue<Person> pq;
    pq.push(Person{"A", 10});
    pq.emplace("B", 1);
    pq.push(Person{"C", 14});
    pq.push(Person{"D", 18});
    pq.push(Person{"E", 7});
    pq.push(Person{"F", 27});

    display(pq);
}


int main (void)
{
    test1();
    test2();

    return 0;
}
