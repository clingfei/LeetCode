/*
 * @lc app=leetcode.cn id=498 lang=golang
 *
 * [498] 对角线遍历
 */
package leetcode
// @lc code=start
func findDiagonalOrder(mat [][]int) []int {
	var res []int
	dir := true		//true为向上
	x, y := 0, 0
	for x < len(mat) && y <len(mat[0]) {
		if dir {
			res = append(res, mat[x][y])
			if x == 0 || y == len(mat[0]) - 1 {
				if y == len(mat[0]) - 1 {
					x, dir = x + 1, !dir
				} else {
					y, dir = y + 1, !dir
				}
			} else {
				x, y = x - 1, y + 1
			}
		} else {
			res = append(res, mat[x][y])
			if y == 0 || x == len(mat) - 1 {
				if x == len(mat) - 1 {
					y, dir = y + 1, !dir
				} else {
					x, dir = x + 1, !dir
				}
			} else {
				x, y = x + 1, y - 1
			}
		}
	}
	return res
}
// @lc code=end

