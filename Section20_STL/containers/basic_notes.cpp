// Containers

// Data structures that can store object of almost any type
    // implemented as Template-based classes

// Each containers has member functions
    // some are specific to the container
    // others are available to all containers

// Each container has an associated header file
    // #include <container_type>



// Containers - common

// Function - Description
/***
 * Default constructor - initializes an empty container
 * Overloaded constructors - initializes containers with many options
 * Copy constructor - initializes a container as a conpy of another container
 * Move constructor - moves existing container to new container
 * Destructor - destroys a container
 * Copy assignment (operator=) - copy one container to another 
 * Move assignment (operator=) - move one container to another 
 * size - returns the number of elements in the container
 * empty - returns boolean (is the container empty?)
 * insert - insert an element into the container
 * 
 * operator< and operator<= - returns boolean (compare contents of 2 containers)
 * operator> and operator>= - returns boolean (compare contents of 2 containers)
 * operator== and operator!= - returns boolean (are the contents of 2 containers equal or not)
 * swap - swap the elements of 2 containers
 * erase - remove element(s) from a container
 * clear - remove all elements from a container
 * begin and end - return iterators to first element or end
 * rbegin and rend - returns reverse iterators to first element or end
 * cbegin and cend - returns constant iterators to first element or end
 * crbegin and crend - returns constant reverse iterators to first element or end
***/




// Container elements
// what types of elements can we store in containers?

// A COPY of the element will be stored i nthe container
    // all primitives OK

// Element should be 
    // copyable and assignable (copy constructor / copy assignment)
    // moveable and efficiency (move constructor / move assignment)

// Ordered associative containers must be able to compare elements
    // operator<, operator==, etc