#include <iostream>
#include <vector>
#include <fstream>

#include "graphNode.hpp"
#include "graph.hpp"
#include "queue.hpp"


bool in_Visited(GraphNode* value, std::vector<GraphNode*> visited){
    //"""Takes 2 parameters and checks if value is in visited."""
    //"""Returns true if in visited else false"""
    
    for(int i = 0; i < visited.size(); i++){
        if(visited[i] == value){
            return true;
        }
    }
    return false;
}

void add_Edge(GraphNode* node_One, GraphNode* node_Two, int weight){
    //"""Takes new GraphNode* and appends each other to the adjacencyList"""
    node_One->adjacencyList[node_Two] = weight;
    node_Two->adjacencyList[node_One] = weight;
}


/*
Title: Dijkstra's Psuedocode
Author: Diana Hintea
Date: 2018
Availability: http://moodle.coventry.ac.uk
*/

std::vector<int> dijkstra(Graph* graph, GraphNode* start, GraphNode* end){
    //"""Takes 3 parameters - Graph, start, end
    //Graph is the graph data structure you want to navigate
    //start and end are the node values you want to path from/to"""
    //Returns a vector of the path found. The last value being the
    //weight of the path


    GraphNode* current_Node = start;
    
    for(int i = 0; i < graph->Nodes.size(); i++)
        graph->Nodes[i]->tentativeWeight = 2000000000; //Setting all nodes tentativeWeight to 'infinite' i.e. a very large number
      
    start->tentativeWeight = 0;            
    std::vector<GraphNode*> visited;
    
    while(current_Node != end){
        for(std::map<GraphNode*, int>::iterator it = current_Node->adjacencyList.begin(); it != current_Node->adjacencyList.end(); it++){
            if(current_Node->tentativeWeight + current_Node->adjacencyList[it->first] < it->first->tentativeWeight){ //Check if the tentativeWeight + current_Nodes weight 
                                                                                                                     //is less than adjacent nodes tentativeWeight
                                                                                                                     
                it->first->tentativeWeight = current_Node->tentativeWeight + current_Node->adjacencyList[it->first]; //set the adjacent tentativeWeight = to the current_Node
                                                                                                                     //tentativeWeight + the current_Node's weighted edge
                it->first->prev = current_Node; //Create a return path to allow us to navigate
                                                //back to the start node (creating the path taken)
            }
        }
        visited.push_back(current_Node);
        int min = 2000000000;
        
        GraphNode* temp;
        
        for(std::map<GraphNode*, int>::iterator it = current_Node->adjacencyList.begin(); it != current_Node->adjacencyList.end(); it++){
                                                                       //Iterating through the current_Node's neighbouring nodes
                                                                       //and finds the node with the smallest tentativeWeight
            if(!in_Visited(it->first, visited) && (it->second < min)){
                temp = it->first;
                min = it->first->tentativeWeight;
            }
        }
        current_Node = temp;
    }
    
    std::vector<int> path_Found;
    path_Found.push_back(current_Node->tentativeWeight); //Placing the weight of the path at the end
        
    while(current_Node != start){
                                            //Iterating through the nodes to navigate backwards to find the route
                                            //and add it to the vector
        path_Found.insert(path_Found.begin(),current_Node->value);           
        current_Node = current_Node->prev;
    }
    path_Found.insert(path_Found.begin(),current_Node->value);
    
    return path_Found;
}


void print_Dijkstra(std::vector<int> values){
    //"""Takes a vector of values and prints them out. The last value being the weight
    //of the path found"""
    for(int i = 0; i < values.size(); i++){
        if(i == values.size()-1){
            std::cout << std::endl;
            std::cout << "Total Weight: " << values[i] << std::endl;
        }
    else
        std::cout << values[i] << " ";
    }
}


int main(){
    
    Graph* g = new Graph();    
    
    for(int i = 0; i<=5; i++){
        GraphNode* node = g->add_Node(i);
    }
    
    add_Edge(g->get_Node(0),g->get_Node(1), 3);
    add_Edge(g->get_Node(0),g->get_Node(3), 11);
    add_Edge(g->get_Node(1),g->get_Node(2), 1);
    add_Edge(g->get_Node(1),g->get_Node(3), 6);
    add_Edge(g->get_Node(2),g->get_Node(3), 5);
    add_Edge(g->get_Node(3),g->get_Node(4), 3);
    
    print_Dijkstra(dijkstra(g,g->get_Node(0),g->get_Node(3)));
    
    
  
    return 1;
}