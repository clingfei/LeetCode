/*
 * @lc app=leetcode.cn id=478 lang=golang
 *
 * [478] 在圆内随机生成点
 */
package leetcode

import (
	"math"
	"math/rand"
	"time"
)

// @lc code=start
type Solution struct {
	radius float64
	x float64
	y float64
}


func Constructor(radius float64, x_center float64, y_center float64) Solution {
	return Solution{radius: radius, x: x_center, y: y_center}
}


func (this *Solution) RandPoint() []float64 {
	r := math.Sqrt(rand.Float64())
	sin, cos := math.Sincos(rand.Float64() * 2 * math.Pi)
	return []float64{this.x + r * this.radius * cos, this.y + r * this.radius * sin}
}


/**
 * Your Solution object will be instantiated and called as such:
 * obj := Constructor(radius, x_center, y_center);
 * param_1 := obj.RandPoint();
 */
// @lc code=end

