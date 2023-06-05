/*
 * @lc app=leetcode.cn id=70 lang=golang
 *
 * [70] 爬楼梯
 *
 * https://leetcode.cn/problems/climbing-stairs/description/
 *
 * algorithms
 * Easy (54.03%)
 * Likes:    2813
 * Dislikes: 0
 * Total Accepted:    1M
 * Total Submissions: 1.9M
 * Testcase Example:  '2'
 *
 * 假设你正在爬楼梯。需要 n 阶你才能到达楼顶。
 * 
 * 每次你可以爬 1 或 2 个台阶。你有多少种不同的方法可以爬到楼顶呢？
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入：n = 2
 * 输出：2
 * 解释：有两种方法可以爬到楼顶。
 * 1. 1 阶 + 1 阶
 * 2. 2 阶
 * 
 * 示例 2：
 * 
 * 
 * 输入：n = 3
 * 输出：3
 * 解释：有三种方法可以爬到楼顶。
 * 1. 1 阶 + 1 阶 + 1 阶
 * 2. 1 阶 + 2 阶
 * 3. 2 阶 + 1 阶
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 1 <= n <= 45
 * 
 * 
 */
package leetcode
// @lc code=start
func climbStairs(n int) int {
	// dp[i]表示爬到第i阶的方法
	// dp[i] = dp[i - 1] + dp[i - 2]
	dp := make([]int, n + 1)
	dp[0] = 1
	dp[1] = 1
	for i := 2; i <= n; i++ {
		dp[i] = dp[i - 1] + dp[i - 2]
	}
	return dp[n]
}
// @lc code=end

