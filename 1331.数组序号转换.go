/*
 * @lc app=leetcode.cn id=1331 lang=golang
 *
 * [1331] 数组序号转换
 */
package leetcode

import "sort"

// @lc code=start
func arrayRankTransform(arr []int) []int {
	arrMap := make(map[int]int)
	array := make([]int, len(arr))
	copy(array, arr)
	sort.Ints(array)
	for k, v := range array {
		if _, ok := arrMap[v]; !ok {
			arrMap[v] = k + 1
		}
	}
	for k, v := range arr {
		arr[k] = arrMap[v]
	}
	return arr
}
// @lc code=end

