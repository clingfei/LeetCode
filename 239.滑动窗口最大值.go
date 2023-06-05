/*
 * @lc app=leetcode.cn id=239 lang=golang
 *
 * [239] 滑动窗口最大值
 *
 * https://leetcode.cn/problems/sliding-window-maximum/description/
 *
 * algorithms
 * Hard (49.94%)
 * Likes:    2031
 * Dislikes: 0
 * Total Accepted:    385.8K
 * Total Submissions: 772.9K
 * Testcase Example:  '[1,3,-1,-3,5,3,6,7]\n3'
 *
 * 给你一个整数数组 nums，有一个大小为 k 的滑动窗口从数组的最左侧移动到数组的最右侧。你只可以看到在滑动窗口内的 k
 * 个数字。滑动窗口每次只向右移动一位。
 * 
 * 返回 滑动窗口中的最大值 。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入：nums = [1,3,-1,-3,5,3,6,7], k = 3
 * 输出：[3,3,5,5,6,7]
 * 解释：
 * 滑动窗口的位置                最大值
 * ---------------               -----
 * [1  3  -1] -3  5  3  6  7       3
 * ⁠1 [3  -1  -3] 5  3  6  7       3
 * ⁠1  3 [-1  -3  5] 3  6  7       5
 * ⁠1  3  -1 [-3  5  3] 6  7       5
 * ⁠1  3  -1  -3 [5  3  6] 7       6
 * ⁠1  3  -1  -3  5 [3  6  7]      7
 * 
 * 
 * 示例 2：
 * 
 * 
 * 输入：nums = [1], k = 1
 * 输出：[1]
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 1 <= nums.length <= 10^5
 * -10^4 <= nums[i] <= 10^4
 * 1 <= k <= nums.length
 * 
 * 
 */
package leetcode
// @lc code=start
func maxSlidingWindow(nums []int, k int) []int {
	que := make([]int, 0)
	for i := 0; i < k; i++ {
		l := len(que)
		for l > 0 && que[l - 1] < nums[i] {
			que = que[:l - 1]
			l--
		}
		que = append(que, nums[i])
	}
	res := make([]int, 0)
	res = append(res, que[0])
	j := k
	for j < len(nums) {
		if que[0] == nums[j - k] {
			que = que[1:]
		}
		l := len(que)
		for l > 0 && que[l - 1] < nums[j] {
			que = que[:l - 1]
			l--
		}
		que = append(que, nums[j])
		res = append(res, que[0])
		j = j + 1
	}
	return res
}
// @lc code=end

