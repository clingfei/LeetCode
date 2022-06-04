/*
 * @lc app=leetcode.cn id=929 lang=golang
 *
 * [929] 独特的电子邮件地址
 */
package leetcode

import "strings"

// @lc code=start
func numUniqueEmails(emails []string) int {
	umap := make(map[string]bool)
	local := strings.Builder{}
	for _, v := range emails {
		local.Reset()
		i := 0
		for ; i < len(v) && v[i] != '@'; i++ {
			if v[i] == '.' {
				continue
			} else if v[i] == '+' {
				for v[i] != '@' {
					i++
				}
				break
			} else {
				local.WriteByte(v[i])
			}
		}
		umap[local.String() + v[i:]] = true
	}
	return len(umap)
}
// @lc code=end

