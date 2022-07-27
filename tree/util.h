#include <vector>

// Only accepts positive values.
struct TreeNode {
  int val = 0;
  TreeNode* left = nullptr;
  TreeNode* right = nullptr;

  TreeNode(int value) : val{value} {
    if (value < 0) {
      throw "TreeNode only takes positive values.";
    }
  }
};

// Recursively delete all nodes in a tree
// Be careful not to double free!
void delete_tree(TreeNode* root);

// Build a tree from vector representation of it.
TreeNode* build_tree(const std::vector<int>& tree);

// Build the vector representation of a tree.
std::vector<int> collapse_tree(TreeNode* root);
