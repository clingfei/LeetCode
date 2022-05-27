/*
 * @lc app=leetcode.cn id=1773 lang=golang
 *
 * [1773] 统计匹配检索规则的物品数量
 */
package leetcode
// @lc code=start
func countMatches(items [][]string, ruleKey string, ruleValue string) int {
	res := 0
	if ruleKey == "type" {
		for _, v := range items {
			if v[0] == ruleValue {
				res++
			}
		}
	} else if ruleKey == "color" {
		for _, v := range items {
			if v[1] == ruleValue {
				res++
			}
		}
	} else if ruleKey == "name" {
		for _, v := range items {
			if v[2] == ruleValue {
				res++
			}
		}
	}
	return res
}
// @lc code=end

