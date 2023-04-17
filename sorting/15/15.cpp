#include <algorithm>
#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> threeSum(vector<int> &nums) {
        int i = 0;
        int len = static_cast<int>(nums.size());
        int left = i + 1;
        int right = len - 1;
        int sum = 0;
        vector<vector<int>> ans{};

        sort(nums.begin(), nums.end());
        for (; i < right - 1; ++i) {
            left = i + 1;
            right = len - 1;

            while (left < right) {
                sum = nums[i] + nums[left] + nums[right];
                if (sum < 0) {
                    ++left;
                } else if (sum > 0) {
                    --right;
                } else {
                    ans.emplace_back(vector<int>{nums[i], nums[left], nums[right]});
                    while (left < right && nums[left] == nums[left + 1]) {
                        ++left;
                    }
                    while (left < right && nums[right] == nums[right - 1]) {
                        --right;
                    }
                    ++left;
                    --right;
                }
            }

            while (i < right - 1 && nums[i] == nums[i + 1]) {
                ++i;
            }
        }

        return ans;
    }
};