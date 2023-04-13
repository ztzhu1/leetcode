class TreeNode(object):

    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right


class Solution(object):

    def buildTree(self, preorder, inorder):
        """
        :type preorder: List[int]
        :type inorder: List[int]
        :rtype: TreeNode

        The most important thing is finding the index of
        root in `inorder` according to the value of root
        in `preorder`.
        """
        if len(preorder) == 0:
            return
        val = preorder[0]
        root = TreeNode(val)
        rootIdx = inorder.index(val)
        root.left = self.buildTree(preorder[1:rootIdx + 1], inorder[:rootIdx])
        root.right = self.buildTree(preorder[rootIdx + 1:],
                                    inorder[rootIdx + 1:])
        return root

    def buildTreeHelper(self, preorder, inorder):
        if preorder is None or inorder is None:
            return
        val = preorder[0]
        root = TreeNode(val)
        rootIdx = inorder.index(val)
        root.left = self.buildTreeHelper(preorder[1:rootIdx + 1],
                                         inorder[:rootIdx])
        root.right = self.buildTreeHelper(preorder[rootIdx + 1:],
                                          inorder[rootIdx + 1:])
        return root
