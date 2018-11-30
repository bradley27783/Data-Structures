#ifndef QUEUE_H
#define QUEUE_H

#include "graphNode.hpp"


class Queue{
    
public:
    std::vector<GraphNode*> queue;
    
    void enqueue(GraphNode* value);
    
    GraphNode* dequeue();
    
    GraphNode* find_Min();
    
    void change_Priority(GraphNode* value);
    
    void print();
};

#endif