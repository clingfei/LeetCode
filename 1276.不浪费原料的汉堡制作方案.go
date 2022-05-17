/*
 * @lc app=leetcode.cn id=1276 lang=golang
 *
 * [1276] 不浪费原料的汉堡制作方案
 */
package leetcode
// @lc code=start
func numOfBurgers(tomatoSlices int, cheeseSlices int) []int {
	if tomatoSlices % 2 != 0 {
		return []int{}
	}
	if cheeseSlices > tomatoSlices - cheeseSlices {
		return []int{}
	}
	if (tomatoSlices - 2 * cheeseSlices) % 2 != 0 {
		return []int{}
	}
	if 2 * cheeseSlices < tomatoSlices / 2 {
		return []int{}
	}
	return []int{(tomatoSlices - 2 * cheeseSlices) / 2, 2 * cheeseSlices - tomatoSlices / 2}
}
// @lc code=end

