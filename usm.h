//
// Created by admin on 2022/8/31.
//
#pragma once

//实现一个Sycl usm的主要步骤

//和zeno一样的设计模式一个普通函数，一个模板函数，两个之间同名
//参数有字节数, 设备名， 上下文内容
inline void *malloc_device() {
    //return detail::select_device_allocator()
}

template<typename T>
T *malloc_device() {

}

class queue;

inline void *malloc_device(size_t num_bytes, const queue& q){

}

//分配内存对齐
inline void *aligned_alloc_device() {

}

//同样的我们也有一个

//同样的接下来是分配host和shared共享内存

//最后包裹一个通用的 malloc
