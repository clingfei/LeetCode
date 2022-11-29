/*
 * @lc app=leetcode.cn id=899 lang=golang
 *
 * [899] 有序队列
 */
package leetcode

import "sort"

// @lc code=start
func orderlyQueue(s string, k int) string {
	if k != 1 {
		t := []byte(s)
		sort.Slice(t, func(i, j int) bool {return t[i] < t[j]})
		return string(t)
	}
	min := s
	s += min
	for i := 0; i < len(min); i++ {
		if s[i: i + len(min)] < min {
			min = s[i: i + len(min)]
		}
	}
	return min
}
// @lc code=end

