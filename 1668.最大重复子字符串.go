  /*
 * @lc app=leetcode.cn id=1668 lang=golang
 *
 * [1668] 最大重复子字符串
 */
package leetcode
// @lc code=start
func maxRepeating(seq string, word string) int {
	var mx, cur int
	wl := len(word)
	for i := 0; i <= len(seq)-wl; i++ {
		if seq[i:i+wl] == word {
			cur++
			i += wl - 1
		} else {
			i -= cur * wl
			cur = 0
		}
		if cur > mx {
			mx = cur
		}
	}
	return mx
}
// @lc code=end

