from typing import Optional, List


class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right


class Solution:
    def findMode(self, root: Optional[TreeNode]) -> List[int]:
        vals = []

        def inorder(node):
            if not node:
                return
            inorder(node.left)
            vals.append(node.val)
            inorder(node.right)

        inorder(root)

        left = 0
        results = []
        maxCount = 0
        while left < len(vals):
            right = left + 1
            while right < len(vals) and vals[right] == vals[left]:
                right += 1
            count = right - left
            if count > maxCount:
                results = [vals[left]]
                maxCount = count
            elif count == maxCount:
                results.append(vals[left])
            left = right
        return results
