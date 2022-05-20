/*
 * @lc app=leetcode.cn id=877 lang=golang
 *
 * [877] 石子游戏
 */
package leetcode
// @lc code=start
func max(i, j int) int {
	if i > j {
		return i
	} else {
		return j
	}
}
// func stoneGame(piles []int) bool {
// 	dp := make([][]int, len(piles))
// 	for i := 0; i < len(piles); i++ {
// 		dp[i] = make([]int, len(piles))
// 	}
// 	for i := 0; i < len(piles); i++ {
// 		dp[i][i] = piles[i]
// 	}
// 	for i := len(piles) - 2; i >= 0; i-- {
// 		for j := i + 1; j < len(piles); j++ {
// 			dp[i][j] = max(piles[i] - dp[i + 1][j], piles[j] - dp[i][j - 1])
// 		}
// 	}
// 	return dp[0][len(piles) - 1] > 0
// }

func stoneGame(piles []int) bool {
	dp := make([]int, len(piles))
	for i := 0; i < len(piles); i++ {
		dp[i] = piles[i]
	}
	for i := len(piles) - 2; i >= 0; i-- {
		for j := i + 1; j < len(piles); j++ {
			dp[i] = max(piles[i] - dp[j], piles[j] - dp[j - 1])
		}
	}
	return dp[len(piles) - 1] > 0
}
// @lc code=end

