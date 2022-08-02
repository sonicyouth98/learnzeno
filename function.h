//
// Created by admin on 2022/8/2.
//
#pragma once

#include <memory>

//泛化版本
template<typename T>
class function;

template<typename Ret, typename ... Param>
class function<Ret(Param...)> {
public:
    function(Ret(*f)(Param...)) : callable{std::make_unique<Ret(*)(Param...)>(f)}{

    }

    Ret operator()(Param... param) {
        return callable->call(Param...);
    }

private:
    struct Callable_interface{
        virtual Ret call(Param... ) = 0;
        virtual ~Callable_interface() = default;
    };

    template<typename Callable>
    struct call_impl : public Callable_interface {
        //重写call函数
        Ret call(Param... param) {
            return callable(param...);
        }
        Callable callable;
    };
    std::unique_ptr<Callable_interface> callable;

};

