//
// Created by admin on 2022/8/8.
//
#pragma once

#include <iostream>
#include <memory>
#include <type_traits>

template<typename T, typename Deleter = std::default_delete<T>>
class copyable_ptr {
public:
    static_assert(!std::is_array_v<T>, "copyable_ptr dose not support array");
    static_assert(std::is_copy_constructible<T>, "copyable_ptr should be copy");

    using pointer = std::add_pointer_t<T>;
    using element_type = T;
    using deleter_type = Deleter;
};