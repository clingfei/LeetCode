/*
 * @lc app=leetcode.cn id=1403 lang=golang
 *
 * [1403] 非递增顺序的最小子序列
 */
package leetcode
import "sort"
// @lc code=start
func minSubsequence(nums []int) (res []int) {
	sum, cur := 0, 0
	for i := 0; i < len(nums); i++ {
		sum += nums[i]
	}
	sort.Slice(nums, func (i, j int) bool {return nums[i] > nums[j]})
	for i := 0; i < len(nums); i++ {
		cur += nums[i]
		res = append(res, nums[i])
		if cur * 2 > sum {
			return 
		}
	}
	return
}
// @lc code=end

