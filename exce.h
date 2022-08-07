//
// Created by admin on 2022/8/7.
//

//假如在构造函数中抛出了异常

#include <cstddef>
#include <iostream>
#include <new>
#include <exception>

template<typename T>
class Matrix {
public:
    Matrix(size_t width, size_t length);
    virtual  ~Matrix();
private:
    void cleanup();//清理资源

    size_t m_width{0};
    size_t m_length{0};
    T** m_matrix{nullptr};
};

template<typename T>
Matrix<T>::Matrix(size_t width, size_t length) {
    m_matrix = new T*[width];
    m_width = width;
    m_length = length;

    try {
        for (size_t i {0}; i < width; i++) {
            //如果内存分配失败会抛异常，自己记得清理资源
            m_matrix[i] = new T[length];
        }
    } catch(...)  {
        std::cerr << "Exception caught in constructor" << std::endl;
        cleanup();
        std::throw_with_nested(std::bad_alloc{});
    }
}

template<typename T>
void Matrix<T>::cleanup() {

}

template<typename T>
Matrix<T> ::~Matrix() {
   cleanup();
}        

