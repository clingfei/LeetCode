/*
 * @lc app=leetcode.cn id=464 lang=golang
 *
 * [464] 我能赢吗
 */
package leetcode
// @lc code=start
func canIWin(maxChoosableInteger, desiredTotal int) bool {
    if (1+maxChoosableInteger)*maxChoosableInteger/2 < desiredTotal {
        return false
    }

    dp := make([]int8, 1<<maxChoosableInteger)
    for i := range dp {
        dp[i] = -1
    }
    var dfs func(int, int) int8
    dfs = func(usedNum, curTot int) (res int8) {
        dv := &dp[usedNum]
        if *dv != -1 {
            return *dv
        }
        defer func() { *dv = res }()
        for i := 0; i < maxChoosableInteger; i++ {
            if usedNum>>i&1 == 0 && (curTot+i+1 >= desiredTotal || dfs(usedNum|1<<i, curTot+i+1) == 0) {
                return 1
            }
        }
        return
    }
    return dfs(0, 0) == 1
}

// @lc code=end

