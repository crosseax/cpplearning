// What is STL Standard Template Library

// A library of powerful, reusable, adaptable, generic classes and functions
// Implemented using C++ templates
// Implements common data structures and algorithms
// Huge class library
// Alexander Stepanov (1994)



// Why use STL

// Assorment of commonly used containers
// Known time and size complexity
// Tried and tested - Reusable
// Consistent, fast and type-safe
// Extensible



// Three main components

// - Containers
    // Collections of objects or primitive types
    // - array, vector, deque, stack, set, map, etc

// - Algorithms
    // Functions for processing sequences of elements from containers
    // - find, max, count ,accumulate, sort, etc

// - Iterators
    // Generate sequences of element from containers
    // - forward, reverse, by value, by reference, constant, etc

// The three main components above are designed independent with each other
// yet they work seemsly




// Types of containers

// - Sequence containers
    // maintain the ordering of inserted elements
    // - array, vector, list, forward_list, deque

// - Associative containers
    // insert elements in a predefined order or no order at all
    // - set, multi set, map, multi map

// - Container adapters
    // are variations of the other container
    // dont support iterators so they can't be used with stl algorithms
    // but the stl still provides support because they are so commonly used
    // - stack, queue, priority queue



// Types of iterators

// Input iterators
    // from the container to the program

// Output iterators
    // from the program to the container

// Forward iterators
    // navigate one item at a time in one direction

// Bi-directional iterators
    // navigate one item at a time both directions

// Random access iterators
    // directly access a container item




// Types of algorithms
    // About 60 algorithms in the STL
// Non-modifying
// Modifying