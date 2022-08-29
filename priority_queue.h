//
// Created by admin on 2022/8/28.
//
#pragma once
#include <vector>

/*
 * Implements a priority_queue using a vector-based max heap
 * */

template<typename T, typename Container = std::vector<T>, typename Less = std::less<Container::value_type>>
        class Priority_Queue {
        private:
            using container_type = Container;
            using size_type = typename container_type::size_type;
            using const_iterator = typename container_type :: const_iterator;
            using value_type = typename container_type ::value_type;
            using iterator = typename container_type ::iterator;
            using allocator_type = typename container_type::allocator_type;
            using Bass = Less;

            //返回节点i的父节点索引
            static size_type parent(size_type i) {
                return (--i) >> 1;
            }

            //返回节点i的右子树
            static size_type right(size_type i) {

            }

            //返回节点i的左子树
            static size_type left(size_type i) {

            }

            void heapify() {

            }

            void decrease_key(size_type i, value_type const& x) {
                m_container[i] = x;
                //自动调整堆
            }

            void increase_key(size_type i, value_type const& x) {
                m_container[i] = x;
                //自动调整堆

            }
        public:
            Priority_Queue(const Less &less) {
                //初始化比较函数和分配器官
            }

            template<typename Input_Iterator>
            Priority_Queue(Input_Iterator begin, Input_Iterator end) {

            }

            void assign(container_type const &container) {
                //接收其他容器来构造堆
                m_container = container;//其实可以用右值优化
                build_heap();
            }

            void build_heap() {
                //构造堆
                //首先特判一下尺寸是否大于一
                if (m_container.size() > 1) {

                }
            }

            value_type &top() {

            }

            value_type const &top() const {

            }

            void pop() {

            }

            void remove() {

            }

            void update() {

            }
            //接下来伺候一些迭代器
        private:
            container_type m_container;
        };

