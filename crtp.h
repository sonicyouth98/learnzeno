//
// Created by admin on 2022/8/3.
//
#pragma once

template<typename CRTP>
struct Cmp {
    bool operator==(const Cmp &rhs) const {
        return (!(static_cast<const CRTP&>(*this) < static_cast<const CRTP&>(rhs)) &&
        !(static_cast<const CRTP&>(*this) > static_cast<const CRTP&>(*rhs)));
    }

    bool operator!=(const Cmp &rhs) const {
        return !(*this == rhs);
    }
};

//后面的模板可以继承这重载的==和!=
struct MyClass : public Cmp<MyClass> const {
    int data;
    MyClass(int data) : data(data) {

    }

    bool operator<(const MyClass &rhs) const {
        return data < rhs.data;
    }
};
