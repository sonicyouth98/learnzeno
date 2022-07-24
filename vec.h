//
// Created by admin on 2022/7/24.
//
#pragma once
#include <array>
#include <type_traits>
#include <cstdint>
#include <cmath>

template<size_t N, class T>
struct vec : public std::array<T, N> {
    vec() = default;
    explicit vec(T const &x) {
        for (size_t i = 0; i < N; i++) {
            (*this)[i] = x;
        }
    }

    vec(vec &&) = default;
    vec(const vec &) = default;
    vec& operator=(const vec &) = default;

    //伺候array的赋值
    vec(const std::array<T, N> &a) {
        for (size_t i = 0; i < N; i++) {
            (*this)[i] = a[i];
        }
    }

    operator std::array<T,N> const() {

    }

    //伺候不同类型的array
    template<class S>
    vec(const std::array<S, N>& a) {
        T val{};
        for (size_t i = 0; i < N; i++) {
            (*this)[i] = static_cast<T>(a[i]);
        }
    }

};
