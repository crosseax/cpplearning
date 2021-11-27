#include <iostream>
#include <stack>
#include <vector>
#include <list>

// This function displays a stack of
// by repeatedly topping and popping the stack
// Note theat the stack is passed in value (a copy)
// so we don't affect the passed in stack

template <typename T>
void display(std::stack<T> s) { // passed in by value, created a copy
    std::cout << "top [ ";
    while (!s.empty()) {
        T elem = s.top();
        s.pop();
        std::cout << elem << " ";
    }
    std::cout << "] bottom" << std::endl;
}

void test1 () {
    std::cout << "===test 1===" << std::endl;

    std::stack<int> s;
    std::stack<int, std::vector<int>> sv;
    std::stack<int, std::list<int>> sl;
    std::stack<int, std::deque<int>> sd;

    for (int i : {1, 2, 3, 4, 5}) {
        s.push(i);
    }
    display(s); // Notice 5 is at the top, because LIFO (it's pushed the last)

    s.push(100);
    display(s);

    s.pop();
    s.pop();
    display(s);

    std::cout << "Size: " << s.size() << std::endl;

    while (!s.empty()) { // this is how you would clear a stack
        s.pop();
    }
    display(s);

    std::cout << "Size: " << s.size() << std::endl;

    s.push(10);
    display(s);

    s.top() = 100; // top() returns a reference of the top element
    display(s);
}

int main () {
    test1();

    return 0;
}