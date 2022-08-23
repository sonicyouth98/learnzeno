//
// Created by admin on 2022/8/2.
//
#pragma once
#include <cstdio>
#include <shared_mutex>
#include <mutex>
#include <unordered_map>
#include <utility>


//标记内存分配类型
enum class MatMemorySpace_t {

};

struct MatMemoryStats_t {
    size_t currentBytesAllocated;
    size_t totalBytesAllocated;
    size_t maxBytesAllocated;
};

struct MatPointerAttr_t {
    size_t size;
    MatMemorySpace_t kind;

};


