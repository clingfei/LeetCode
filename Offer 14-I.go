package leetcode

import "math"

func cuttingRope(n int) int {
	// n为的最大值为dp[j] * dp(n - j)
	dp := make([]int, n+1)
	if n <= 2 {
		return 1
	}
	max := func(a, b  int) int {
		if a >= b {
			return a
		} else {
			return b
		}
 	}
	dp[2] = 1
	for i := 3; i <= n; i++ {
		for j := 1; j <= i; j++ {
			dp[i] = max(dp[i], max(j * (i - j), (i - j) * dp[j]))
		}
	}
	return dp[n]
}