/*
 * @lc app=leetcode.cn id=767 lang=golang
 *
 * [767] 重构字符串
 */
package leetcode
// @lc code=start
func reorganizeString(s string) string {
	alpha := make([]int, 26)
	i, m := 0, 0
	res := make([]byte, len(s))

	for _, c := range s {
		alpha[c - 'a']++
		if alpha[c - 'a'] > alpha[m] {
			m = int(c - 'a')
		}
	}
	if alpha[m] > (len(s) + 1) / 2 {
		return ""
	}
	for alpha[m] > 0 {
		res[i] = byte(m + 'a');
		i += 2
		alpha[m]--
	}
	for j := range alpha {
		for alpha[j] > 0 {
			if i >= len(s) {
				i = 1
			}
			res[i] = byte(j + 'a');
			i += 2
			alpha[j]--
		}
	}
	return string(res)
}
// @lc code=end

