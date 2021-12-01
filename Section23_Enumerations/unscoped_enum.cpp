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


// Used for test2
// Unscoped enumeration representing items for a grocery shopping list
enum Grocery_Item {Milk, Bread, Apple, Orange};
//                 0     1      2      3
// automatically done by compiler

// Overloading the stream insertion operator<< 
// to insert the string representation of the 
// provided Grocery_Item parameter into the output stream
std::ostream& operator<< (std::ostream& os, Grocery_Item grocery_item) {
    switch (grocery_item)
    {
        case Milk: os << "Milk"; break;
        case Bread: os << "Bread"; break;
        case Apple: os << "Apple"; break;
        case Orange: os << "Orange"; break;
        default: os << "Invalid item"; break;
    }
    return os;
}

// Used for test2
// returns a boolean depending on whether the 
// Grocery_Item parameter is a valid enumerator or not
bool is_valid_grocery_item(Grocery_Item grocery_item) {
    switch (grocery_item)
    {
        case Milk:
        case Bread:
        case Apple:
        case Orange:
            return true;
        default:
            return false;
    }
}

// Used for test2
// GIven a vector of Grocery_Item, 
// this function displays the string representation of 
// each item using the overloaded operator<< function.
// This function also keeps track of 
// how many valid and invalid items are in the provided vector
// by using the is_valid_grocery_item function written above
void display_grocery_list (const std::vector<Grocery_Item>& grocery_list) {
    std::cout << "===Grocery List===" << std::endl; 
    int invalid_item_count {0};
    int valid_item_count {0};
    for (Grocery_Item grocery_item : grocery_list) {
        std::cout << grocery_item << std::endl;

        // check that grocery is valid grocery item
        if (is_valid_grocery_item(grocery_item)) {
            valid_item_count++;
        } else {
            invalid_item_count++;
        }
    }
    std::cout << "===Results===" << std::endl;
    
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