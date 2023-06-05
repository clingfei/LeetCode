/*
 * @lc app=leetcode.cn id=316 lang=golang
 *
 * [316] 去除重复字母
 *
 * https://leetcode.cn/problems/remove-duplicate-letters/description/
 *
 * algorithms
 * Medium (48.12%)
 * Likes:    865
 * Dislikes: 0
 * Total Accepted:    107.9K
 * Total Submissions: 223.9K
 * Testcase Example:  '"bcabc"'
 *
 * 给你一个字符串 s ，请你去除字符串中重复的字母，使得每个字母只出现一次。需保证 返回结果的字典序最小（要求不能打乱其他字符的相对位置）。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入：s = "bcabc"
 * 输出："abc"
 * 
 * 
 * 示例 2：
 * 
 * 
 * 输入：s = "cbacdcbc"
 * 输出："acdb"
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 1 <= s.length <= 10^4
 * s 由小写英文字母组成
 * 
 * 
 * 
 * 
 * 注意：该题与 1081
 * https://leetcode-cn.com/problems/smallest-subsequence-of-distinct-characters
 * 相同
 * 
 */
package leetcode 
// @lc code=start
func removeDuplicateLetters(s string) string {
	// 对于新的字符，首先判断之前有没有出现过，如果没有出现过，插入哈希表，
	// 如果出现过，如何判断最小的字典序？
	// 两个字符aba，有两种可能：ab和ba，判断后一个字符，如果后一个字符比自己大，则是最小的
	umap := make([]int, 26)
	// 记录每个字母的出现次数
	for _, v := range s {
		umap[v - 'a']++
	}
	sta := make([]byte, 0)
	hashmap := make([]int, 26)
	i := 0 
	for i < len(s) {
		if hashmap[s[i] - 'a'] > 0 {
            umap[s[i] - 'a']--
			i++
		} else if len(sta) == 0 || s[i] > sta[len(sta) - 1] || umap[sta[len(sta) - 1] - 'a'] <= 0 {
			sta = append(sta, s[i])
			hashmap[s[i] - 'a']++
			umap[s[i] - 'a']--
			i++
		} else {
			l := len(sta) - 1
			hashmap[sta[l] - 'a']--
			sta = sta[:l]
		}
	}
	res := ""
	for i := 0; i < len(sta); i++ {
		res += string(sta[i])
	}
	return res
}
// @lc code=end

