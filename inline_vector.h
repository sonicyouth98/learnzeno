//
// Created by admin on 2022/8/20.
//

#pragma once

#include <memory>
#include <algorithm>
#include <type_traits>
#include <any>
#include <string>

template<class T>
T safe_any_cast(std::any &&a, std::string const &msg = {}) {
    try{
        return std::any_cast<T>(std::forward<std::any>(a));
        //如果抛出异常,直接catch
    } catch(std::bad_any_cast const &e) {
        //return
    }
}

template<class T, class S>
T *safe_dynamic_cast(S *s, const std::string &msg = "safe_dynamic_cast") {
    //return dynamic_cast<>这样直接返回
    auto t = dynamic_cast<T*>(s);
    if (!t) {
        //throw();
    }
    return t;
}

template<>
template<typename T, size_t N>
class inline_vector{
public:
    static_assert(N > 0, "inline_vector requires an inlined capacity");

};
