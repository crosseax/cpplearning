// std::vector

// #include <vector>

// Dynamic size
    // handled automatically
    // can expand and contract as needed
    // elements are stored in contiguous memory as an array
// Direct element access (constant time)
// Rapid insertion and deletion at the back (constant time)
// Insertion or removal of elements (linear time)
// All iterators available and may invalidate




// std::vector<int> vec1 {1, 2, 3, 4, 5};
// std::vector<int> vec2 (10, 100); // ten 100s

// std::vector<std::string> stooges {
//     std::string{"Larry"},
//     "Moe",
//     std::string{"Curly"}
// };

// vec1 = {2, 4, 6, 8, 10};





// common methods:

// std::vector<int> vec {1, 2, 3, 4, 5}

    // vec.size();      // 5
    // vec.at(0);       // 1, with bounds checking
    // vec[1];          // 2, no bounds checking
    // vec.capacity();  // 5
    // vec.max_size();  // a very large number
    // vec.clear();     // remove all the elements

    // vec.front();     // 1, vec.front == *vec.begin()
    // vec.back();      // 5, vec.back == *(vec.end() - 1)

    // vec.empty();     // 0 (false), return true if the vec is empty
    // vec.swap(vec1);  // swaps the 2 vectors, has to container same type of element, but the size can be different
    
    // std::sort(vec.begin(), vec.end());   // sort within those element



// Person p1 {"Larry", 18};
// std::vector<person> vec;

    // vec.push_back(p1);   // add p1 to the back
    // vec.pop_back();      // remove p1 from the back

    // vec.push_back(Person{"Larry", 18});  // construct then add to back
    // vec.emplace_back("Larry", 18);       // efficient!! just pass in the constructor args



// how to insert data into vec:

// std::vector<int> vec1 {1, 2, 3, 4, 5};
// std::vector<int> vec2 {10, 20, 30, 40, 50};

// auto it = std::find(vec1.begin(), vec1.end(), 3);    // insert before element 3
// vec1.insert (it, 10); // 1, 2, 10, 3, 4, 5

// it = std::find(vec1.begin(), vec1.end(), 4);
// vec1::insert(it, vec2.begin(), vec2.end(), 4);       // insert copy before element 4
    // 1, 2, 10, 3 10, 20, 30, 40, 50, 4, 5

// check en.cppreference.com for more info





