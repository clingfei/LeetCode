/*
 * @lc app=leetcode.cn id=881 lang=golang
 *
 * [881] 救生艇
 */
package leetcode

import "sort"

// @lc code=start
func numRescueBoats(people []int, limit int) int {
	sort.Ints(people)
	res := 0
	i, j := 0, len(people) - 1
	for i < j {
		if people[i] + people[j] <= limit {
			i++
			j--
			res++
		} else {
			res++
			j--
		}
	}
	if i == j {
		res++
	}

	return res
}
// @lc code=end

