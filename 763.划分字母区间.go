/*
 * @lc app=leetcode.cn id=763 lang=golang
 *
 * [763] 划分字母区间
 *
 * https://leetcode.cn/problems/partition-labels/description/
 *
 * algorithms
 * Medium (76.89%)
 * Likes:    877
 * Dislikes: 0
 * Total Accepted:    146.5K
 * Total Submissions: 190.6K
 * Testcase Example:  '"ababcbacadefegdehijhklij"'
 *
 * 给你一个字符串 s 。我们要把这个字符串划分为尽可能多的片段，同一字母最多出现在一个片段中。
 * 
 * 注意，划分结果需要满足：将所有划分结果按顺序连接，得到的字符串仍然是 s 。
 * 
 * 返回一个表示每个字符串片段的长度的列表。
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入：s = "ababcbacadefegdehijhklij"
 * 输出：[9,7,8]
 * 解释：
 * 划分结果为 "ababcbaca"、"defegde"、"hijhklij" 。
 * 每个字母最多出现在一个片段中。
 * 像 "ababcbacadefegde", "hijhklij" 这样的划分是错误的，因为划分的片段数较少。 
 * 
 * 示例 2：
 * 
 * 
 * 输入：s = "eccbbbbdec"
 * 输出：[10]
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 1 <= s.length <= 500
 * s 仅由小写英文字母组成
 * 
 * 
 */
package leetcode
// @lc code=start
func partitionLabels(s string) []int {
	// 记录每个字母出现的最后下标
	// 从头到尾扫描每个字母，找到一个最后的边界
	alpha := make([]int, 26)
	for i, a := range s {
		alpha[a - 'a'] = i
	}
	res := make([]int, 0)
	boundary := alpha[s[0] - 'a']
	cnt := 0
	for i := 0; i < len(s); i++ {
		if i > boundary {
			boundary = alpha[s[i] - 'a']
			cnt = 1
		} else {
			cnt++
			boundary = max(boundary, alpha[s[i] - 'a'])
		}
		if i == boundary {
			res = append(res, cnt)
		}
	}
	return res
}

func max(a, b int) int {
	if a > b {
		return a
	} else {
		return b
	}
}
// @lc code=end

