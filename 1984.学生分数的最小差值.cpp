/*
 * @lc app=leetcode.cn id=1984 lang=cpp
 *
 * [1984] 学生分数的最小差值
 */
#include <vector>
#include <algorithm>
using namespace std;
// @lc code=start
class Solution {
public:
    int minimumDifference(vector<int>& nums, int k) {
        int start = 0;
        sort(nums.begin(), nums.end());
        int res = nums.back() - nums.front();
        while (start + k <= nums.size()) {
            int tmp = nums[start + k - 1] - nums[start];
            if (tmp < res)
                res = tmp;
            ++start;
        }
        return res;
    }
};
// @lc code=end

