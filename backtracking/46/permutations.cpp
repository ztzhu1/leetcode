#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> permute(vector<int> &nums) {
        vector<vector<int>> ans;
        vector<int> permutation;
        vector<bool> used(nums.size(), false);
        dfs(ans, nums, used, permutation, 0);
        return ans;
    }

    void dfs(vector<vector<int>> &ans, vector<int> &nums, vector<bool> &used, vector<int> &permutation, int depth) {
        int n = static_cast<int>(nums.size());
        if (depth == n) {
            ans.push_back(permutation);
            return;
        }
        for (int i = 0; i < n; ++i) {
            if (!used[i]) {
                used[i] = true;
                permutation.push_back(nums[i]);
                dfs(ans, nums, used, permutation, depth + 1);
                permutation.pop_back();
                used[i] = false;
            }
        }
    }
};