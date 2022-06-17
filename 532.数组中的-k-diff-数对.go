/*
 * @lc app=leetcode.cn id=532 lang=golang
 *
 * [532] 数组中的 k-diff 数对
 */
package leetcode
// @lc code=start
func findPairs(nums []int, k int) (ans int) {
	sort.Ints(nums)
	y, n := 0, len(nums)
	for x, num := range nums {
		if x == 0 || num != nums[x-1] {
			for y < n && (nums[y] < num+k || y <= x) {
				y++
			}
			if y < n && nums[y] == num+k {
				ans++
			}
		}
	}
	return
}
// @lc code=end

