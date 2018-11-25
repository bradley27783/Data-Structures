#include <iostream>
#include <vector>

#include "graphNode.hpp"
#include "stack.hpp"
#include "graph.hpp"


bool in_Visited(GraphNode* value, std::vector<GraphNode*> visited){
    //"""Takes 2 parameters and checks is value is in visited."""
    //"""Returns true if in visited else false"""
    
    for(int i = 0; i < visited.size(); i++){
        if(visited[i] == value){
            return true;
        }
    }
    return false;
}

void add_Edge(GraphNode* node_One, GraphNode* node_Two){
    //"""Takes new GraphNode* and appends each other to the adjacencyList"""
        node_One->adjacencyList.push_back(node_Two);
        node_Two->adjacencyList.push_back(node_One);
    }


int degree(GraphNode* node){
    //"""Takes a GraphNode* and returns the degree of the node"""
        return node->adjacencyList.size();
}


std::vector<GraphNode*> is_Path(GraphNode* start, GraphNode* end){
    //"""Takes two GraphNode* and returns the path between the two"""
    
    Stack* s = new Stack();
    std::vector<GraphNode*> visited;
    s->push(start);

    while(s->stack.size() != 0){ //Iterate until the stack is empty
        GraphNode* top = s->pop();

        if(!in_Visited(top, visited)){ /* Calls the in_Visited() function 
                                        * which returns true if top is in visited */
            visited.push_back(top);

            std::cout << top->value << std::endl;

            if(top == end){ // Exit case if end is found
                return visited;
            }

            else{                
                for(int i = 0; i < degree(top); i++){
                    s->push(top->adjacencyList[i]);     // Calls the degree function
                                                        // then appends all the nodes 
                                                        // neighbours to the stack
                }
            }
        }
    }
    return visited;
}




std::vector<GraphNode*> depth_First(GraphNode* start){
    //"""Takes a GraphNode* and traverses the tree until all nodes are visited"""
    //"""Returns the path traversed"""
    
    Stack* s = new Stack();
    std::vector<GraphNode*> visited;
    s->push(start);

    while(s->stack.size() != 0){ //Iterate until the stack is empty
        GraphNode* top = s->pop();

        if(!in_Visited(top, visited)){ /* Calls the in_Visited() function 
                                        * which returns true if top is in visited */ 
            visited.push_back(top);

            std::cout << top->value << " ";

            for(int i = 0; i < degree(top); i++){  // Calls the degree function 
                s->push(top->adjacencyList[i]);    // then appends all the nodes 
                                                   // neighbours to the stack
                }
            std::cout << std::endl;
        }
    }
    return visited;
}

int main(){
    
    Graph* g = new Graph();
    
    
    for(int i = 0; i<=5; i++){
        GraphNode* node = g->add_Node(i);
        //std::cout << node->value << std::endl;
    }
    
    add_Edge(g->get_Node(0),g->get_Node(1));
    add_Edge(g->get_Node(0),g->get_Node(3));
    add_Edge(g->get_Node(1),g->get_Node(2));
    add_Edge(g->get_Node(1),g->get_Node(3));
    add_Edge(g->get_Node(2),g->get_Node(3));
    add_Edge(g->get_Node(3),g->get_Node(4));
    
    
    is_Path(g->get_Node(0),g->get_Node(2));
    
    //depth_First(g->get_Node(0));

    //g->print_Graph();
    
    
  
    return 1;
}