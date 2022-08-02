//
// Created by admin on 2022/8/2.
//
//怎么将lambda放进容器中，如果一个lambda是没有捕获的，那他可以和函数指针做转换
#include <vector>
#include <functional>

auto make_lambda(int value) {
    return [value](int i) {
        return i + value;
    };
}
int main() {
    std::vector<decltype(make_lambda(42))> data;
    data.push_back(make_lambda(1));
    data.push_back(make_lambda(2));
}