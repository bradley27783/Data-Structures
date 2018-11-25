#ifndef GRAPH_H
#define GRAPH_H

#include "graphNode.hpp"

class Graph{
    //"""Datastructure for a graph. Stores GraphNode* in a vector"""
    
public:
    std::vector<GraphNode*> Nodes;
    
    GraphNode* add_Node(int value);
    
    GraphNode* get_Node(int val);
    
    void print_Graph();
};

#endif