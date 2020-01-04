
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

class TreeNode {
    public:
        int val = 0;
        TreeNode *left;
        TreeNode *right;

        TreeNode(int x) {
            val = x;
            left = right = nullptr;
        }
};

vector<vector<int>> zigzagTraversal(TreeNode *root) {
        vector<vector<int>> result;

        // Tree is empty
        if (root == nullptr) {
          return result;
        }

        queue<TreeNode *> queue;
        queue.push(root);

        // Tell zigzag traversal direction
        bool leftToRight = true;

        // Walk through level by level for populating current level array and preparing next level
        while (!queue.empty()) {
            int levelSize = queue.size();
            vector<int> levelValues(levelSize);

            // The loop will populate an array of current level items and will add next level items
            for (int i = 0; i < levelSize; i++) {
                TreeNode *currentNode = queue.front();
                queue.pop();

                // Add current node's value based on traversal direction
                if (leftToRight) {
                  levelValues[i] = currentNode->val;
                } else {
                  levelValues[levelSize - 1 - i] = currentNode->val;
                }

                // Enqueue the children of current node
                if (currentNode->left != nullptr) {
                  queue.push(currentNode->left);
                }
                if (currentNode->right != nullptr) {
                  queue.push(currentNode->right);
                }
        }

        // Add curreLevel into result & Toggle the traversal direction
        result.push_back(levelValues);
        leftToRight = !leftToRight;
    }

    return result;
  }

int main()
{
    // create tree
    struct TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(7);
    root->left->right = new TreeNode(6);
    root->right->left = new TreeNode(5);
    root->right->right = new TreeNode(4);

    vector<vector<int>> result = zigzagTraversal(root);

    for(auto level : result){
        int n = level.size();
        for (auto i=0; i<n; i++)
        {
            cout<<level[i]<<" ";
        }

        cout<<endl;
    }

    return 0;
}
/*
 Time Complexity : O(N) where N is number of nodes in the tree.
 Since we walk through each nodes in the tree

 Space Complexity : O(N)
 Since we are storing all nodes in the array and Queue will hold at most N/2 elements in case it is perfect binary tree
 So it is O(N) + O(N/2) ~ O(N)
 */
