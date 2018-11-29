#ifndef QUEUE_H
#define QUEUE_H

#include "graphNode.hpp"


class Queue{
    //"""FIFO datastructure for GraphNode*"""
    
public:
    std::vector<GraphNode*> queue;
    
    void enqueue(GraphNode* value);
    
    GraphNode* dequeue();
    
    void print();
};

#endif