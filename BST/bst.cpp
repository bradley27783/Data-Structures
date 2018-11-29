#include "bst.hpp"

BinTreeNode* tree_insert(BinTreeNode* tree, std::string item) {
    """Takes a """;
        
	if (tree == NULL)
		tree = new BinTreeNode(item, NULL);
	else
        if(tree->value == item){
            tree->frequency++;
        }
		else if (item < tree->value)
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
    std::cout << tree->frequency << std::endl;
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

BinTreeNode* find_Node(BinTreeNode* tree, std::string target) {
    std::cout << "Value: " << tree->value << "    " << tree->frequency << std::endl;
    
    if (tree == NULL){
        std::cout << "No Tree Given!" << std::endl;
        return NULL;
    }
    
    else if (tree->value == target){
        std::cout << "Node found!" << std::endl;
        return tree;                          
    }
    
    else if (tree->value > target){
        if(tree->left == NULL){
            std::cout << "Node not found!" << std::endl;
            return NULL;
        }
        else
            return find_Node(tree->left, target);
    }
    
    else{ 
        if(tree->right == NULL){
            std::cout << "Node not found!" << std::endl;
            return NULL;
        }
        else
            return find_Node(tree->right, target);
    }
}

BinTreeNode* deletion(BinTreeNode* tree){
    if(tree != NULL){
        BinTreeNode* parent = tree->parent;
        BinTreeNode* min;
        BinTreeNode* max;
        
        //Node to be deleted is a leaf
        if(tree->left == NULL && tree->right == NULL){
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
        std::cout << "Could Not Perform Deletion: No Tree Given!" << std::endl;
}

std::vector<std::string> read_Text(const char* fileName){
    std::vector<std::string> words;   
    std::ifstream file;
    
    file.open(fileName);
    
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



/*int main(int argc, char *argv[])
{
    
    std::vector<std::string> text = read_Text("paragraph.txt");
    
    
	BinTreeNode* tree = tree_insert(0, text[0]);
    for(int i = 1; i < text.size(); i++){
        tree_insert(tree,text[i]);
    }
        
	in_order(tree);
    std::cout << "----------------------------------" << std::endl;
	deletion(find_Node(tree,"in"));
    std::cout << "----------------------------------" << std::endl;
    in_order(tree);
	return 0;
}*/
