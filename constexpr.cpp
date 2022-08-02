//
// Created by admin on 2022/8/2.
//
#include <iostream>

constexpr int get_value(int value) {

    return value * 3;
}

//使用consteval的函数都是在编译期间求值的
int main() {
    //这里value是const常量， 不能改变
    constexpr static auto value = get_value(42);
    //如果不加static,编译器未必会将其留在编译期计算
    //如果我想既要在编译期间计算，又要不是co
    constinit static
    //constinit 必须是static的 但不是const
}
