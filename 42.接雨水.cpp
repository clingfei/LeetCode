/*
 * @lc app=leetcode.cn id=42 lang=cpp
 *
 * [42] 接雨水
 *
 * https://leetcode.cn/problems/trapping-rain-water/description/
 *
 * algorithms
 * Hard (62.69%)
 * Likes:    4362
 * Dislikes: 0
 * Total Accepted:    693.6K
 * Total Submissions: 1.1M
 * Testcase Example:  '[0,1,0,2,1,0,1,3,2,1,2,1]'
 *
 * 给定 n 个非负整数表示每个宽度为 1 的柱子的高度图，计算按此排列的柱子，下雨之后能接多少雨水。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 
 * 
 * 输入：height = [0,1,0,2,1,0,1,3,2,1,2,1]
 * 输出：6
 * 解释：上面是由数组 [0,1,0,2,1,0,1,3,2,1,2,1] 表示的高度图，在这种情况下，可以接 6 个单位的雨水（蓝色部分表示雨水）。 
 * 
 * 
 * 示例 2：
 * 
 * 
 * 输入：height = [4,2,0,3,2,5]
 * 输出：9
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * n == height.length
 * 1 <= n <= 2 * 10^4
 * 0 <= height[i] <= 10^5
 * 
 * 
 */
#include <vector>
#include <iostream>

using namespace std;

// @lc code=start
class Solution {
public:
    int trap(vector<int>& height) {
        int res = 0;
        vector<int> right(height.size());
        vector<int> left(height.size());
        int len = height.size() - 1;
        right[len] = height[len];
        left[0] = height[0];
        for (int j = height.size() - 2; j >= 0; j--) {
            right[j] = max(height[j], right[j + 1]);
        }
        for (int i = 1; i <= len; i++) {
            left[i] = max(height[i], left[i - 1]);
        }
        for (int i = 0; i <= len; i++) {
            res += min(left[i], right[i]) - height[i];
        }
        return res;
    }
};
// @lc code=end

