//
// Created by admin on 2022/8/24.
//
#pragma once
#include <iostream>
#include <map>

class Dict {
public:
    std::map<std::string, std::string> data_;

    Dict() = default;

    //
    template<typename T>
    Dict(const std::string &key, const T &value) {

    }

    //这是一个模板函数但是下面我们有很多函数重载
    template<typename T>
    Dict &set(std::string name, T val) {

    }

    Dict &set(std::string name, const char *value) {

    }

};
