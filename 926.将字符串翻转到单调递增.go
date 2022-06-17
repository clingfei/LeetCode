/*
 * @lc app=leetcode.cn id=926 lang=golang
 *
 * [926] 将字符串翻转到单调递增
 */
package leetcode
// @lc code=start
func minFlipsMonoIncr(s string) int {
	cnt0 := 0
	for _, v := range s {
		if v == '0' {
			cnt0++
		}
	}	
	res := []int{cnt0}
	for _, v := range s {
		if v == '1' {
			cnt0++
		} else {
			cnt0--
		}
		res = append(res, cnt0)
	}
	min := res[0]
	for i := 1; i < len(res); i++ {
		if res[i] < min {
			min = res[i]
		}
	}
	return min
}
// @lc code=end

