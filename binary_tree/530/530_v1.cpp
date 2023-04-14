#include <cstddef>
#include <vector>

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    int getMinimumDifference(TreeNode *root) {
        std::vector<int> vals;
        inorder(vals, root);
        int minimum = vals[1] - vals[0];
        for (size_t i = 2; i < vals.size(); ++i) {
            int diff = vals[i] - vals[i - 1];
            if (diff < minimum) {
                minimum = diff;
            }
        }
        return minimum;
    }

    void inorder(std::vector<int> &vals, TreeNode *node) {
        if (node == nullptr) {
            return;
        }
        inorder(vals, node->left);
        vals.push_back(node->val);
        inorder(vals, node->right);
    }
};