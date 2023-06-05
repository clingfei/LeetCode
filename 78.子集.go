/*
 * @lc app=leetcode.cn id=78 lang=golang
 *
 * [78] 子集
 *
 * https://leetcode.cn/problems/subsets/description/
 *
 * algorithms
 * Medium (80.97%)
 * Likes:    1890
 * Dislikes: 0
 * Total Accepted:    564.5K
 * Total Submissions: 697.1K
 * Testcase Example:  '[1,2,3]'
 *
 * 给你一个整数数组 nums ，数组中的元素 互不相同 。返回该数组所有可能的子集（幂集）。
 * 
 * 解集 不能 包含重复的子集。你可以按 任意顺序 返回解集。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入：nums = [1,2,3]
 * 输出：[[],[1],[2],[1,2],[3],[1,3],[2,3],[1,2,3]]
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
 * nums 中的所有元素 互不相同
 * 
 * 
 */
package leetcode
// @lc code=start
func subsets(nums []int) [][]int {
	var res [][]int
	res = append(res, []int{})
	var path []int
	var dfs func(int) 
	dfs = func(idx int) {
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
		}
	}
	dfs(0)
	return res
}
// @lc code=end

