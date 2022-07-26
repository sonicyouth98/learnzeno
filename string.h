//
// Created by admin on 2022/7/24.
//
//一下字符串函数
#pragma once

#include <map>
#include <string>
#include <memory>
#include <sstream>
#include <vector>

std::vector<std::string> spilt_str(const std::string& str, char delimiter = ' ') {
       std::vector<std::string> tokens;
       std::string token;
       std::istringstream iss(str);
       //istringstream
       while (std::getline(iss, token, delimiter)) {
           tokens.push_back(token);
       }
       return tokens;
}

template<class S, class T>
static std::string join_str(const std::vector<T> &elems, const S &delim) {
    std::stringstream ss;
    //delim是分隔符
    auto p = elems.begin(), end = elems.end();
    if (p != end) {
        ss << *p++;
    }

   // return ss.str;
}