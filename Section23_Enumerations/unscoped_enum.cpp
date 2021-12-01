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
    std::cout << "Valid items count: " << valid_item_count << std::endl;
    std::cout << "Invalid items count: " << invalid_item_count << std::endl;
    std::cout << "Total items: " << valid_item_count + invalid_item_count << std::endl;
}

// Using an unscoped enumeration to model grocery items
void test2() {
    std::cout << "\n===test 2===" << std::endl;

    std::vector<Grocery_Item> shopping_list;

    shopping_list.push_back(Apple);
    shopping_list.push_back(Apple);
    shopping_list.push_back(Milk);
    shopping_list.push_back(Orange);

    // Grocery_Item item = 100; // compiler error
    int Helicopter {1000};

    shopping_list.push_back(Grocery_Item(Helicopter)); // Invalid item
    shopping_list.push_back(Grocery_Item(0)); // will add Milk again

    display_grocery_list(shopping_list);
}

// Used for test3
// Unscoped enumerations holding the possible states
// and sequences of rocket launch
// Note the addition of the Unknown enumerator for the State enumeration
enum State {Engine_Failure, Inclement_Weather, Nominal, Unknown};
enum Sequence {Abort, Hold, Launch};

// Used for test 3
// Overloading the stream extraction operator>> 
// to allow a user to enter the state of State enumeration
// Note the use of underlying_type_t

std::istream& operator>> (std::istream& is, State& state) {
    
    // int user_input; // Will also work
    // underlying_type_t is better cuz if in the future
    // someone assigning the state to not a int
    // this will still work
    std::underlying_type_t<State> user_input;
    is >> user_input;

    switch (user_input) {
        case Engine_Failure:
        case Inclement_Weather:
        case Nominal:
        case Unknown:
            state = State(user_input);
            break;
        default:
            std::cout << "User input is not a valid lauch state." << std::endl;
            state = Unknown;
    }
    return is;
}

// Used for test3
// Overloading the stream insertion operator<<
// to insert the string representation of the
// provided Sequence parameter into the output stream
std::ostream& operator<< (std::ostream& os, const Sequence& sequence) {
    switch (sequence) {
        case Abort: os << "Abort"; break;
        case Hold: os << "Hold"; break;
        case Launch: os << "Launch"; break;
    }
    return os;
}

// Used for test3
// Displays an informaton message given the sequence parameter
void initiate (Sequence sequence) {
    std::cout << "Initiate " << sequence << " sequence!" << std::endl; // Uses overloaded operator<<
}

// Using unscoped enums to control a rocket launch
// reads input from the user for the State of the rocket launch
// and then determines which Sequence to execute
void test3() {
    std::cout << "\n===test 3===" << std::endl;

    State state;
    std::cout << "Launch state: ";
    std::cin >> state; // uses the overloaded operator>>

    switch (state) {
        case Engine_Failure:
        case Unknown:
            initiate(Abort);
            break;
        case Inclement_Weather:
            initiate(Hold);
            break;
        case Nominal:
            initiate(Launch);
            break;
    }
}



int main (void) 
{
    test1();
    test2();
    test3();


    return 0;
}