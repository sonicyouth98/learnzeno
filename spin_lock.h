//
// Created by admin on 2022/7/27.
//
#pragma once
#include <atomic>
#include <thread>
#include <chrono>

class SpinMutex {
    //如果运行的线程数大于硬件的线程数
private:
    std::atomic_flag mFlag = ATOMIC_FLAG_INIT;
public:
    SpinMutex() = default;
    SpinMutex(const SpinMutex&) = delete;
    SpinMutex& operator=(const SpinMutex&) = delete;

    void lock() noexcept{
        while (mFlag.test_and_set(std::memory_order_acquire)) {
            //线程等待
            std::this_thread::sleep_for(std::chrono::microseconds(1));
        }
        //如果我的标志位为真，则线性等待
    }

    void unlock() noexcept{
        mFlag.clear(std::memory_order_release);//原地将标志位设置为false
    }
};
