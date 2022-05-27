/*
 * @lc app=leetcode.cn id=853 lang=golang
 *
 * [853] 车队
 */
package leetcode

import (
	"fmt"
	"sort"
)

// @lc code=start
type car struct {
	pos int
	time float64
}

type carSlice []car

func (c carSlice) Len() int {
	return len(c)
}

func (c carSlice) Less(i, j int) bool {
	return c[i].pos > c[j].pos
}

func (c carSlice) Swap(i, j int) {
	c[i], c[j] = c[j], c[i]
} 

func carFleet(target int, position []int, speed []int) int {
	if len(position) == 0 {
		return 0
	}
	var cars carSlice
	cars = make([]car, len(position))
	for i := 0; i < len(cars); i++ {
		cars[i] = car{position[i], float64(target - position[i]) / float64(speed[i])}
	}
	sort.Sort(cars)
	res := 1
	mt := cars[0].time
	for i := 1; i < len(cars); i++ {
		if cars[i].time > mt {
			res++
			mt = cars[i].time
		}
	}
	return res
}
// @lc code=end

