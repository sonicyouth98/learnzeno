//
// Created by admin on 2022/8/23.
//
#pragma once

#include <chrono>
#include <string_view>
#include <map>
#include <utility>

class Timer {
    using ClockType = std::chrono::high_resolution_clock;

    struct Record {
        std::string tag;
        int us;

        Record(std::string &&tag, int us) : tag(std::move(tag)), us(us){

        }
    };
private:
    static Timer *current;
    static std::vector<Record> records;

    Timer *parent = nullptr;
    ClockType ::time_point beg;
    ClockType ::time_point end;
    std::string tag;

    Timer();
    void Destroy(ClockType::time_point &&end) {
        current = parent;
        auto diff = end - beg;
        int us = std::chrono::duration_cast<std::chrono::microseconds>(diff).count();
        records.emplace_back(std::move(tag), us);
    }

public:

    ~Timer() {
        Destroy(ClockType::now());
    }

    static auto const &getRecords() {
        return records;
    }
    static std::string getLog() {
        if (records.size() == 0) {
            return "";
        }
        std::string res;

        struct Statistic {
            int max_us{};
            int min_us{};
            int total_us{};
            int count_res{};
        };

        std::map<std::string, Statistic> stats;
        for (auto &[tag, us] : records) {

        }

        std::vector<std::pair<std::string, Statistic>> sortstats;
        for (const auto &kv : stats) {
            sortstats.push_back(kv);
        }
        return res;
    }
};

Timer *Timer::current = nullptr;
std::vector<Timer::Record> Timer::records;
