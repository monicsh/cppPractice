#include <iostream>
#include <queue>

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

class LevelOrderTraversal {
 public:
  static vector<vector<int>> traverse(TreeNode *root) {
      vector<vector<int>> result;
      queue<TreeNode*> parent;
      queue<TreeNode*> children;
      queue<TreeNode*> temp;
      parent.push(root);
      int level = 0;

      while(!parent.empty())
      {
          result.push_back(vector<int>{});
          //int n = parent.size();

          //for(auto i=0; i<n; i++)
          while(!parent.empty())
          {
            TreeNode* curr = parent.front();
            parent.pop();
            result[level].push_back(curr->val);

            cout<<"ell"<<endl;
              if (curr->left)   children.push(curr->left);
              if (curr->right)  children.push(curr->right);

          }
          temp = parent;
          parent = children;
          children = temp;

        level++;
      }

      return result;
  }
};

int main(int argc, char *argv[]) {
  TreeNode *root = new TreeNode(12);
  root->left = new TreeNode(7);
  root->right = new TreeNode(1);
  root->left->left = new TreeNode(9);
  root->right->left = new TreeNode(10);
  root->right->right = new TreeNode(5);
  vector<vector<int>> result = LevelOrderTraversal::traverse(root);
  cout << "Level order traversal: "<<endl;
  for (auto vec : result) {
    for (auto num : vec) {
      cout << num << " :";
    }
    cout << endl;
  }
}

