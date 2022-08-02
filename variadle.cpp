//
// Created by admin on 2022/8/2.
//
#include <sstream>
#include <iostream>
#include <vector>
template<typename T>
std::string to_string_impl(const T &t) {
    std::stringstream s;
    s << t;
    return s.str();
}

//参数为0时候的特化
std::vector<std::string> to_string() {
    return {};
}

template<typename P1, typename ...Param>
std::vector<std::string> to_string(const P1 &p1, const Param& ...param) {
    std::vector<std::string> ss;
    ss.push_back(to_string_impl(p1));
    //开始递归调用
    const auto remainder = to_string(param...);

    ss.insert(ss.end(), remainder.begin(), remainder.end());
    return ss;
}

template<typename T>
void print_impl(const T &t) {
    std::cout << t << '\n';
}


int main() {
    const auto Vec = to_string(1, "abc", 6.4);
    for (auto c : Vec) {
        std::cout << c << std::endl;
    }
}