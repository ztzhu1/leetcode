from collections import deque


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

        If it's a BST (i.e., left children are less than root and right children are
        greater than root), we may not need `inorder`.
        """
        if len(preorder) == 0:
            return
        val = preorder[0]
        root = TreeNode(val)
        rightRoot = 0
        while rightRoot < len(preorder):
            if preorder[rightRoot] > val:
                break
            rightRoot += 1
        root.left = self.buildTree(preorder[1:rightRoot], None)
        root.right = self.buildTree(preorder[rightRoot:], None)
        return root


def parseTree(rootNode):
    res = []
    queue = deque()
    queue.append(rootNode)
    while len(queue) != 0:
        node = queue.popleft()
        if node is not None:
            res.append(node.val)
            if node.left is not None or node.right is not None:
                queue.append(node.left)
                queue.append(node.right)
        else:
            res.append(None)
    return res


if __name__ == '__main__':
    preorder = [10, 7, 3, 9, 12, 13]
    ans = [10, 7, 12, 3, 9, None, 13]
    tree = Solution().buildTree(preorder, None)
    res = parseTree(tree)
    print("preorder:", preorder)
    print("expect:", ans)
    print("result:", res)