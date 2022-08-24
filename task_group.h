//
// Created by admin on 2022/8/23.
//
#pragma once
#include <vector>
#include <functional>
#include <algorithm>
#include <variant>

struct task_group {
    std::vector<std::function<void()>> m_tasks;

    void add() {

    }

    void clear() {
        m_tasks.clear();
    }

    void run() {
        std::for_each(m_tasks.begin(), m_tasks.end(), [&](auto &&f){std::move(f)();});
    }

    template<class Accept = std::variant<std::vector<int>, float>, class F>
    void foreach_attr(F &&f) {
        std::string pos_name = "pos";
        f(pos_name);
        //
    }
};
