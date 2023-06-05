/*
 * @lc app=leetcode.cn id=404 lang=golang
 *
 * [404] 左叶子之和
 *
 * https://leetcode.cn/problems/sum-of-left-leaves/description/
 *
 * algorithms
 * Easy (61.88%)
 * Likes:    541
 * Dislikes: 0
 * Total Accepted:    204K
 * Total Submissions: 329.7K
 * Testcase Example:  '[3,9,20,null,null,15,7]'
 *
 * 给定二叉树的根节点 root ，返回所有左叶子之和。
 *
 *
 *
 * 示例 1：
 *
 *
 *
 *
 * 输入: root = [3,9,20,null,null,15,7]
 * 输出: 24
 * 解释: 在这个二叉树中，有两个左叶子，分别是 9 和 15，所以返回 24
 *
 *
 * 示例 2:
 *
 *
 * 输入: root = [1]
 * 输出: 0
 *
 *
 *
 *
 * 提示:
 *
 *
 * 节点数在 [1, 1000] 范围内
 * -1000 <= Node.val <= 1000
 *
 *
 *
 *
 */
package leetcode

type TreeNode struct {
	Val   int
	Left  *TreeNode
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
func sumOfLeftLeaves(root *TreeNode) int {
	res := 0
	if root == nil {
		return res
	}
	var dfs func(*TreeNode)
	dfs = func(tn *TreeNode) {
		if tn == nil {
			return
		}
		if tn.Left != nil && tn.Left.Left == nil && tn.Left.Right == nil {
			res += tn.Left.Val
			if tn.Right != nil {
				dfs(tn.Right)
			}
		} else {
			if tn.Left != nil {
				dfs(tn.Left)
			}
			if tn.Right != nil {
				dfs(tn.Right)
			}
		}
	}
	dfs(root)
	return res
}

// @lc code=end
