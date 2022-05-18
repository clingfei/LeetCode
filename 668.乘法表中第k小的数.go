/*
 * @lc app=leetcode.cn id=668 lang=golang
 *
 * [668] 乘法表中第k小的数
 */
package leetcode

import "math"

// @lc code=start
func findKthNumber(m int, n int, k int) int {
	left, right := 1, m * n
	for left < right {
		x := (left + right) / 2
		count := x / n * n
		for i := x / n + 1; i <= m; i ++ {
			count += x / i
		}
		if count >= k {
			right = x
		} else {
			left = x + 1
		}
	}
	return left
}
// @lc code=end

