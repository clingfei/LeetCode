/*
 * @lc app=leetcode.cn id=15 lang=golang
 *
 * [15] 三数之和
 */
package leetcode
import "sort"

// @lc code=start
func threeSum(nums []int) [][]int {
	var res [][]int
	if len(nums) < 3 {
		return res
	}
	sort.Ints(nums)
	i := 0
	for i < len(nums) - 2 {
		j, k := i + 1, len(nums) - 1
		for j < k {
			if nums[i] + nums[j] + nums[k] == 0 {
				res = append(res, []int{nums[i], nums[j], nums[k]})
				for  j + 1 < k && nums[j] == nums[j + 1] {
					j++
				}
				j++
			} else if nums[i] + nums[j] + nums[k] < 0 {
				for j + 1 < k && nums[j + 1] == nums[j] {
					j++
				}
				j++
			} else {
				for k - 1 > j && nums[k] == nums[k-1] {
					k--
				}
				k--
			}
		}
		for i + 1 < len(nums) - 2 && nums[i] == nums[i + 1] {
			i++
		}
		i++
	}
	return res
}
// @lc code=end

