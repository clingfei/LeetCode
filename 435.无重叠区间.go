/*
 * @lc app=leetcode.cn id=435 lang=golang
 *
 * [435] 无重叠区间
 *
 * https://leetcode.cn/problems/non-overlapping-intervals/description/
 *
 * algorithms
 * Medium (51.14%)
 * Likes:    870
 * Dislikes: 0
 * Total Accepted:    193.5K
 * Total Submissions: 378.3K
 * Testcase Example:  '[[1,2],[2,3],[3,4],[1,3]]'
 *
 * 给定一个区间的集合 intervals ，其中 intervals[i] = [starti, endi] 。返回
 * 需要移除区间的最小数量，使剩余区间互不重叠 。
 *
 *
 *
 * 示例 1:
 *
 *
 * 输入: intervals = [[1,2],[2,3],[3,4],[1,3]]
 * 输出: 1
 * 解释: 移除 [1,3] 后，剩下的区间没有重叠。
 *
 *
 * 示例 2:
 *
 *
 * 输入: intervals = [ [1,2], [1,2], [1,2] ]
 * 输出: 2
 * 解释: 你需要移除两个 [1,2] 来使剩下的区间没有重叠。
 *
 *
 * 示例 3:
 *
 *
 * 输入: intervals = [ [1,2], [2,3] ]
 * 输出: 0
 * 解释: 你不需要移除任何区间，因为它们已经是无重叠的了。
 *
 *
 *
 *
 * 提示:
 *
 *
 * 1 <= intervals.length <= 10^5
 * intervals[i].length == 2
 * -5 * 10^4 <= starti < endi <= 5 * 10^4
 *
 *
 */
package leetcode

import (
	"fmt"
	"sort"
)

// @lc code=start
func eraseOverlapIntervals(intervals [][]int) int {
	sort.Slice(intervals, func (i, j int) bool {
		return intervals[i][0] < intervals[j][0] || (intervals[i][0] == intervals[j][0] && intervals[i][1] < intervals[j][1])
	})
	res := 0
	boundary := intervals[0][1]
	for i := 1; i < len(intervals); i++ {
		if intervals[i][0] < boundary {
			res++
			boundary = min(boundary, intervals[i][1])
		} else {
			boundary = intervals[i][1]
		}
	}
	return res
}

func min(a, b int) int {
	if a < b {
		return a
	} else {
		return b
	}
}
// @lc code=end

