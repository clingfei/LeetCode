/*
 * @lc app=leetcode.cn id=1620 lang=golang
 *
 * [1620] 网络信号最好的坐标
 */
package leetcode

import "math"

// @lc code=start
func bestCoordinate(towers [][]int, radius int) []int {
	res := []int{0, 0}
	maxq := 0
	for i := 0; i <= 50; i++ {
		for j := 0; j <= 50; j++ {
			cur := 0
			for _, v := range towers {
				d1 := (i-v[0]) * (i-v[0]) + (j - v[1])*(j-v[1])
				if d1 <= radius * radius {
					cur += int(float64(v[2]) / (1 + math.Sqrt(float64(d1))))
				}
			}
			if cur > maxq {
				maxq = cur
				res = []int{i, j}
			}
		}
	}
	return res
}
// @lc code=end

