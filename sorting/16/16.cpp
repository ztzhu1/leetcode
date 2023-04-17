#include <algorithm>
#include <cmath>
#include <numeric>
#include <vector>

using namespace std;

class Solution {
public:
    int threeSumClosest(vector<int> &nums, int target) {
        int sum = 0;
        int minDist = numeric_limits<int>::max();
        int len = static_cast<int>(nums.size());
        int i = 0;
        int left = i + 1;
        int right = len - 1;

        int s = 0;
        int diff = 0;
        int dist = 0;
        sort(nums.begin(), nums.end());
        for (; i < right - 1; ++i) {
            left = i + 1;
            right = len - 1;
            while (left < right) {
                s = nums[i] + nums[left] + nums[right];
                diff = s - target;
                dist = abs(diff);
                if (dist == 0) {
                    return target;
                }
                if (dist < minDist) {
                    minDist = dist;
                    sum = s;
                }
                if (diff > 0) {
                    --right;
                } else {
                    ++left;
                }
            }
        }

        return sum;
    }
};