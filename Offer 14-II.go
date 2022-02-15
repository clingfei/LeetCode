package leetcode

func cuttingRope(n int) int {
	mod := 1e9 + 7
	if n <= 2 {
		return 1
	} else if n == 3 {
		return 2
	}
	res := 1
	for n > 4 {
		res = (res * 3) % int(mod)
		n -= 3
	}
	res =  (res * n) % int(mod)
	return res
}