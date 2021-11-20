// Stream manipulators

// Streams have useful member functions to control formatting
// Can be used on input and output streams
// The time of the effect on the stream varies
// Can be used as member functions or as manipulators

// std::cout.width(10); // member functions
// std::cout << std::setw(10); // manipulator - similar to overloading, <iomanip>

// we'll focus on manipulator usage

// common stream manipulators

// - Boolean
    // boolalpha    
    // noboolalpha

// - Integer
    // dec
    // hex
    // oct
    // showbase
    // noshowbase
    // showpos
    // noshowpos
    // uppercase
    // nouppercase

// - Floating point
    // fixed 
    // scientific
    // setprecision
    // showpoint
    // noshowpoint
    // showpos
    // noshowpos

// - Field width, justification and fill
    // setw
    // left
    // right 
    // internal 
    // setfill

// - Others
    // endl
    // flush
    // skipws
    // noskipws
    // ws (whitespace)


