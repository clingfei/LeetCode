/*
 * @lc app=leetcode.cn id=875 lang=golang
 *
 * [875] 爱吃香蕉的珂珂
 */
package leetcode

import "math"

// @lc code=start
func max(piles []int) (res int) {
	for _, v := range piles {
		if res < v {
			res = v
		}
	}
	return
}
func minEatingSpeed(piles []int, h int) int {
	left, right := 1, max(piles) + 1
	for left < right {
		mid := (left + right) / 2
		if judge(piles, mid, h) {
			right = mid
		} else {
			left = mid + 1
		}
	}
	return left
}
func judge(piles []int, mid int, h int) bool {
	time := 0
	for i := 0; i < len(piles); i++ {
		time += (piles[i] - 1) / mid + 1
	}
	return time <= h
}
// @lc code=end

