/*
 * @lc app=leetcode.cn id=958 lang=golang
 *
 * [958] 二叉树的完全性检验
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
func isCompleteTree(root *TreeNode) bool {
	var queue []*TreeNode
	if root == nil {
		return true
	}
	queue = append(queue, root)
	last := false
	for len(queue) > 0 {
		size := len(queue)
		this := false
		for i := 0; i < size; i++ {
			p := queue[0]
			queue = queue[1:]
			if p.Left != nil {
				if this || last {
					return false
				} else {
					queue = append(queue, p.Left)
				}
			} else {
				this = true
				last = true
			}
			if p.Right != nil {
				if this || last {
					return false
				} else {
					queue = append(queue, p.Right)
				}
			} else {
				this = true
				last = true
			}
		}
	}
	return true
}
// @lc code=end

