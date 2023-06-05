/*
 * @lc app=leetcode.cn id=47 lang=golang
 *
 * [47] 全排列 II
 *
 * https://leetcode.cn/problems/permutations-ii/description/
 *
 * algorithms
 * Medium (65.37%)
 * Likes:    1262
 * Dislikes: 0
 * Total Accepted:    411.2K
 * Total Submissions: 629K
 * Testcase Example:  '[1,1,2]'
 *
 * 给定一个可包含重复数字的序列 nums ，按任意顺序 返回所有不重复的全排列。
 *
 *
 *
 * 示例 1：
 *
 *
 * 输入：nums = [1,1,2]
 * 输出：
 * [[1,1,2],
 * ⁠[1,2,1],
 * ⁠[2,1,1]]
 *
 *
 * 示例 2：
 *
 *
 * 输入：nums = [1,2,3]
 * 输出：[[1,2,3],[1,3,2],[2,1,3],[2,3,1],[3,1,2],[3,2,1]]
 *
 *
 *
 *
 * 提示：
 *
 *
 * 1 <= nums.length <= 8
 * -10 <= nums[i] <= 10
 *
 *
 */
package leetcode

import "sort"

// @lc code=start
func permuteUnique(nums []int) [][]int {
	sort.Ints(nums)
	size := len(nums)
	var res [][]int
	cur := make([]int, size)
	var dfs func(idx int)
	used := make([]bool, size)
	dfs = func(idx int) {
		if idx >= size {
			tmp := make([]int, size)
			copy(tmp, cur)
			res = append(res, tmp)
			return
		}
		
		for i := 0; i < size; i++ {
			if used[i] {
				continue
			}
			cur[idx] = nums[i]
			used[i] = true
			dfs(idx + 1)
			used[i] = false
			for i + 1 < size && nums[i] == nums[i + 1] {
				i++
			}
		}
	}
	dfs(0)
	return res
}
// @lc code=end

