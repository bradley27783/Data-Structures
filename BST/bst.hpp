#ifndef BST_H
#define BST_H

#include "bstNode.hpp"

BinTreeNode* tree_insert(BinTreeNode* tree, std::string item);;

void postorder(BinTreeNode* tree);

void in_order(BinTreeNode* tree);

void pre_order(BinTreeNode* tree);

BinTreeNode* findMin(BinTreeNode* tree);

BinTreeNode* findMax(BinTreeNode* tree);

BinTreeNode* find_Node(BinTreeNode* tree, std::string target);

BinTreeNode* deletion(BinTreeNode* tree);

std::vector<std::string> read_Text(const char* fileName); 

#endif