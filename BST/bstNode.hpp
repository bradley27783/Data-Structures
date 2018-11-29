#ifndef BSTNODE_H
#define BSTNODE_H

#include <iostream>
#include <fstream>
#include <vector>
#include <string>


class BinTreeNode {
    //"""A Class that creates the datastructure of a Binary Search Tree""";
public:
    BinTreeNode(std::string value, BinTreeNode* parent);
    
	std::string value;
    int frequency;
	BinTreeNode* left;
	BinTreeNode* right;
    BinTreeNode* parent;
};

#endif
