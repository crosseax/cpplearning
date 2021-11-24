// Algorithms

// STL algorithms work on sequences of container elements provided to them by an iterator
// STL has many common and useful algorithms
// Too many to describe in this note
    // check http://en.cppreference.com/w/cpp/algorithm
// Many algorithms require extra information in order to do their work
    // functors (function objects)
    // function pointers
    // lambda expressions (C++11)



// #include <algorithm>

// Different containers support different types of algorithms
    // and since algorithms depend on iterators
    // this determines the certain types of algorithms we can use with certain containers

// All STL algorithms expect iterators as arguments
    // this determines the sequence obtained from the container




// Iterator invalidation
    // Iterators point to container elements
    // It's possible iterators become invalid during processing
    // Suppose we are iterating over a vector of 10 elements
        // and we clear() the vector while iterating -
        // this is called - undefined behavior - out iterators are pointing to invalid locations
        // something to be aware of



// ep. find
    // The find algorithm tries to locate the first occurrence of an element in a container
    // lots of variations
    // returns an iterator pointing to the located element or end()

// std::vector<int> vec {1, 2, 3};
// auto loc = std::find(vec.begin(), vec.end(), 3);
// if (loc != vec.end()){              // if found it
//     std::cout << *loc << std::endl; // 3
// }
    
// find needs to be able to compare object
// operator== is used and must be provided by your class

// std::vector<Player> team {/* assume initialized */};
// Player p {"Hero", 100, 12};

// auto loc = std::find(team.begin(), team.end(), p);
// if (loc != vec.end()) {             // found
//     std::cout << *loc << std::endl; // operator<< overloaded
// }





// ep. for_each
    // for_each algorithm applies a function to each element in the iterator sequence
    // function must be provided to the algorithm as:
        // functor (function object)
        // function pointer
        // lambda expression (C++11)

// say lets square each element

// struct Square_Functor {
//     void operator() (int x) { // overload () operator
//         std::cout << x * x << " ";
//     }
// };

// Functor

// Square_Functor square; // function object
// std::vector<int> vec {1, 2, 3, 4};
// std::for_each(vec.begin(), vec.end(), square);
// // output: 1 4 9 16

// Function pointer

// void square(int x) { // function
//     std::cout << x * x << " ";
// }
// std::vector<int> vec {1, 2, 3, 4};
// std::for_each(vec.begin(), vec.end(), square); // no parenthesis, pass in a function pointer, which is really the address of function square() itself
// // output: 1 4 9 16

// Lambda expression (anonymous function)

// std::vector<int> vec {1, 2, 3, 4};
// std::for_each(vec.begin(), vec.end(), 
//     [](int x) { std::cout << x * x << " "; });
// // output: 1 4 9 16


