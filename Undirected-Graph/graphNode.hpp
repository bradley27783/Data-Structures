#ifndef GRAPHNODE_H
#define GRAPHNODE_H

#include <iostream>
#include <vector>

class GraphNode{
    // """GraphNode datastructure that stores neighbour values in a list"""
    
public:
    
    std::vector<GraphNode*> adjacencyList;
    int value;
    
    GraphNode(int value);
};

#endif