/*
 * @lc app=leetcode.cn id=128 lang=cpp
 *
 * [128] 最长连续序列
 *
 * https://leetcode.cn/problems/longest-consecutive-sequence/description/
 *
 * algorithms
 * Medium (54.79%)
 * Likes:    1667
 * Dislikes: 0
 * Total Accepted:    392.7K
 * Total Submissions: 716.7K
 * Testcase Example:  '[100,4,200,1,3,2]'
 *
 * 给定一个未排序的整数数组 nums ，找出数字连续的最长序列（不要求序列元素在原数组中连续）的长度。
 * 
 * 请你设计并实现时间复杂度为 O(n) 的算法解决此问题。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入：nums = [100,4,200,1,3,2]
 * 输出：4
 * 解释：最长数字连续序列是 [1, 2, 3, 4]。它的长度为 4。
 * 
 * 示例 2：
 * 
 * 
 * 输入：nums = [0,3,7,2,5,8,4,6,0,1]
 * 输出：9
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 0 
 * -10^9 
 * 
 * 
 */
#include <vector>
#include <set>

using namespace std;

// @lc code=start
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        std::set<int> num_set;
        for (auto const num : nums) {
            num_set.insert(num);
        }
        int res = 0;
        for (auto num : num_set) {
            if (num_set.find(num - 1) != num_set.end())
                continue;
            int j = num + 1;
            while (num_set.find(j) != num_set.end()) {
                j++;
            }
            int cur = j - num;
            if (cur > res) {
                res = cur;
            }
        }
        return res;
    }

};
// @lc code=end

