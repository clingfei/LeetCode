/*
 * @lc app=leetcode.cn id=890 lang=golang
 *
 * [890] 查找和替换模式
 */
package leetcode
// @lc code=start
func findAndReplacePattern(words []string, pattern string) []string {
	var res []string
	for _, v := range words {
		flag := true
		map1, map2 := make(map[byte]byte), make(map[byte]byte)
		for  i := 0; i < len(pattern); i++ {
			_, ok1 := map1[v[i]]
			_, ok2 := map2[pattern[i]]
			if !ok1 && !ok2 {
				map1[v[i]] = pattern[i]
				map2[pattern[i]] = v[i]
			} else if !ok1 || !ok2 {
				flag = false
				break 
			} else {
				if map1[v[i]] != pattern[i] || map2[pattern[i]] != v[i] {
					flag = false
					break
				}
			}
		}
		if flag {
			res = append(res, v)
		}
	}
	return res
}
// @lc code=end

