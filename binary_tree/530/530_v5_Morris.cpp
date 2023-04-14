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
        TreeNode *curr = root;
        TreeNode *predecessor = nullptr;
        while (curr) {
            if (curr->left) {
                predecessor = curr->left;
                while (predecessor->right && predecessor->right != curr) {
                    predecessor = predecessor->right;
                }
                if (!predecessor->right) {
                    predecessor->right = curr;
                    curr = curr->left;
                } else {
                    if (_pre.has_value()) {
                        int diff = curr->val - _pre.value();
                        if (!_minimum.has_value() || diff < _minimum) {
                            _minimum = diff;
                            if (_minimum == 0) {
                                return 0;
                            }
                        }
                    }
                    _pre = curr->val;
                    curr = curr->right;
                    predecessor->right = nullptr;
                }
            } else {
                if (_pre.has_value()) {
                    int diff = curr->val - _pre.value();
                    if (!_minimum.has_value() || diff < _minimum) {
                        _minimum = diff;
                        if (_minimum == 0) {
                            return 0;
                        }
                    }
                }
                _pre = curr->val;
                curr = curr->right;
            }
        }
        return _minimum.value();
    }

private:
    std::optional<int> _pre;
    std::optional<int> _minimum;
};