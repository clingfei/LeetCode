/*
 * @lc app=leetcode.cn id=72 lang=golang
 *
 * [72] 编辑距离
 *
 * https://leetcode.cn/problems/edit-distance/description/
 *
 * algorithms
 * Hard (62.77%)
 * Likes:    2740
 * Dislikes: 0
 * Total Accepted:    331.3K
 * Total Submissions: 527.7K
 * Testcase Example:  '"horse"\n"ros"'
 *
 * 给你两个单词 word1 和 word2， 请返回将 word1 转换成 word2 所使用的最少操作数  。
 * 
 * 你可以对一个单词进行如下三种操作：
 * 
 * 
 * 插入一个字符
 * 删除一个字符
 * 替换一个字符
 * 
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入：word1 = "horse", word2 = "ros"
 * 输出：3
 * 解释：
 * horse -> rorse (将 'h' 替换为 'r')
 * rorse -> rose (删除 'r')
 * rose -> ros (删除 'e')
 * 
 * 
 * 示例 2：
 * 
 * 
 * 输入：word1 = "intention", word2 = "execution"
 * 输出：5
 * 解释：
 * intention -> inention (删除 't')
 * inention -> enention (将 'i' 替换为 'e')
 * enention -> exention (将 'n' 替换为 'x')
 * exention -> exection (将 'n' 替换为 'c')
 * exection -> execution (插入 'u')
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 0 <= word1.length, word2.length <= 500
 * word1 和 word2 由小写英文字母组成
 * 
 * 
 */
package leetcode
// @lc code=start
func minDistance(word1 string, word2 string) int {
	row, col := len(word1), len(word2)
	// dp[i][j]表示将将word1[:i]转化为word2[:j]的最少操作数
	dp := make([][]int, row + 1)
	for i := 0; i <= row; i++ {
		dp[i] = make([]int, col + 1)
	}
	for i := 0; i <= row; i++ {
		dp[i][0] = i
	}
	for j := 0; j <= col; j++ {
		dp[0][j] = j
	}
	for i := 1; i <= row; i++ {
		for j := 1; j <= col; j++ {
			if word1[i - 1] == word2[j - 1] {
				dp[i][j] = dp[i - 1][j - 1]
			} else {
				dp[i][j] = min(dp[i - 1][j - 1], min(dp[i - 1][j], dp[i][j - 1])) + 1
			}
		}
	}
	return dp[row][col]
}

func min(a, b int) int {
	if a < b {
		return a
	} else {
		return b
	}
}
// @lc code=end

