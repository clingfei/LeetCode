/*
 * @lc app=leetcode.cn id=279 lang=golang
 *
 * [279] 完全平方数
 *
 * https://leetcode.cn/problems/perfect-squares/description/
 *
 * algorithms
 * Medium (65.78%)
 * Likes:    1547
 * Dislikes: 0
 * Total Accepted:    356.5K
 * Total Submissions: 541.9K
 * Testcase Example:  '12'
 *
 * 给你一个整数 n ，返回 和为 n 的完全平方数的最少数量 。
 *
 * 完全平方数 是一个整数，其值等于另一个整数的平方；换句话说，其值等于一个整数自乘的积。例如，1、4、9 和 16 都是完全平方数，而 3 和 11
 * 不是。
 *
 *
 *
 * 示例 1：
 *
 *
 * 输入：n = 12
 * 输出：3
 * 解释：12 = 4 + 4 + 4
 *
 * 示例 2：
 *
 *
 * 输入：n = 13
 * 输出：2
 * 解释：13 = 4 + 9
 *
 *
 * 提示：
 *
 *
 * 1 <= n <= 10^4
 *
 *
 */
package leetcode

import "math"

// @lc code=start
func numSquares(n int) int {
	dp := make([]int, n + 1)
	for i := 1; i <= n; i++ {
		dp[i] = math.MaxInt32
		for j := 1; j * j <= i; j++ {
			dp[i] = min(dp[i], 1 + dp[i - j * j])			
		}
	}
	return dp[n]
}

func min(a, b int) int {
	if a < b {
		return a
	} else {
		return b
	}
}
// @lc code=end

