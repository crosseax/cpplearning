// std::stack

// Last-in First-out (LIFO) data structure
// Implemented as an adpter over other STL container.
// Can be implemented as a vector, list, or deque
// All operations occur on one end of the stack (top)
// No iterators are supported


// #include <stack>

// push - insert an element at the top of the stack
// pop - remove an element from the top of the stack
// top - access the top element of the stack
// empty - is the stack empty or not
// size - number of elements in the stack



// std::stack initialization

    // std::stack<int> s;                       // deque
    // std::stack<int, std::vector<int>> s1;    // vector
    // std::stack<int, std::list<int>> s1;      // list
    // std::stack<int, std::deque<int>> s1;     // deque