#include <iostream>
#include <fstream>
#include <vector>
#include <string>


class BinTreeNode {
public:
	BinTreeNode(std::string value, BinTreeNode* parent) {
		this->value = value;
		this->left = NULL;
		this->right = NULL;
        this->parent = parent;
	}
	std::string value;
	BinTreeNode* left;
	BinTreeNode* right;
    BinTreeNode* parent;
};

BinTreeNode* tree_insert(BinTreeNode* tree, std::string item) {
	if (tree == NULL)
		tree = new BinTreeNode(item, NULL);
	else
		if (item < tree->value)
			if (tree->left == NULL)
				tree->left = new BinTreeNode(item,tree);
			else
				tree_insert(tree->left, item);
		else
			if (tree->right == NULL)
				tree->right = new BinTreeNode(item,tree);
			else
				tree_insert(tree->right, item);
	return tree;

}

void postorder(BinTreeNode* tree) {
	if (tree->left != NULL)
		postorder(tree->left);
	if (tree->right != NULL)
		postorder(tree->right);
	std::cout << tree->value << std::endl;
}

void in_order(BinTreeNode* tree) {
	if (tree->left != NULL){
		in_order(tree->left);
    }
	std::cout << tree->value << std::endl;
	if (tree->right != NULL){
		in_order(tree->right);
    }
}

void pre_order(BinTreeNode* tree) {
    std::cout << tree->value << std::endl;
	if (tree->left != NULL){
		pre_order(tree->left);
    }
	if (tree->right != NULL){
		pre_order(tree->right);
    }
}

BinTreeNode* find_Node(BinTreeNode* tree, std::string target){ 
    std::cout<<tree->value<<std::endl;
    
    if(tree == NULL){
        std::cout << "Node Not Found!" << std::endl;
        return tree;
    }
    
    else if(tree->value == target){
        std::cout << "Node Found!" << std::endl;
        return tree;
    }
    else if(tree->value > target)
        find_Node(tree->left, target);

    else{
        find_Node(tree->right,target);
    }
}


BinTreeNode* findMin(BinTreeNode* tree){
    while(tree->left != NULL){
        tree = tree->left;
    }
    return tree;
}

BinTreeNode* findMax(BinTreeNode* tree){
    while(tree->right != NULL){
        tree = tree->right;
    }
    return tree;
}

BinTreeNode* deletion(BinTreeNode* tree){
    if(tree != NULL){
        BinTreeNode* parent = tree->parent;
        BinTreeNode* min;
        BinTreeNode* max;
        
        //Node to be deleted is a leaf
        if(tree->left == NULL && tree->right == NULL){
            std::cout << "1" << std::endl;
            if(parent->left != tree && parent->right == tree){
                delete tree;
                parent->right = NULL;
            }
            else if(parent->left == tree && parent->right != tree){
                delete tree;
                parent->left = NULL;
            }
        }
        
        //Node to be deleted has a subtree on the right
        else if(tree->left == NULL && tree->right != NULL){
            std::cout << "2" << std::endl;
            if(parent->left != tree && parent->right == tree){
                delete tree;
                parent->right = tree->right;
            }
            else if(parent->left == tree && parent->right != tree){
                delete tree;
                parent->left = tree->right;
            }
        }      
        
        //Node to be deleted has a subtree on the left
        else if(tree->left != NULL && tree->right == NULL){
            std::cout << "3" << std::endl;
            if(parent->left != tree && parent->right == tree){
                delete tree;
                parent->right = tree->left;
            }
            else if(parent->left == tree && parent->right != tree){
                delete tree;
                parent->left = tree->left;
            }
        }
        
        //Node to be deleted has a subtree on both sides
        else{         
            std::cout << "4" << std::endl;
            min = findMin(tree->right);
            tree->value = min->value;
            delete min;

            if(min->parent->left != min && min->parent->right == min){
                min->parent->right = NULL;
            }
            else if(min->parent->left == min && min->parent->right != tree){
                min->parent->left = NULL;
            }           
        }                
    }
    else 
        std::cout << "No Tree!" << std::endl;
}

std::vector<std::string> read_Text(){
    std::vector<std::string> words;
    
    std::ifstream file;
    file.open("paragraph.txt");
    
    if(file.is_open()){
        std::string word;
        while(file >> word){
            words.push_back(word);
        }
        return words;
    }
    else
        std::cout << "Cannot Open The File!" << std::endl;    
} 




int main(int argc, char *argv[])
{
    std::vector<std::string> text = read_Text();
    
    
	BinTreeNode* t = tree_insert(0, text[0]);
    for(int i = 1; i < text.size(); i++){
        tree_insert(t,text[i]);
    }
    //find_Node(t,"single");
    
	in_order(t);
    std::cout << "----------------------------------" << std::endl;
	deletion(find_Node(t,"zebra"));
    std::cout << "----------------------------------" << std::endl;
    in_order(t);
	return 0;
}
