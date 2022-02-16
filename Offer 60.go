package leetcode

func dicesProbability(n int) []float64 {
	dp := make([][]float64, n)
	for i := 0; i < n; i++ {
		dp[i] = make([]float64, n * 6)
	}
	for i:=0; i < 6; i++ {
		dp[0][i] = 1.0 / 6.0
	}
	for i := 1; i < n; i++ {
		for j := 0; j < len(dp[i]); j++ {
			for k := 1; k <= 6 && k <= j; k++ {
				dp[i][j] += dp[i - 1][j - k] / 6.0
			}
		}
	}
	return dp[n-1][:len(dp[n-1]) - n + 1]
}