// what is a Class template

// similar to function template, but at the class level
// allows plugging-in any data type
// compiler generates the appropriate class from the blueprint

// like std::vector<T> (when we what a vector of type T)

// CANNOT overload class within the same namespace


// Template classes are typically conpletely contained in header files (.h)
// So, we would have the template class in item.h and no item.cpp file
// Because the compiler is not compiling the blueprint
// it's basically using it to create a specialized version of it that will later be compiled


#include <iostream>
#include <string>
#include <vector>

template <typename T> // this is also called a decorator, typically, a template decorator
class Item {
private:
    std::string name;
    T value;
public:
    Item(std::string name, T value) 
        : name {name}, value {value} {}
    std::string get_name() const { return name; }
    T get_value() const { return value; }

    friend std::ostream& operator<< (std::ostream& os, const Item<T>& obj) {
        os << obj.get_name() << " " << obj.get_value();
        return os;
    }
};

template <typename T1, typename T2>
struct My_Pair {
    T1 first;
    T2 second;
};


int main (void)
{
    Item<int> item1 {"Frank", 100};
    std::cout << item1.get_name() << " " << item1.get_value() << std::endl;

    Item<std::string> item2 {"Good", "Dude"};
    std::cout << item2.get_name() << " " << item2.get_value() << std::endl;
    
    Item<Item<std::string>> item3 {"Great", {"C++", "Professor"}};
    std::cout << item3.get_name() << " " 
              << item3.get_value().get_name() << " "
              << item3.get_value().get_value() << std::endl;
    
    std::cout << item3 << std::endl;

    std::cout << "===========" << std::endl;


    return 0;
}
