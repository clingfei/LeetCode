/*
 * @lc app=leetcode.cn id=961 lang=golang
 *
 * [961] 在长度 2N 的数组中找出重复 N 次的元素
 */
package leetcode
// @lc code=start
func repeatedNTimes(nums []int) int {
	nmap := make(map[int]int)
	for _, v := range nums {
		if nmap[v]++; nmap[v] > 1 {
			return v
		}
	}
	return -1
}
// @lc code=end

