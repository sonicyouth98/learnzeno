//
// Created by admin on 2022/9/2.
//

//学习MATX的Operator操作
#pragma once;

//使用CRTP
template<typename T>
class BaseOp {
public:
    using value_type = T;
    using matxop = bool;
    //launch a kernal in GPU Stream
    /*
    void run() {

    }
     */

    /*
     * launch a kernal in a GPU Stream and record an event
     * */

    template<typename Ex>
    void run(Ex ex) {
        //这里需要静态断言一下
        //static_assert();
    }
};

//这里BaseOp的类型就是
template<class I1, class I2, class Op>
class BinaryOp : public BaseOp<BinaryOp<I1, I2, Op>> {

};

//cast转换函数