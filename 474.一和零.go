/*
 * @lc app=leetcode.cn id=474 lang=golang
 *
 * [474] 一和零
 *
 * https://leetcode.cn/problems/ones-and-zeroes/description/
 *
 * algorithms
 * Medium (64.47%)
 * Likes:    846
 * Dislikes: 0
 * Total Accepted:    138.8K
 * Total Submissions: 215.1K
 * Testcase Example:  '["10","0001","111001","1","0"]\n5\n3'
 *
 * 给你一个二进制字符串数组 strs 和两个整数 m 和 n 。
 *
 *
 * 请你找出并返回 strs 的最大子集的长度，该子集中 最多 有 m 个 0 和 n 个 1 。
 *
 * 如果 x 的所有元素也是 y 的元素，集合 x 是集合 y 的 子集 。
 *
 *
 *
 *
 * 示例 1：
 *
 *
 * 输入：strs = ["10", "0001", "111001", "1", "0"], m = 5, n = 3
 * 输出：4
 * 解释：最多有 5 个 0 和 3 个 1 的最大子集是 {"10","0001","1","0"} ，因此答案是 4 。
 * 其他满足题意但较小的子集包括 {"0001","1"} 和 {"10","1","0"} 。{"111001"} 不满足题意，因为它含 4 个 1
 * ，大于 n 的值 3 。
 *
 *
 * 示例 2：
 *
 *
 * 输入：strs = ["10", "0", "1"], m = 1, n = 1
 * 输出：2
 * 解释：最大的子集是 {"0", "1"} ，所以答案是 2 。
 *
 *
 *
 *
 * 提示：
 *
 *
 * 1 <= strs.length <= 600
 * 1 <= strs[i].length <= 100
 * strs[i] 仅由 '0' 和 '1' 组成
 * 1 <= m, n <= 100
 *
 *
 */
package leetcode

import "fmt"

// @lc code=start
func findMaxForm(strs []string, m int, n int) int {
	// dp[i][j]表示有i个0，j个1的最大子集的长度
	// 加入strs[i]有x个0，y个1
	// dp[i][j] = dp[i - ones[i]][j - zeros[i]] + 1
	dp := make([][]int, m + 1)
	for i := range dp {
		dp[i] = make([]int, n + 1)
	}
	for _, str := range strs {
		zeros, ones := 0, 0
		for _, c := range str {
			if c == '0' {
				zeros++
			} else {
				ones++
			}
		}
		for i := m; i >= zeros; i-- {
			for j := n; j >= ones; j-- {
				dp[i][j] = max(dp[i][j], dp[i - zeros][j - ones] + 1)
				fmt.Println(i, j, dp[i][j])
			}
		}
	}
	return dp[m][n]
}
func max(a, b int) int {
	if a > b {
		return a
	} else {
		return b
	}
}
// @lc code=end

