

#include <stdio.h>

#define CATCH_CONFIG_MAIN
#include "catch.hpp"

using namespace std;

/*
 TreeNode Structure
 */
class TreeNode{
public:
    int val;
    TreeNode * left;
    TreeNode * right;

    TreeNode(int val){
        val = val;
        left = nullptr;
        right = nullptr;
    }
};

bool isBalancedUtil(TreeNode* root, int & height){
    // If tree is empty: set height & return true
    if (root == nullptr){
        height = -1;
        return true;
    }

    int leftHt;
    int rightHt;
    if (isBalancedUtil(root->left, leftHt) &&
        isBalancedUtil(root->right, rightHt) &&
        abs(leftHt-rightHt) <= 1)
    {
        height = 1 + max(leftHt, rightHt);
        return true;
    }

    return false;
}

bool isBalanced(TreeNode* root){
    int height;
    return isBalancedUtil(root, height);
}



TEST_CASE("Balanced Tree TC001", "[isBalanced]"){
    // arrange
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->left->left->left = new TreeNode(8);

    //act
    bool status = false;

    // assert
    CHECK( status == isBalanced(root));
}

TEST_CASE("Balanced Tree TC002", "[isBalanced]"){
    // arrange
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);


    //act
    bool status = true;

    // assert
    CHECK( status == isBalanced(root));
}
