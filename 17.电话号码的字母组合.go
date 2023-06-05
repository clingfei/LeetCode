/*
 * @lc app=leetcode.cn id=17 lang=golang
 *
 * [17] 电话号码的字母组合
 *
 * https://leetcode.cn/problems/letter-combinations-of-a-phone-number/description/
 *
 * algorithms
 * Medium (58.00%)
 * Likes:    2261
 * Dislikes: 0
 * Total Accepted:    621K
 * Total Submissions: 1.1M
 * Testcase Example:  '"23"'
 *
 * 给定一个仅包含数字 2-9 的字符串，返回所有它能表示的字母组合。答案可以按 任意顺序 返回。
 * 
 * 给出数字到字母的映射如下（与电话按键相同）。注意 1 不对应任何字母。
 * 
 * 
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入：digits = "23"
 * 输出：["ad","ae","af","bd","be","bf","cd","ce","cf"]
 * 
 * 
 * 示例 2：
 * 
 * 
 * 输入：digits = ""
 * 输出：[]
 * 
 * 
 * 示例 3：
 * 
 * 
 * 输入：digits = "2"
 * 输出：["a","b","c"]
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 0 <= digits.length <= 4
 * digits[i] 是范围 ['2', '9'] 的一个数字。
 * 
 * 
 */
package leetcode
// @lc code=start
func letterCombinations(digits string) []string {
	if len(digits) == 0 {
		return []string{}
	}
	umap := make(map[byte]string)
	umap['2'] = "abc"
	umap['3'] = "def"
	umap['4'] = "ghi"
	umap['5'] = "jkl"
	umap['6'] = "mno"
	umap['7'] = "pqrs"
	umap['8'] = "tuv"
	umap['9'] = "wxyz"
	var res []string
	var path string
	var dfs func (idx int)
	dfs = func(idx int) {
		if idx == len(digits) {
			res = append(res, path)
			return
		}
		for _, v := range umap[digits[idx]] {
			path += string(v)
			dfs(idx + 1)
			path = path[:len(path) - 1]
		}
	}
	dfs(0)
	return res
}
// @lc code=end

