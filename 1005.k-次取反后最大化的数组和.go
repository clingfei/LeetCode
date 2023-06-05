/*
 * @lc app=leetcode.cn id=1005 lang=golang
 *
 * [1005] K 次取反后最大化的数组和
 *
 * https://leetcode.cn/problems/maximize-sum-of-array-after-k-negations/description/
 *
 * algorithms
 * Easy (51.25%)
 * Likes:    308
 * Dislikes: 0
 * Total Accepted:    110.3K
 * Total Submissions: 215.3K
 * Testcase Example:  '[4,2,3]\n1'
 *
 * 给你一个整数数组 nums 和一个整数 k ，按以下方法修改该数组：
 *
 *
 * 选择某个下标 i 并将 nums[i] 替换为 -nums[i] 。
 *
 *
 * 重复这个过程恰好 k 次。可以多次选择同一个下标 i 。
 *
 * 以这种方式修改数组后，返回数组 可能的最大和 。
 *
 *
 *
 * 示例 1：
 *
 *
 * 输入：nums = [4,2,3], k = 1
 * 输出：5
 * 解释：选择下标 1 ，nums 变为 [4,-2,3] 。
 *
 *
 * 示例 2：
 *
 *
 * 输入：nums = [3,-1,0,2], k = 3
 * 输出：6
 * 解释：选择下标 (1, 2, 2) ，nums 变为 [3,1,0,2] 。
 *
 *
 * 示例 3：
 *
 *
 * 输入：nums = [2,-3,-1,5,-4], k = 2
 * 输出：13
 * 解释：选择下标 (1, 4) ，nums 变为 [2,3,-1,5,4] 。
 *
 *
 *
 *
 * 提示：
 *
 *
 * 1 <= nums.length <= 10^4
 * -100 <= nums[i] <= 100
 * 1 <= k <= 10^4
 *
 *
 */
package leetcode

import "sort"

// @lc code=start
func largestSumAfterKNegations(nums []int, k int) int {
	// 将负数从小到大依次重置，如果还存在k，则选择最大的负数
	sort.Ints(nums)
	res := 0
	i := 0
	for i < len(nums) {
		if k == 0 || nums[i] >= 0 {
			break
		} else {
			res += -nums[i]
			k--
		}
		i++
	}
	k %= 2
	if k == 1 {
		if i == len(nums) {
			res += nums[i - 1]
			res += nums[i - 1]
		} else if nums[i] == 0 {
			k = 0
		}else if i == 0 {
			nums[0] = -nums[0]
		} else if -nums[i - 1]> nums[i] {
			nums[i] = -nums[i] 
		} else {
			res += nums[i - 1]
			res += nums[i - 1]
		}
	}
	for i < len(nums) {
		res += nums[i]
		i++
	}
	return res
}
// @lc code=end

