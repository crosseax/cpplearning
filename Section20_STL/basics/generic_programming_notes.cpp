// Generic Programming 
    // Writing code that works with a variety of types as arguments,
    // as long as those argument types meet specific syntactic and semantic requirements


// Macros
    // be very careful using it

// Macros (#define) 
    // so basically, the preprocessor substitute those #define words before it sends to compiler
    // no ;, cuz if you do, that is also included in substitution process

// - C++ preprocessor directives
// - No type information
// - Simple substitution 
    // - preprocessor knows nothing about cpp, so there can be potential problem (why be careful)

// ep. 
    // #define MAX_SIZE 100
    // #define PI 3.14159


// why micro

    // // without macro
    // int max(int a, int b) {
    //     return (a > b) ? a : b;
    // }
    // // but now you have to do the same for double, char and more

    // // with macro
    // #define MAX(a, b) ((a > b) ? a : b)
    // // Now it works with every type because its a replacement before the complation process

// careful designing
    
    // // bad practice
    // #define SQUARE(a) a*a
    // SQUARE(5) == 5*5 == 25
    // 100 / SQUARE(5) == 100 / 5*5 == 100

    // // better practice
    // #define SQUARE(5) ((a)*(a))
    // // so basically use parenthesis on arg