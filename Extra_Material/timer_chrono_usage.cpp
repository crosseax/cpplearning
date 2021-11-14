// This files shows a use case for timing program in .cpp programming
// Including a brief look to <chrono> and <thread> library

// this compiles after -std=c++14

#include <iostream>
#include <chrono>
#include <thread>



int main (void)
{
    using namespace std::literals::chrono_literals; // enable using 1s as 1 second in the later code

    auto start = std::chrono::high_resolution_clock::now(); // get the time for now
    std::this_thread::sleep_for(1s); // pause the program for 1 second
    auto end = std::chrono::high_resolution_clock::now(); // get the time for now

    std::chrono::duration<float> duration; // get the during in format of floats (so more precise) 
    duration = end - start; 
    std::cout << duration.count() << " seconds " << std::endl;


    return 0;
}