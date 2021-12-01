#include <iostream>
#include <vector>
#include <string>


// Used for test1
enum Direction {North, South, East, West};
//              0      1      2     3
// automatically done by compiler

// limitation of unscoped enumaration
// enum Street (Main, North, Elm); // Error, cant use North again

// Used for test one
// This function expects a Direction parameter
// and returns its string representation
std::string direction_to_string(Direction direction) {
    std::string result;
    switch (direction)
    {
        case North: result = "North"; break;
        case South: result = "South"; break;
        case East: result = "East"; break;
        case West: result = "West"; break;
        
        default: result = "Unknown Direction"; break;
    }
    return result;
}

void test1() {
    std::cout << "\n===test 1===" << std::endl;

    Direction direction {North}; // this is an int
    // creating a type and initialization

    std::cout << "\nDirection " << direction << std::endl;
    std::cout << direction_to_string(direction) << std::endl;

    direction = West;
    std::cout << "\nDirection " << direction << std::endl;
    std::cout << direction_to_string(direction) << std::endl;

    // direction = 5; // compiler error

    // Be careful casting 
    // since the compiler will assume you know what you're doing 

    direction = Direction(100);
    std::cout << "\nDirection " << direction << std::endl;
    std::cout << direction_to_string(direction) << std::endl;

    direction = East;
    std::cout << "\nDirection " << direction << std::endl;
    std::cout << direction_to_string(direction) << std::endl;

    direction = static_cast<Direction> (200);
    std::cout << "\nDirection " << direction << std::endl;
    std::cout << direction_to_string(direction) << std::endl;
}

void test2() {
    std::cout << "\n===test 2===" << std::endl;
}

void test3() {
    std::cout << "\n===test 3===" << std::endl;
}


int main (void) 
{
    test1();
    test2();
    test3();


    return 0;
}