#include <iostream>
#include "vec.h"

int main() {
    std::cout << "Hello, World!" << std::endl;
    vec<5, int> a{7};
    for (int i = 0; i < 5; i++) {
        std::cout << a[i] << " ";
    }
    return 0;
}
