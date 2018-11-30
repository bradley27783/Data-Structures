#include <iostream>
#include <vector>

#include "graph.hpp"

GraphNode* Graph::add_Node(int value){
    //"""Creates a new node and adds it to the Graph"""
    //"""Returns a pointer to a new node"""
    
    if(get_Node(value) != NULL){
        std::cout << "Node Already Exists!" << std::endl;
        return NULL;
    }
    else{  
        GraphNode* graph_Node = new GraphNode(value);
        Nodes.push_back(graph_Node);
        return graph_Node;
    }
}

GraphNode* Graph::get_Node(int val){
    //"""Pass in an int of an existing node and returns GraphNode* if found"""

    for(int i = 0; i < Nodes.size(); i++){
        if(Nodes[i]->value == val){
            return Nodes[i];
        }
    }
    return NULL;
}   
void Graph::print_Graph(){
    //"""Prints all GraphNode values that exist in Nodes vector"""

    for(int i = 0; i < Nodes.size(); i++){
        std::cout << "Node: " << Nodes[i]->value << " " << "Connected to: ";
        for(int j = 0; j < Nodes[i]->adjacencyList.size(); j++){
            std::cout << Nodes[i]->adjacencyList[j]->value << " ";
        }
        std::cout << std::endl;
    }
}