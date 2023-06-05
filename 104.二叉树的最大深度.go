/*
 * @lc app=leetcode.cn id=104 lang=golang
 *
 * [104] 二叉树的最大深度
 *
 * https://leetcode.cn/problems/maximum-depth-of-binary-tree/description/
 *
 * algorithms
 * Easy (77.12%)
 * Likes:    1464
 * Dislikes: 0
 * Total Accepted:    915.2K
 * Total Submissions: 1.2M
 * Testcase Example:  '[3,9,20,null,null,15,7]'
 *
 * 给定一个二叉树，找出其最大深度。
 * 
 * 二叉树的深度为根节点到最远叶子节点的最长路径上的节点数。
 * 
 * 说明: 叶子节点是指没有子节点的节点。
 * 
 * 示例：
 * 给定二叉树 [3,9,20,null,null,15,7]，
 * 
 * ⁠   3
 * ⁠  / \
 * ⁠ 9  20
 * ⁠   /  \
 * ⁠  15   7
 * 
 * 返回它的最大深度 3 。
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
func maxDepth(root *TreeNode) int {
	var que []*TreeNode
	if root != nil {
		que = append(que, root)
	}
	res := 0
	for len(que) > 0 {
		res++
		size := len(que)
		for i := 0; i < size; i++ {
			p := que[0]
			que = que[1:]
			if p.Left != nil {
				que = append(que, p.Left)
			}
			if p.Right != nil {
				que = append(que, p.Right)
			}
		}
	}
	return res
}
// @lc code=end

