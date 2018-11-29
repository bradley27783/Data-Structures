#include <iostream>
#include <vector>
#include <iterator>

#include "graph.hpp"

GraphNode* Graph::add_Node(int value){
    //"""Creates a new node and adds it to the Graph"""
    //"""Returns a pointer to a new node"""

    GraphNode* graph_Node = new GraphNode(value);
    Nodes.push_back(graph_Node);
    return graph_Node;
}

GraphNode* Graph::get_Node(int val){
    //"""Pass in an int of an existing node and returns GraphNode* if found"""

    for(int i = 0; i < Nodes.size(); i++){
        if(Nodes[i]->value == val){
            return Nodes[i];
        }
    }
}   
void Graph::print_Graph(){
    //"""Prints all GraphNode values that exist in Nodes vector"""

    for(int i = 0; i < Nodes.size(); i++){
        std::cout << "Node: " << Nodes[i]->value << " " << "Connected to: " << std::endl;
        for(std::map<GraphNode*, int>::iterator it = Nodes[i]->adjacencyList.begin(); it != Nodes[i]->adjacencyList.end(); it++){
            std::cout << it->first->value << " Weight: " << it->second << std::endl;
        }
        std::cout << std::endl;
    }
}