from typing import List, Optional


class TreeNode:

    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right


class Solution:

    def sortedArrayToBST(self, nums: List[int]) -> Optional[TreeNode]:
        '''
        The `nums` is sorted, which means it can be considered
        as the inorder traversal of a balanced BST. We just need
        to transform it back.
        '''
        if not nums:
            return None
        rootIdx = int(len(nums) / 2)
        root = TreeNode(nums[rootIdx])
        root.left = self.sortedArrayToBST(nums[:rootIdx])
        root.right = self.sortedArrayToBST(nums[rootIdx + 1:])
        return root