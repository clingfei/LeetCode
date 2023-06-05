/*
 * @lc app=leetcode.cn id=90 lang=golang
 *
 * [90] 子集 II
 *
 * https://leetcode.cn/problems/subsets-ii/description/
 *
 * algorithms
 * Medium (63.67%)
 * Likes:    1000
 * Dislikes: 0
 * Total Accepted:    265.8K
 * Total Submissions: 417.4K
 * Testcase Example:  '[1,2,2]'
 *
 * 给你一个整数数组 nums ，其中可能包含重复元素，请你返回该数组所有可能的子集（幂集）。
 *
 * 解集 不能 包含重复的子集。返回的解集中，子集可以按 任意顺序 排列。
 *
 *
 *
 *
 *
 * 示例 1：
 *
 *
 * 输入：nums = [1,2,2]
 * 输出：[[],[1],[1,2],[1,2,2],[2],[2,2]]
 *
 *
 * 示例 2：
 *
 *
 * 输入：nums = [0]
 * 输出：[[],[0]]
 *
 *
 *
 *
 * 提示：
 *
 *
 * 1
 * -10
 *
 *
 *
 *
 */
package leetcode

import "sort"

// @lc code=start
func subsetsWithDup(nums []int) [][]int {
	sort.Ints(nums)
	var res [][]int
	res = append(res, []int{})
	var path []int
	var dfs func(idx int)
	dfs = func (idx int)  {
		if idx >= len(nums) {
			return
		}
		for i := idx; i < len(nums); i++ {
			path = append(path, nums[i])
			tmp := make([]int, len(path))
			copy(tmp, path)
			res = append(res, tmp)
			dfs(i + 1)
			path = path[:len(path) - 1]
			for i + 1 < len(nums) && nums[i] == nums[i + 1] {
				i++
			}
		}
	}
	dfs(0)
	return res
}
// @lc code=end

