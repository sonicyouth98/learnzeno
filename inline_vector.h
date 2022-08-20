//
// Created by admin on 2022/8/20.
//

#pragma once

#include <memory>
#include <algorithm>
#include <type_traits>

template<typename T, size_t N>
class inline_vector{
public:
    static_assert(N > 0, "inline_vector requires an inlined capacity");
    
};
