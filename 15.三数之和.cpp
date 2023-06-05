/*
 * @lc app=leetcode.cn id=15 lang=cpp
 *
 * [15] 三数之和
 */
#include <algorithm>
#include <vector>
using namespace std;
// @lc code=start
class Solution
{
public:
    vector<vector<int>> threeSum(vector<int> &nums)
    {
        vector<vector<int>> res;
        sort(nums.begin(), nums.end());
        int i = 0, j = nums.size() - 1;
        if (nums[i] > 0 || nums[j] < 0 || nums.size() < 3)
            return {};
        for (i = 0; i < nums.size() - 2; i++)
        {
            if (nums[i] > 0)
                return res;
            if (i > 0 && nums[i] == nums[i - 1])
                continue;
            int j = i + 1, k = nums.size() - 1;
            while (j < k)
            {
                int temp = nums[i] + nums[j] + nums[k];
                if (temp > 0)
                {
                    k--;
                }
                else if (temp < 0)
                {
                    j++;
                } else {
                    res.push_back({nums[i], nums[j], nums[k]});
                    while (j + 1 < k && nums[j + 1] == nums[j])
                        j++;
                    while (k - 1 > j && nums[k - 1] == nums[k])
                        k--;
                    j++; 
                    k--;
                }
            }
        }
        return res;
    }
};
// @lc code=end
