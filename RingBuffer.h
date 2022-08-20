//
// Created by admin on 2022/7/29.
//

#pragma once

#include <vector>
#include <array>

//环形队列
template<typename T, int Size = 8>
struct RingBuffer {
    constexpr RingBuffer() {

    }

    constexpr void push_back(const T &element) noexcept {

    }

    constexpr void push_back(T &&element) noexcept {

    }

    constexpr void pop() {

    }

    //获取末尾元素
    constexpr T &back() noexcept {
        return buf(tail);
    }

    constexpr T const &back() const{
        return buf(tail);
    }

    constexpr T &operator[](size_t index) noexcept{
        index += head;
        index %= _size;
        return buf[index];
    }

    constexpr const T &operator[](size_t index) const noexcept{
        index += head;
        index %= _size;
        return buf[index];
    }

    constexpr int size() {
        return _size;
    }
private:
    std::array<T, Size> buf{};
    //头指针，尾指针,尺寸
    int head, tail, _size;


};