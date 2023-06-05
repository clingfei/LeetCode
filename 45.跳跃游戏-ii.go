/*
 * @lc app=leetcode.cn id=45 lang=golang
 *
 * [45] 跳跃游戏 II
 *
 * https://leetcode.cn/problems/jump-game-ii/description/
 *
 * algorithms
 * Medium (45.14%)
 * Likes:    1886
 * Dislikes: 0
 * Total Accepted:    426.5K
 * Total Submissions: 944.9K
 * Testcase Example:  '[2,3,1,1,4]'
 *
 * 给你一个非负整数数组 nums ，你最初位于数组的第一个位置。
 * 
 * 数组中的每个元素代表你在该位置可以跳跃的最大长度。
 * 
 * 你的目标是使用最少的跳跃次数到达数组的最后一个位置。
 * 
 * 假设你总是可以到达数组的最后一个位置。
 * 
 * 
 * 
 * 示例 1:
 * 
 * 
 * 输入: nums = [2,3,1,1,4]
 * 输出: 2
 * 解释: 跳到最后一个位置的最小跳跃数是 2。
 * 从下标为 0 跳到下标为 1 的位置，跳 1 步，然后跳 3 步到达数组的最后一个位置。
 * 
 * 
 * 示例 2:
 * 
 * 
 * 输入: nums = [2,3,0,1,4]
 * 输出: 2
 * 
 * 
 * 
 * 
 * 提示:
 * 
 * 
 * 1 
 * 0 
 * 
 * 
 */
package leetcode
// @lc code=start
func jump(nums []int) int {
	// dp[i]表示跳到i最少的跳跃数
	cur := 0
	dist := 0
	curdist := 0
	for i := 0; i < len(nums); i++ {
		// curdist表示在步数为cur时，能够走出的最远距离
		dist = max(dist, i + nums[i])
		if i == curdist {
			if i != len(nums) - 1{
				cur++
			}
			curdist = dist
		}
	}
	return cur
}

func max(a, b int) int {
	if a < b {
		return b
	} else {
		return a
	}
}
// @lc code=end

