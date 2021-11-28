#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>

struct Square_Functor {
    void operator() (int x) {
        std::cout << x * x << " ";
    }
};


template <typename T>
struct Displayer {
    void operator() (const T& data) {
        std::cout << data << " ";
    }
};


void test1 () {
    std::cout << "\n===test 1===" << std::endl;
    Square_Functor square;

    square(4); // square.operator()(4); display 16
    // lambda expressions are converted into function objects like that above behind the scene

    Displayer<int> d1;
    Displayer<std::string> d2;

    d1(100); // d1.operator()(100); display 100
    d2("Frank"); // d2.operator()("Frank"); display Frank
    std::cout << std::endl;
}

void test2 () {
    std::cout << "\n===test 2===" << std::endl;
    Square_Functor square;

    std::vector<int> vec1 {1, 2, 3, 4, 5};
    std::vector<std::string> vec2 {"Larry", "Moe", "Curly"};

    std::for_each(vec1.begin(), vec1.end(), square); // passed in as fucntion object, also displaying
    std::cout << std::endl;

    Displayer<int> d1;
    Displayer<std::string> d2;

    std::for_each(vec1.begin(), vec1.end(), d1);
    std::cout << std::endl;

    std::for_each(vec1.begin(), vec1.end(), Displayer<int>());
    std::cout << std::endl;
    
    std::for_each(vec2.begin(), vec2.end(), d2);
    std::cout << std::endl;

    std::for_each(vec2.begin(), vec2.end(), Displayer<std::string>());
    std::cout << std::endl;
}

void test3 () {
    std::cout << "\n===test 3===" << std::endl;

    std::vector<int> vec1 {1, 2, 3, 4, 5};
    std::vector<std::string> vec2 {"Larry", "Moe", "Curly"};

    std::for_each(vec1.begin(),vec1.end(), 
        [] (int x) { std::cout << x * x << " "; } );
    std::cout << std::endl;

    std::for_each(vec1.begin(),vec1.end(), 
        [] (int x) { std::cout << x * 10 << " "; } );
    std::cout << std::endl;

    std::for_each(vec1.begin(),vec1.end(), 
        [] (int x) { std::cout << x << " "; } );
    std::cout << std::endl;

    std::for_each(vec2.begin(),vec2.end(), 
        [] (std::string s) { std::cout << s << " "; } );
    std::cout << std::endl;
}

void test4 () {
    std::cout << "\n===test 4===" << std::endl;

    
}

int main (void) 
{
    test1();
    test2();
    test3();
    test4();


    return 0;
}