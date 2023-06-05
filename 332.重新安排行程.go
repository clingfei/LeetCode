/*
 * @lc app=leetcode.cn id=332 lang=golang
 *
 * [332] 重新安排行程
 *
 * https://leetcode.cn/problems/reconstruct-itinerary/description/
 *
 * algorithms
 * Hard (47.42%)
 * Likes:    710
 * Dislikes: 0
 * Total Accepted:    75.5K
 * Total Submissions: 159.2K
 * Testcase Example:  '[["MUC","LHR"],["JFK","MUC"],["SFO","SJC"],["LHR","SFO"]]'
 *
 * 给你一份航线列表 tickets ，其中 tickets[i] = [fromi, toi]
 * 表示飞机出发和降落的机场地点。请你对该行程进行重新规划排序。
 *
 * 所有这些机票都属于一个从 JFK（肯尼迪国际机场）出发的先生，所以该行程必须从 JFK
 * 开始。如果存在多种有效的行程，请你按字典排序返回最小的行程组合。
 *
 *
 * 例如，行程 ["JFK", "LGA"] 与 ["JFK", "LGB"] 相比就更小，排序更靠前。
 *
 *
 * 假定所有机票至少存在一种合理的行程。且所有的机票 必须都用一次 且 只能用一次。
 *
 *
 *
 * 示例 1：
 *
 *
 * 输入：tickets = [["MUC","LHR"],["JFK","MUC"],["SFO","SJC"],["LHR","SFO"]]
 * 输出：["JFK","MUC","LHR","SFO","SJC"]
 *
 *
 * 示例 2：
 *
 *
 * 输入：tickets =
 * [["JFK","SFO"],["JFK","ATL"],["SFO","ATL"],["ATL","JFK"],["ATL","SFO"]]
 * 输出：["JFK","ATL","JFK","SFO","ATL","SFO"]
 * 解释：另一种有效的行程是 ["JFK","SFO","ATL","JFK","ATL","SFO"] ，但是它字典排序更大更靠后。
 *
 *
 *
 *
 * 提示：
 *
 *
 * 1
 * tickets[i].length == 2
 * fromi.length == 3
 * toi.length == 3
 * fromi 和 toi 由大写英文字母组成
 * fromi != toi
 *
 *
 */
package leetcode

import "sort"

// @lc code=start
type pairs [][]string
func (p pairs) Len() int {
	return len(p)
}

func (p pairs) Swap(i, j int) {
	p[i], p[j] = p[j], p[i]
}

func (p pairs) Less(i, j int) bool {
	return p[i][0] < p[j][0] || p[i][0] == p[j][0] && p[i][1] < p[j][1]
}

func findItinerary(tickets [][]string) []string {
	sort.Sort(pairs(tickets))
	size := len(tickets)
	res := []string{"JFK"}
	// 深度优先搜索，找到每一步能用的机票，更新next
	// 如果没有找到，则回退
	// 首先对机票进行一个排序，排序的目的是，具有相同始发站的机票，到达站字典序更靠前的放在前面，这样找到的第一个满足条件的就是最终的结果
	isVisited := make([]bool, size)
	var dfs func(string) bool
	dfs = func(next string) bool {
		if len(res) == len(tickets) + 1 {
			return true
		}
		for i := 0; i < size; i++ {
			if isVisited[i] {
				continue
			}
			if tickets[i][0] == next {
				isVisited[i] = true
				res = append(res, tickets[i][1])
				if dfs(tickets[i][1]) {
					return true
				}
				isVisited[i] = false
				res = res[:len(res) - 1]
			}
		}	
		return false
	}
	dfs("JFK")
	return res
}
// @lc code=end

