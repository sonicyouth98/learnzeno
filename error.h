//
// Created by admin on 2022/8/21.
//
#pragma once
#include <exception>

enum  class Error_t {
    Io,
    Std
};

static constexpr const char *ErrorToString(Error_t err) {
    switch (err) {
        case Error_t::Io:
            return "Io";
        default:
            return "Unknown";
    }
}

struct MatException : std::exception {

};

#define MAT_STATIC_ASSERT(a, error) \
{                                   \
       static_assert((a), #error ": " #a)    \
}

#define MAT_STATIC_ASSERT_STR(a, error, str) \
{                                            \
       static_assert((a), #error ": " #a)      \
}
