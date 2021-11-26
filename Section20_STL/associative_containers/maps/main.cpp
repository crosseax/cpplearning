#include <iostream>
#include <map>
#include <set>


void display(const std::map<std::string, std::set<int>>& m) {
    std::cout << "{ ";
    for (const auto& elem : m){
        std::cout << elem.first << ": [ ";
        for (const auto& set_elem : elem.second) {
            std::cout << set_elem << " ";
        }
        std::cout << "] ";
    }
    std::cout << "} " << std::endl;
}

template <typename T1, typename T2>
void display(const std::map<T1, T2>& m) {
    std::cout << "{ ";
    for (const auto& elem : m) {
        std::cout << elem.first << ": " << elem.second << " ";
    }
    std::cout << "} " << std::endl;
}

void test1() {
    std::cout << "\n===test 1===" << std::endl;

    std::map<std::string, int> m {
        {"Larry", 3},
        {"Moe", 1},
        {"Curly", 2}
    };
    display(m); // notice it's ordered by key, the string

    m.insert(std::pair<std::string, int> {"Anna", 10});
    display(m); // notice it's ordered by key, the string

    m.insert(std::make_pair("Joe", 5));
    display(m);

    m["Frank"] = 18; // this is like insert
    display(m);

    m["Frank"] += 10; // adding 10 to Frank's number (Key's value)
    display(m);

    m.erase("Frank");
    display(m);

    std::cout << "Count for Joe: " << m.count("Joe") << std::endl;
    std::cout << "Count for Frank: " << m.count("Frank") << std::endl;

    std::map<std::string, int>::iterator it = m.find("Larry");
    // auto it = m.find("Larry");
    if (it != m.end()) { // it is like a pointer to the pair
        std::cout << "Found: " << it->first << " : " << (*it).second << std::endl;
    }

    m.clear();
    display(m);
}

void test2() {
    std::cout << "\n===test 2===" << std::endl;

    std::map<std::string, std::set<int>> grades {
        {"Larry", {100, 90}},
        {"Moe", {94}},
        {"Curly", {80, 90, 100}}
    };

    display(grades);

    // [] operator returns a reference
    grades["Larry"].insert(95);     // insert 95 to Larry's set<int> (value)
    display(grades);

    std::map<std::string, std::set<int>>::iterator it = grades.find("Moe");
    // auto it = grades.find("Moe");
    if (it != grades.end()) { // Found Moe
        it->second.insert(1000); // it here acts like a pointer to a pair
        // (*it).second.insert(1000); // same as above
    }
    display(grades);
}   


int main (void)
{
    test1();
    test2();

    return 0;
}