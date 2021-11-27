#include <iostream>
#include <queue>
#include <vector>
#include <list>

// This function displays a queue of
// by repeatedly removing elements from the front of the queue
// Note theat the queue is passed in value (a copy)
// so we don't affect the passed in queue

template <typename T>
void display(std::queue<T> q) { // passed in by value, created a copy
    std::cout << "front [ ";
    while (!q.empty()) {
        T elem = q.front();
        q.pop();
        std::cout << elem << " ";
    }
    std::cout << "] back" << std::endl;
}

void test1 () {
    std::cout << "===test 1===" << std::endl;

    std::queue<int> q;
    std::queue<int, std::list<int>> ql;
    std::queue<int, std::deque<int>> qd;

    for (int i : {1, 2, 3, 4, 5}) {
        q.push(i);
    }
    display(q); // Notice 5 is at the back, because FIFO (it'q pushed the last)

    std::cout << "front: " << q.front() << std::endl;
    std::cout << "back: " << q.back() << std::endl;

    q.push(100);
    display(q);

    q.pop();
    display(q);

    q.pop();
    display(q);

    while (!q.empty()) { // this is how you would clear a queue
        q.pop();
    }
    display(q);

    q.push(10);
    q.push(100);
    q.push(1000);
    display(q);

    std::cout << "front: " << q.front() << std::endl;
    std::cout << "back: " << q.back() << std::endl;

    q.front() = 50; // passed in by value so can modify
    q.back() = 5000; // passed in by value so can modify
    display(q);

    std::cout << "front: " << q.front() << std::endl;
    std::cout << "back: " << q.back() << std::endl;
}

int main () {
    test1();

    return 0;
}