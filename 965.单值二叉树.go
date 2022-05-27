/*
 * @lc app=leetcode.cn id=965 lang=golang
 *
 * [965] 单值二叉树
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
func isUnivalTree(root *TreeNode) bool {
	if root == nil {
		return true
	}
	return inOrder(root.Left, root.Val) && inOrder(root.Right, root.Val)
}

func inOrder(root *TreeNode, pre int) bool {
	if root == nil {
		return true
	}
	if root.Val != pre {
		return false
	} else {
		return inOrder(root.Left, pre) && inOrder(root.Right, pre)
	}
}
// @lc code=end

