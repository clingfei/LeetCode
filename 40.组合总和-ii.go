/*
 * @lc app=leetcode.cn id=40 lang=golang
 *
 * [40] 组合总和 II
 *
 * https://leetcode.cn/problems/combination-sum-ii/description/
 *
 * algorithms
 * Medium (60.25%)
 * Likes:    1202
 * Dislikes: 0
 * Total Accepted:    382.6K
 * Total Submissions: 635.2K
 * Testcase Example:  '[10,1,2,7,6,1,5]\n8'
 *
 * 给定一个候选人编号的集合 candidates 和一个目标数 target ，找出 candidates 中所有可以使数字和为 target 的组合。
 *
 * candidates 中的每个数字在每个组合中只能使用 一次 。
 *
 * 注意：解集不能包含重复的组合。
 *
 *
 *
 * 示例 1:
 *
 *
 * 输入: candidates = [10,1,2,7,6,1,5], target = 8,
 * 输出:
 * [
 * [1,1,6],
 * [1,2,5],
 * [1,7],
 * [2,6]
 * ]
 *
 * 示例 2:
 *
 *
 * 输入: candidates = [2,5,2,1,2], target = 5,
 * 输出:
 * [
 * [1,2,2],
 * [5]
 * ]
 *
 *
 *
 * 提示:
 *
 *
 * 1 <= candidates.length <= 100
 * 1 <= candidates[i] <= 50
 * 1 <= target <= 30
 *
 *
 */
package leetcode

import "sort"

// @lc code=start
func combinationSum2(candidates []int, target int) [][]int {
	sort.Ints(candidates)
	var res [][]int
	var path []int
	cur := 0
	var dfs func(int)
	dfs = func(idx int) {
		for i := idx; i < len(candidates); i++ {
			cur += candidates[i]
			if cur > target {
				cur -= candidates[i]
				break
			}
			path = append(path, candidates[i])
			if cur == target {
				tmp := make([]int, len(path))
				copy(tmp, path)
				res = append(res, tmp)
				cur -= candidates[i]
				path = path[:len(path) - 1]
				break
			}
			dfs(i + 1)
			cur -= candidates[i]
			path = path[:len(path) - 1]
			for i + 1 < len(candidates) && candidates[i + 1] == candidates[i] {
				i++
			}
		}
	}
	dfs(0)
	return res
}
// @lc code=end

