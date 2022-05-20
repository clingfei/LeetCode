/*
 * @lc app=leetcode.cn id=436 lang=golang
 *
 * [436] 寻找右区间
 */
package leetcode
// @lc code=start
func findRightInterval(intervals [][]int) []int {
    for i := range intervals {
        intervals[i] = append(intervals[i], i)
    }
    sort.Slice(intervals, func(i, j int) bool { return intervals[i][0] < intervals[j][0] })

    n := len(intervals)
    ans := make([]int, n)
    for _, p := range intervals {
        i := sort.Search(n, func(i int) bool { return intervals[i][0] >= p[1] })
        if i < n {
            ans[p[2]] = intervals[i][2]
        } else {
            ans[p[2]] = -1
        }
    }
    return ans
}
// @lc code=end

