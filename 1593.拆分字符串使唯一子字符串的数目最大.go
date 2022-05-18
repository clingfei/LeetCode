/*
 * @lc app=leetcode.cn id=1593 lang=golang
 *
 * [1593] 拆分字符串使唯一子字符串的数目最大
 */
package leetcode

import "math"

// @lc code=start

func max(a int, b int) int {
	if a > b {
		return a
	} else {
		return b
	}
}

func maxUniqueSplit(s string) int {
	umap := make(map[string]int)
	res := 1
	dfs(s, 0, umap, &res)
	return res
}
func dfs(s string, index int, umap map[string]int, res *int) {
	if index == len(s) {
		*res = max(len(umap), *res)
		return
	}
	for i := index; i < len(s); i++ {
		tmp := s[index:i + 1]
		if _, ok := umap[tmp]; ok {
			continue
		}
		umap[tmp]++
		dfs(s, i + 1, umap, res)
		delete(umap, tmp)
	}
}
// @lc code=end

