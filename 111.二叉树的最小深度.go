/*
 * @lc app=leetcode.cn id=111 lang=golang
 *
 * [111] 二叉树的最小深度
 *
 * https://leetcode.cn/problems/minimum-depth-of-binary-tree/description/
 *
 * algorithms
 * Easy (51.52%)
 * Likes:    903
 * Dislikes: 0
 * Total Accepted:    497K
 * Total Submissions: 964.7K
 * Testcase Example:  '[3,9,20,null,null,15,7]'
 *
 * 给定一个二叉树，找出其最小深度。
 * 
 * 最小深度是从根节点到最近叶子节点的最短路径上的节点数量。
 * 
 * 说明：叶子节点是指没有子节点的节点。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入：root = [3,9,20,null,null,15,7]
 * 输出：2
 * 
 * 
 * 示例 2：
 * 
 * 
 * 输入：root = [2,null,3,null,4,null,5,null,6]
 * 输出：5
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 树中节点数的范围在 [0, 10^5] 内
 * -1000 
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
func minDepth(root *TreeNode) int {
	res := 0
	var que []*TreeNode
	if root != nil {
		que = append(que, root)
	}
	for len(que) > 0 {
		res++
		size := len(que)
		for i := 0; i < size; i++ {
			p := que[0]
			if p.Left == nil && p.Right == nil {
				return res
			}
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

