#include <cxxtest/TestSuite.h>
#include "bstNode.hpp"
#include "bst.hpp"

class MyTestSuite : public CxxTest::TestSuite{
public:
    
    BinTreeNode* create_Tree(){
        std::vector<std::string> text = read_Text("paragraph.txt");

        BinTreeNode* tree = tree_insert(0, text[0]);
        for(int i = 1; i < text.size(); i++){
            tree_insert(tree,text[i]);
        }
        return tree;
    }
    
    void test_delete_Leaf(){     

        BinTreeNode* root = create_Tree();
        //TS_ASSERT_EQUALS();
  }
  
};