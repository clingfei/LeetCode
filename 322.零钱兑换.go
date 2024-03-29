/*
 * @lc app=leetcode.cn id=322 lang=golang
 *
 * [322] 零钱兑换
 *
 * https://leetcode.cn/problems/coin-change/description/
 *
 * algorithms
 * Medium (46.14%)
 * Likes:    2217
 * Dislikes: 0
 * Total Accepted:    557.3K
 * Total Submissions: 1.2M
 * Testcase Example:  '[1,2,5]\n11'
 *
 * 给你一个整数数组 coins ，表示不同面额的硬币；以及一个整数 amount ，表示总金额。
 * 
 * 计算并返回可以凑成总金额所需的 最少的硬币个数 。如果没有任何一种硬币组合能组成总金额，返回 -1 。
 * 
 * 你可以认为每种硬币的数量是无限的。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入：coins = [1, 2, 5], amount = 11
 * 输出：3 
 * 解释：11 = 5 + 5 + 1
 * 
 * 示例 2：
 * 
 * 
 * 输入：coins = [2], amount = 3
 * 输出：-1
 * 
 * 示例 3：
 * 
 * 
 * 输入：coins = [1], amount = 0
 * 输出：0
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 1 <= coins.length <= 12
 * 1 <= coins[i] <= 2^31 - 1
 * 0 <= amount <= 10^4
 * 
 * 
 */
package leetcode
// @lc code=start
func coinChange(coins []int, amount int) int {
	dp := make([]int, amount + 1)
	//dp[i]表示能够凑成I的最小的硬币个数
	for _, v := range coins {
		if v <= amount {
			if v == amount {
				return 1
			}
			dp[v] = 1
		} 
	}
	for i := 1; i <= amount; i++ {
		dp[i] = amount + 1
		for _, v := range coins {
			if v <= i {
				dp[i] = min(dp[i], dp[i - v] + 1)
			}	
		}
	}
	if dp[amount] >= amount + 1 {
		return -1
	} else {
		return dp[amount]
	}
}

func min(a, b int) int {
	if a < b {
		return a
	} else {
		return b
	} 
}
// @lc code=end

