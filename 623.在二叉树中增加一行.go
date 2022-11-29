/*
 * @lc app=leetcode.cn id=623 lang=golang
 *
 * [623] 在二叉树中增加一行
 */
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
func addOneRow(root *TreeNode, val int, depth int) *TreeNode {
	if depth == 1 {
		return &TreeNode{val, root, nil}
	}
	que := []*TreeNode{root}
	curdepth := 1
	for len(que) != 0 && curdepth < depth - 1 {
		size := len(que)
		for i := 0; i < size; i++ {
			ptr := que[0]
			if ptr.Left != nil {
				que = append(que, ptr.Left)
			} 
			if ptr.Right != nil {
				que = append(que, ptr.Right)
			}
			que = que[1:]
		}
		curdepth++
	}
	for len(que) != 0 {
		ptr := que[0]
		ptr.Left = &TreeNode{val, ptr.Left, nil}
		ptr.Right = &TreeNode{val, nil, ptr.Right}
		que = que[1:]
	}
	return root
}
// @lc code=end

