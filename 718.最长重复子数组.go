/*
 * @lc app=leetcode.cn id=718 lang=golang
 *
 * [718] 最长重复子数组
 *
 * https://leetcode.cn/problems/maximum-length-of-repeated-subarray/description/
 *
 * algorithms
 * Medium (57.12%)
 * Likes:    845
 * Dislikes: 0
 * Total Accepted:    167.4K
 * Total Submissions: 293.1K
 * Testcase Example:  '[1,2,3,2,1]\n[3,2,1,4,7]'
 *
 * 给两个整数数组 nums1 和 nums2 ，返回 两个数组中 公共的 、长度最长的子数组的长度 。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入：nums1 = [1,2,3,2,1], nums2 = [3,2,1,4,7]
 * 输出：3
 * 解释：长度最长的公共子数组是 [3,2,1] 。
 * 
 * 
 * 示例 2：
 * 
 * 
 * 输入：nums1 = [0,0,0,0,0], nums2 = [0,0,0,0,0]
 * 输出：5
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 1 <= nums1.length, nums2.length <= 1000
 * 0 <= nums1[i], nums2[i] <= 100
 * 
 * 
 */
package leetcode
// @lc code=start
func findLength(nums1 []int, nums2 []int) int {
	//dp[i][j]表示nums1前i个，nums2前j个公共的长度最长的子数组长度
	// dp[i][j] = dp[i - 1][j - 1] + 1
	col, row := len(nums1), len(nums2)
	dp := make([][]int, len(nums1))
	for i := 0; i < col; i++ {
		dp[i] = make([]int, row)
	}
	res := 0
	for i := 0; i < col; i++ {
		for j := 0; j < row; j++ {
			if nums1[i] == nums2[j] {
				if i == 0 || j == 0 {
					dp[i][j] = 1
				} else {
					dp[i][j] = dp[i - 1][j - 1] + 1
				}
				res = max(res, dp[i][j])
			}
		}
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

