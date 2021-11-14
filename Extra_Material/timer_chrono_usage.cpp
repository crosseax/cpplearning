// This files shows a use case for timing program in .cpp programming
// Including a brief look to <chrono> and <thread> library


#include <iostream>
#include <chrono>
#include <thread>

// This compiles after -std=c++11;
class Timer { // so now use obj life time to automatically time things instead of writing lots of codes below
public:
        std::chrono::time_point<std::chrono::steady_clock> start, end;
        std::chrono::duration<float> duration;

    Timer() {
        start = std::chrono::high_resolution_clock::now();
    }

    ~Timer() {
        end = std::chrono::high_resolution_clock::now();
        duration = end - start;

        float ms = duration.count() * 1000.0f; // by default, duration.count() returns in seconds
        std::cout << "Timer took " << ms << " ms " << std::endl;
    }
};
// by using the obj lifetime above, 
// just create Timer obj at the beginning of the code you wanna time
// then destruct it when you want to stop the Timer

void say_hello() {
    for (int i = 0; i < 1000; i++) {
        std::cout << "Hello" << std::endl;
    }
}

int main (void)
{
    Timer timer;
    say_hello();
    std::this_thread::sleep_for(std::chrono::seconds(1)); // program sleep for one second




    // codes below are the abundant way of doing timing in cpp
    // this compiles after -std=c++14

    // auto start = std::chrono::high_resolution_clock::now(); // get the time for now
    // std::this_thread::sleep_for(std::chrono::seconds(1)); // pause the program for 1 second
    // auto end = std::chrono::high_resolution_clock::now(); // get the time for now

    // std::chrono::duration<float> duration; // get the during in format of floats (so more precise) 
    // duration = end - start; 
    // std::cout << duration.count() << " seconds " << std::endl;


    return 0;
}