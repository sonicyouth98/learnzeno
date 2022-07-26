//
// Created by admin on 2022/7/25.
//

#pragma once

#include <map>
#include <string>
#include <string_view>

template<class T>
T const &safe_at(const std::map<std::string, T> &m, const std::string &key, std::string_view msg) {
    auto it = m.find(key);
    if (it == m.end()) {
        //抛出一个异常对象
    }
    return it->second;
}

//没有const 的版本
template<class T>
T &safe_at(std::map<std::string, T> &m, const std::string &key, std::string_view msg) {
    auto it = m.find(key);
    return const_cast<T&>(it->seond);
}
