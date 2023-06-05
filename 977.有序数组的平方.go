/*
 * @lc app=leetcode.cn id=977 lang=golang
 *
 * [977] 有序数组的平方
 *
 * https://leetcode.cn/problems/squares-of-a-sorted-array/description/
 *
 * algorithms
 * Easy (68.70%)
 * Likes:    679
 * Dislikes: 0
 * Total Accepted:    445.6K
 * Total Submissions: 649K
 * Testcase Example:  '[-4,-1,0,3,10]'
 *
 * 给你一个按 非递减顺序 排序的整数数组 nums，返回 每个数字的平方 组成的新数组，要求也按 非递减顺序 排序。
 * 
 * 
 * 
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入：nums = [-4,-1,0,3,10]
 * 输出：[0,1,9,16,100]
 * 解释：平方后，数组变为 [16,1,0,9,100]
 * 排序后，数组变为 [0,1,9,16,100]
 * 
 * 示例 2：
 * 
 * 
 * 输入：nums = [-7,-3,2,3,11]
 * 输出：[4,9,9,49,121]
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 1 10^4
 * -10^4 
 * nums 已按 非递减顺序 排序
 * 
 * 
 * 
 * 
 * 进阶：
 * 
 * 
 * 请你设计时间复杂度为 O(n) 的算法解决本问题
 * 
 * 
 */
package leetcode
// @lc code=start
func sortedSquares(nums []int) []int {
	res := make([]int, len(nums))
	if nums[0] >= 0 {
		for k, v := range nums{
			res[k] = v *v
		}
		return res
	} else if nums[len(nums) - 1] < 0{
		l := len(nums) - 1
		for k, v := range nums {
			res[l - k] = v * v
		}
		return res
	}
	idx := 0
	for k, v := range nums {
		if v == 0 {
			idx = k
		} else if v > 0 && k > 0 && nums[k - 1] < 0 {
			idx = k
		}
	}
	i := 0
	left := idx - 1
	right := idx
	for i < len(res) && left >= 0 && right < len(res) {
		if nums[left] * nums[left] < nums[right] * nums[right] {
			res[i] = nums[left] * nums[left]
			left--
		} else {
			res[i] = nums[right] * nums[right]
			right++
		}
		i++
	}
	for left >= 0 {
		res[i] = nums[left] * nums[left]
		left--
		i++
	}
	for right < len(res) {
		res[i] = nums[right] * nums[right]
		right++
		i++
	}
	return res
}
// @lc code=end

