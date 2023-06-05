/*
 * @lc app=leetcode.cn id=135 lang=golang
 *
 * [135] 分发糖果
 *
 * https://leetcode.cn/problems/candy/description/
 *
 * algorithms
 * Hard (49.59%)
 * Likes:    1083
 * Dislikes: 0
 * Total Accepted:    189.5K
 * Total Submissions: 382.1K
 * Testcase Example:  '[1,0,2]'
 *
 * n 个孩子站成一排。给你一个整数数组 ratings 表示每个孩子的评分。
 * 
 * 你需要按照以下要求，给这些孩子分发糖果：
 * 
 * 
 * 每个孩子至少分配到 1 个糖果。
 * 相邻两个孩子评分更高的孩子会获得更多的糖果。
 * 
 * 
 * 请你给每个孩子分发糖果，计算并返回需要准备的 最少糖果数目 。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入：ratings = [1,0,2]
 * 输出：5
 * 解释：你可以分别给第一个、第二个、第三个孩子分发 2、1、2 颗糖果。
 * 
 * 
 * 示例 2：
 * 
 * 
 * 输入：ratings = [1,2,2]
 * 输出：4
 * 解释：你可以分别给第一个、第二个、第三个孩子分发 1、2、1 颗糖果。
 * ⁠    第三个孩子只得到 1 颗糖果，这满足题面中的两个条件。
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * n == ratings.length
 * 1 <= n <= 2 * 10^4
 * 0 <= ratings[i] <= 2 * 10^4
 * 
 * 
 */
package leetcode
// @lc code=start
func candy(ratings []int) int {
	// 最少的糖果数是由最近的极小值点决定的
	// 统计连续递减的数量
	res := 0
	candys := make([]int, len(ratings))
	candys[0] = 1 
	for i := 1; i < len(ratings); i++ {
		if ratings[i] > ratings[i - 1] {
			candys[i] = candys[i - 1] + 1
		} else {
			candys[i] = 1
		}
	}
	// 最后一个人获得的糖果仅和其前一个人获得的糖果有关，从左往右一定满足条件，从右往左一定也满足条件
	for i := len(ratings) - 2; i >= 0; i-- {
		if ratings[i] > ratings[i + 1] {
			candys[i] = max(candys[i], candys[i + 1] + 1)
		}
	}
	for i := range ratings {
		res += candys[i]
	}
	return res
}
func max(a, b int) int {
	if a > b {
		return a
	} else {
		return b
	}
}
// @lc code=end

