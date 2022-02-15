package leetcode

import "math"

func printNumbers(n int) (res []int) {
	res = make([]int, int(math.Pow10(n) - 1))
	for i := 1; i < int(math.Pow10(n)); i++ {
		res[i - 1] = i
	}
	return res
}