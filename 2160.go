package leetcode

import "sort"

func minimumSum(num int) int {
	var temp []int
	for num != 0 {
		temp = append(temp, num%10)
		num /= 10
	}
	for len(temp) < 4 {
		temp = append(temp, 0)
	}
	sort.Ints(temp)
	return temp[0] * 10 + temp[2] + temp[1] * 10 + temp[3]
}