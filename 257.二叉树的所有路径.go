/*
 * @lc app=leetcode.cn id=257 lang=golang
 *
 * [257] 二叉树的所有路径
 *
 * https://leetcode.cn/problems/binary-tree-paths/description/
 *
 * algorithms
 * Easy (70.58%)
 * Likes:    864
 * Dislikes: 0
 * Total Accepted:    274.5K
 * Total Submissions: 388.9K
 * Testcase Example:  '[1,2,3,null,5]'
 *
 * 给你一个二叉树的根节点 root ，按 任意顺序 ，返回所有从根节点到叶子节点的路径。
 *
 * 叶子节点 是指没有子节点的节点。
 *
 *
 * 示例 1：
 *
 *
 * 输入：root = [1,2,3,null,5]
 * 输出：["1->2->5","1->3"]
 *
 *
 * 示例 2：
 *
 *
 * 输入：root = [1]
 * 输出：["1"]
 *
 *
 *
 *
 * 提示：
 *
 *
 * 树中节点的数目在范围 [1, 100] 内
 * -100 <= Node.val <= 100
 *
 *
 */
package leetcode

import "fmt"
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
func binaryTreePaths(root *TreeNode) []string {
	var res []string
	if root == nil {
		return res
	}
	var dfs func (*TreeNode, string)
	tmp := fmt.Sprint(root.Val)
	dfs = func(tn *TreeNode, tmp string) {
		if tn == nil {
			return 
		}
		tmp += "->" + fmt.Sprint(tn.Val)
		if tn.Left != nil {
			dfs(tn.Left, tmp)	
		}
		if tn.Right != nil {
			dfs(tn.Right, tmp)
		}
		if tn.Left == nil && tn.Right == nil {
			res = append(res, tmp)
		}
	}
	if root.Left == nil && root.Right == nil {
		res = append(res, tmp)
	} else {
		dfs(root.Left, tmp)
		dfs(root.Right, tmp)
	}
	return res
}
// @lc code=end

