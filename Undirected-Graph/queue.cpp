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
void Queue::print(){
    //"""Prints all values currently in the stack"""

    for(int i = 0; i < queue.size();  i++)
        std::cout << queue[i]->value << std::endl;
}
