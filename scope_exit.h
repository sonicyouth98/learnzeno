//
// Created by admin on 2022/9/1.
//
#pragma once
#include <functional>
//利用raii思想,在离开作用域的时候
template<class Func = std::function<void()>>
class scope_exit{
private:
    Func func;
    bool enabled {false};
public:
    scope_exit(){

    }

    scope_exit(Func &&func) : func(std::move(func)), enabled(true){

    }

    ~scope_exit() {
        if (enabled) {
            func();
        }
    }

    void reset() {

    }
};
