// Iterators
    // allows abstracting an arbitrary container as a sequence of elements
    // they are objects that work like pointers by design
    // most container classes can be traversed with iterators


// Declaring iterators
    // iterators must be declared based on the container type they will iterate over
    // - container_type::iterator_type iterator_name;
// ep.
    // std::vector<int>::iterator it1;
    // std::list<std::string>::iterator it2;
    // std::map<std::string, std::string>::iterator it3
    // std::set<char>::iterator it4;



// ep std::vector
    // vector is a container in the STL
    // that stores elements in contiguous memory
    // and can resize itself to accommodate elements dynamically




// how is vector implemented doesn't matter to us,
// what matters tis that a container has a beginning and an end

// ********
// The STL defines the beginning (vec.begin()) as the first element in the container
// and the STL defined the end (vec.end()) as one after the last element in the container
// ********

// to initialize the iterator like
// std::vector<int>::iterator it = vec.begin(), it points to the first element in the vec
// or auto it = vec.begin()

// then you can:
    // ++it, it++, it = it1 (applies to all iterator)
    // *it, it-> (applies to input and output)
    // it == it1, it != it1 (applies to input)
    // --it, it-- (bidirectional iterator)
    // it + i, it += i, it - i, it -= i, it < it1, it <= it1, it > it1, it >= it1 (random access)
    


// // ep using itrators -std
// std::vector<int> vec {1,2,3};
// std::vector<int>::iterator it = vec.begin();
// while (it != vec.end()) {
//     std::cout << *it << " ";
//     it++;
// }

// // or
// for (auto it = vec.begin(); it != vec.end(); it++) {
//     std::cout << *it << " ";
// }
// // output: 1 2 3



// // ep reverse iterator
// std::vector<int> vec {1,2,3};
// std::vector<int>::reverse_interator rit = vec.begin();
// while (it != vec.end()) {
//     std::cout << *rit << " ";
// }
// // output: 3 2 1
