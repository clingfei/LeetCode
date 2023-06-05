/*
 * @lc app=leetcode.cn id=1864 lang=golang
 *
 * [1864] 构成交替字符串需要的最小交换次数
 *
 * https://leetcode.cn/problems/minimum-number-of-swaps-to-make-the-binary-string-alternating/description/
 *
 * algorithms
 * Medium (40.49%)
 * Likes:    26
 * Dislikes: 0
 * Total Accepted:    6.5K
 * Total Submissions: 15.9K
 * Testcase Example:  '"111000"'
 *
 * 给你一个二进制字符串 s ，现需要将其转化为一个 交替字符串 。请你计算并返回转化所需的 最小 字符交换次数，如果无法完成转化，返回 -1 。
 * 
 * 交替字符串 是指：相邻字符之间不存在相等情况的字符串。例如，字符串 "010" 和 "1010" 属于交替字符串，但 "0100" 不是。
 * 
 * 任意两个字符都可以进行交换，不必相邻 。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入：s = "111000"
 * 输出：1
 * 解释：交换位置 1 和 4："111000" -> "101010" ，字符串变为交替字符串。
 * 
 * 
 * 示例 2：
 * 
 * 
 * 输入：s = "010"
 * 输出：0
 * 解释：字符串已经是交替字符串了，不需要交换。
 * 
 * 
 * 示例 3：
 * 
 * 
 * 输入：s = "1110"
 * 输出：-1
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 1 
 * s[i] 的值为 '0' 或 '1'
 * 
 * 
 */
package leetcode
// @lc code=start
func minSwaps(s string) int {
	zeros := 0
	for _, v := range s {
		if v == '0' {
			zeros++
		}
	}
	if len(s) % 2 == 0 {
		if zeros != len(s) / 2 {
			return -1
		}
		min := Swaps(zeros, 1, s)
		cur := Swaps(zeros, 0, s)
		if cur < min {
			min = cur
		} 
		return min
	} else {
		if zeros == len(s) / 2 + 1 {
			return Swaps(zeros, 1, s)
		} else if zeros == len(s) / 2{
			return Swaps(zeros, 0, s)
		} else {
			return -1
		}
	}
}

func Swaps(zeros int, pre int, s string) int {
	cur := 0
	for i := 0; i < len(s); i++ {
		if int(s[i] - '0') == pre {
			if pre == 1 {
				zeros--
				cur++
				pre = 0
			} else {
				pre = 1
			}
		} else {
			pre = int(s[i] - '0')
		}
	}
	return cur
}
// @lc code=end

