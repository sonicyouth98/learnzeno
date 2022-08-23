//
// Created by admin on 2022/8/23.
//
#pragma once
#include <variant>
#include <vector>
#include <type_traits>
#include <iostream>

using NumericValue = std::variant<int, std::vector<int>>;

struct NumericObject {
    NumericValue value;

    NumericObject() = default;
    NumericObject(const NumericValue &value) : value(value) {

    }

    NumericValue &get() {
        return value;
    }

    NumericValue const &get() const {
        return value;
    }

    template<typename T>
    T get() const{
        std::visit([](auto const& value) ->T {
            using V = std::decay<decltype(value)>;
            if (!std::is_convertible_v<T, V>) {
                //std::cout << "wrong" << std::endl;
                return "Wrong";
            } else {
                return T(value);
            }
        }, value);
    }
    template<typename T>
    void set(const T &x) {
        value = x;
    }


};
