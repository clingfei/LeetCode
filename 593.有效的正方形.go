/*
 * @lc app=leetcode.cn id=593 lang=golang
 *
 * [593] 有效的正方形
 */
package leetcode

import "reflect"

// @lc code=start
func abs(a int) int {
	if a < 0 {
		return -a
 	} else {
		 return a
	 }
}
func validSquare(p1 []int, p2 []int, p3 []int, p4 []int) bool {
	if reflect.DeepEqual(p1, p2) || reflect.DeepEqual(p1, p3) || reflect.DeepEqual(p1, p4) || reflect.DeepEqual(p2, p3) || reflect.DeepEqual(p2, p4) || reflect.DeepEqual(p3, p4) {
		return false 
	}
	v1 := []int{p1[0] - p2[0], p1[1] - p2[1]}
	v2 := []int{p3[0] - p4[0], p3[1] - p4[1]}
	
	if v1[0] * v2[0] + v1[1] * v2[1] == 0 {
		if v1[0] * v1[0] + v1[1] * v1[1] == v2[0] * v2[0] + v2[1] * v2[1] {
			return true
		} else {
			return false
		}
	} 
	if v1[0] == 0 && v2[0] == 0 {
		if v1[1] == v2[1] {
			if abs(p1[0] - p3[0]) == abs(v1[1]) {
				return true
			} else {
				return false
			}
		} else if v1[1] == -v2[1] {
			t1 := []int{p1[0] - p3[0], p1[1] - p3[1]}
			t2 := []int{p2[0] - p4[0], p2[1] - p4[1]}
			if t1[0] * t2[0] + t1[1] * t2[1] == 0 && t1[0] * t1[0] + t1[1] * t1[1] == t2[0] * t2[0] + t2[1] * t2[1] {
				return true
			} else {
				return false
			}
		} else {
			return false
		}
	} else if v1[0] == 0 || v2[0] == 0 {
		return false
	} else {
		if v1[1] / v1[0] == v2[1] / v2[0] {
			if v1[0] * v1[0] + v1[1] * v1[1] == v2[0] * v2[0] + v2[1] * v2[1] {
				t1 := []int{p1[0] - p3[0], p1[1] - p3[1]}
				t2 := []int{p2[0] - p4[0], p2[1] - p4[1]}
				if t1[0] * t2[0] + t1[1] * t2[1] == 0 && t1[0] * t1[0] + t1[1] * t1[1] == t2[0] * t2[0] + t2[1] * t2[1] {
					return true
				} 
				t1 = []int{p1[0] - p4[0], p1[1] - p4[1]}
				t2 = []int{p2[0] - p3[0], p2[1] - p3[1]}
				if t1[0] * t2[0] + t1[1] * t2[1] == 0 && t1[0] * t1[0] + t1[1] * t1[1] == t2[0] * t2[0] + t2[1] * t2[1] {
					return true
				} 
				return false
			} else {
				return false
			}
		} else if v1[1] * v2[1] + v1[0] * v1[0] == 0 && v1[0] * v1[0] + v1[1] * v1[1] == v2[0] * v2[0] + v2[1] * v2[1] {
			return true
		} else {
			return false
		}
	}
}
// @lc code=end

