/*
 * @lc app=leetcode.cn id=1413 lang=golang
 *
 * [1413] 逐步求和得到正数的最小值
 */

// @lc code=start
func minStartValue(nums []int) int {
	prefix, min := 0, 0
	for _, v := range nums {
		prefix += v
		if prefix < min {
			min = prefix
		}
	}
	return 1 - min
}
// @lc code=end

