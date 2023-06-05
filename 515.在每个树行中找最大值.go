/*
 * @lc app=leetcode.cn id=515 lang=golang
 *
 * [515] 在每个树行中找最大值
 *
 * https://leetcode.cn/problems/find-largest-value-in-each-tree-row/description/
 *
 * algorithms
 * Medium (66.34%)
 * Likes:    293
 * Dislikes: 0
 * Total Accepted:    108.3K
 * Total Submissions: 163.2K
 * Testcase Example:  '[1,3,2,5,3,null,9]'
 *
 * 给定一棵二叉树的根节点 root ，请找出该二叉树中每一层的最大值。
 * 
 * 
 * 
 * 示例1：
 * 
 * 
 * 
 * 
 * 输入: root = [1,3,2,5,3,null,9]
 * 输出: [1,3,9]
 * 
 * 
 * 示例2：
 * 
 * 
 * 输入: root = [1,2,3]
 * 输出: [1,3]
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 二叉树的节点个数的范围是 [0,10^4]
 * -2^31 <= Node.val <= 2^31 - 1
 * 
 * 
 * 
 * 
 */
package leetcode
type TreeNode struct {
    Val int
    Left *TreeNode
    Right *TreeNode
}
// @lc code=start
/**
 * Definition for a binary tree node.
 * type TreeNode struct {
 *     Val int
 *     Left *TreeNode
 *     Right *TreeNode
 * }
 */
func largestValues(root *TreeNode) []int {
	var res []int
	var que []*TreeNode
	if root != nil {
		que = append(que, root)
	}
	for len(que) > 0 {
		size := len(que)
		max := que[0].Val
		for i := 0; i < size; i++ {
			p := que[i]
			if p.Val > max {
				max = p.Val
			}
			if p.Left != nil {
				que = append(que, p.Left)
			}
			if p.Right != nil {
				que = append(que, p.Right)
			}
		}
		que = que[size:]
		res = append(res, max)
	}
	return res
}
// @lc code=end

