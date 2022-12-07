/*
 * @lc app=leetcode.cn id=221 lang=golang
 *
 * [221] 最大正方形
 *
 * https://leetcode.cn/problems/maximal-square/description/
 *
 * algorithms
 * Medium (49.35%)
 * Likes:    1327
 * Dislikes: 0
 * Total Accepted:    243.2K
 * Total Submissions: 492.8K
 * Testcase Example:  '[["1","0","1","0","0"],["1","0","1","1","1"],["1","1","1","1","1"],["1","0","0","1","0"]]'
 *
 * 在一个由 '0' 和 '1' 组成的二维矩阵内，找到只包含 '1' 的最大正方形，并返回其面积。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入：matrix =
 * [["1","0","1","0","0"],["1","0","1","1","1"],["1","1","1","1","1"],["1","0","0","1","0"]]
 * 输出：4
 * 
 * 
 * 示例 2：
 * 
 * 
 * 输入：matrix = [["0","1"],["1","0"]]
 * 输出：1
 * 
 * 
 * 示例 3：
 * 
 * 
 * 输入：matrix = [["0"]]
 * 输出：0
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * m == matrix.length
 * n == matrix[i].length
 * 1 
 * matrix[i][j] 为 '0' 或 '1'
 * 
 * 
 */
package leetcode
// @lc code=start
func maximalSquare(matrix [][]byte) int {
	dp := make([][]int, len(matrix))
	for i := 0; i < len(matrix); i++ {
		dp[i] = make([]int, len(matrix[0]))
		for j := 0; j < len(matrix[0]); j++ {
			if matrix[i][j] == '1' {
				if i == 0 || j == 0 {
					dp[i][j] = 1
				} else {
					dp[i][j] = min(dp[i - 1][j - 1], min(dp[i - 1][j], dp[i][j - 1])) + 1
				}
			}			
		}
	}
	m := 0
	for i := 0; i < len(matrix); i++ {
		for j := 0; j < len(matrix[i]); j++ {
			if dp[i][j] > m {
				m = dp[i][j]
			}
		}
	}
	return m * m
}

func min(a, b int) int {
	if a < b {
		return a
	} else {
		return b
	}
}
// @lc code=end

