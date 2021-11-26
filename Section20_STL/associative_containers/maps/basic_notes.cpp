// Map containers

// Associative containers
    // collection of stored objects that allow fast retrieval using a key
    // STL provides sets and maps
    // usually implemented as a balanced binary tree or hashsets
    // most operations are very efficient

// maps
    // std::map
    // std::unordered_map
    // std::multimap
    // std::unordered_multimap


// std::map

    // #include <map>

    // similar to a dictionary
    // elements are stored as key, value pairs (std::pair)
    // ordered by key
    // no duplicate elements (keys are unique)
    // direct element access using the key
    // all iterators available and invalidate when corresponding element is deleted


// std::multi_map

    // #include <map>

    // Ordered by key, value pairs
    // Allows duplicate elements
    // All iterators are available


// std::unordered_map

    // #include <unordered_map>

    // Elements are unordered
    // No duplicate elements allowed
    // No reverse iterators are allowed


// std::unordered_multimap

    // #include <unordered_map>

    // Elements are unordered
    // Allows duplicate elements
    // No reverse iterators are allowed




    // std::map<std::string, int> m { // key is the string, value is the int, <key, value>
    //     {"Larry", 18},
    //     {"Moe", 25}
    // };

    // std::map<std::string, std::string> m {  // <key, value>
    //     {"Bob", "Butcher"},
    //     {"Anne", "Baker"},
    //     {"George", "Candlestick maker"}
    // };

    // m.size();       // 3 
    // m.max_size();   // a very large number

    // No concept of front and back

    // std::pair<std::string, std::string> p1 {"James", "Mechanic"};
    // m.insert(p1);
    // m.insert(std::make_pair("Roger", "Ranger"));


    // m["Frank"] = "Teacher";         // insert
    // m["Frank"] = "Instructor";      // update value
    // m.at("Frank") = "Professor";    // update value, will throw exception if key not exist


    // m.erase("Anne");                 // erase Anne

    // if (m.find("Bob") != m.end()) {  // find Bob
    //     std::cout << "Found Bob!";
    // }

    // auto it = m.find("George");      
    // if (it != m.end()) {
    //     m.erase(it);                 // erase George
    // }


    // int num = m.count("Bob");       // 0 or 1
    // m.clear();                      // remove all elements
    // m.empty();                      // true or false