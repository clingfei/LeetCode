/*
 * @lc app=leetcode.cn id=54 lang=golang
 *
 * [54] 螺旋矩阵
 *
 * https://leetcode.cn/problems/spiral-matrix/description/
 *
 * algorithms
 * Medium (49.20%)
 * Likes:    1275
 * Dislikes: 0
 * Total Accepted:    330K
 * Total Submissions: 670.3K
 * Testcase Example:  '[[1,2,3],[4,5,6],[7,8,9]]'
 *
 * 给你一个 m 行 n 列的矩阵 matrix ，请按照 顺时针螺旋顺序 ，返回矩阵中的所有元素。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入：matrix = [[1,2,3],[4,5,6],[7,8,9]]
 * 输出：[1,2,3,6,9,8,7,4,5]
 * 
 * 
 * 示例 2：
 * 
 * 
 * 输入：matrix = [[1,2,3,4],[5,6,7,8],[9,10,11,12]]
 * 输出：[1,2,3,4,8,12,11,10,9,5,6,7]
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
 * -100 
 * 
 * 
 */
package leetcode 
// @lc code=start
func spiralOrder(matrix [][]int) []int {
	row, col := len(matrix), len(matrix[0])
	res := make([]int, row * col)
	direction := 0
	r, c := 0, 0
	for i := 0; i < row * col; i++ {
		res[i] = matrix[r][c]
		matrix[r][c] = -101
		switch direction {
		case 0: {
			c++
			if c >= col || matrix[r][c] == -101 {
				r, c = r + 1, c - 1
				direction = 1
			}
			break
		}
		case 1: {
			r++
			if r >= row || matrix[r][c] == -101 {
				r, c = r - 1, c - 1
				direction = 2
			}
			break
		}
		case 2: {
			c--
			if c < 0 || matrix[r][c] == -101 {
				r, c = r - 1, c + 1
				direction = 3
			}
			break
		}
		case 3: {
			r--
			if r < 0 || matrix[r][c] == -101 {
				r, c = r + 1, c + 1
				direction = 0
			}
			break
		}
		}
	}
	return res
}
// @lc code=end

