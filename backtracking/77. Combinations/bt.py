from typing import List


class Solution:
    def combine(self, n: int, k: int) -> List[List[int]]:
        results = []
        used = [False] * n
        self.bt(results, [], n, k, 0, used)
        return results

    def bt(self, results: List[List[int]], result: List[int], n: int, k: int,
           depth: int, used: List[bool]):
        if depth == k:
            results.append(result)
            return
        for i in range(len(used)):
            num = i + 1
            if used[i] == False and (len(result) == 0 or result[-1] < num):
                used[i] = True
                self.bt(results, result + [num], n, k, depth + 1, used)
                used[i] = False
