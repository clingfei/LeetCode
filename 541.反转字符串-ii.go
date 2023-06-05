/*
 * @lc app=leetcode.cn id=541 lang=golang
 *
 * [541] 反转字符串 II
 *
 * https://leetcode.cn/problems/reverse-string-ii/description/
 *
 * algorithms
 * Easy (58.82%)
 * Likes:    395
 * Dislikes: 0
 * Total Accepted:    162.9K
 * Total Submissions: 277.1K
 * Testcase Example:  '"abcdefg"\n2'
 *
 * 给定一个字符串 s 和一个整数 k，从字符串开头算起，每计数至 2k 个字符，就反转这 2k 字符中的前 k 个字符。
 * 
 * 
 * 如果剩余字符少于 k 个，则将剩余字符全部反转。
 * 如果剩余字符小于 2k 但大于或等于 k 个，则反转前 k 个字符，其余字符保持原样。
 * 
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入：s = "abcdefg", k = 2
 * 输出："bacdfeg"
 * 
 * 
 * 示例 2：
 * 
 * 
 * 输入：s = "abcd", k = 2
 * 输出："bacd"
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 1 <= s.length <= 10^4
 * s 仅由小写英文组成
 * 1 <= k <= 10^4
 * 
 * 
 */
package leetcode
// @lc code=start
func reverseStr(s string, k int) string {
	i := 0
	str := []byte(s)
	for i < len(s) {
		if i + k > len(s) {
			reverse(str, i, len(s))
			break
		} else {
			reverse(str, i, i + k)
			i += 2 * k
		}
	}
	return string(str)
}

func reverse(s []byte, left, right int) {
	i, j := left, right - 1
	for i < j {
		temp := s[i]
		s[i] = s[j]	
		s[j] = temp
		i, j = i + 1, j - 1
	}
}
// @lc code=end

