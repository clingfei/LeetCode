/*
 * @lc app=leetcode.cn id=22 lang=golang
 *
 * [22] 括号生成
 *
 * https://leetcode.cn/problems/generate-parentheses/description/
 *
 * algorithms
 * Medium (77.54%)
 * Likes:    2983
 * Dislikes: 0
 * Total Accepted:    622.8K
 * Total Submissions: 803.2K
 * Testcase Example:  '3'
 *
 * 数字 n 代表生成括号的对数，请你设计一个函数，用于能够生成所有可能的并且 有效的 括号组合。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入：n = 3
 * 输出：["((()))","(()())","(())()","()(())","()()()"]
 * 
 * 
 * 示例 2：
 * 
 * 
 * 输入：n = 1
 * 输出：["()"]
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 1 <= n <= 8
 * 
 * 
 */
package leetcode
// @lc code=start
func generateParenthesis(n int) []string {
	dp := make(map[int][]string)
	dp[1] = []string{"()"}
	dp[2] = []string{"()()", "(())"}
	for i := 3; i <= n; i++ {
		for j := 0; j < len(dp[i - 1]); j++ {
			dp[i] = append(dp[i], "()" + dp[i - 1][j])
		}
		for _, v := range dp[i - 1] {
			dp[i] = append(dp[i], "(" + v + ")")
		}
		for j := 1; j < i; j ++ {
			for _, v := range dp[j] {
				for _, v1 := range dp[i - j - 1] {
					dp[i] = append(dp[i], "(" + v + ")" + v1)
				}
			}
		}
	} 
	return dp[n]
}
// @lc code=end

