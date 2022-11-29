/*
 * @lc app=leetcode.cn id=5 lang=golang
 *
 * [5] 最长回文子串
 *
 * https://leetcode.cn/problems/longest-palindromic-substring/description/
 *
 * algorithms
 * Medium (37.26%)
 * Likes:    5930
 * Dislikes: 0
 * Total Accepted:    1.3M
 * Total Submissions: 3.4M
 * Testcase Example:  '"babad"'
 *
 * 给你一个字符串 s，找到 s 中最长的回文子串。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入：s = "babad"
 * 输出："bab"
 * 解释："aba" 同样是符合题意的答案。
 * 
 * 
 * 示例 2：
 * 
 * 
 * 输入：s = "cbbd"
 * 输出："bb"
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 1 <= s.length <= 1000
 * s 仅由数字和英文字母组成
 * 
 * 
 */
package leetcode

// @lc code=start
func longestPalindrome(s string) string {
	left, right := 0, 0
	maxlen := 1
	for i := 0; i < len(s); i++ {
		l, r := i - 1, i + 1
		curlen := 1;
		for l >= 0 && r < len(s) {
			if s[l] == s[r] {
				l, r = l - 1, r + 1
				curlen += 2
			} else {
				break
			}
		}
		if curlen > maxlen {
			maxlen = curlen
			left, right = l + 1, r - 1
		}
		l, r = i, i + 1
		curlen = 0
		for l >= 0 && r < len(s) {
			if s[l] == s[r] {
				curlen += 2
				l, r = l - 1, r + 1
			} else {
				break
			}
		}
		if curlen > maxlen {
			maxlen = curlen
			left, right = l + 1, r - 1
		}
	}
	return s[left: right + 1]
}
// @lc code=end

