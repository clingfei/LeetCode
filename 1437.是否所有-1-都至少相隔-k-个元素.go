/*
 * @lc app=leetcode.cn id=1437 lang=golang
 *
 * [1437] 是否所有 1 都至少相隔 k 个元素
 */
package leetcode
// @lc code=start
func kLengthApart(nums []int, k int) bool {
	last := -1;
	for i, v := range nums {
		if v == 1 {
			if last == -1 {
				last = i
			} else {
				if i - last - 1 < k {
					return false
				} else {
					last = i
				}
			}
		}
	}
	return true
}
// @lc code=end

