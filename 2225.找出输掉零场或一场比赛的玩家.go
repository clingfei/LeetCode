/*
 * @lc app=leetcode.cn id=2225 lang=golang
 *
 * [2225] 找出输掉零场或一场比赛的玩家
 */
package leetcode

import "sort"

// @lc code=start
func findWinners(matches [][]int) [][]int {
	answer := make([][]int, 2)
	winMap := make(map[int]int)
	loserMap := make(map[int]int)
	for _, v := range matches {
		winMap[v[0]]++
		loserMap[v[0]] += 0
		loserMap[v[1]]++
	}
	for k, v := range loserMap {
		if v == 0 {
			answer[0] = append(answer[0], k)
		} else if v == 1 {
			answer[1] = append(answer[1], k)
		}
	} 
	sort.Ints(answer[0])
	sort.Ints(answer[1])
	return answer
}
// @lc code=end

