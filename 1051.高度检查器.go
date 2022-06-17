/*
 * @lc app=leetcode.cn id=1051 lang=golang
 *
 * [1051] 高度检查器
 */
package leetcode

import (
	"fmt"
	"sort"
)

// @lc code=start
func heightChecker(heights []int) int {
	expected := make([]int, len(heights))
	copy(expected, heights)
	sort.Ints(expected)
	res := 0
	for k, v := range expected {
		if v != heights[k] {
			res++
		}
	}
	return res
}
// @lc code=end

