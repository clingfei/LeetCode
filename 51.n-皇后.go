/*
 * @lc app=leetcode.cn id=51 lang=golang
 *
 * [51] N 皇后
 *
 * https://leetcode.cn/problems/n-queens/description/
 *
 * algorithms
 * Hard (74.21%)
 * Likes:    1609
 * Dislikes: 0
 * Total Accepted:    274.1K
 * Total Submissions: 369.4K
 * Testcase Example:  '4'
 *
 * 按照国际象棋的规则，皇后可以攻击与之处在同一行或同一列或同一斜线上的棋子。
 *
 * n 皇后问题 研究的是如何将 n 个皇后放置在 n×n 的棋盘上，并且使皇后彼此之间不能相互攻击。
 *
 * 给你一个整数 n ，返回所有不同的 n 皇后问题 的解决方案。
 *
 *
 *
 * 每一种解法包含一个不同的 n 皇后问题 的棋子放置方案，该方案中 'Q' 和 '.' 分别代表了皇后和空位。
 *
 *
 *
 * 示例 1：
 *
 *
 * 输入：n = 4
 * 输出：[[".Q..","...Q","Q...","..Q."],["..Q.","Q...","...Q",".Q.."]]
 * 解释：如上图所示，4 皇后问题存在两个不同的解法。
 *
 *
 * 示例 2：
 *
 *
 * 输入：n = 1
 * 输出：[["Q"]]
 *
 *
 *
 *
 * 提示：
 *
 *
 * 1 <= n <= 9
 *
 *
 *
 *
 */
package leetcode

import "strings"

// @lc code=start
func solveNQueens(n int) [][]string {
	// 返回所有的解决方案
	var res [][]string
	path := make([][]string, n)
	for i := 0; i < n; i++ {
		path[i] = make([]string, n)
		for j := 0; j < n; j++ {
			path[i][j] = "."
		}
	}
	var dfs func(int)
	dfs = func(idx int) {
		if idx >= n {
			tmp := make([]string, n)
			for i, str := range path {
				tmp[i] = strings.Join(str, "")
			}
			res = append(res, tmp)
			return
		}
		for i := 0; i < n; i++ {
			if isValid(path, idx, i) {
				path[idx][i] = "Q"
				dfs(idx + 1)
				path[idx][i] = "."
			}
		}
	}
	dfs(0)
	return res
}

func isValid(path [][]string, row, col int) bool {
	for i := 0; i < row; i++ {
		if path[i][col] == "Q" {
			return false
		}
	}
	for i, j := row - 1, col - 1; i >= 0 && j >= 0; i, j = i - 1, j - 1 {
		if path[i][j] == "Q" {
			return false
		}
	}
	for i, j := row - 1, col + 1; i >= 0 && j < len(path); i, j = i - 1, j + 1{
		if path[i][j] == "Q" {
			return false
		}
	}
	return true
}
// @lc code=end

