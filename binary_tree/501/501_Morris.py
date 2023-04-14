from typing import Optional, List


class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right


class Solution:
    def findMode(self, root: Optional[TreeNode]) -> List[int]:
        results = []
        maxCount = 0
        count = 0
        curr_val = None
        curr = root
        while curr:
            if curr.left:
                predecessor = curr.left
                while predecessor.right and predecessor.right != curr:
                    predecessor = predecessor.right
                if predecessor.right is None:
                    predecessor.right = curr
                    curr = curr.left
                else:
                    if curr_val is None:
                        curr_val = curr.val
                    if curr_val == curr.val:
                        count += 1
                    else:
                        curr_val = curr.val
                        count = 1
                    if count > maxCount:
                        results = [curr_val]
                        maxCount = count
                    elif count == maxCount:
                        results.append(curr_val)
                    curr = curr.right
                    predecessor.right = None
            else:
                if curr_val is None:
                    curr_val = curr.val
                if curr_val == curr.val:
                    count += 1
                else:
                    curr_val = curr.val
                    count = 1
                if count > maxCount:
                    results = [curr_val]
                    maxCount = count
                elif count == maxCount:
                    results.append(curr_val)
                curr = curr.right

        return results


if __name__ == '__main__':
    root = TreeNode(1)
    root.left = TreeNode(0)
    root.right = TreeNode(1)
    root.left.left = TreeNode(0)
    root.left.right = TreeNode(0)
    root.right.left = TreeNode(1)
    root.right.right = TreeNode(1)
    root.left.left.left = TreeNode(0)
    result = Solution().findMode(root)
    print(result)
