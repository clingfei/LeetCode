/*
 * @lc app=leetcode.cn id=102 lang=golang
 *
 * [102] 二叉树的层序遍历
 */
package leetcode
// @lc code=start
/**
 * Definition for a binary tree node.
 * type TreeNode struct {
 *     Val int
 *     Left *TreeNode
 *     Right *TreeNode
 * }
 */
 type TreeNode struct {
    Val int
    Left *TreeNode
    Right *TreeNode
}
func levelOrder(root *TreeNode) [][]int {
	var res [][]int
	var queue []*TreeNode
	if root == nil {
		return res
	}
	p := root
	queue = append(queue, p)
	for len(queue) > 0 {
		size := len(queue)
		var temp []int
		for i := 0; i < size; i++ {
			p = queue[0]
			queue = queue[1:]
			temp = append(temp, p.Val)
			if p.Left != nil {
				queue = append(queue, p.Left)
			}
			if p.Right != nil {
				queue = append(queue, p.Right)
			}
		}
		res = append(res, temp)
	}
	return res
}
// @lc code=end

