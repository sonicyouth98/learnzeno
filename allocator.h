//
// Created by admin on 2022/8/2.
//
#pragma once
#include <cstdio>
#include <shared_mutex>
#include <mutex>
#include <unordered_map>
#include <utility>
#include <type_traits>
//类似于统一host于device的内存分配
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

inline std::shared_mutex memory_mtx;
std::unordered_map<void *, MatPointerAttr_t> allocationMap;
inline bool IsAllocated(void *ptr) {
    if (ptr == nullptr) {
        return false;
    }

    std::unique_lock<std::shared_mutex> lck(memory_mtx);
    auto it = allocationMap.find(ptr);
    return it != allocationMap.end();
}

inline MatMemoryStats_t GetPointerKind(void *ptr) {
    if (ptr == nullptr) {
        //
    }

    //上锁
}

//打印内存信息到屏幕上
inline void matPrintMemoryStatistics() {

}

//分配内存
inline void matMalloc(void **ptr, size_t bytes = 0) {

}
inline void maxFree(void *ptr) {
    if (ptr == nullptr) {
        return ;
    }


}
template<typename T>
struct mat_allocator {
    inline T *allocate(size_t size) {
        T *tmp;
        //调用自定义分配函数
        return tmp;
    }

    inline void deallocate(void *ptr, [[maybe_unused]]size_t size) {

    }
};
/*
 * 有一种做法就是定义一个同名函数
 * 然后再搞一个同名的模板函数
 * 同名的模板函数调用他,这是zeno的一种设计模式
 * */

template<class T>
std::shared_ptr<T> get_input() {

}

class IObject;
template<class T>
T ObejectToLiteral(std::shared_ptr<IObject> const &ptr, const std::string &msg = "ObjectToLiteral") {
    if constexpr(std::is_same_v<T, std::string>) {

    } else if constexpr(std::is_same_v<int, T>) {

    } else {
       // return std::visit()
    }

}