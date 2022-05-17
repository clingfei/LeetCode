/*
 * @lc app=leetcode.cn id=792 lang=golang
 *
 * [792] 匹配子序列的单词数
 */
package leetcode

// @lc code=start
func numMatchingSubseq(s string, words []string) int {
	smap := make(map[string]int)
	res := 0
	for _, word := range(words) {
		smap[word]++
	}
	for k, v := range(smap) {
		if isSub(k, s) {
			res += v
		}
	}
	return res
}

func isSub(word string, s string) bool {
	i, j := 0, 0
	for ; i < len(word) && j < len(s); j++ {
		if word[i] == s[j] {
			i++
		}
	}
	return i >= len(word) 
}
// @lc code=end

