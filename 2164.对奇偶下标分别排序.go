/*
 * @lc app=leetcode.cn id=2164 lang=golang
 *
 * [2164] 对奇偶下标分别排序
 */
package leetcode

import "sort"

// @lc code=start

func sortEvenOdd(nums []int) []int {
	var evenlen int
	if len(nums) % 2 == 0 {
		evenlen = len(nums) / 2
	} else {
		evenlen = len(nums) / 2 + 1
	}
	odd := make([]int, len(nums) / 2)
	even := make([]int, evenlen)
	i, j, k := 0, 0, 0
	for i < evenlen && j < len(odd) && k < len(nums) {
		even[i] = nums[k]
		odd[j] = nums[k + 1]
		i, j , k = i + 1, j + 1, k + 2 
	}
	if i < evenlen {
		even[i] = nums[len(nums) - 1]
	}
	sort.Ints(even)
	sort.Ints(odd)
	i, j, k = 0, len(odd) - 1, 0
	for k < len(nums) && i < evenlen && j >= 0 {
		nums[k] = even[i]
		nums[k + 1] = odd[j]
		i, j, k = i + 1, j - 1, k + 2
	}
	if i < evenlen {
		nums[len(nums) - 1] = even[i]
	}
	return nums
}
// @lc code=end

