//
// Created by admin on 2022/9/1.
//
#pragma once
#include <iostream>
#include <vector>

class TVMValue;
class StackVM {
public:
    //param 是参数， 和Module
    void Run() {

    }

    enum class OpCode {

    };

    //类似于太极中的field
    enum StructFieldKind {

    };

    union Code {
        OpCode code;
        int v_int;
    };

    //接下来就是虚拟机栈
    class StackVN {
    public:
        //
        std::vector<TVMValue> heap;
        std::vector<TVMValue> stack;

        int PrintCode(std::ostream &out);

        //初始化栈的大小
        size_t stack_size{1024};

        
    };
};
