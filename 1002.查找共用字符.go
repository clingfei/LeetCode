/*
 * @lc app=leetcode.cn id=1002 lang=golang
 *
 * [1002] 查找共用字符
 *
 * https://leetcode.cn/problems/find-common-characters/description/
 *
 * algorithms
 * Easy (71.40%)
 * Likes:    306
 * Dislikes: 0
 * Total Accepted:    76.9K
 * Total Submissions: 107.8K
 * Testcase Example:  '["bella","label","roller"]'
 *
 * 给你一个字符串数组 words ，请你找出所有在 words 的每个字符串中都出现的共用字符（ 包括重复字符），并以数组形式返回。你可以按 任意顺序
 * 返回答案。
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入：words = ["bella","label","roller"]
 * 输出：["e","l","l"]
 * 
 * 
 * 示例 2：
 * 
 * 
 * 输入：words = ["cool","lock","cook"]
 * 输出：["c","o"]
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 1 <= words.length <= 100
 * 1 <= words[i].length <= 100
 * words[i] 由小写英文字母组成
 * 
 * 
 */
package leetcode
// @lc code=start
func commonChars(words []string) []string {
	hashMap := make(map[rune]int)
	for _, v := range words[0] {
		hashMap[v]++
	}
	for i := 1; i < len(words); i++ {
		map1 := make(map[rune]int)
		for _, v := range words[i] {
			map1[v]++
		}
		for k, v := range hashMap {
			if cnt, ok := map1[k]; !ok {
				delete(hashMap, k)
			} else {
				hashMap[k] = min(v, cnt)
			}
		}
	}
	res := []string{}
	for k, v := range hashMap {
		for i := 0; i < v; i++ {
			res = append(res, string(k))
		}
	}
	return res
}

func min(a, b int) int {
	if a < b {
		return a
	} else {
		return b
	}
}
// @lc code=end

