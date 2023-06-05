/*
 * @lc app=leetcode.cn id=93 lang=golang
 *
 * [93] 复原 IP 地址
 *
 * https://leetcode.cn/problems/restore-ip-addresses/description/
 *
 * algorithms
 * Medium (57.69%)
 * Likes:    1116
 * Dislikes: 0
 * Total Accepted:    298.1K
 * Total Submissions: 516.7K
 * Testcase Example:  '"25525511135"'
 *
 * 有效 IP 地址 正好由四个整数（每个整数位于 0 到 255 之间组成，且不能含有前导 0），整数之间用 '.' 分隔。
 *
 *
 * 例如："0.1.2.201" 和 "192.168.1.1" 是 有效 IP 地址，但是 "0.011.255.245"、"192.168.1.312"
 * 和 "192.168@1.1" 是 无效 IP 地址。
 *
 *
 * 给定一个只包含数字的字符串 s ，用以表示一个 IP 地址，返回所有可能的有效 IP 地址，这些地址可以通过在 s 中插入 '.' 来形成。你 不能
 * 重新排序或删除 s 中的任何数字。你可以按 任何 顺序返回答案。
 *
 *
 *
 * 示例 1：
 *
 *
 * 输入：s = "25525511135"
 * 输出：["255.255.11.135","255.255.111.35"]
 *
 *
 * 示例 2：
 *
 *
 * 输入：s = "0000"
 * 输出：["0.0.0.0"]
 *
 *
 * 示例 3：
 *
 *
 * 输入：s = "101023"
 * 输出：["1.0.10.23","1.0.102.3","10.1.0.23","10.10.2.3","101.0.2.3"]
 *
 *
 *
 *
 * 提示：
 *
 *
 * 1 <= s.length <= 20
 * s 仅由数字组成
 *
 *
 */
package leetcode

import "strconv"

// @lc code=start
func check(str string) bool {
	if str[0] == '0' && len(str) != 1 {
		return false
	}
	v, err := strconv.Atoi(str)
	if err != nil || v < 0 || v > 255 {
		return false
	} else {
		return true
	}
}
func restoreIpAddresses(s string) []string {
	var res []string
	var path []string
	var dfs func(int )
	dfs = func(idx int) {
		if len(path) > 4 || (len(path) == 4 && idx < len(s)) || (idx >= len(s) && len(path) < 4) {
			return
		} else if idx >= len(s) {
			tmp := ""
			tmp += path[0]
			for i := 1; i < len(path); i++ {
				tmp += "." + path[i]
			}
			res = append(res, tmp)
			return 
		}
		for i := idx; i < len(s) && i < idx + 3; i++ {
			tmp := s[idx:i + 1]
			if check(tmp) {
				path = append(path, tmp) 
				dfs(i + 1)
				path = path[:len(path) - 1]
			} else {
				break
			} 
		}
	}
	dfs(0)
	return res
}
// @lc code=end

