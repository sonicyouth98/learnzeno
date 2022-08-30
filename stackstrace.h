//
// Created by admin on 2022/8/30.
//
#pragma once
#include <stdio.h>
#include <iostream>

static inline void printStackStrace(std::ostream &eout = std::cerr,
                                    unsigned int max_frames = 52) {
#ifdef _WIN32

#else
    std::stringstream out;
    //堆栈跟踪地址
    void *addrlist[max_frames + 1];

    if() {
        out <<
        return ;
    }

    free(addrlist);
#endif
}
