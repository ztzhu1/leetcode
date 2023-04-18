from typing import List


class Solution:
    def permuteUnique(self, nums: List[int]) -> List[List[int]]:
        results = []
        used = [False] * len(nums)
        self.bt(results, [], nums, used)
        return results

    def bt(self, results: List[List[int]], result: List[int], nums: List[int],
           used: List[bool]):
        if (len(result) == len(nums)):
            results.append(result)
            return
        used_num = []
        for i in range(len(used)):
            if used[i] == False and nums[i] not in used_num:
                used[i] = True
                used_num.append(nums[i])
                self.bt(results, result + [nums[i]], nums, used)
                used[i] = False
