from typing import Optional


class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right


class Solution:
    def recoverTree(self, root: Optional[TreeNode]) -> None:
        """
        The tree is sorted, we can use inorder traversal.
        If the position of a node is wrong, it must be
        less or greater than both of its adjacent nodes, 
        except it only has one neighbor or one of its
        neighbors is also a wrong node.
        """
        pre = None
        x = None
        y = None

        curr = root
        while curr:
            if curr.left:
                predecessor = curr.left
                while predecessor.right and predecessor.right != curr:
                    predecessor = predecessor.right
                if not predecessor.right:
                    predecessor.right = curr
                    curr = curr.left
                else:
                    predecessor.right = None
                    if pre and pre.val > curr.val:
                        if not x:
                            x = pre
                        y = curr
                    pre = curr
                    curr = curr.right
            else:
                if pre and pre.val > curr.val:
                    if not x:
                        x = pre
                    y = curr
                pre = curr
                curr = curr.right
        if x and y:
            x.val, y.val = y.val, x.val


if __name__ == '__main__':
    root = TreeNode(1)
    root.left = TreeNode(3)
    root.left.right = TreeNode(2)
    Solution().recoverTree(root)
