// Set containers

// Associative containers
    // collection of stored objects that allow fast retrieval using a key
    // STL provides sets and maps
    // usually implemented as a balanced binary tree or hashsets
    // most operations are very efficient

// sets
    // std::set
    // std::unordered_set
    // std::multiset
    // std::unordered_multiset

// std::set

    // #include <set>

    // Similar to a mathematical set
    // Ordered by key
    // No duplicate elements
    // All iterators available and invalidate when corresponding element is deleted


// std::multi_set

    // #include <set>

    // Sorted by key
    // Allows duplicate elements
    // All iterators are available


// std::unordered_set

    // #include <unordered_set>

    // Elements are unordered
    // No duplicate elements allowed
    // Elements cannot be modified
        // must be erased and new element inserted
    // No reverse iterators are allowed


// std::unordered_multiset

    // #include <unordered_set>

    // Elements are unordered
    // Allows duplicate elements
    // No reverse iterators are allowed






    // std::set<int> s {1, 2, 3, 4, 5};

    // std::set<std::string> stooges {
    //     std::string {"larry"},
    //     "moe",
    //     std::string {"curly"},
    // }

    // s = {2, 4, 6, 8, 10};



    // Use operator< for ordering!
    // set also use operator< to determing if an element is in the set

    // the insert method
    // returns a std::pair<iterator, bool>
        // first in an iterator to the inserted element or to the duplicate in the set
        // second is a boolean indicating success or failure



    // std::set<int> s {4, 1, 1, 3, 3, 2, 5}; // 1 2 3 4 5

    // s.size();            // 5
    // s.max_size();        // a very large number

    // No concept of front and back
    // so no direct access of element

    // s.insert(7);         // 1 2 3 4 5 7
    // s.erase(3);          // 1 2 4 5 7

    // std::set<int>::iterator it = s.find(5);
    // auto it = s.find(5);

    // if (it != s.end()) { // found
    //     s.erase(it);     // 1 2 4 7
    // }

    // int num = s.count(1); // 0 or 1, for exist in the set or not
        // the method above is good for multi_set because multi_set allows duplicates
    // s.clear();           // empty the set
    // s.empty();           // true or false, is empty or not


    // Person p1 {"Larry", 18};
    // Person p2 {"Moe", 25};

    // std::set<Person> stooges;

    // stooges.insert(p1);                  // adds p1 to the set
    // auto result = stooges.insert(p2);    // adds p2 to the set



// en.cppreference.com