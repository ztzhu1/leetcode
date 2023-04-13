#include <vector>

using namespace std;

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
    TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder) {
        return buildTree(preorder, inorder, 0, 0, (int)preorder.size() - 1);
    }

    /** `preorder` tells us the left and right child root of this subroot,
     *  `inorder` tells us the intervals of left children and right children.
     *  @param root the root index in preorder
     *  @param left the minimum index in inorder that we have to consider
     *  @param right the maximum index in inorder that we have to consider
     */
    TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder, int root, int left, int right) {
        if (root < 0 || root > (int)preorder.size() - 1) {
            return nullptr;
        }
        int val = preorder[root];
        int rootInInorder = indexOf(val, inorder);
        if (rootInInorder < left || rootInInorder > right) {
            return nullptr;
        }
        int leftRoot = root + 1;
        int leftSize = rootInInorder - left;
        int rightRoot = leftRoot + leftSize;
        TreeNode *rootNode = new TreeNode(val);
        rootNode->left = buildTree(preorder, inorder, leftRoot, left, rootInInorder - 1);
        rootNode->right = buildTree(preorder, inorder, rightRoot, rootInInorder + 1, right);
        return rootNode;
    }

    int indexOf(int val, vector<int> &inorder) {
        int i = 0;
        for (; i < (int)inorder.size(); ++i) {
            if (inorder[i] == val) {
                break;
            }
        }
        return i;
    }
};