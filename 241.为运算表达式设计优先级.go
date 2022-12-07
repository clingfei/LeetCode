/*
 * @lc app=leetcode.cn id=241 lang=golang
 *
 * [241] 为运算表达式设计优先级
 *
 * https://leetcode.cn/problems/different-ways-to-add-parentheses/description/
 *
 * algorithms
 * Medium (75.73%)
 * Likes:    768
 * Dislikes: 0
 * Total Accepted:    71.3K
 * Total Submissions: 94.2K
 * Testcase Example:  '"2-1-1"'
 *
 * 给你一个由数字和运算符组成的字符串 expression ，按不同优先级组合数字和运算符，计算并返回所有可能组合的结果。你可以 按任意顺序 返回答案。
 *
 * 生成的测试用例满足其对应输出值符合 32 位整数范围，不同结果的数量不超过 10^4 。
 *
 *
 *
 * 示例 1：
 *
 *
 * 输入：expression = "2-1-1"
 * 输出：[0,2]
 * 解释：
 * ((2-1)-1) = 0
 * (2-(1-1)) = 2
 *
 *
 * 示例 2：
 *
 *
 * 输入：expression = "2*3-4*5"
 * 输出：[-34,-14,-10,-10,10]
 * 解释：
 * (2*(3-(4*5))) = -34
 * ((2*3)-(4*5)) = -14
 * ((2*(3-4))*5) = -10
 * (2*((3-4)*5)) = -10
 * (((2*3)-4)*5) = 10
 *
 *
 *
 *
 * 提示：
 *
 *
 * 1 <= expression.length <= 20
 * expression 由数字和算符 '+'、'-' 和 '*' 组成。
 * 输入表达式中的所有整数值在范围 [0, 99]
 *
 *
 */
package leetcode

import (
	"fmt"
	"strconv"
)

// @lc code=start
func diffWaysToCompute(expression string) []int {
	if val, err := strconv.Atoi(expression); err == nil {
		return []int{val}
	} else{}
	res := []int{}
	for i := 0; i < len(expression); i++ {
		if expression[i] >= '0' && expression[i] <= '9' {
			continue
		}
		for _, v := range diffWaysToCompute(expression[:i]) {
			for _, v1 := range diffWaysToCompute(expression[i + 1: ]) {
				res = append(res, calc(expression[i], v, v1))	
			}
		}
	}
	return res
}

func calc(op byte, op1, op2 int) int {
	switch op {
	case '+':
		return op1 + op2
	case '-': 
		return op1 - op2
	case '*':
		return op1 * op2
	}
	return 0
}
// @lc code=end

