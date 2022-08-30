//
// Created by admin on 2022/8/21.
//

//异常处理最好和堆栈打印结合起来

#pragma once
#include <exception>
#include <string>
#include <strstream>
#include <sstream>

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
    Error_t e;
    char str[400];
    std::stringstream stack;

    //抛出一个异常并且打印堆栈
    MatException() {

    }

    //所有继承自exception的都需要重写
    //throw()表明不抛出任何异常
    const char *what() throw() {
        return str;
    }
};
#define MAT_THROW(e, str) \
{                         \
     //throw MatException(e, str)                     \
} \

#define MAX_ASSERT(a, error) { \
        if ((a) != true) {     \
            MAT_THROW(error, #a)             \
        }                               \
                               \
}


#define MAT_STATIC_ASSERT(a, error) \
{                                   \
       static_assert((a), #error ": " #a)    \
}

#define MAT_STATIC_ASSERT_STR(a, error, str) \
{                                            \
       static_assert((a), #error ": " #a)      \
}
