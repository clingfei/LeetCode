/*
 * @lc app=leetcode.cn id=110 lang=golang
 *
 * [110] 平衡二叉树
 *
 * https://leetcode.cn/problems/balanced-binary-tree/description/
 *
 * algorithms
 * Easy (57.42%)
 * Likes:    1223
 * Dislikes: 0
 * Total Accepted:    453K
 * Total Submissions: 788.9K
 * Testcase Example:  '[3,9,20,null,null,15,7]'
 *
 * 给定一个二叉树，判断它是否是高度平衡的二叉树。
 *
 * 本题中，一棵高度平衡二叉树定义为：
 *
 *
 * 一个二叉树每个节点 的左右两个子树的高度差的绝对值不超过 1 。
 *
 *
 *
 *
 * 示例 1：
 *
 *
 * 输入：root = [3,9,20,null,null,15,7]
 * 输出：true
 *
 *
 * 示例 2：
 *
 *
 * 输入：root = [1,2,2,3,3,null,null,4,4]
 * 输出：false
 *
 *
 * 示例 3：
 *
 *
 * 输入：root = []
 * 输出：true
 *
 *
 *
 *
 * 提示：
 *
 *
 * 树中的节点数在范围 [0, 5000] 内
 * -10^4
 *
 *
 */
package leetcode

import (
	"fmt"
	"math"
)
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
func isBalanced(root *TreeNode) bool {
	ok, _ := balanced(root)
	return ok
}

func balanced(root *TreeNode) (bool, float64) {
	if root == nil {
		return true, 0
	}
	flag1, height1 := balanced(root.Left)
	if !flag1 {
		return false, -1 
	}
	flag2, height2 := balanced(root.Right)
	if !flag2 {
		return false, -1
	}	
	if math.Abs(height1 - height2) <= 1 {
		return true, math.Max(height1, height2) + 1
	} else {
		return false, -1
	}
}

// @lc code=end

