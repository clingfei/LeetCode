/*
 * @lc app=leetcode.cn id=416 lang=golang
 *
 * [416] 分割等和子集
 *
 * https://leetcode.cn/problems/partition-equal-subset-sum/description/
 *
 * algorithms
 * Medium (52.22%)
 * Likes:    1608
 * Dislikes: 0
 * Total Accepted:    362.8K
 * Total Submissions: 694.6K
 * Testcase Example:  '[1,5,11,5]'
 *
 * 给你一个 只包含正整数 的 非空 数组 nums 。请你判断是否可以将这个数组分割成两个子集，使得两个子集的元素和相等。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入：nums = [1,5,11,5]
 * 输出：true
 * 解释：数组可以分割成 [1, 5, 5] 和 [11] 。
 * 
 * 示例 2：
 * 
 * 
 * 输入：nums = [1,2,3,5]
 * 输出：false
 * 解释：数组不能分割成两个元素和相等的子集。
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 1 
 * 1 
 * 
 * 
 */
package leetcode
// @lc code=start
func canPartition(nums []int) bool {
	sum := 0
	for _, v := range nums {
		sum += v
	}
	if sum % 2 != 0 {
		return false
	}
	target := sum / 2
	dp := make([]int, target + 1)
	// dp[j]表示和为j，只有0和1两个数
	// dp[j] = max(dp[j], dp[j - nums[i]])
	for i := 0; i < len(nums); i++ {
		for j := target; j >= nums[i]; j-- {
			dp[j] = max(dp[j], dp[j - nums[i]] + nums[i]);
		}
	}
	return dp[target] == target
}

func max(a, b int) int {
	if a > b {
		return a
	} else {
		return b
	}
}
// @lc code=end

