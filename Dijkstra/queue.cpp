#include <iostream>
#include <vector>

#include "queue.hpp"
   
void Queue::enqueue(GraphNode* value){
    //"""Takes GraphNode* as input and adds it to the stack"""

    queue.emplace_back(value);
}
GraphNode* Queue::dequeue(){
    //"""Remove top element from the stack and returns GraphNode* value"""

    if(queue.size() != 0){
        GraphNode* bottom = queue.front();
        queue.erase(queue.begin());
        return bottom;
    }
    else
        std::cout << "Queue Empty!" << std::endl;
}

std::map<GraphNode*,int> Queue::find_Min(){
    std::map<GraphNode*,int> min = min.insert({queue.begin->first,queue.begin->second});
    
    for(std::map<GraphNode*, int>::iterator it = queue.begin(); it != queue.end(); it++){
        if(min > it->second){
            min.empty();
            min.insert({queue.begin()->first,queue.begin()->second});
        }
    }
    queue.erase(queue.find(min.begin()->first));
    return min;
}
    
void Queue::change_Priority(GraphNode* value){
    queue.find(value);
}

void Queue::print(){
    //"""Prints all values currently in the stack"""

    for(int i = 0; i < queue.size();  i++)
        std::cout << queue[i]->value << std::endl;
}
