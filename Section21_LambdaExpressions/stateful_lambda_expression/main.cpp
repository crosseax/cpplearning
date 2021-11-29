// stateful lambda expression

// [caotured_variables] Non-empty capture list,
// defines what information/variables should be captured

// by capturing
// what is referring to is the llambdas ability to 
// use variables decalred within its reaching
// this is accomplished by simply listing the variables 
// we would like the limit to use within its capture list


// when defining a stateful lambda capture list, 
// we're defining the parameterize constructor of the lambdas compiler generated closure

// [=] default capture by value
// [&] default capture by reference
// [this] default capture this object by reference

// [=, &x] default capture by value but capture x by reference
// [&, y] default capture by reference but capture y by value
// [this, z] default capture this by reference but capture z by value



#include <iostream>
#include <string>
#include <vector>
#include <algorithm>


int global_x {1000};

// Used for test 8
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

    auto change_person_this() { 
        // always use this one
        return [this] (std::string newName, int newAge) {
            name = newName;
            age = newAge;
        };
    }

    auto change_person_value() { 
        // deprecated in c++20, because it is also captured by value
        return [=] (std::string newName, int newAge) {
            name = newName;
            age = newAge;
        };
    }

    auto change_person_reference() { 
        return [&] (std::string newName, int newAge) {
            name = newName;
            age = newAge;
        };
    }
};

std::ostream& operator<< (std::ostream& os, const Person& p) {
    os << "[Person: " << p.name << ": " << p.age << "]";
    return os;
}


// Used for test 9
class Lambda {
private:
    int y;
public:
    Lambda(int y) : y{y} {}

    void operator() (int x) const {
        std::cout << x + y << std::endl;
    }
};

// Used for test 10
class People {
private:
    std::vector<Person> people;
    int max_people_showing;
public:
    People(int max = 10) : max_people_showing {max} {} // overloaded constructor with a default value
    People(const People& p) = default; // copy constructor

    void add(std::string name, int age) {
        people.emplace_back(name, age);
    }

    void set_max_people_showing(int max) {
        max_people_showing = max;
    }

    int get_max_people_showing() const {
        return max_people_showing;
    }

    // This method returns a vector of Person objects in people
    // whose age > max_age AND it limits the number of persons returned
    // to be <= the member variable max_people_showing
    // Note that the lambda in this example captures [this], by reference and by value
    std::vector<Person> get_people_older_than(int max_age) {
        std::vector<Person> result;
        int count{0};
        std::copy_if(people.begin(), people.end(), std::back_inserter(result), 
            [this, &count, max_age] (const Person& p) {
            // this - instance variable in this class
            // &count - local variable count by reference
            // max_age - function parameter captured by value
                return p.get_age() > max_age && ++count <= max_people_showing;
                                                // pre-increment count 
                                                // and make sure it's no greater than max_people
            });
        return result;
    }
};

// Capture by value - default capture mode
// the global variable global_x cannot be captured 
// because it is not within the reaching schope of the lambda
// it can however still be accessed from within the lambda using normal name lookup rules

// cannot capture global or static variables
void test1 () {
    std::cout << "\n===test 1===" << std::endl;

    int local_x {100}; 
    auto l = [local_x] () { // this local_x is a copy
        std::cout << local_x << std::endl;
        std::cout << global_x << std::endl;
    };
    l();

    std::cout << local_x << std::endl;
}

// Capture by value - mutable
// the captured variable x can only be modified within the lambda
// by using the mutable keyword
// note that this modifiability only pertains 
// to the captured variable within the lambda body and not the actual variable
void test2 () {
    std::cout << "\n===test 2===" << std::endl;

    int x {100};

    // created a closure class
    auto l = [x] () mutable { // called constructor
        x += 100; // incrementing the local value, the copy, not the real one
        std::cout << x << std::endl;
    };

    l(); // operator() called， 200
    std::cout << x << std::endl; // still 100

    l(); // operator() called, 300
    std::cout << x << std::endl; // still 100
}

// Capture by reference 
// any changes made to the captured reference variable 
// within the lambda body will change the actual value
void test3 () {
    std::cout << "\n===test 3===" << std::endl;

    int x {100};

    auto l = [&x] () mutable {
        x += 100;
        std::cout << x << std::endl;
    };

    l();
    std::cout << x << std::endl;

    l();
    std::cout << x << std::endl;
}

// Default capture by value - mutable
// only variables used within the lambda body are captured by value
// the variable z is not captured by the lambda
void test4 () {
    std::cout << "\n===test 4===" << std::endl;

    int x {100};
    int y {200};
    int z {300};    // if z is not captured in the lambda
                    // it would provide a warning when compiling of "unused variable"

    auto l = [=] () mutable {
        x += 111;
        y += 122;
        std::cout << x << std::endl;
        std::cout << y << std::endl;
        std::cout << z << std::endl;
    };

    l();

    std::cout << std::endl;

    l();

    std::cout << std::endl; 

    std::cout << x << std::endl;
    std::cout << y << std::endl;
    std::cout << z << std::endl;
}

// Default capture by reference
// this time because all three variables - xyz are used within the lambda body
// all three of them will be captured by reference
void test5 () {
    std::cout << "\n===test 5===" << std::endl;

    int x {100};
    int y {200};
    int z {300};

    auto l = [&] () {
        x += 150;
        y += 150;
        z += 150;
        std::cout << x << std::endl;
        std::cout << y << std::endl;
        std::cout << z << std::endl;
    };

    l();

    std::cout << std::endl;

    std::cout << x << std::endl;
    std::cout << y << std::endl;
    std::cout << z << std::endl;
}

// Default capture by value, 
// capture y by reference
void test6 () {
    std::cout << "\n===test 6===" << std::endl;

    int x {100};
    int y {200};
    int z {300};

    auto l = [=, &y] () mutable {
        x += 150;
        y += 150;
        z += 150;
        std::cout << x << std::endl;
        std::cout << y << std::endl;
        std::cout << z << std::endl;
    };

    l();

    std::cout << std::endl;

    std::cout << x << std::endl;
    std::cout << y << std::endl;
    std::cout << z << std::endl;
}

// Default capture by reference
// capture x and z by value
void test7 () {
    std::cout << "\n===test 7===" << std::endl;

    int x {100};
    int y {200};
    int z {300};

    auto l = [&, x, z] () mutable {
        x += 130;
        y += 130;
        z += 130;
        std::cout << x << std::endl;
        std::cout << y << std::endl;
        std::cout << z << std::endl;
    };

    l();

    std::cout << std::endl;

    std::cout << x << std::endl;
    std::cout << y << std::endl;
    std::cout << z << std::endl;
}

void test8 () {
    std::cout << "\n===test 8===" << std::endl;

    Person stooge {"Larry", 18};
    std::cout << stooge << std::endl;

    // Default capture [this]
    // the preferred way
    auto change_person1 = stooge.change_person_this();
    change_person1("Moe", 30);
    std::cout << stooge << std::endl;

    // Default capture [=]
    // deprecated in c++20, DONT use this plz
    auto change_person2 = stooge.change_person_value();
    change_person2("Curly", 27);
    std::cout << stooge << std::endl;

    // Default capture [&]
    auto change_person3 = stooge.change_person_reference();
    change_person3("Frank", 34);
    std::cout << stooge << std::endl;
}

// Lambda class equivalence example
void test9 () {
    std::cout << "\n===test 9===" << std::endl;

    int y {100};

    // for below
    // the class Lambda above is just like what expression l2 would generate
    // that's how lambda works behind the scene
    Lambda l1 (y); // constructor
    auto l2 = [y] (int x) { std::cout << y + x << std::endl; };

    l1(200); // calling overloaded operator() method within the class
    l2(200); // calling lambda function, same result

    l1(350); // calling overloaded operator() method within the class
    l2(350); // calling lambda function, same result
}

void test10 () {
    std::cout << "\n===test 10===" << std::endl;

    People friends;
    friends.add("Larry", 18);
    friends.add("Moe", 25);
    friends.add("Curly", 35);
    friends.add("Frank", 28);
    friends.add("James", 65);
    friends.add("Garry", 9);
    friends.add("KC", 54);

    auto result = friends.get_people_older_than(17);
    for (const auto& p : result) {
        std::cout << p << std::endl;
    }

    std::cout << std::endl;

    // changing the attribute
    // but not actually getting rid of Persons in it
    // so it only shows 3 result
    friends.set_max_people_showing(3); 

    result = friends.get_people_older_than(17);    
    for (const auto& p : result) {
        std::cout << p << std::endl;
    }

    std::cout << std::endl;

    result = friends.get_people_older_than(50);
    for (const auto& p : result) {
        std::cout << p << std::endl;
    }

    std::cout << std::endl;

    friends.set_max_people_showing(5);

    result = friends.get_people_older_than(1);
    for (const auto& p : result) {
        std::cout << p << std::endl;
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
    test8();
    test9();
    test10();

    return 0;
}