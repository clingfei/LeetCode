/*
 * @lc app=leetcode.cn id=189 lang=cpp
 *
 * [189] 轮转数组
 *
 * https://leetcode.cn/problems/rotate-array/description/
 *
 * algorithms
 * Medium (44.14%)
 * Likes:    1855
 * Dislikes: 0
 * Total Accepted:    657.5K
 * Total Submissions: 1.5M
 * Testcase Example:  '[1,2,3,4,5,6,7]\n3'
 *
 * 给定一个整数数组 nums，将数组中的元素向右轮转 k 个位置，其中 k 是非负数。
 * 
 * 
 * 
 * 示例 1:
 * 
 * 
 * 输入: nums = [1,2,3,4,5,6,7], k = 3
 * 输出: [5,6,7,1,2,3,4]
 * 解释:
 * 向右轮转 1 步: [7,1,2,3,4,5,6]
 * 向右轮转 2 步: [6,7,1,2,3,4,5]
 * 向右轮转 3 步: [5,6,7,1,2,3,4]
 * 
 * 
 * 示例 2:
 * 
 * 
 * 输入：nums = [-1,-100,3,99], k = 2
 * 输出：[3,99,-1,-100]
 * 解释: 
 * 向右轮转 1 步: [99,-1,-100,3]
 * 向右轮转 2 步: [3,99,-1,-100]
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 1 <= nums.length <= 10^5
 * -2^31 <= nums[i] <= 2^31 - 1
 * 0 <= k <= 10^5
 * 
 * 
 * 
 * 
 * 进阶：
 * 
 * 
 * 尽可能想出更多的解决方案，至少有 三种 不同的方法可以解决这个问题。
 * 你可以使用空间复杂度为 O(1) 的 原地 算法解决这个问题吗？
 * 
 * 
 */
#include <vector>

using namespace std;

// @lc code=start
class Solution {
private:
    void reverse(vector<int>& nums, int left, int right) {
        for (int i = left, j = right; i < j; i++, j--) {
            int temp = nums[i];
            nums[i] = nums[j];
            nums[j] = temp;
        }
    }
public:
    void rotate(vector<int>& nums, int k) {
        int len = nums.size();
        k %= len;
        reverse(nums, 0, len - k - 1);
        reverse(nums, len - k, len - 1);
        reverse(nums, 0, len - 1);
    }
};
// @lc code=end

