/*
 * @lc app=leetcode.cn id=1089 lang=golang
 *
 * [1089] 复写零
 */
package leetcode
// @lc code=start
func duplicateZeros(arr []int)  {
	tmp := []int{}
	for _, v := range arr{
		tmp = append(tmp, v)
		if v == 0 {
			tmp = append(tmp, 0)
		}
	}
	copy(arr, tmp)
}
// @lc code=end

