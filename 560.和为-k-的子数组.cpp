/*
 * @lc app=leetcode.cn id=560 lang=cpp
 *
 * [560] 和为 K 的子数组
 *
 * https://leetcode.cn/problems/subarray-sum-equals-k/description/
 *
 * algorithms
 * Medium (45.07%)
 * Likes:    1939
 * Dislikes: 0
 * Total Accepted:    321.9K
 * Total Submissions: 714.3K
 * Testcase Example:  '[1,1,1]\n2'
 *
 * 给你一个整数数组 nums 和一个整数 k ，请你统计并返回 该数组中和为 k 的连续子数组的个数 。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入：nums = [1,1,1], k = 2
 * 输出：2
 * 
 * 
 * 示例 2：
 * 
 * 
 * 输入：nums = [1,2,3], k = 3
 * 输出：2
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 1 <= nums.length <= 2 * 10^4
 * -1000 <= nums[i] <= 1000
 * -10^7 <= k <= 10^7
 * 
 * 
 */
#include <vector>
#include <unordered_map>
using namespace std;

// @lc code=start
class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int res = 0;
        int pre = 0;
        unordered_map<int, int> umap;
        umap[0] = 1;
        for (int i = 0; i < nums.size(); i++) {
            pre += nums[i];
            if (umap.find(pre-k) != umap.end()) 
                res += umap[pre - k];
            umap[pre]++;
        }
        return res;
    }
};
// @lc code=end

