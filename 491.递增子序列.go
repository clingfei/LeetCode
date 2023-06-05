/*
 * @lc app=leetcode.cn id=491 lang=golang
 *
 * [491] 递增子序列
 *
 * https://leetcode.cn/problems/non-decreasing-subsequences/description/
 *
 * algorithms
 * Medium (52.63%)
 * Likes:    567
 * Dislikes: 0
 * Total Accepted:    113.3K
 * Total Submissions: 215.3K
 * Testcase Example:  '[4,6,7,7]'
 *
 * 给你一个整数数组 nums ，找出并返回所有该数组中不同的递增子序列，递增子序列中 至少有两个元素 。你可以按 任意顺序 返回答案。
 * 
 * 数组中可能含有重复元素，如出现两个整数相等，也可以视作递增序列的一种特殊情况。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入：nums = [4,6,7,7]
 * 输出：[[4,6],[4,6,7],[4,6,7,7],[4,7],[4,7,7],[6,7],[6,7,7],[7,7]]
 * 
 * 
 * 示例 2：
 * 
 * 
 * 输入：nums = [4,4,3,2,1]
 * 输出：[[4,4]]
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 1 <= nums.length <= 15
 * -100 <= nums[i] <= 100
 * 
 * 
 */
package leetcode
// @lc code=start
func findSubsequences(nums []int) [][]int {
	var res [][]int
	var path []int
	var dfs func(idx int)
	dfs = func(idx int) {
        if len(path) >= 2 {
            tmp := make([]int, len(path))
			copy(tmp, path)
			res = append(res, tmp)
        }
		used := make(map[int]int)
		for i := idx; i < len(nums); i++ {
			if used[nums[i]] == 1 {
				continue
			}
			size := len(path)
			if size == 0 || nums[i] >= path[size - 1] {
				used[nums[i]] = 1
				path = append(path, nums[i])
				dfs(i + 1)
				path = path[:len(path) - 1]
			}
		}
	}
	dfs(0)
	return res
}
// @lc code=end

