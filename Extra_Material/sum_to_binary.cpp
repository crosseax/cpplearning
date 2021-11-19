// This is a question from codewars.com

#include <iostream>
#include <string>


// std::string add_binary(uint64_t a, uint64_t b) {
//     std::string tmp;
//     uint64_t sum = a + b;
//     // sum *= 2;
//     // std::cout << sum << std::endl;
//     if (sum > 0) {
//         while (sum > 0) {
//         int bi = sum % 2;
//         if (bi == 1) {
//             tmp = tmp + '1';
//         } else {
//             tmp = tmp + '0';
//         }
//         // std::cout << tmp << " ";
//         sum /= 2;
//         }
//     // std::cout << tmp << std::endl;
//     } else {
//         tmp = '0';
//     }
//     std::string result;
//     for (size_t i = 0; i < tmp.length(); i++) {
//         result += tmp[tmp.length() - 1 - i];
//     }
//     std::cout << result << std::endl;
//     return result;
// }

std::string add_binary(uint64_t a, uint64_t b) {
    a += b;
    std::string output;

    do {
        output = std::to_string(a % 2) + output;
        a /= 2;
    } while(a > 0);
    std::cout << output << std::endl;   
    return output;
}


int main (void) 
{
    
    add_binary(5,3);
    add_binary(0,0);
    add_binary(1,11);
    add_binary(1109220521037,921633258894011);
    

    return 0;
}