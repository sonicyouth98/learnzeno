//
// Created by admin on 2022/7/26.
//

#pragma once
#include <mutex>
#include <queue>
#include <memory>

template<typename T>
class threadSafe_queue {
    mutable std::mutex mtx;
    std::queue<T> data_queue;
    std::condition_variable data_cond;
public:
    threadSafe_queue() {}
    threadSafe_queue(const threadSafe_queue &other) {
        std::lock_guard<std::mutex> lk(other.mtx);
        data_queue = other.data_queue;
    }

    void push(const T& val) {
        std::lock_guard<std::mutex> lk(mtx);
        data_queue.push(val);
        //开始通知
        data_cond.notify_one();
    }

    void push(T &&val) {
     std::lock_guard<std::mutex> lk(mtx);
     data_queue.push(std::move(val));
     data_cond.notify_one();
    }

    void wait_pop(T &val) {
        std::unique_lock<std::mutex> lk(mtx);
        data_cond.wait(lk, [this] {return !data_queue.empty();});
        val = data_queue.front();
        data_queue.pop();
    }

    decltype(auto) wait_pop() {

    }

    bool empty() const {
        std::lock_guard<std::mutex> lk(mtx);
        return data_queue.empty();
    }

    std::shared_ptr<T> wait_and_pop_ptr() {

    }

    bool try_top(T &value) {
        std::lock_guard<std::mutex> lk(mtx);
        if (data_queue.empty()) {
            return false;
        }
        value = data_queue.front();
        data_queue.pop();
        return true;
    }

};