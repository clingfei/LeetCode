/*
 * @lc app=leetcode.cn id=59 lang=golang
 *
 * [59] 螺旋矩阵 II
 *
 * https://leetcode.cn/problems/spiral-matrix-ii/description/
 *
 * algorithms
 * Medium (74.70%)
 * Likes:    884
 * Dislikes: 0
 * Total Accepted:    266.4K
 * Total Submissions: 357.4K
 * Testcase Example:  '3'
 *
 * 给你一个正整数 n ，生成一个包含 1 到 n^2 所有元素，且元素按顺时针顺序螺旋排列的 n x n 正方形矩阵 matrix 。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入：n = 3
 * 输出：[[1,2,3],[8,9,4],[7,6,5]]
 * 
 * 
 * 示例 2：
 * 
 * 
 * 输入：n = 1
 * 输出：[[1]]
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 1 
 * 
 * 
 */
package leetcode
// @lc code=start
func generateMatrix(n int) [][]int {
	i, j := 0, 0
	direction := 0
	matrix := make([][]int, n)
	for i := 0; i < n; i++ {
		matrix[i] = make([]int, n)
	}
	for k := 1; k <= n * n; k++ {
		switch direction {
		case 0: {
			matrix[i][j] = k
			j++
			if j >= n || matrix[i][j] != 0 {
				j--
				i++
				direction = 1 
			}
			break
		}
		case 1: {
			matrix[i][j] = k
			i++
			if i >= n || matrix[i][j] != 0 {
				i--
				j--
				direction = 2
			}
			break
		}
		case 2: {
			matrix[i][j] = k
			j--
			if j < 0 || matrix[i][j] != 0 {
				j, i = j + 1, i - 1
				direction = 3 
			}
			break
		}
		case 3: {
			matrix[i][j] = k
			i--
			if i < 0 || matrix[i][j] != 0 {
				j, i = j + 1, i + 1
				direction = 0
			}
			break
		}
		}
	}
	return matrix
}
// @lc code=end

