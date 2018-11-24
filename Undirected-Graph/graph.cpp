#include <iostream>
#include <vector>

class GraphNode {
public:
    std::vector<GraphNode*> adjacencyList;
    int value;
    
    GraphNode(int value){
        this->value = value;
    }
};



class Graph{
public:
    std::vector<GraphNode*> Nodes;
    
    GraphNode* add_Node(int value){
        GraphNode* graph_Node = new GraphNode(value);
        Nodes.push_back(graph_Node);
        return graph_Node;
    }
    
    GraphNode* get_Node(int val){
        for(int i = 0; i < Nodes.size(); i++){
            if(Nodes[i]->value == val){
                return Nodes[i];
            }
        }
    }

    void add_Edge(GraphNode* node_One, GraphNode* node_Two){
        node_One->adjacencyList.push_back(node_Two);
        node_Two->adjacencyList.push_back(node_One);
    }
    
    void print_Graph(){
        for(int i = 0; i < Nodes.size(); i++){
            std::cout << "Node: " << Nodes[i]->value << " " << "Connected to: ";
            for(int j = 0; j < Nodes[i]->adjacencyList.size(); j++){
                std::cout << Nodes[i]->adjacencyList[j]->value << ", ";
            }
            std::cout << std::endl;
        }
    }
};

int main(){
    
    Graph* g = new Graph();
    
    for(int i = 0; i<=4; i++){
        GraphNode* node = g->add_Node(i);
        std::cout << node->value << std::endl;
    }    
    
    g->add_Edge(g->get_Node(0),g->get_Node(1));
    g->add_Edge(g->get_Node(0),g->get_Node(3));
    g->add_Edge(g->get_Node(1),g->get_Node(2));
    g->add_Edge(g->get_Node(1),g->get_Node(3));
    g->add_Edge(g->get_Node(2),g->get_Node(1));
    g->add_Edge(g->get_Node(2),g->get_Node(3));
    g->add_Edge(g->get_Node(3),g->get_Node(4));

    g->print_Graph();
    
    
  
    return 1;
}