#ifndef GRAPHNODE_H
#define GRAPHNODE_H

#include <iostream>
#include <vector>
#include <map>

class GraphNode{
    // """GraphNode datastructure that stores neighbour values in a list"""
    
public:
    
    std::map<GraphNode* , int> adjacencyList;
    
    int tentativeWeight;
    GraphNode* prev;
    
    int value;
    
    GraphNode(int value);
};

#endif