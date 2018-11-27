#include <iostream>
#include <vector>
#include <fstream>

#include "graphNode.hpp"
#include "stack.hpp"
#include "queue.hpp"
#include "graph.hpp"


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

    while(s->stack.size() > 0){ //Iterate until the stack is empty
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

    while(s->stack.size() > 0){ //Iterate until the stack is empty
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



std::vector<GraphNode*> breadth_First(GraphNode* start){
    Queue* q = new Queue();
    std::vector<GraphNode*> visited;  
    q->enqueue(start);
    
    while(q->queue.size() > 0){ //Iterate until the queue is empty
        GraphNode* bottom = q->dequeue();
        
        if(!in_Visited(bottom, visited)){  //Calls the in_Visited() function
            visited.push_back(bottom);     //which returns true if top is in visited
            std::cout << bottom->value << " ";
            
            for(int i = 0; i < degree(bottom); i++){  // Calls the degree function 
                q->enqueue(bottom->adjacencyList[i]); // then appends all the nodes 
                                                      // neighbours to the stack
            }
            std::cout << std::endl;
        }
    }
    return visited;
}


bool is_Connected(Graph* graph){
    //"""Takes the parameter of graph and checks whether the graph 
    //   is connected (returns true) or not (returns false)."""
 
    bool connected;
    
    if(graph == NULL){
        std::cout << "No Graph Exists!" << std::endl;
        return false;
    }
    else if(graph->Nodes.size() == 1){
        std::cout << "Yes" << std::endl;
        return true;
    }
    else{
        std::vector<GraphNode*> connected_Nodes = depth_First(graph->Nodes[0]); //Fetchs vector from depth_First
        
        for(int i = 0; i < graph->Nodes.size(); i++){ //For each node in the graph compare with nodes found by
            connected = false;                        //depth_First if a value is missing then the graph isn't connected
            for(int j = 0; j < connected_Nodes.size(); j++){
                if(graph->Nodes[i] == connected_Nodes[j]){
                    connected = true;
                }
            }
            if(!connected){
                std::cout << "No" << std::endl;
                return false;
            }
        }
        std::cout << "Yes" << std::endl;
        return true;
    }
}


void write(std::vector<GraphNode*> values, std::string file_Name){
    //"""Takes a vector of graphnodes and a string file_Name and
    //   inserts the graphnodes into the file called file_Name"""

    std::ofstream file;
    file.open(file_Name);
    
    if(file.is_open()){
        for(int i = 0; i < values.size(); i++)
            file << values[i]->value;
    }
    else{
        std::cout << "Cannot Open File!" << std::endl;
    }
    file.close();
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
    
    
    write(is_Path(g->get_Node(0),g->get_Node(2)),"path.txt");
    
    write(depth_First(g->get_Node(0)),"DFS.txt");
    write(breadth_First(g->get_Node(0)),"BFS.txt");
    
    is_Connected(g);

    //g->print_Graph();
    
    
  
    return 1;
}