

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

int height(TreeNode * root){
    if (root == nullptr)
        return 0;

    return 1 + max(height(root->left), height(root->right));

}

bool isBalanced(TreeNode* root){
    // left and right subtree height
    int leftHt;
    int rightHt;

    // Check if tree is empty
    if (root == nullptr)
        return true;

    // Calculate height of left and right subtree
    leftHt = height(root->left);
    rightHt = height(root->right);

    // determine if tree is height-balanced
    if(abs(leftHt - rightHt) <=1 && isBalanced(root->left) && isBalanced(root->right))
        return true;

    return false;
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
