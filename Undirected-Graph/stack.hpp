#ifndef STACK_H
#define STACK_H

#include "graphNode.hpp"


class Stack{
    //"""FIFO datastructure for GraphNode*"""
    
public:
    std::vector<GraphNode*> stack;
    
    void push(GraphNode* value);
    
    GraphNode* pop();
    
    void print();
};

#endif