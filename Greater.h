//
// Created by admin on 2022/8/24.
//

#pragma once

template<typename T>
struct equal_to {
    using first_argument_type = T;
    using second_argument_type = T;
    using result_type = T;

    bool operator()(T const &a, T const &b) {

    }
};
