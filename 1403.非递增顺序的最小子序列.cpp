/*
 * @lc app=leetcode.cn id=1403 lang=cpp
 *
 * [1403] 非递增顺序的最小子序列
 */
#include <vector>
#include <algorithm>
using namespace std;
// @lc code=start
class Solution {
public:
    vector<int> minSubsequence(vector<int>& nums) {
        int sum = 0;
        for (auto v : nums) {
            sum += v;
        }
        sort(nums.begin(), nums.end());
        int cur = 0;
        vector<int> res;
        for (auto iter = nums.end() - 1; iter != nums.end(); iter--) {
            cur += *iter;
            res.emplace_back(*iter);
            if (cur * 2 > sum) 
                return res;
        }
        return res;
    }
};
// @lc code=end

