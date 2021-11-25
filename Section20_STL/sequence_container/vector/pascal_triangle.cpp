#include <iostream>
#include <algorithm>
#include <vector>

// template function to display any vector
template<typename T>
void display(const std::vector<T>& vec) {
    std::cout << "[ ";
    for (const auto& elem : vec) {
        std::cout << elem << " ";
    }
    std::cout << "]" << std::endl;
}

void pascal_triangle(uint64_t n) {
    std::cout << "\n===pascal triangle using std::transform===" << std::endl;
    
    std::vector<uint64_t> vec1 {1};
    display(vec1);
    std::vector<uint64_t> vec2;
    std::vector<uint64_t> vec3;

    for (uint64_t i = 0; i < n - 1; i++){
        // make 1 0
        vec1.push_back(0);

        // make 0 1
        std::copy(vec1.rbegin(), vec1.rend(), std::back_inserter(vec2));

        // make 1 1
        std::transform(vec1.begin(), vec1.end(), vec2.begin(), std::back_inserter(vec3), 
            [] (uint64_t x, uint64_t y) { return x + y; });

        display(vec3);

        // assign and continue
        vec1 = vec3;

        vec2.clear();
        vec3.clear();
    }
}


int main (void)
{
    uint64_t x {};
    std::cout << "How many layers of pascal triangle you want: ";
    std::cin >> x;
    pascal_triangle(x);

    return 0;
}