// std::list and std::forward_list

// Sequence containers
// Non-contiguous in memory
// No direct access to elements
// Very efficient for inserting and deleting elements once an element is found



// std::list 
    // #include <list>

    // Dynamic size
        // lists of elements
        // list is bidirectional (doubly linked)
    // Direct element access is NOT provided
    // Rapid isertion and deletion of elements anywhere in the container (constant time)
    // All iterators available and invalidate when corresponding element is deleted


    // If you need a container where you will have lots of insertions and removals
    // from the container and you dont need direct access to the elements
    // then the list is a good choice

// std::forward_list (since C++11)
    // #include <forward_list>

    // Dynamic size
        // lists of elements
        // list is uni-directional (singly linked)
        // less overhed than std::list
    // Direct element access is NOT provided
    // Rapid isertion and deletion of elements anywhere in the container (constant time)
    // Rever iterators not available. 
    // Iterators invalidate when corresponding element is deleted



    



// std::list<int> l1 {1, 2, 3, 4, 5};
// std::list<int> l2 (10, 100); // ten 100s

// std::list<std::string> stooges {
//     std::string{"Larry"},
//     "Moe",
//     std::string{"Curly"}
// };

// d1 = {2, 4, 6, 8, 10};



// std::list<int> 

    // std::list<int> l {1, 2, 3, 4, 5};

    // l.size();            // 5
    // l.max_size();        // a very large number
    // l.front();           // 1
    // l.back();            // 5

    // since no direct element access, must use a iterator
    // std::list<int>::iterator it = std::find(l.begin(), l.end(), 3); // find before 3
    // auto it = std::find(l.begin(), l.end(), 3); // find before 3

    // l.insert(it, 10);    // 1 2 10 3 4 5, iterator here is not invalidated, it still reference the 3
    // l.erase(it);         // 1 2 10 4 5, erase the 3, now the iterator is invalid
    // l.resize(2);         // 1 2
    // l.resize(5);         // 1 2 0 0 0

    // std::list<int>::iterator it = std::find(l.begin(), l.end(), 3); // find before 3
    // auto it = std::find(l.begin(), l.end(), 3); // find before 3

    // std::cout << *it;    // 3
    // it++;
    // std::cout << *it;    // 3
    // it--;                // because list is bi-directional
    // std::cout << *it;    // 3


    // Person p1 {"Larry", 18};
    // std::list<Person> 1;

    // l.push_back(p1);
    // l.pop_back();
    // l.push_front(p1);
    // l.pop_front();
    // l.emplace_back("Moe", 24);
    // l.emplace_front("Curly", 30);





// std::forward_list<int> 

    // std::list<int> l {1, 2, 3, 4, 5};

    // l.max_size();        // a very large number
    // l.front();           // 1

    // since no direct element access, must use a iterator
    // std::forward_list<int>::iterator it = std::find(l.begin(), l.end(), 3); // find before 3
    // auto it = std::find(l.begin(), l.end(), 3); // find before 3

    // l.insert_after(it, 10);      // 1 2 3 10 4 5
    // l.emplace_after(it, 100);    // 1 2 3 100 10 4 5
    // l.erase_after(it);           // 1 2 3 10 4 5
    // l.resize(2);                 // 1 2
    // l.resize(5);                 // 1 2 3 4 5
    
    
    // Person p1 {"Larry", 18};
    // std::forward_list<Person> 1;

    // l.push_front(p1);
    // l.pop_front();
    // l.emplace_front("Curly", 30);
