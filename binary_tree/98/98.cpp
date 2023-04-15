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
    bool isValidBST(TreeNode *root) {
        std::vector<int> vals;
        getVal(vals, root);
        for (int i = 0; i < static_cast<int>(vals.size()) - 1; ++i) {
            if (vals[i + 1] <= vals[i]) {
                return false;
            }
        }
        return true;
    }
    void getVal(std::vector<int> &vals, TreeNode *node) {
        if (node == nullptr) {
            return;
        }
        getVal(vals, node->left);
        vals.push_back(node->val);
        getVal(vals, node->right);
    }
};