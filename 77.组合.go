/*
 * @lc app=leetcode.cn id=77 lang=golang
 *
 * [77] 组合
 *
 * https://leetcode.cn/problems/combinations/description/
 *
 * algorithms
 * Medium (77.27%)
 * Likes:    1246
 * Dislikes: 0
 * Total Accepted:    469.7K
 * Total Submissions: 607.8K
 * Testcase Example:  '4\n2'
 *
 * 给定两个整数 n 和 k，返回范围 [1, n] 中所有可能的 k 个数的组合。
 * 
 * 你可以按 任何顺序 返回答案。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入：n = 4, k = 2
 * 输出：
 * [
 * ⁠ [2,4],
 * ⁠ [3,4],
 * ⁠ [2,3],
 * ⁠ [1,2],
 * ⁠ [1,3],
 * ⁠ [1,4],
 * ]
 * 
 * 示例 2：
 * 
 * 
 * 输入：n = 1, k = 1
 * 输出：[[1]]
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 1 
 * 1 
 * 
 * 
 */
package leetcode
// @lc code=start
func combine(n int, k int) [][]int {
	var res [][]int
	var path []int
	var dfs func(int)
	dfs = func (startIndex int) {
		if len(path) == k {
			tmp := make([]int, k)
			copy(tmp, path)
			res = append(res, tmp)
			return			
		}
		for i := startIndex; i <= n + 1 - k + len(path); i++ {
			path = append(path, i)
			dfs(i + 1)
			path = path[:len(path) - 1]
		} 
	}
	dfs(1)
	return res
}
// @lc code=end

