/*
 * @lc app=leetcode.cn id=2309 lang=golang
 *
 * [2309] 兼具大小写的最好英文字母
 *
 * https://leetcode.cn/problems/greatest-english-letter-in-upper-and-lower-case/description/
 *
 * algorithms
 * Easy (67.23%)
 * Likes:    15
 * Dislikes: 0
 * Total Accepted:    14.2K
 * Total Submissions: 20.4K
 * Testcase Example:  '"lEeTcOdE"'
 *
 * 给你一个由英文字母组成的字符串 s ，请你找出并返回 s 中的 最好
 * 英文字母。返回的字母必须为大写形式。如果不存在满足条件的字母，则返回一个空字符串。
 * 
 * 最好 英文字母的大写和小写形式必须 都 在 s 中出现。
 * 
 * 英文字母 b 比另一个英文字母 a 更好 的前提是：英文字母表中，b 在 a 之 后 出现。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入：s = "lEeTcOdE"
 * 输出："E"
 * 解释：
 * 字母 'E' 是唯一一个大写和小写形式都出现的字母。
 * 
 * 示例 2：
 * 
 * 
 * 输入：s = "arRAzFif"
 * 输出："R"
 * 解释：
 * 字母 'R' 是大写和小写形式都出现的最好英文字母。
 * 注意 'A' 和 'F' 的大写和小写形式也都出现了，但是 'R' 比 'F' 和 'A' 更好。
 * 
 * 
 * 示例 3：
 * 
 * 
 * 输入：s = "AbCdEfGhIjK"
 * 输出：""
 * 解释：
 * 不存在大写和小写形式都出现的字母。
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 1 <= s.length <= 1000
 * s 由小写和大写英文字母组成
 * 
 * 
 */
package leetcode
// @lc code=start
func greatestLetter(s string) string {
	low, high := make([]int, 26), make([]int, 26)
	cur := ""
	for i := 0; i < len(s); i++ {
		if s[i] >= 'a' && s[i] <= 'z' {
			low[int(s[i] - 'a')] = 1
			if high[int(s[i] - 'a')] == 1 {
				if cur == "" || cur[0] < 'A' + s[i] - 'a' {
					cur = string('A' + s[i] - 'a')
				}
			}
		} else {
			high[int(s[i] - 'A')] = 1
			if low[int(s[i] - 'A')] == 1 {
				if cur == "" || cur[0] < s[i] {
					cur = string(s[i])
				}
			}
		}
	}
	return cur
}
// @lc code=end

