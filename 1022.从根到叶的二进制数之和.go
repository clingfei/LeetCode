/*
 * @lc app=leetcode.cn id=1022 lang=golang
 *
 * [1022] 从根到叶的二进制数之和
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
func sumRootToLeaf(root *TreeNode) int {
	res := 0
	sum(root, 0, &res)
	return res
}

func sum(root *TreeNode, cur int, res *int) {
	if root == nil {
		return
	}
	cur = cur << 1 + root.Val
	if root.Left == nil && root.Right == nil {
		*res += cur
		return
	} else if root.Left == nil {
		sum(root.Right, cur, res)
	} else if root.Right == nil {
		sum(root.Left, cur, res)
	} else {
		sum(root.Left, cur, res)
		sum(root.Right, cur, res)
	}
}
// @lc code=end

