/*
 * @lc app=leetcode.cn id=20 lang=golang
 *
 * [20] 有效的括号
 *
 * https://leetcode.cn/problems/valid-parentheses/description/
 *
 * algorithms
 * Easy (44.42%)
 * Likes:    3648
 * Dislikes: 0
 * Total Accepted:    1.3M
 * Total Submissions: 3M
 * Testcase Example:  '"()"'
 *
 * 给定一个只包括 '('，')'，'{'，'}'，'['，']' 的字符串 s ，判断字符串是否有效。
 *
 * 有效字符串需满足：
 *
 *
 * 左括号必须用相同类型的右括号闭合。
 * 左括号必须以正确的顺序闭合。
 * 每个右括号都有一个对应的相同类型的左括号。
 *
 *
 *
 *
 * 示例 1：
 *
 *
 * 输入：s = "()"
 * 输出：true
 *
 *
 * 示例 2：
 *
 *
 * 输入：s = "()[]{}"
 * 输出：true
 *
 *
 * 示例 3：
 *
 *
 * 输入：s = "(]"
 * 输出：false
 *
 *
 *
 *
 * 提示：
 *
 *
 * 1 <= s.length <= 10^4
 * s 仅由括号 '()[]{}' 组成
 *
 *
 */
package leetcode

import "fmt"

// @lc code=start
type Stack []rune

func (s *Stack) Push(x rune) {
	*s = append(*s, x)
}

func (s *Stack) back() rune {
	res := (*s)[len(*s) - 1]
	return res
}

func (s *Stack) Pop() rune {
	l := len(*s)
	res := (*s)[l - 1]
	*s = (*s)[:l - 1]
	return res
}

func (s *Stack) isEmpty() bool {
	return len(*s) == 0
}

func isValid(s string) bool {
	var sta Stack

	for _, v := range s {
		if v == '(' || v == '{' || v == '[' {
			sta.Push(v)
		} else {
			if sta.isEmpty() {
				return false
			}
			switch v {
			case ')':
				if sta.back() == '(' {
					sta.Pop()
				} else {
					return false
				}
			case '}':
				if sta.back() == '{' {
					sta.Pop()
				} else {
					return false
				}
			case ']':
				if sta.back() == '[' {
					sta.Pop()
				} else {
					return false
				}
			}
		}
	}
	return sta.isEmpty()
}
// @lc code=end

