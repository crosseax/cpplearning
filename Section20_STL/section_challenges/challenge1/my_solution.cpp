// a palindrome is a string that reads the same backwards and forwards
// a phrase can be palindrome too
// ep. a toyota's a toyota

// for the purpose of this challenge, we only consider alphabet

 
#include <cctype>
#include <deque>
#include <iostream>
#include <string>
#include <vector>
#include <iomanip>

template<typename T>
void display(const std::deque<T>& d) {
    std::cout << "[ ";
    for (const auto& elem : d) {
        std::cout << elem << " ";
    }
    std::cout << "]" << std::endl;
}


bool is_palindrome(const std::string& str)
{
    std::deque<char> d1;
    std::deque<char> d2;
    for (auto s : str) {
        if (std::isalpha(s)) {
            d1.push_back(std::toupper(s));
            d2.push_front(std::toupper(s));
        }
    }
    d1.shrink_to_fit();
    d2.shrink_to_fit();

    if (d1 == d2) {
        return true;
    } else {
        return false;
    }
}

int main()
{
    std::vector<std::string> test_strings{ "a", "aa", "aba", "abba", "abbcbba", "ab", "abc", "radar", "bob", "ana",
        "avid diva", "Amore, Roma", "A Toyota's a toyota", "A Santa at NASA", "C++",
        "A man, a plan, a cat, a ham, a yak, a yam, a hat, a canal-Panama!", "This is a palindrome", "palindrome" };
   
    std::cout << std::boolalpha;
    std::cout << std::setw(8) << std::left << "Result" << "String" << std::endl;
    for(const auto& s : test_strings) {
        std::cout << std::setw(8) << std::left << is_palindrome(s)  << s << std::endl;
    }
    std::cout << std::endl;
    return 0;
}