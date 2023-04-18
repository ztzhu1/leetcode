from typing import List


class Solution:
    def combine(self, n: int, k: int) -> List[List[int]]:
        dp = [[] for _ in range(k + 1)]
        dp[1] = [[i] for i in range(1, n + 1)]

        for i in range(2, len(dp)):
            for c in dp[i - 1]:
                for j in range(1, n + 1):
                    if j not in c and (len(c) == 0 or c[-1] < j):
                        dp[i].append(c + [j])

        return dp[k]


if __name__ == '__main__':
    Solution().combine(3, 3)
