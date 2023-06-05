/*
 * @lc app=leetcode.cn id=383 lang=golang
 *
 * [383] 赎金信
 *
 * https://leetcode.cn/problems/ransom-note/description/
 *
 * algorithms
 * Easy (60.17%)
 * Likes:    601
 * Dislikes: 0
 * Total Accepted:    274.5K
 * Total Submissions: 456.5K
 * Testcase Example:  '"a"\n"b"'
 *
 * 给你两个字符串：ransomNote 和 magazine ，判断 ransomNote 能不能由 magazine 里面的字符构成。
 * 
 * 如果可以，返回 true ；否则返回 false 。
 * 
 * magazine 中的每个字符只能在 ransomNote 中使用一次。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入：ransomNote = "a", magazine = "b"
 * 输出：false
 * 
 * 
 * 示例 2：
 * 
 * 
 * 输入：ransomNote = "aa", magazine = "ab"
 * 输出：false
 * 
 * 
 * 示例 3：
 * 
 * 
 * 输入：ransomNote = "aa", magazine = "aab"
 * 输出：true
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 1 <= ransomNote.length, magazine.length <= 10^5
 * ransomNote 和 magazine 由小写英文字母组成
 * 
 * 
 */
package leetcode
// @lc code=start
func canConstruct(ransomNote string, magazine string) bool {
	hashMap := make(map[rune]int)
	for _, v := range magazine {
		hashMap[v]++
	}
	for _, v := range ransomNote {
		if cnt, ok := hashMap[v]; !ok || cnt == 0 {
			return false
		} else {
			hashMap[v]--
		}
	}
	return true
}
// @lc code=end

