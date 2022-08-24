//
// Created by admin on 2022/8/24.
//
#pragma once

#include <optional>
#include <unordered_map>
#include <vector>
#include <memory>

class CFGNode {


    std::vector<CFGNode *> prev, next;
    static void add_edge(CFGNode *from, CFGNode *to);

};

class ControlFlowGraph {
private:
    void erase(int node_id); //删除一个空节点

public:
    std::vector<std::unique_ptr<CFGNode>> nodes;

    template<typename... Args>
    CFGNode *push_back(Args &&...args) {
        nodes.template emplace_back(std::make_unique<CFGNode>(std::forward<Args>(args)...));
        //返回一个裸指针
        return nodes.back().get();
    }

    void print_graph_structure() const{

    }

    std::size_t size() const {

    }

    void reaching_definition_analysis(bool after_lower_access) {

    }


};
