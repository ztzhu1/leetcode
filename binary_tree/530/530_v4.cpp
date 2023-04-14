#include <cstddef>
#include <optional>
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
        inorder(root);
        return _minimum.value();
    }

    void inorder(TreeNode *node) {
        if (node == nullptr || (_minimum.has_value() && _minimum.value() == 0)) {
            return;
        }
        inorder(node->left);
        if (_pre.has_value()) {
            int diff = node->val - _pre.value();
            if (!_minimum.has_value() || diff < _minimum.value()) {
                _minimum = diff;
                if (diff == 0) {
                    return;
                }
            }
        }
        _pre = node->val;
        inorder(node->right);
    }

private:
    std::optional<int> _pre;
    std::optional<int> _minimum;
};