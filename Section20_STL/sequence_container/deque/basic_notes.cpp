// std::deque (double ended queue)
// A good way to think of deque is a linked-list of vectors

// #include <deque>

// Dynamic size
    // handled automatically
    // can expand and contract as needed
    // elements are NOT stored in contiguous memory

// Direct element access (constant time), O(1)
// Rapid insertion and deletion at the front and back (constant time), O(1)
// Insertion or removal of elements (linear time)
// All iterators available and may invalidate




// std::deque<int> d1 {1, 2, 3, 4, 5};
// std::deque<int> d2 (10, 100); // ten 100s

// std::deque<std::string> stooges {
//     std::string{"Larry"},
//     "Moe",
//     std::string{"Curly"}
// };

// d1 = {2, 4, 6, 8, 10};



// std::deque<int> d {1, 2, 3, 4, 5};

    // d.size();        // 5
    // d.max_size();    // a very large number
    // d.at(0);         // 1, bounds checking
    // d[1];            // 2, no bounds checking

    // d.front();       // 1
    // d.back();        // 5


// Person p1 {"Larry", 18};
// std::deque<Person> d;

    // d.push_back();   // 
    // d.push_front(Person{"Dude", 25});  // 
    // d.pop_back();
    // d.pop_front();
    // d.clear();

    // d.emplace_back("Moe", 24);
    // d.emplace_front("Curly", 30)


// check en.cppreference.com for more info
