package leetcode

func nthUglyNumber(n int) int {
	dp := make([]int, n+1)
	dp[1] = 1
	p1, p2, p3 := 1, 1, 1
	i := 2
	for ; i <= n; i++ {
		temp := min(dp[p1] * 2, dp[p2] * 3, dp[p3] * 5)
		dp[i] = temp
		if temp == dp[p1] * 2 {
			p1++
		} 
		if temp == dp[p2] * 3 {
			p2++
		} 
		if temp == dp[p3] * 5 {
			p3++
		}
	}
	return dp[n]
}

func min(a, b, c int) int {
	if (a < b) {
		if (a < c) {
			return a
		} else {
			return c
		}
	} else {
		if b > c {
			return c
		} else {
			return b
		}
	}
}