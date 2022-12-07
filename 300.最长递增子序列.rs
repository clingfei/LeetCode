/*
 * @lc app=leetcode.cn id=300 lang=rust
 *
 * [300] 最长递增子序列
 *
 * https://leetcode.cn/problems/longest-increasing-subsequence/description/
 *
 * algorithms
 * Medium (54.31%)
 * Likes:    2897
 * Dislikes: 0
 * Total Accepted:    651.6K
 * Total Submissions: 1.2M
 * Testcase Example:  '[10,9,2,5,3,7,101,18]'
 *
 * 给你一个整数数组 nums ，找到其中最长严格递增子序列的长度。
 * 
 * 子序列 是由数组派生而来的序列，删除（或不删除）数组中的元素而不改变其余元素的顺序。例如，[3,6,2,7] 是数组 [0,3,1,6,2,2,7]
 * 的子序列。
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入：nums = [10,9,2,5,3,7,101,18]
 * 输出：4
 * 解释：最长递增子序列是 [2,3,7,101]，因此长度为 4 。
 * 
 * 
 * 示例 2：
 * 
 * 
 * 输入：nums = [0,1,0,3,2,3]
 * 输出：4
 * 
 * 
 * 示例 3：
 * 
 * 
 * 输入：nums = [7,7,7,7,7,7,7]
 * 输出：1
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 1 <= nums.length <= 2500
 * -10^4 <= nums[i] <= 10^4
 * 
 * 
 * 
 * 
 * 进阶：
 * 
 * 
 * 你能将算法的时间复杂度降低到 O(n log(n)) 吗?
 * 
 * 
 */

// @lc code=start
impl Solution {
    pub fn length_of_lis(nums: Vec<i32>) -> i32 {
        let mut d = vec![0; nums.len() + 1];
        d[1] = nums[0];
        let mut len = 1;
        let mut i = 1;
        while i < nums.len() {
            if nums[i] > d[len] {
                len += 1;
                d[len] = nums[i];
            } else {
                let mut l = 1;
                let mut r = len;
                let mut pos = 0;
                while l <= r {
                    let mid = (l + r) / 2; 
                    if d[mid] < nums[i] {
                        pos = mid;
                        l = mid + 1;
                    } else {
                        r = mid - 1;
                    }
                }
                d[pos + 1] = nums[i];
            }
            i+=1;
        }
        return len as i32;
    }
}
// @lc code=end

