/*
 * @lc app=leetcode.cn id=242 lang=golang
 *
 * [242] 有效的字母异位词
 *
 * https://leetcode.cn/problems/valid-anagram/description/
 *
 * algorithms
 * Easy (65.66%)
 * Likes:    705
 * Dislikes: 0
 * Total Accepted:    530.3K
 * Total Submissions: 807.1K
 * Testcase Example:  '"anagram"\n"nagaram"'
 *
 * 给定两个字符串 s 和 t ，编写一个函数来判断 t 是否是 s 的字母异位词。
 * 
 * 注意：若 s 和 t 中每个字符出现的次数都相同，则称 s 和 t 互为字母异位词。
 * 
 * 
 * 
 * 示例 1:
 * 
 * 
 * 输入: s = "anagram", t = "nagaram"
 * 输出: true
 * 
 * 
 * 示例 2:
 * 
 * 
 * 输入: s = "rat", t = "car"
 * 输出: false
 * 
 * 
 * 
 * 提示:
 * 
 * 
 * 1 
 * s 和 t 仅包含小写字母
 * 
 * 
 * 
 * 
 * 进阶: 如果输入字符串包含 unicode 字符怎么办？你能否调整你的解法来应对这种情况？
 * 
 */
package leetcode
// @lc code=start
func isAnagram(s string, t string) bool {
	hashMap := make(map[rune]int)
	for _, v := range s {
		hashMap[v]++
	}
	for _, v := range t {
		hashMap[v]--
		if hashMap[v] < 0 {
			return false
		}
	}
	for _, v := range hashMap {
		if v != 0 {
			return false
		}
	}
	return true
}
// @lc code=end

