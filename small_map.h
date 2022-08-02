//
// Created by admin on 2022/7/27.
//
#pragma once

#include <iostream>
#include <algorithm>
#include <vector>

template<class Key, class Value>
class Small_map {
public:
    using value_type = std::pair<Key, Value>;
    using key_type = Key;
    using mapped_type = Value;

    auto begin() noexcept {
        return _v.begin();
    }

    auto cbegin() noexcept {
        return _v.cebgin();
    }

    auto end() noexcept {
        return _v.end();
    }


    std::size_t size() {
        return _v.size();
    }

    auto find(const Key &k) const noexcept {
        return std::find_if(_v.cbegin(), _v.cend(), [&](const value_type &v) {return v.first == k; });
    }

    auto find(const Key &k) noexcept {
        return std::find_if(_v.cbegin(), _v.cend(), [&](const value_type &v) {
            return v.first == k;
        });
    }

    bool contain(const Key &k) const noexcept {
        return find(k) != _v.cend();
    }

    void clear() {
        _v.clear();
    }

    Value& operator[](const Key& k) {
        auto exisiting = find(k);
        if (exisiting != _v.end()) {
            return exisiting->second;
        }
        //如果没有的化make_pair一下
        _v.push_back(std::make_pair(k, Value{}));
        return _v.back().second;
    }
private:
    std::vector<std::pair<Key, Value>> _v;
};