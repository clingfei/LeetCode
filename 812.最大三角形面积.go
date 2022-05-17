/*
 * @lc app=leetcode.cn id=812 lang=golang
 *
 * [812] 最大三角形面积
 */
package leetcode

import "math"

// @lc code=start
func largestTriangleArea(points [][]int) float64 {
	var res float64
	for i := 0; i < len(points); i++ {
		for j := 0; j < len(points); j++ {
			for k := 0; k < len(points); k++ {
				x1 := float64(points[i][0])
				x2 := float64(points[j][0]) - x1
				x3 := float64(points[k][0]) - x1
				y1 := float64(points[i][1])
				y2 := float64(points[j][1]) - y1
				y3 := float64(points[k][1]) - y1
				if tmp := math.Abs(x2 * y3 - x3 * y2) / 2; tmp > res {
					res = tmp
				}
			}
		}
	}
	return res
}
// @lc code=end

