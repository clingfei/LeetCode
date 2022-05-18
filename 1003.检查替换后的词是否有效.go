/*
 * @lc app=leetcode.cn id=1003 lang=golang
 *
 * [1003] 检查替换后的词是否有效
 */
package leetcode
// @lc code=start
func isValid(s string) bool {
	var stack []byte
	for i := 0; i < len(s); i++ {
		if s[i] == 'a' {
			stack = append(stack, 'a');
		} else if s[i] == 'b' {
			stack = append(stack, 'b')
		} else {
			if len(stack) < 2 {
				return false
			}
			if stack[len(stack) - 1] == 'b' && stack[len(stack) - 2] == 'a' {
				stack = stack[:len(stack) - 2]
			} else {
				stack = append(stack, 'c')
			}
		}
	}
	return len(stack) == 0
}
// @lc code=end

