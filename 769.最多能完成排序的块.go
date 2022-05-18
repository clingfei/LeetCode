/*
 * @lc app=leetcode.cn id=769 lang=golang
 *
 * [769] 最多能完成排序的块
 */
package leetcode
// @lc code=start
func maxChunksToSorted(arr []int) int {
	max := func (a int, b int) int {
		if a > b {
			return a 
		} else {
			return b
		}
	}	
	res, m := 0, 0 
	for i, v := range arr {
		m = max(v, m)
		if m == i {
			res++
		} 
	}
	return res
}
// @lc code=end

