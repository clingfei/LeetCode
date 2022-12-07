/*
 * @lc app=leetcode.cn id=131 lang=golang
 *
 * [131] 分割回文串
 *
 * https://leetcode.cn/problems/palindrome-partitioning/description/
 *
 * algorithms
 * Medium (73.30%)
 * Likes:    1324
 * Dislikes: 0
 * Total Accepted:    250.7K
 * Total Submissions: 342K
 * Testcase Example:  '"aab"'
 *
 * 给你一个字符串 s，请你将 s 分割成一些子串，使每个子串都是 回文串 。返回 s 所有可能的分割方案。
 *
 * 回文串 是正着读和反着读都一样的字符串。
 *
 *
 *
 * 示例 1：
 *
 *
 * 输入：s = "aab"
 * 输出：[["a","a","b"],["aa","b"]]
 *
 *
 * 示例 2：
 *
 *
 * 输入：s = "a"
 * 输出：[["a"]]
 *
 *
 *
 *
 * 提示：
 *
 *
 * 1
 * s 仅由小写英文字母组成
 *
 *
 */
package leetcode
// @lc code=start
func partition(s string) [][]string {
	//分割回文串：
	var res [][]string
	temp := []string{}
	for i := 0; i < len(s); i++ {
		if !check(s, 0, i) {
			continue
		} 
		temp = append(temp, s[:i + 1])
		if i == len(s) - 1 {
			t := make([]string, len(temp))
			copy(t, temp)
			res = append(res, t)
		} else {
			backtracing(&res, &temp, s, i + 1)
		}
		temp = temp[:len(temp) - 1]
	}
	return res
}

func check(s string, left, right int) bool {
	i, j := left, right
	for i <= j {
		if s[i] == s[j] {
			i++
			j--
		} else {
			return false
		}
	}
	return true
}

func backtracing(res *[][]string, temp *[]string, s string, start int) {
	for i := start; i < len(s); i++ {
		if !check(s, start, i) {
			continue
		}
		*temp = append(*temp, s[start: i + 1])
		if i == len(s) - 1 {
			t := make([]string, len(*temp))
			copy(t, *temp)
			*res = append(*res, t)
		} else {
			backtracing(res, temp, s, i + 1)
		}
		*temp = (*temp)[:len(*temp) - 1]
	}
}

// @lc code=end

