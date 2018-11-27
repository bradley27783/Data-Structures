#include <iostream>
#include <vector>

#include "stack.hpp"
   
void Stack::push(GraphNode* value){
    //"""Takes GraphNode* as input and adds it to the stack"""

    stack.emplace_back(value);
}
GraphNode* Stack::pop(){
    //"""Remove top element from the stack and returns GraphNode* value"""

    if(stack.size() > 0){
        GraphNode* top = stack.back();
        stack.pop_back();
        return top;
    }
    else
        std::cout << "Stack Empty!" << std::endl;
}
void Stack::print(){
    //"""Prints all values currently in the stack"""

    for(int i = 0; i < stack.size();  i++)
        std::cout << stack[i]->value << std::endl;
}
