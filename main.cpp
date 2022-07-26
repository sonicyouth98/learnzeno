#include <iostream>
#include <string>
#include "vec.h"
#include "string.h"
int main() {
    std::cout << "Hello, World!" << std::endl;
    vec<5, int> a{7};
    for (int i = 0; i < 5; i++) {
        std::cout << a[i] << " "<< std::endl;
    }


    std::vector<std::string> b = spilt_str("abcdefg hhh jjj", ' ');
    for (auto it = b.begin(); it != b.end(); it++) {
        std::cout << *it << std::endl;
    }

    return 0;
}
