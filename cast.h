//
// Created by admin on 2022/8/5.
//
#pragma once
#include <cstring>

struct My {
    int i ;
    int j;
};

void up_to_date(char *blob, int new_value) {
    reinterpret_cast<My*>(blob)->i = new_value;
}

void up_to_data_up(char *blob, int new_value) {
    My obj[3];
    memcpy(obj, blob, sizeof(obj));
    obj[2].i = new_value;
    memcpy(blob, obj, sizeof(obj));
    //一种更安全的转换方式
}
