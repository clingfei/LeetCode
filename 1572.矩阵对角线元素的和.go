/*
 * @lc app=leetcode.cn id=1572 lang=golang
 *
 * [1572] 矩阵对角线元素的和
 */
package leetcode
// @lc code=start
func diagonalSum(mat [][]int) int {
	res := 0
	for i := 0; i < len(mat); i++ {
		res += mat[i][i]
		res += mat[i][len(mat) - 1 - i]
		if i == len(mat) - 1 - i {
			res -= mat[i][i]
		}
	}
	return res
}
// @lc code=end

