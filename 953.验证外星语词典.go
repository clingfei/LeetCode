/*
 * @lc app=leetcode.cn id=953 lang=golang
 *
 * [953] 验证外星语词典
 */
package leetcode
// @lc code=start
func isAlienSorted(words []string, order string) bool {
	umap := make(map[rune]int)
	for i, v := range order {
		umap[v] = i
	}
	for i := 0; i < len(words) - 1; i++ {
		if !cmp(words[i], words[i + 1], &umap) {
			return false
		}
	}
	return true
}

func cmp(word1 string, word2 string, umap * map[rune]int) bool {
	i, j := 0, 0
	for i < len(word1) && j < len(word2) {
		if (*umap)[rune(word1[i])] < (*umap)[rune(word2[j])] {
			return true
		} else if (*umap)[rune(word1[i])] > (*umap)[rune(word2[j])] {
			return false
		}
		i++
		j++
	}
	if i == len(word1) && j <= len(word2) {
		return true
	} else {
		return false
	}
}
// @lc code=end

