/*
 * @lc app=leetcode.cn id=1791 lang=golang
 *
 * [1791] 找出星型图的中心节点
 */
package leetcode
// @lc code=start
func findCenter(edges [][]int) int {
	if edges[0][0] == edges[1][0] {
		return edges[0][0]
	} else if edges[0][0] == edges[1][1] {
		return edges[0][0]
	} else {
		return edges[0][1]
	}
}
// @lc code=end

