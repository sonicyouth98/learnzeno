//
// Created by admin on 2022/8/2.
//
//怎么将lambda放进容器中，如果一个lambda是没有捕获的，那他可以和函数指针做转换
#include <vector>
#include <functional>
#include <set>

auto make_lambda(int value) {
    return [value](int i) {
        return i + value;
    };
}

struct MyData {
    std::string key;
    std::string value;
};

int main() {
    std::vector<decltype(make_lambda(42))> data;
    data.push_back(make_lambda(1));
    data.push_back(make_lambda(2));
    //将一个lambda塞进容器中
    //几种搞法，如果没有捕获就可以用函数指针代替
    auto l = [](auto j) {return 42 + j;};
    std::vector<int(*)(int)> d;
    d.push_back(l);
    d.push_back([](int j) {return j;});

    std::set<MyData, decltype([](const MyData &lhs, const MyData &rhs) {
        return lhs.key > rhs.key;
    })>;

    //必须要加一个decltype

    auto lambda = [](const MyData &lhs, const MyData &rhs) {
        return rhs.key > lhs.key;
    };

    std::set<MyData, decltype(lambda)> a{lambda};
    //拿来初始化一下

}