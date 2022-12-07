/*
 * @lc app=leetcode.cn id=368 lang=golang
 *
 * [368] 最大整除子集
 *
 * https://leetcode.cn/problems/largest-divisible-subset/description/
 *
 * algorithms
 * Medium (46.02%)
 * Likes:    476
 * Dislikes: 0
 * Total Accepted:    53.4K
 * Total Submissions: 116.1K
 * Testcase Example:  '[1,2,3]'
 *
 * 给你一个由 无重复 正整数组成的集合 nums ，请你找出并返回其中最大的整除子集 answer ，子集中每一元素对 (answer[i],
 * answer[j]) 都应当满足：
 *
 * answer[i] % answer[j] == 0 ，或
 * answer[j] % answer[i] == 0
 *
 *
 * 如果存在多个有效解子集，返回其中任何一个均可。
 *
 *
 *
 * 示例 1：
 *
 *
 * 输入：nums = [1,2,3]
 * 输出：[1,2]
 * 解释：[1,3] 也会被视为正确答案。
 *
 *
 * 示例 2：
 *
 *
 * 输入：nums = [1,2,4,8]
 * 输出：[1,2,4,8]
 *
 *
 *
 *
 * 提示：
 *
 *
 * 1
 * 1
 * nums 中的所有整数 互不相同
 *
 *
 */
package leetcode

import (
	"fmt"
	"sort"
)

// @lc code=start
func largestDivisibleSubset(nums []int) []int {
	sort.Ints(nums)
	dp := make([][]int, len(nums))
	dp[0] = []int{nums[0]}
	m := 0
	for i := 1; i < len(nums); i++ {
		dp[i] = []int{}
		mxlen := 1
		idx := -1
		for j := i - 1; j >= 0; j-- {
			if nums[i] % nums[j] == 0 && mxlen < len(dp[j]) + 1{
				mxlen = len(dp[j]) + 1
				idx = j
			}
		}
		if mxlen > 1 {
			dp[i] = append(dp[i], dp[idx]...)
		}
		dp[i] = append(dp[i], nums[i])
		if mxlen > len(dp[m]) {
			m = i
		}
	}
	return dp[m]
}
// @lc code=end

