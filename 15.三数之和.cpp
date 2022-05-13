/*
 * @lc app=leetcode.cn id=15 lang=cpp
 *
 * [15] 三数之和
 */`
#include <algorithm>
#include <vector>
using namespace std;
// @lc code=start
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> res;
        sort(nums.begin(), nums.end());
        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i] > 0) return res;
            if (i > 0 && nums[i] == nums[i - 1]) continue;
            int j = i + 1, k = nums.size() - 1;
            while (k > j) {
                if (nums[i] + nums[j] + nums[k] > 0) k--;
                else if (nums[i] + nums[j] + nums[k] < 0) j++;
                else {
                    res.push_back({nums[i], nums[j], nums[k]});
                    while (k > j && nums[k] == nums[k - 1]) k--;
                    while (j < k && nums[j] == nums[j + 1]) j++;
                    j++;
                    k--;
                }
            }
        }
        return res;
    }
};
// @lc code=end

