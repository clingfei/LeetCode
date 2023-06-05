/*
 * @lc app=leetcode.cn id=46 lang=golang
 *
 * [46] 全排列
 *
 * https://leetcode.cn/problems/permutations/description/
 *
 * algorithms
 * Medium (78.85%)
 * Likes:    2364
 * Dislikes: 0
 * Total Accepted:    783.7K
 * Total Submissions: 993.9K
 * Testcase Example:  '[1,2,3]'
 *
 * 给定一个不含重复数字的数组 nums ，返回其 所有可能的全排列 。你可以 按任意顺序 返回答案。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入：nums = [1,2,3]
 * 输出：[[1,2,3],[1,3,2],[2,1,3],[2,3,1],[3,1,2],[3,2,1]]
 * 
 * 
 * 示例 2：
 * 
 * 
 * 输入：nums = [0,1]
 * 输出：[[0,1],[1,0]]
 * 
 * 
 * 示例 3：
 * 
 * 
 * 输入：nums = [1]
 * 输出：[[1]]
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 1 <= nums.length <= 6
 * -10 <= nums[i] <= 10
 * nums 中的所有整数 互不相同
 * 
 * 
 */
package leetcode
// @lc code=start
func permute(nums []int) [][]int {
	var res [][]int
	size := len(nums)
	cur := make([]int, size)
	used := make([]bool, size)
	var dfs func(int)
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
		}
	}
	dfs(0)
	return res
}
// @lc code=end

