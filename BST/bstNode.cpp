#include "bstNode.hpp"

BinTreeNode::BinTreeNode(std::string value, BinTreeNode* parent) {
    """Constructor that takes a string and BinTreeNode, then assigns the varibles""";
    this->value = value;
    this->frequency = 1;
    this->left = NULL;
    this->right = NULL;
    this->parent = parent;
}

