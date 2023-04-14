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
        nodes = []
        def traversal(node):
            if not node:
                return
            traversal(node.left)
            nodes.append(node)
            traversal(node.right)
        traversal(root)
        pre = nodes[0]
        x = None
        y = None
        for i in range(1, len(nodes)):
            # if a left node is greater than its right
            # neighbor, it must be a wrong node, no
            # matter the right neighbor is wrong or not (we can
            # consider two probabilities: two wrong nodes are
            # adjacent or not, the conclusion holds).
            if pre.val > nodes[i].val:
                y = nodes[i]
                if not x:
                    x = pre
            pre = nodes[i]
        x.val, y.val = y.val, x.val
