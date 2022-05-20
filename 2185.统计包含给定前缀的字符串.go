/*
 * @lc app=leetcode.cn id=2185 lang=golang
 *
 * [2185] 统计包含给定前缀的字符串
 */
package leetcode
// @lc code=start
func prefixCount(words []string, pref string) int {
	res := 0
	for _, word := range words {
		if isPrefix(word, pref) {
			res++
		}
	}
	return res
}

func isPrefix(word string, pref string) bool {
	if len(pref) > len(word) {
		return false
	}
	for i := 0; i < len(pref); i++ {
		if pref[i] != word[i] {
			return false
		}
	}
	return true
}
// @lc code=end

